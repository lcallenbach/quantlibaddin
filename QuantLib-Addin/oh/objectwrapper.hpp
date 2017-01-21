/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2004, 2005, 2006, 2007  Eric Ehlers
 Copyright (C) 2006 Plamen Neykov
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
    \brief Class ObjectWrapper - Ensure that Object references are up to date.
*/

#ifndef oh_objectwrapper_hpp
#define oh_objectwrapper_hpp

#include <ostream>
#include <iostream>
#include <oh/object.hpp>
#include <oh/observable.hpp>
#include <oh/utilities.hpp>

namespace ObjectHandler {

    //! Container to ensure that Object references are updated.
    /*! ObjectWrapper holds a reference to an Object.  Before returning the reference
        the ObjectHandler client application, the ObjectWrapper ensures that the state
        of the Object is updated as necessary to reflect any changes in its precedents.
        There is a 1:1 relationship between Object and ObjectWrapper instances.

        ObjectWrapper inherits from Observer and Observable.  ObjectWrapper registers as
        an Observer of its Object's precedents.  If any of those precedents changes,
        the ObjectWrapper is notified and sets its Dirty property to true.  If the
        ObjectHandler client application attempts to retrieve a Dirty Object, the
        ObjectWrapper first recreates the Object, ensuring that its state reflects
        any changes in the precedents.
    */
    class ObjectWrapper : public Observer, public Observable {        
    public:
        //! \name Structors
        //@{
        //! Construct the ObjectWrapper from the given Object.
        ObjectWrapper(const boost::shared_ptr<Object>& object);
        //! Virtual destructor - unregister with Observers.
        virtual ~ObjectWrapper() { unregisterWithAll(); }
        //@}

        //! \name Behavior
        //@{
        //! Recreate the Object contained by the ObjectWrapper.
        /*! This function is called on any attempt to retrieve a Dirty Object.
            To recreate the Object, we take its ValueObject, which is a snapshot
            of the arguments to the Object's constructor, and pass this ValueObject
            to the SerializationFactory which recreates the Object.
        */
        void recreate();
        //! Update the ObjectWrapper following a change in its precedents.
        /*! This function is called by the Observable with which this Observer
            has registered.  Sets Dirty -> true.
        */
        virtual void update();
        //! Return a copy of the reference to the Object contained by ObjectWrapper.
        boost::shared_ptr<Object> object() const { return object_; }
        //! Replace the contained Object with the one provided.
        void reset(boost::shared_ptr<Object> object);
        //@}

        //! \name Inspectors
        //@{
        //! Query the value of the dirty flag.
        /*! False means the Object is up to date, true means it is invalid.
        */
        bool dirty() const { return dirty_; }
        //@}

    protected:
        //! Reference to the Object contained by ObjectWrapper.
        boost::shared_ptr<Object> object_;

    private:
        // Flag indicating whether contained Object is up to date.
        bool dirty_;
    };

    inline ObjectWrapper::ObjectWrapper(const boost::shared_ptr<Object>& object)
        : object_(object), dirty_(false) { }

    inline void ObjectWrapper::recreate(){
        try {
            object_->update();
            dirty_ = false;
        } catch (const std::exception &e) {
            OH_FAIL("Error in function ObjectWrapper::recreate() : " << e.what());
        }
    }

    inline void ObjectWrapper::update(){
    std::cerr << "update begin " << std::endl;
        object_->update();
        dirty_ = false;
        notifyObservers();
    std::cerr << "update end " << std::endl;
    }

    inline void ObjectWrapper::reset(boost::shared_ptr<Object> object) {
    std::cerr << "reset start " << std::endl;
        object_ = object;
        dirty_ = false;
        notifyObservers();
    std::cerr << "reset end " << std::endl;
    }
}

#endif

