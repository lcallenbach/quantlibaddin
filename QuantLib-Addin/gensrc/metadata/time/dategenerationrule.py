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
    ("QuantLib::DateGeneration::Rule",  "std::string", "string", "EnumeratedType", "<<"),
]


QuantLibTypes = [
    ("EnumeratedType", "ql/time/dategenerationrule.hpp", "QuantLib::DateGeneration::Rule", 
        "std::string", "Backward", "QuantLib::DateGeneration::Backward"),
    ("EnumeratedType", "ql/time/dategenerationrule.hpp", "QuantLib::DateGeneration::Rule", 
        "std::string", "Forward", "QuantLib::DateGeneration::Forward"),
    ("EnumeratedType", "ql/time/dategenerationrule.hpp", "QuantLib::DateGeneration::Rule", 
        "std::string", "ThirdWednesday", "QuantLib::DateGeneration::ThirdWednesday"),
    ("EnumeratedType", "ql/time/dategenerationrule.hpp", "QuantLib::DateGeneration::Rule", 
        "std::string", "Twentieth", "QuantLib::DateGeneration::Twentieth"),
    ("EnumeratedType", "ql/time/dategenerationrule.hpp", "QuantLib::DateGeneration::Rule", 
        "std::string", "TwentiethIMM", "QuantLib::DateGeneration::TwentiethIMM"),
    ("EnumeratedType", "ql/time/dategenerationrule.hpp", "QuantLib::DateGeneration::Rule", 
        "std::string", "OldCDS", "QuantLib::DateGeneration::OldCDS"),
    ("EnumeratedType", "ql/time/dategenerationrule.hpp", "QuantLib::DateGeneration::Rule", 
        "std::string", "CDS", "QuantLib::DateGeneration::CDS"),
]

