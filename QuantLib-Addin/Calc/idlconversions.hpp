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
#ifndef __idl_conversions_calc_hpp__
#define __idl_conversions_calc_hpp__

#include <exception>
#include <iostream>

#include <idltypes.hpp>
#include <ql/quantlib.hpp>
#include <oh/utilities.hpp>
#include <oh/repository.hpp>


#define STRFROMASCII(s)     IDL_string::createFromAscii( s )
#define STRFROMANSI(s)      IDL_string( s, strlen( s ), RTL_TEXTENCODING_MS_1252 )

namespace Addin {


	inline std::string ouStringToString(IDL_string from) {
	    rtl::OString ret;
	    if (from.convertToString(&ret, RTL_TEXTENCODING_ASCII_US, OUSTRING_TO_OSTRING_CVTFLAGS))
		return ret.getStr();
	    else
		return std::string("");
	};

	
	/** 
         *   conversions from IDL_any to IDL subtype
         *   python conversion functions
         **/

	class AnyException: public std::exception {
	    const char * what () const throw () {
      	        return "No value or not valid type for parameter provided!";
            }
	};


	inline void conversionAnyToIDL(IDL_any from, IDL_string &to) {
    	    rtl::OString type = from.getValueTypeName().toUtf8();
	    //std::cerr << "IDL_string " << type.getStr() << std::endl;
	    if(from.hasValue()) {
		if(type.equalsIgnoreAsciiCase(STRFROMANSI("STRING").toUtf8())) {
   	            IDL_string temp;
	            from >>= temp;
	            to = (IDL_string)(temp);
		    return;
                }
            } 
	    throw AnyException();
        }    

	inline void conversionAnyToIDL(IDL_any from, IDL_double &to) {
    	    rtl::OString type = from.getValueTypeName().toUtf8();
	    //std::cerr << "IDL_double " << type.getStr() << std::endl;
	    if(from.hasValue()) {
		if(type.equalsIgnoreAsciiCase(STRFROMANSI("DOUBLE").toUtf8()) or type.equalsIgnoreAsciiCase(STRFROMANSI("LONG").toUtf8())) {
	            from >>= to;
		    return;
	        }
	    }
	    throw AnyException();
	}
	
	inline void conversionAnyToIDL(IDL_any from, IDL_long &to) {
    	    rtl::OString type = from.getValueTypeName().toUtf8();
	    //std::cerr << "IDL_long " << type.getStr() << std::endl;
	    if(from.hasValue()) {
		if(type.equalsIgnoreAsciiCase(STRFROMANSI("LONG").toUtf8())) {
	            long temp;
        	    from >>= temp;
        	    to = (IDL_long)((int)(temp));
		    return;
	        } 
		if(type.equalsIgnoreAsciiCase(STRFROMANSI("DOUBLE").toUtf8())) {
	            double temp;
        	    from >>= temp;
        	    to = (IDL_long)((int)(temp));
		    return;
	        } 
	    }
	    throw AnyException();
	}


	template <class T_FROM, class T_TO>
	inline void scalarAnyToIDL(T_FROM from, T_TO &to) {
	    conversionAnyToIDL(from, to);
	};


	template <class T_FROM, class T_TO>
	inline void vectorAnyToIDL(SEQSEQ(T_FROM) from, SEQSEQ(T_TO) &to) {
	    to.realloc(from.getLength());
	    for(int i=0; i<from.getLength(); i++) {
   	        to[i].realloc(from[i].getLength());	
		for(int j=0; j<from[i].getLength(); j++) {
		    scalarAnyToIDL(from[i][j], to[i][j]);
                }
	    }
	};


	template <class T_FROM, class T_TO>
	inline void matrixAnyToIDL(SEQSEQ(T_FROM) from, SEQSEQ(T_TO) &to) {
	    vectorAnyToIDL(from, to);
	};


	/** 
         *   conversions from IDL subtype to cpp type
         *   for special QuantLib types
         **/

	inline void interfaceToString(IDL_string from, std::string &to) {
	    to = std::string(ouStringToString(from));
	};


	inline void interfaceToDate(IDL_long from, QuantLib::Date &to) {
	    std::cerr << "interfaceToDate " << (int)(from) << std::endl;
	    to = QuantLib::Date(from);
	};


	inline void interfaceToPeriod(IDL_string from, QuantLib::Period &to) {
	    std::string idCpp = ouStringToString(from);
	    to = QuantLib::PeriodParser::parse(idCpp);
	};


	inline void interfaceToMatrix(SEQSEQ(IDL_double) from, QuantLib::Matrix &to) {
	    int x_dim=from[0].getLength(), y_dim = from.getLength();
	    to = QuantLib::Matrix(x_dim, y_dim);
	    for(int i=0; i<x_dim; i++)
	        for(int j=0; j<y_dim; j++)
	            to[i][j] = from[i][j];
	};


	/**
         *   python conversion functions
         *   for native types
         **/ 

	class DimensionException: public std::exception {
	    const char * what () const throw () {
      	        return "Wrong dimension of some parameter (should not be a matrix)!";
            }
	};


	template <class T_FROM, class T_TO>
	inline void interfaceToIdentity(T_FROM from, T_TO &to) {
		to = (T_TO)(from);
	};


	template <class T_FROM, class T_TO>
	inline void scalarInterfaceToCpp(T_FROM from, T_TO &to, void conversionFunction(T_FROM, T_TO &)) {
	    conversionFunction(from, to);
	};


	template <class T_FROM, class T_TO>
	inline void vectorInterfaceToCpp(SEQSEQ(T_FROM) from, std::vector<T_TO> &to, void conversionFunction(T_FROM, T_TO &)) {
	    to.clear();
	    if(from.getLength()>1 && from[0].getLength()>1)
		throw DimensionException();
	    for(int i=0; i<from.getLength(); i++) {
		for(int j=0; j<from[i].getLength(); j++) {
		    T_TO temp;
		    scalarInterfaceToCpp(from[i][j], temp, conversionFunction);
		    to.push_back(temp);
                }
	    }
	};


	template <class T_FROM, class T_TO>
	inline void matrixInterfaceToCpp(SEQSEQ(T_FROM) from, std::vector<std::vector<T_TO> > &to, void conversionFunction(T_FROM, T_TO &)) {
	    to.clear();	    
	    for(int i=0; i<from.getLength(); i++) {
                std::vector<T_TO> vec;
		for(int j=0; j<from[i].getLength(); j++) {
		    T_TO temp;
		    scalarInterfaceToCpp(from[i][j], temp, conversionFunction);
		    vec.push_back(temp);
                }
		to.push_back(vec);
	    }
	};


	/**
         *   python conversion functions
         *   for repository objects
         **/ 

	template <class T_TO>
	inline void scalarObject(IDL_string from, T_TO &to) {
	   std::string ObjectId_cpp;
	   interfaceToString(from, ObjectId_cpp);
	   to = static_cast<T_TO *>(OH_GET_OBJECT_SIMPLE(ObjectId_cpp)->get());
	};


	template <class T_TO>
	inline void vectorObject(SEQSEQ(IDL_string) from, std::vector<T_TO> &to) {
	   if(from.getLength()<from[0].getLength()) { 
	      for(int i=0; i<from[0].getLength(); i++) {
   	         std::string ObjectId_cpp;
	         interfaceToString(from[0][i], ObjectId_cpp);
	         to.push_back(static_cast<T_TO *>(OH_GET_OBJECT_SIMPLE(ObjectId_cpp)->get()));
	      }
           } else {
	      for(int i=0; i<from.getLength(); i++) {
   	         std::string ObjectId_cpp;
	         interfaceToString(from[i][0], ObjectId_cpp);
	         to.push_back(static_cast<T_TO *>(OH_GET_OBJECT_SIMPLE(ObjectId_cpp)->get()));
	      }
           }
	};


        /**
         *   conversions back to the IDL (return parameters)
         *   	first three functions for conversion from QuantLib data to IDL data types
         *   	next two functions for conversion from IDL data types to SEQSEQ(IDL_any)
         **/

	template <class T_FROM, class T_TO>
	inline void interfaceFromCpp(T_FROM from, T_TO &to, void conversionFunction(T_FROM, T_TO &)) {
            conversionFunction(from, to);
	};

	template <class T_FROM, class T_TO>
	inline void interfaceFromCpp(std::vector<T_FROM> from, SEQSEQ(T_TO) &to, void conversionFunction(T_FROM, T_TO &)) {
	    to.realloc(from.size());
	    SEQ(T_TO) vector(from.size());
	    for(int i=0; i<from.size(); i++) {
	        conversionFunction(from[i], vector[i]);
	    }
	    to[0] = vector;
            for(int i=1; i<from.size(); i++) {
                SEQ(T_TO) vector(from.size());
                for(int j=0; j<from.size(); j++) 
                    conversionFunction(from[i], vector[j]);
                to[i] = vector;
            }
	};

	template <class T_FROM, class T_TO>
	inline void interfaceFromCpp(std::vector<std::vector<T_FROM> > from, SEQSEQ(T_TO) &to, void conversionFunction(T_FROM, T_TO &)) {
	    to.realloc(from.size());
            for(int i=0; i<from.size(); i++) {
   	        SEQ(T_TO) vector(from[i].size());	
                for(int j=0; j<from[i].size(); j++) 
                    conversionFunction(from[i][j], vector[j]);
                to[i] = vector;
            }
	};


	template <class T_FROM>
	inline void idlConversionToAny(T_FROM from, SEQSEQ(IDL_any) &to) {
	    to.realloc(1);
            SEQ(IDL_any) vector(1);
            vector[0] = CSS::uno::makeAny(from);
            to[0] = vector;
	};

	template <class T_FROM>
	inline void idlConversionToAny(SEQSEQ(T_FROM) from, SEQSEQ(IDL_any) &to) {
	    to.realloc(from.getLength());
            for(int i=0; i<from.getLength(); i++) {
                SEQ(IDL_any) vector(from[i].getLength());
                for(int j=0; j<from[i].getLength(); j++) 
                    vector[j] = CSS::uno::makeAny(from[i][j]);
                to[i] = vector;
            }
	};


	template <class T_TO>          
	inline void deleter(T_TO *ptr) {};


	template <class T_TO>
	inline void scalarObjectSharedPtr(IDL_string from, boost::shared_ptr<T_TO > &to) {
	   std::string ObjectId_cpp;
	   interfaceToString(from, ObjectId_cpp);
	   std::cerr << "in objectshared_ptr " << ObjectId_cpp << std::endl;
	   to = boost::shared_ptr<T_TO>(static_cast<T_TO *>(OH_GET_OBJECT_SIMPLE(ObjectId_cpp)->get()), deleter<T_TO>);
	   std::cerr << "leaving objectshared_ptr " << ObjectId_cpp << std::endl;
	};


	template <class T_TO>
	inline void vectorObjectSharedPtr(SEQSEQ(IDL_string) from, std::vector<boost::shared_ptr<T_TO > > &to) {
	   if(from.getLength()<from[0].getLength()) { 
  	      for(int i=0; i<from[0].getLength(); i++) {
   	         std::string ObjectId_cpp;
	         interfaceToString(from[0][i], ObjectId_cpp);
	         to.push_back(boost::shared_ptr<T_TO>(static_cast<T_TO *>(OH_GET_OBJECT_SIMPLE(ObjectId_cpp)->get()), deleter<T_TO>));
	      }
           } else {
  	      for(int i=0; i<from.getLength(); i++) {
   	         std::string ObjectId_cpp;
	         interfaceToString(from[i][0], ObjectId_cpp);
	         to.push_back(boost::shared_ptr<T_TO>(static_cast<T_TO *>(OH_GET_OBJECT_SIMPLE(ObjectId_cpp)->get()), deleter<T_TO>));
	      }
           };
	};


	template <class T_TO>
	inline void scalarObjectHandle(IDL_string from, QuantLib::Handle<T_TO > &to) {
	   std::string ObjectId_cpp;
	   interfaceToString(from, ObjectId_cpp);
	   std::cerr << "in scalarObjectHandle " << std::endl; 
	   to = QuantLib::Handle<T_TO>(boost::shared_ptr<T_TO>(static_cast<T_TO *>(OH_GET_OBJECT_SIMPLE(ObjectId_cpp)->get()), deleter<T_TO>));
	   std::cerr << "return from scalarObjectHandle " << std::endl; 
	};


	template <class T_TO>
	inline void vectorObjectHandle(SEQSEQ(IDL_string) from, std::vector<QuantLib::Handle<T_TO > > &to) {
	   if(from.getLength()<from[0].getLength()) { 
	      for(int i=0; i<from[0].getLength(); i++) {
   	          std::string ObjectId_cpp;
	          interfaceToString(from[0][i], ObjectId_cpp);
	          to.push_back(QuantLib::Handle<T_TO>(boost::shared_ptr<T_TO>(static_cast<T_TO *>(OH_GET_OBJECT_SIMPLE(ObjectId_cpp)->get()), deleter<T_TO>)));
	      }
           } else {
	      for(int i=0; i<from.getLength(); i++) {
   	          std::string ObjectId_cpp;
	          interfaceToString(from[i][0], ObjectId_cpp);
	          to.push_back(QuantLib::Handle<T_TO>(boost::shared_ptr<T_TO>(static_cast<T_TO *>(OH_GET_OBJECT_SIMPLE(ObjectId_cpp)->get()), deleter<T_TO>)));
	      }
           };
	};


	template <class T_FROM>
	inline void convertIdl(T_FROM from, IDL_any &to) {
	    to = CSS::uno::makeAny(from);
	};


	template <class T_FROM>
	inline void convertToIdl(T_FROM from, IDL_long &to) {
	    to = static_cast<IDL_long>( (long)(from) );	
	};

	inline void convertToIdl(std::string from, IDL_string &to) {
            to = STRFROMASCII(from.c_str());
	};

	template <class T_FROM>
	inline void convertToIdl(T_FROM from, IDL_double &to) {
	    to = static_cast<IDL_double>( (double)(from) );	
	};

	
	/*
         *  for QuantLib::Date()
         */
	inline void interfaceFromDate(QuantLib::Date from, IDL_long &to) {
	    to = static_cast<IDL_long>( (int)(from.serialNumber()) );	
	}


	/* 
 	 * for QuantLib::Matrix
         */
	inline void interfaceFromMatrix(QuantLib::Matrix from, SEQSEQ(IDL_double) &to) {
 	    int x_dim = from.columns(), y_dim=from.rows();

	    to.realloc(x_dim);
	    for(int i=0; i<x_dim; i++) {
		SEQ(IDL_double) col;
		col.realloc(y_dim);
		for(int j=0; j<y_dim; j++) {
 		    col[j] = from[i][j];
		}
		to[i] = col;
	    }
	};

}

#endif 
