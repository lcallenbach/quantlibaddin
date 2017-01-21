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
    ("Constructor", "ql/termstructures/yield/piecewiseyieldcurve.hpp", 
        "<Traits, Interpolator>QuantLib::PiecewiseYieldCurve(QuantLib::Date ReferenceDate, std::vector<boost::shared_ptr<QuantLib::BootstrapHelper<QuantLib::YieldTermStructure> > > BootstrapInstruments, QuantLib::DayCounter DayCounter, QuantLib::Real Accuracy)", 
        "", "qlPiecewiseYieldCurve"),
     
    ("TemplateArgument", "ql/termstructures/yield/bootstraptraits.hpp", 
       "Traits", "std::string", "ZeroYield", "QuantLib::ZeroYield", "qlPiecewiseYieldCurve"),
    ("TemplateArgument", "ql/termstructures/yield/bootstraptraits.hpp", 
       "Traits", "std::string", "Discount", "QuantLib::Discount", "qlPiecewiseYieldCurve"),
    ("TemplateArgument", "ql/termstructures/yield/bootstraptraits.hpp", 
       "Traits", "std::string", "ForwardRate", "QuantLib::ForwardRate", "qlPiecewiseYieldCurve"),
     
    ("TemplateArgument", "ql/math/interpolations/linearinterpolation.hpp", 
       "Interpolator", "std::string", "Linear", "QuantLib::Linear", "qlPiecewiseYieldCurve"),
    ("TemplateArgument", "ql/math/interpolations/cubicinterpolation.hpp", 
       "Interpolator", "std::string", "KrugerCubic", "QuantLib::Cubic", "qlPiecewiseYieldCurve"),
]

