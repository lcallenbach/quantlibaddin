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


QuantLibTypes = [
    ("Constructor", "ql/termstructures/credit/piecewisedefaultcurve.hpp", 
        "<Traits, Interpolator>QuantLib::PiecewiseDefaultCurve(QuantLib::Date ReferenceDate, std::vector<boost::shared_ptr<QuantLib::BootstrapHelper<QuantLib::DefaultProbabilityTermStructure> > > BootstrapInstruments, QuantLib::DayCounter DayCounter, QuantLib::Real Accuracy = 1e-12)", 
        "", "qlPiecewiseDefaultCurve"),
     
    ("TemplateArgument", "ql/termstructures/credit/probabilitytraits.hpp", 
       "Traits", "std::string", "SurvivalProbability", "QuantLib::SurvivalProbability", "qlPiecewiseDefaultCurve"),
    ("TemplateArgument", "ql/termstructures/yield/probabilitytraits.hpp", 
       "Traits", "std::string", "HazardRate", "QuantLib::HazardRate", "qlPiecewiseDefaultCurve"),
    ("TemplateArgument", "ql/termstructures/yield/probabilitytraits.hpp", 
       "Traits", "std::string", "DefaultDensity", "QuantLib::DefaultDensity", "qlPiecewiseDefaultCurve"),
     
    ("TemplateArgument", "ql/math/interpolations/linearinterpolation.hpp", 
       "Interpolator", "std::string", "Linear", "QuantLib::Linear", "qlPiecewiseDefaultCurve"),
    ("TemplateArgument", "ql/math/interpolations/backwardflatinterpolation.hpp", 
       "Interpolator", "std::string", "BackwardFlat", "QuantLib::BackwardFlat", "qlPiecewiseDefaultCurve"),
]

