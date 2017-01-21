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
    ("Constructor", "qlo/interpolation.hpp", 
        "<Interpolator2DID>Addin::AddinInterpolation2D(std::vector<QuantLib::Real> XVector, std::vector<QuantLib::Real> YVector, QuantLib::Matrix ZData)", 
        "", "qlInterpolation2D"),

     ("TemplateArgument", "ql/math/interpolations/bilinearinterpolation.hpp", 
       "Interpolator2DID", "std::string", "Bilinear", "QuantLib::BilinearInterpolation", "qlInterpolation2D"),
     ("TemplateArgument", "ql/math/interpolations/bicubicinterpolation.hpp", 
       "Interpolator2DID", "std::string", "BicubicSpline", "QuantLib::BicubicSpline", "qlInterpolation2D"),
     
    ("MemberFunction", "ql/math/interpolations/interpolation2d.hpp",
        "QuantLib::Interpolation2D()", "QuantLib::Real operator()(QuantLib::Real X, QuantLib::Real Y, bool Extrapolate)",
        "qlInterpolatedValue2D")
]

