/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2004, 2005, 2006, 2007, 2008 Eric Ehlers
 Copyright (C) 2005, 2006, 2007, 2012 Ferdinando Ametrano
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

#if defined(HAVE_CONFIG_H)     // Dynamically created by configure
#include <oh/config.hpp>
#endif

#include <oh/repository.hpp>
#include <oh/exception.hpp>
#include <boost/regex.hpp>
#include <ostream>
#include <iostream>
#include <sstream>

using boost::shared_ptr;
using std::set;
using std::string;
using std::endl;
using std::cerr;

namespace ObjectHandler {

    inline void deleter(ObjectWrapper *objectWrapper) {};

    Repository *Repository::instance_;

    // std::map cannot be exported across DLL boundaries
    // so instead we use a static variable.
    Repository::ObjectMap objectMap_;

    Repository::Repository() {
        instance_ = this;
    }

    Repository::~Repository() {
        instance_ = 0;
    }

    Repository &Repository::instance() {
        OH_REQUIRE(instance_,
                   "Attempt to reference uninitialized Repository object");
        return *instance_;
    }

    // TODO: implement Scott Meyers' "Effective STL" item 24
    string Repository::storeObject(const string &objectID,
                                   const shared_ptr<Object> &object,
                                   bool overwrite) {
        OH_REQUIRE(overwrite || !objectExists(objectID),
                   "Cannot store object with ID '" << objectID <<
                   "' because an object with that ID already exists");

        std::cerr << "Repository for " << objectID << std::endl;
        if(objectExists(objectID)){
            std::cerr << "Repository 1 start " << std::endl;
            ObjectMap::const_iterator result = objectMap_.find(objectID);
            //result->second->notifyObservers();
            result->second->reset(object);
            std::cerr << "Repository 1 ende " << std::endl;
        } else{
            std::cerr << "Repository 2 start " << std::endl;
            shared_ptr<ObjectWrapper> objWrapper = shared_ptr<ObjectWrapper>(new ObjectWrapper(object), deleter);
            objectMap_[objectID] = objWrapper;
            std::cerr << "Repository 2 ende " << std::endl;
        }

        registerObserver(objectMap_[objectID]);
        return objectID;
    }

    shared_ptr<Object> Repository::retrieveObject(const string &objectID) {

        ObjectMap::const_iterator result = objectMap_.find(formatID(objectID));
        OH_REQUIRE(result != objectMap_.end(),
                   "ObjectHandler error: attempt to retrieve object "
                   "with unknown ID '" << objectID << "'");
        if(result->second->dirty()) {
            result->second->recreate();
        }
        return result->second->object();
    }

    const shared_ptr<ObjectWrapper>&
    Repository::getObjectWrapper(const string &objectID) const {

        ObjectMap::const_iterator result = objectMap_.find(objectID);
        OH_REQUIRE(result != objectMap_.end(),
                   "ObjectHandler error: attempt to retrieve object "
                   "with unknown ID '" << objectID << "'");

        return result->second;
    }

    void Repository::registerObserver(shared_ptr<ObjectWrapper> objWrapper) {

        std::cerr << "registerObserver start " << std::endl;
        objWrapper->unregisterWithAll();
        std::cerr << "unregister start " << std::endl;
        const set<string>& relationObs =
            objWrapper->object()->getPrecedentObjects();
        set<string>::const_iterator iter = relationObs.begin();
        for(; iter != relationObs.end();  iter++) {
            std::cerr << "register " << *iter << std::endl;
            shared_ptr<ObjectWrapper> objServable =
                                            getObjectWrapper(formatID(*iter));
            objWrapper->registerWith(objServable);
        }
        std::cerr << "registerObserver end " << std::endl;
    }

    void Repository::deleteObject(const string &objectID) {
        string realID = formatID(objectID);
        OH_REQUIRE(objectExists(realID),
                   "Cannot delete '" << realID << "' because no Object with "
                   "that ID is present in the Repository");
        objectMap_.erase(realID);
    }

    void Repository::deleteObject(const std::vector<string> &objectIDs) {
        OH_REQUIRE(!objectIDs.empty(),
                   "List of Object IDs for deletion is empty");
        std::vector<string>::const_iterator i;
        for (i = objectIDs.begin(); i != objectIDs.end(); ++i)
            deleteObject(*i);
    }

    void Repository::deleteAllObjects(const bool &deletePermanent) {

        if (deletePermanent) {
            objectMap_.clear();
        } else {
            ObjectMap::iterator i = objectMap_.begin();
            while (i != objectMap_.end()) {
                if (i->second->object()->permanent())
                    ++i;
                else
                    objectMap_.erase(i++);                    
            }
        }
    }

    int Repository::objectCount() {
        return objectMap_.size();
    }

    const std::vector<string> Repository::listObjectIDs(const string &regex) {

        std::vector<string> objectIDs;
        if (regex.empty()) {
            objectIDs.reserve(objectMap_.size());
            ObjectMap::const_iterator i;
            for (i=objectMap_.begin(); i!=objectMap_.end(); ++i)
                objectIDs.push_back(i->first);
        } else {
            boost::regex r(regex, boost::regex::perl | boost::regex::icase);
            ObjectMap::const_iterator i;
            for (i=objectMap_.begin(); i!=objectMap_.end(); ++i) {
                string objectID = i->first;
                if (regex_match(objectID, r))
                    objectIDs.push_back(objectID);
            }
        }
        return objectIDs;
    }

    bool Repository::objectExists(const string &objectID) const {
        return objectMap_.find(objectID) != objectMap_.end();
    }

    std::vector<bool>
    Repository::objectExists(const std::vector<string> &objectList) {
        std::vector<bool> ret;

        std::vector<string>::const_iterator i;
        for (i = objectList.begin(); i != objectList.end(); ++i) {
                ret.push_back(objectExists(formatID(*i)));
        }

        return ret;
    }

    std::vector<bool>
    Repository::isPermanent(const std::vector<string> &objectList) {
        std::vector<bool> ret;

        std::vector<string>::const_iterator i;
        for (i = objectList.begin(); i != objectList.end(); ++i) {
            string realID = formatID(*i);
            if (objectExists(realID)){
                ObjectMap::const_iterator result = objectMap_.find(realID);
                ret.push_back(result->second->object()->permanent());
            } else {
                OH_FAIL("Unable to retrieve object with ID "<<*i);
            }
        }
        return ret;
    }

    const std::vector<string>
    Repository::className(const std::vector<string> &objectList) {
        std::vector<string> ret;

        std::vector<string>::const_iterator i;
        for (i = objectList.begin(); i != objectList.end(); ++i) {
            string realID = formatID(*i);
            if (objectExists(realID)){

                ObjectMap::const_iterator result = objectMap_.find(realID);

                ret.push_back(result->second->object()->className());

            } else {
                OH_FAIL("Unable to retrieve object with ID "<<*i);
            }
        }
        return ret;
    }

    string Repository::formatID(const string &objectID) {
        return objectID;
    }

}

