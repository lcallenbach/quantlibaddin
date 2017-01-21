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
    ("QuantLib::TimeUnit",  "std::string", "string", "EnumeratedType", "", "<<")
]


QuantLibTypes = [
    ("EnumeratedType", "ql/time/timeunit.hpp", "QuantLib::TimeUnit", 
        "std::string", "Days", "QuantLib::Days"),
    ("EnumeratedType", "ql/time/timeunit.hpp", "QuantLib::TimeUnit", 
        "std::string", "Weeks", "QuantLib::Weeks"),
    ("EnumeratedType", "ql/time/timeunit.hpp", "QuantLib::TimeUnit", 
        "std::string", "Months", "QuantLib::Months"),
    ("EnumeratedType", "ql/time/timeunit.hpp", "QuantLib::TimeUnit", 
        "std::string", "Years", "QuantLib::Years")
]


