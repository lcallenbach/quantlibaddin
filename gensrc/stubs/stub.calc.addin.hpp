/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*	
 Copyright (C) 2004, 2005, 2006, 2008 Eric Ehlers
 Copyright (C) 2009 Roland Lichters
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

/*
    http://wiki.services.openoffice.org/wiki/Calc/Add-In/Simple_Calc_Add-In
    http://wiki.services.openoffice.org/wiki/CompleteAddIn
    http://quantlib.org/quantlibaddin
*/

#ifndef quantlib_calcaddins_hpp
#define quantlib_calcaddins_hpp

#include <cppuhelper/implbase4.hxx> //4-parameter template will be used
#include <cppuhelper/factory.hxx>
#include <cppuhelper/implementationentry.hxx>

#include <uno/lbnames.h>

#include <com/sun/star/sheet/XAddIn.hpp>
#include <com/sun/star/lang/XServiceName.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <quantlib/XCalcAddins.hpp>

#include <cstdlib>
#include <cmath>

#include <ql/quantlib.hpp>

#include <init.hpp>
#include <idlconversions.hpp>

#define _serviceName_ "quantlib.CalcAddins"
#define _implName_ "quantlib.CalcAddins_impl.CalcAddins"
#define _AddserviceName_ "com.sun.star.sheet.AddIn"

using namespace ::rtl;
using namespace ::com::sun::star;
using namespace ::com::sun::star::uno;

#define STRING              ::rtl::OUString

//4-parameter template
class CalcAddins_impl 
    : public ::cppu::WeakImplHelper4< ::quantlib::XCalcAddins, sheet::XAddIn,
                                      lang::XServiceName, lang::XServiceInfo> {
    //Locale
    lang::Locale locale;
       
    std::map< STRING, STRING > funcMap;                 // function names
    std::map< STRING, STRING > funcDesc;                // function descriptions
    std::map< STRING, std::vector < STRING > > argName; // parameter names
    std::map< STRING, std::vector < STRING > > argDesc; // parameter description
public:
    //XCalcAddins
    /**************************************************************************
     * Start declaring methods here ...
     * Eric has put these into separate header files that are included at the
     * bottom of the class decleration with #include <<Addins/Calc/qlo_all.hpp>
     *************************************************************************/
    
    // addin interface functions

%s

    /*************************************************************************
     * ... and stop declaring methods here.
     *************************************************************************/

    //XAddIn
    OUString SAL_CALL getProgrammaticFuntionName(const OUString& aDisplayName)
        throw (RuntimeException);
    OUString SAL_CALL getDisplayFunctionName(const OUString& aProgrammaticName) 
        throw (RuntimeException);
    OUString SAL_CALL getFunctionDescription(const OUString& aProgrammaticName) 
        throw (RuntimeException);
    OUString SAL_CALL getDisplayArgumentName(const OUString& aProgrammaticName,
                                             ::sal_Int32 nArgument) 
        throw (RuntimeException);
    OUString SAL_CALL getArgumentDescription(const OUString& aProgrammaticName,
                                             ::sal_Int32 nArgument) 
        throw (RuntimeException);
    OUString SAL_CALL getProgrammaticCategoryName(
                                             const OUString& aProgrammaticName) 
        throw (RuntimeException);
    OUString SAL_CALL getDisplayCategoryName(const OUString& aProgrammaticName)
        throw (RuntimeException);

    //XServiceName
    OUString SAL_CALL getServiceName() throw (RuntimeException);

    //XServiceInfo
    OUString SAL_CALL getImplementationName() throw (RuntimeException);
    ::sal_Bool SAL_CALL supportsService(const OUString& ServiceName) 
        throw (RuntimeException);
    Sequence< OUString > SAL_CALL getSupportedServiceNames() 
        throw (RuntimeException);

    //XLocalizable
    void SAL_CALL setLocale(const lang::Locale& eLocale) 
        throw (RuntimeException);
    lang::Locale SAL_CALL getLocale() throw (RuntimeException);

    /**************************************************************************
     * RL: Declare constructor and desctructor here, following Eric's example.
     *     This is to initialize QuantLibAddin's repository and set up
     *     descriptions for the function wizard.
     *     Implemented in funcdef.cpp
     *************************************************************************/
    CalcAddins_impl() throw ();
    virtual ~CalcAddins_impl() {};

};

#endif