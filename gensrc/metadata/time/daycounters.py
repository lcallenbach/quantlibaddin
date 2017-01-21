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
    ("EnumeratedClass", "ql/time/daycounters/actual360.hpp", "QuantLib::DayCounter()", 
        "std::string", "Actual/360", "QuantLib::Actual360()"),
    ("EnumeratedClass", "ql/time/daycounters/actual365fixed.hpp", "QuantLib::DayCounter()", 
        "std::string", "Actual/365 (Fixed)", "QuantLib::Actual365Fixed()"),
    ("EnumeratedClass", "ql/time/daycounters/actual365nl.hpp", "QuantLib::DayCounter()", 
        "std::string", "Actual/365 (NL)", "QuantLib::Actual365NoLeap()"),
    ("EnumeratedClass", "ql/time/daycounters/actualactual.hpp", "QuantLib::DayCounter()", 
        "std::string", "Actual/Actual", "QuantLib::ActualActual()"),
    ("EnumeratedClass", "ql/time/daycounters/actualactual.hpp", "QuantLib::DayCounter()", 
        "std::string", "Actual/Actual (ISMA)", "QuantLib::ActualActual(QuantLib::ActualActual::ISMA)"),
    ("EnumeratedClass", "ql/time/daycounters/actualactual.hpp", "QuantLib::DayCounter()", 
        "std::string", "Actual/Actual (ISDA)", "QuantLib::ActualActual(QuantLib::ActualActual::ISDA)"),
    ("EnumeratedClass", "ql/time/daycounters/actualactual.hpp", "QuantLib::DayCounter()", 
        "std::string", "Actual/Actual (AFB)", "QuantLib::ActualActual(QuantLib::ActualActual::AFB)"),
    ("EnumeratedClass", "ql/time/daycounters/thirty360.hpp", "QuantLib::DayCounter()", 
        "std::string", "30/360", "QuantLib::Thirty360()"),
    ("EnumeratedClass", "ql/time/daycounters/thirty360.hpp", "QuantLib::DayCounter()", 
        "std::string", "30/360 (Bond Basis)", "QuantLib::Thirty360(QuantLib::Thirty360::BondBasis)"),
    ("EnumeratedClass", "ql/time/daycounters/thirty360.hpp", "QuantLib::DayCounter()", 
        "std::string", "30/360 (Eurobond Basis)", "QuantLib::Thirty360(QuantLib::Thirty360::EurobondBasis)"),
    ("EnumeratedClass", "ql/time/daycounters/thirty360.hpp", "QuantLib::DayCounter()", 
        "std::string", "30/360 (Italian)", "QuantLib::Thirty360(QuantLib::Thirty360::Italian)"),
    ("EnumeratedClass", "ql/time/daycounters/simpledaycounter.hpp", "QuantLib::DayCounter()", 
        "std::string", "Simple", "QuantLib::SimpleDayCounter()"),
     
]
