"""
 Python source for QuantLib addin in LibreOffice/Calc.
 Copyright (C) 2016 Lars Callenbach

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
"""


ImplicitConversionsCalc = [
    ("QuantLib::BlackVarianceSurface::Extrapolation",  "std::string", "string", "EnumeratedType", ""),
]


QuantLibTypes = [
    ("Constructor", "ql/termstructures/volatility/equityfx/blackvariancesurface.hpp", 
        "QuantLib::BlackVarianceSurface(QuantLib::Date ReferenceDate, QuantLib::Calendar Calendar, std::vector<QuantLib::Date> Dates, std::vector<QuantLib::Real> Strikes, QuantLib::Matrix BlackVolMatrix, QuantLib::DayCounter DayCounter, QuantLib::BlackVarianceSurface::Extrapolation LowerExtrapolation, QuantLib::BlackVarianceSurface::Extrapolation UpperExtrapolation)", 
        "", "qlBlackVarianceSurface"),
    
    ("EnumeratedType", "ql/termstructures/volatility/equityfx/blackvariancesurface.hpp", "QuantLib::BlackVarianceSurface::Extrapolation", 
        "std::string", "ConstantExtrapolation", "QuantLib::BlackVarianceSurface::ConstantExtrapolation"),
    ("EnumeratedType", "ql/termstructures/volatility/equityfx/blackvariancesurface.hpp", "QuantLib::BlackVarianceSurface::Extrapolation", 
        "std::string", "InterpolatorDefaultExtrapolation", "QuantLib::BlackVarianceSurface::InterpolatorDefaultExtrapolation"),
     
]

