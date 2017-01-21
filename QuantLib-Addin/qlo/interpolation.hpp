/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

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
#ifndef __qlo_interpolation_hpp__
#define __qlo_interpolation_hpp__

#include <ql/math/matrix.hpp>
#include <ql/math/interpolation.hpp>


namespace Addin {


	class Interpolation1DStorage {
	    public:
		std::vector<QuantLib::Real> vec_x, vec_y;
		Interpolation1DStorage(std::vector<QuantLib::Real> x, std::vector<QuantLib::Real> y) {
			vec_x = x;
			vec_y = y;
		}
	};

	template<class T>
	class AddinInterpolation1D : public Interpolation1DStorage, public T {
           public:
		AddinInterpolation1D(std::vector<QuantLib::Real> x, std::vector<QuantLib::Real> y) : 
			Interpolation1DStorage(x, y),
			T(vec_x.begin(), vec_x.end(), vec_y.begin()) {}
	};


	class Interpolation2DStorage {
	    public:
		std::vector<QuantLib::Real> vec_x, vec_y;
		QuantLib::Matrix z_data;
		Interpolation2DStorage(std::vector<QuantLib::Real> x, std::vector<QuantLib::Real> y, QuantLib::Matrix zData) {
			vec_x = x;
			vec_y = y;
			z_data = zData;
		}
	};

	template<class T>
	class AddinInterpolation2D : public Interpolation2DStorage, public T {
           public:
		AddinInterpolation2D(std::vector<QuantLib::Real> x, std::vector<QuantLib::Real> y, QuantLib::Matrix zData) : 
			Interpolation2DStorage(x, y, zData), 
			T(vec_x.begin(), vec_x.end(), vec_y.begin(), vec_y.end(), z_data)  {};
	};

}





#endif 
