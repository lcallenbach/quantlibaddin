/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2004, 2005, 2006, 2007, 2008 Eric Ehlers
 Copyright (C) 2006, 2008 Plamen Neykov
 Copyright (C) 2008 Nazcatech sprl Belgium
 Copyright (C) 2016 Lars Callenbach

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file
    \brief Class Object - Define interface for Objects to be stored in the Repository
*/

#ifndef oh_object_hpp
#define oh_object_hpp

#include <oh/ohdefines.hpp>
#include <oh/exception.hpp>
#include <boost/shared_ptr.hpp>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <set>

namespace ObjectHandler {

    //! Interface for Objects to be stored in the ObjectHandler Repository.
    /*! Objects are constructed by the client and passed to
        Repository::storeObject() for storage in the Repository.

        All member functions of this class are implemented inline.  This is not
        for performance reasons; the entire implementation of the class must appear
        in the header file in order to allow derived classes to inherit from Object
        across DLL boundaries on the Windows platform.
    */
    class Object {        
    public:
        //! \name Structors
        //@{
        //! Default constructor.
        /*! Construct an Object.  To store the resulting Object in the
            Repository, call
            \code
                Repository::instance().storeObject(objectID, object);
            \endcode
        */
        Object(std::string className,
               bool permanent = false)
            : className_(className), permanent_(permanent) {}
        //! Empty virtual destructor.
        virtual ~Object() {}
        //@}

        //! \name Permanent Objects
        //@{
        //! Query the value of the "permanent" flag.
        /*! Permanent Objects remain in the Repository after a call to
            Repository::deleteAllObjects() or Repository::collectGarbage().

            This feature allows a finer level of granularity in maintaining
            the contents of the Repository.
        */
        const virtual bool &permanent() const { return permanent_; }
        //@}

        //! Retrieve the list of precedent Object IDs.
        const std::set<std::string>& getPrecedentObjects() { return precedentIDs_;}

        //! Name of this Object's class.
        const std::string &className() const { return className_; }

        //! Object reference.
        void *get() { return object_; }

        //! Object update call.
        virtual void update() {};

        //! Object update call.
        virtual void del() {};


    protected:
        //! Object to be stored as (void *).
        void *object_;

    private:
        // Flag to indicate whether this Object is permanent.
        bool permanent_;
        //! List of precedent Object IDs
        std::set<std::string> precedentIDs_;
        //! A string identifiying the class of this Object.
        std::string className_;
    };

}

#endif

