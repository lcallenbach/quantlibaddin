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
    ("QuantLib::Date",  "QuantLib::Date", "long", "interfaceToDate", "interfaceFromDate"),
    ("QuantLib::Day",   "int", "long", "Default", "Default"),
    ("QuantLib::Month", "int", "long", "Default", "Default"),
    ("QuantLib::Year",  "int", "long", "Default", "Default")
]


#QuantLibTypes = [
#    ("ConstructorMemberFunction", "ql/time/date.hpp", 
#        "QuantLib::Date(QuantLib::Day Day, QuantLib::Month Month, QuantLib::Year Year)", 
#        "QuantLib::BigInteger serialNumber()", "qlDate"),
#
#    ("Enumeration", "ql/time/date.hpp", "QuantLib::Month", 
#        "(std::string)", "Jan", "QuantLib::Month.Jan"),
#    ("Enumeration", "ql/time/date.hpp", "QuantLib::Month", 
#        "(std::string)", "Feb", "QuantLib::Month.Feb"),
#    ("Enumeration", "ql/time/date.hpp", "QuantLib::Month", 
#        "(std::string)", "Mar", "QuantLib::Month.Mar"),
#    ("Enumeration", "ql/time/date.hpp", "QuantLib::Month", 
#        "(std::string)", "Apr", "QuantLib::Month.Apr")
#]


