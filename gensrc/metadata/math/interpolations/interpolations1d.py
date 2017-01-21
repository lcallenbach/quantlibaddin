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
    ("Constructor", "qlo/all.hpp", 
        "<Interpolator1DID>Addin::AddinInterpolation1D(std::vector<QuantLib::Real> XVector, std::vector<QuantLib::Real> YVector)", 
        "", "qlInterpolation1D"),

     ("TemplateArgument", "ql/math/interpolations/linearinterpolation.hpp", 
       "Interpolator1DID", "std::string", "Linear", "QuantLib::LinearInterpolation", "qlInterpolation1D"),
     ("TemplateArgument", "ql/math/interpolations/cubicinterpolation.hpp", 
       "Interpolator1DID", "std::string", "CubicNaturalSpline", "QuantLib::CubicNaturalSpline", "qlInterpolation1D"),
     ("TemplateArgument", "ql/math/interpolations/cubicinterpolation.hpp", 
       "Interpolator1DID", "std::string", "MonotonicCubicNaturalSpline", "QuantLib::MonotonicCubicNaturalSpline", "qlInterpolation1D"),
     ("TemplateArgument", "ql/math/interpolations/cubicinterpolation.hpp", 
       "Interpolator1DID", "std::string", "KrugerCubic", "QuantLib::KrugerCubic", "qlInterpolation1D"),
     ("TemplateArgument", "ql/math/interpolations/loginterpolation.hpp", 
       "Interpolator1DID", "std::string", "LogLinearInterpolation", "QuantLib::LogLinearInterpolation", "qlInterpolation1D"),
     ("TemplateArgument", "ql/math/interpolations/loginterpolation.hpp", 
       "Interpolator1DID", "std::string", "LogCubicNaturalSpline", "QuantLib::LogCubicNaturalSpline", "qlInterpolation1D"),
     ("TemplateArgument", "ql/math/interpolations/loginterpolation.hpp", 
       "Interpolator1DID", "std::string", "MonotonicLogCubicNaturalSpline", "QuantLib::MonotonicLogCubicNaturalSpline", "qlInterpolation1D"),
     ("TemplateArgument", "ql/math/interpolations/loginterpolation.hpp", 
       "Interpolator1DID", "std::string", "KrugerLogCubic", "QuantLib::KrugerLogCubic", "qlInterpolation1D"),
     
    ("MemberFunction", "ql/math/interpolation.hpp",
        "QuantLib::Interpolation()", "QuantLib::Real operator()(QuantLib::Real X, bool Extrapolate)",
        "qlInterpolatedValue1D"),
    
]

