/*
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
#ifndef __calc_types_hpp__
#define __calc_types_hpp__

#include <com/sun/star/sheet/XAddIn.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/lang/XServiceName.hpp>
#include <com/sun/star/lang/XTypeProvider.hpp>

#define CSS                 ::com::sun::star
#define SEQ(c)              CSS::uno::Sequence< c >
#define SEQSEQ(c)           CSS::uno::Sequence< CSS::uno::Sequence< c > >

#define IDL_string          rtl::OUString
#define IDL_double          double 
#define IDL_long            sal_Int32
#define IDL_any             CSS::uno::Any

#define THROW_RTE           throw CSS::uno::RuntimeException()
#define THROW_MSG(m,r)      throw(CSS::uno::RuntimeException( m , r))


namespace Addin {

   class AddinException : public std::exception {
      public:
        AddinException(const std::string& message = "")  { message_ = message; };
        ~AddinException() throw() {}
        const char* what() const throw () { return message_.c_str(); };
      private:
        std::string message_;
  };

}

#endif

