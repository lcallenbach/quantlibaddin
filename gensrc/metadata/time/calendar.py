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
    ("QuantLib::Calendar",  "std::string", "string", "EnumeratedClass", "", "name()"),
]

QuantLibTypes = [
    ("MemberFunction", "ql/time/calendar.hpp", 
        "QuantLib::Calendar()", 
        "std::string name()", "qlCalendarName"),
    ("MemberFunction", "ql/time/calendar.hpp", 
        "QuantLib::Calendar()", 
        "bool isHoliday(QuantLib::Date Date)", "qlCalendarIsHoliday"),
    ("MemberFunction", "ql/time/calendar.hpp", 
        "QuantLib::Calendar()", 
        "bool isBusinessDay(QuantLib::Date Date)", "qlCalendarIsBusinessDay"),
    ("MemberFunction", "ql/time/calendar.hpp", 
        "QuantLib::Calendar()", 
        "QuantLib::Date advance(QuantLib::Date StartDate, QuantLib::Period Period, QuantLib::BusinessDayConvention BusinessDayConvention, bool EndOfMonth=false)", "qlCalendarAdvance"),
]

