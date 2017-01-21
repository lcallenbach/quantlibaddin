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
    ("QuantLib::Frequency",  "std::string", "string", "EnumeratedType", "", "<<")
]


QuantLibTypes = [
    ("EnumeratedType", "ql/time/frequency.hpp", "QuantLib::Frequency", 
        "std::string", "No-Frequency", "QuantLib::NoFrequency"),
    ("EnumeratedType", "ql/time/frequency.hpp", "QuantLib::Frequency", 
        "std::string", "Once", "QuantLib::Once"),
    ("EnumeratedType", "ql/time/frequency.hpp", "QuantLib::Frequency", 
        "std::string", "Annual", "QuantLib::Annual"),
    ("EnumeratedType", "ql/time/frequency.hpp", "QuantLib::Frequency", 
        "std::string", "Semiannual", "QuantLib::Semiannual"),
    ("EnumeratedType", "ql/time/frequency.hpp", "QuantLib::Frequency", 
        "std::string", "Every-Fourth-Month", "QuantLib::EveryFourthMonth"),
    ("EnumeratedType", "ql/time/frequency.hpp", "QuantLib::Frequency", 
        "std::string", "Quarterly", "QuantLib::Quarterly"),
    ("EnumeratedType", "ql/time/frequency.hpp", "QuantLib::Frequency", 
        "std::string", "Bimonthly", "QuantLib::Bimonthly"),
    ("EnumeratedType", "ql/time/frequency.hpp", "QuantLib::Frequency", 
        "std::string", "Monthly", "QuantLib::Monthly"),
    ("EnumeratedType", "ql/time/frequency.hpp", "QuantLib::Frequency", 
        "std::string", "Every-Fourth-Week", "QuantLib::EveryFourthWeek"),
    ("EnumeratedType", "ql/time/frequency.hpp", "QuantLib::Frequency", 
        "std::string", "Biweekly", "QuantLib::Biweekly"),
    ("EnumeratedType", "ql/time/frequency.hpp", "QuantLib::Frequency", 
        "std::string", "Weekly", "QuantLib::Weekly"),
    ("EnumeratedType", "ql/time/frequency.hpp", "QuantLib::Frequency", 
        "std::string", "Daily", "QuantLib::Daily"),
]

