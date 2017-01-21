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

#include <qlcalc.hpp>
#include <addin.hpp>
#include <init.hpp>
#include <idlconversions.hpp>

#define STRFROMANSI(s)      IDL_string( s, strlen( s ), RTL_TEXTENCODING_MS_1252 )

using namespace QuantLib;
using namespace Addin;


// addin interface functions

%s



// addin constructor and helper functions

CalcAddins_impl::CalcAddins_impl() throw ()  {
    Addin::initializeAddin();

%s

}

// XAddIn
/*
 * Not used by Calc, so return an empty string
 */
OUString CalcAddins_impl::getProgrammaticFuntionName(
                      const OUString& aDisplayName) throw (RuntimeException) {
    return OUString(); // not used by calc ?
}

OUString CalcAddins_impl::getDisplayFunctionName(
                 const OUString& aProgrammaticName) throw (RuntimeException) {
    return funcMap[ aProgrammaticName ];
}

OUString CalcAddins_impl::getFunctionDescription(
                  const OUString& aProgrammaticName) throw (RuntimeException) {
    return funcDesc[ aProgrammaticName ];
}

OUString CalcAddins_impl::getDisplayArgumentName(
                     const OUString& aProgrammaticName, ::sal_Int32 nArgument) 
    throw (RuntimeException) {
    std::map< STRING, std::vector < STRING > >::const_iterator i =
        argName.find(aProgrammaticName);
    if (i == argName.end())
        return STRFROMASCII("no help available");
    else {
        std::vector < STRING >v = i->second;
        return v[nArgument];
    }
}

OUString CalcAddins_impl::getArgumentDescription(
                                        const OUString& aProgrammaticName, 
                                        ::sal_Int32 nArgument) 
    throw (RuntimeException) {
    std::map< STRING, std::vector < STRING > >::const_iterator i =
        argDesc.find(aProgrammaticName);
    if (i == argDesc.end())
        return STRFROMASCII("no help available");
    else {
        std::vector < STRING >v = i->second;
        return v[nArgument];
    }
}

OUString CalcAddins_impl::getProgrammaticCategoryName(
                  const OUString& aProgrammaticName) throw (RuntimeException) {
    return STRFROMASCII( "Add-In" );
}

OUString CalcAddins_impl::getDisplayCategoryName(
                  const OUString& aProgrammaticName) throw (RuntimeException) {
    return STRFROMASCII( "Add-In" );
}

//XServiceName
OUString CalcAddins_impl::getServiceName() throw (RuntimeException) {
    return STRFROMASCII( _serviceName_ );
}

//XServiceInfo
static OUString getImplementationName_CalcAddins_impl() 
    throw (RuntimeException) {
    return STRFROMASCII( _implName_ );
}

OUString CalcAddins_impl::getImplementationName() throw (RuntimeException) {
    return getImplementationName_CalcAddins_impl();
}

::sal_Bool CalcAddins_impl::supportsService(OUString const & serviceName) 
    throw (RuntimeException) {
    return serviceName.compareToAscii( _serviceName_ ) == 0 || 
        serviceName.compareToAscii( _AddserviceName_ ) == 0;
}

static Sequence<OUString> getSupportedServiceNames_CalcAddins_impl() 
    throw (RuntimeException) {
    Sequence< OUString > name(2);
    name[0] = STRFROMASCII( _serviceName_ );
    name[1] = STRFROMASCII( _AddserviceName_ );
    return name;
}

Sequence< OUString > CalcAddins_impl::getSupportedServiceNames() 
    throw (RuntimeException) {
    return getSupportedServiceNames_CalcAddins_impl();
}

//XLocalizable
void CalcAddins_impl::setLocale(const lang::Locale& eLocale) 
    throw (RuntimeException) {
    locale = eLocale;
}

lang::Locale CalcAddins_impl::getLocale() throw (RuntimeException) {
    return locale;
}

static Reference< XInterface > 
SAL_CALL create_CalcAddins_impl(Reference<XComponentContext> const & xContext) 
{
    return static_cast< ::cppu::OWeakObject * > ( new CalcAddins_impl );
}

static struct ::cppu::ImplementationEntry s_component_entries[] = {
    { create_CalcAddins_impl, getImplementationName_CalcAddins_impl,
      getSupportedServiceNames_CalcAddins_impl, 
      ::cppu::createSingleComponentFactory, 0, 0 },
    { 0, 0, 0, 0, 0, 0 }
};


extern "C" {
	SAL_DLLPUBLIC_EXPORT  void SAL_CALL component_getImplementationEnvironment(
                                            sal_Char const ** ppEnvTypeName, 
                                            uno_Environment ** ppEnv) {
		*ppEnvTypeName = CPPU_CURRENT_LANGUAGE_BINDING_NAME;
	}

	SAL_DLLPUBLIC_EXPORT  sal_Bool SAL_CALL component_writeInfo(lang::XMultiServiceFactory * xMgr, 
                                          registry::XRegistryKey * xRegistry) { 
		return ::cppu::component_writeInfoHelper( xMgr, xRegistry, 
                                                  s_component_entries );
	}

	SAL_DLLPUBLIC_EXPORT  void * SAL_CALL component_getFactory( sal_Char const * implName,
		lang::XMultiServiceFactory * xMgr, registry::XRegistryKey * xRegistry) {
		return ::cppu::component_getFactoryHelper(implName, xMgr, xRegistry, 
                                                  s_component_entries );
	}
}