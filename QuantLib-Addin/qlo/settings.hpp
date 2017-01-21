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
#ifndef __qlo_settings_hpp__
#define __qlo_settings_hpp__

#include <ql/settings.hpp>



namespace Addin {

	class AddinSettings  {
	    public:
		inline static void setEvaluationDate(QuantLib::Date date) {
			QuantLib::Settings::instance().evaluationDate() = date;
		}
		
		inline static QuantLib::Date getEvaluationDate(void) {
			return QuantLib::Settings::instance().evaluationDate();
		}

		inline static void setIncludeReferenceDateEvents(bool parameter) {
			QuantLib::Settings::instance().includeReferenceDateEvents() = parameter;
		}

		inline static bool getIncludeReferenceDateEvents(void) {
			return QuantLib::Settings::instance().includeReferenceDateEvents();
		}
		
	};

}

#endif
