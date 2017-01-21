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
    ("Constructor", "ql/processes/blackscholesprocess.hpp", 
        "QuantLib::GeneralizedBlackScholesProcess(QuantLib::Handle<QuantLib::Quote> Quote, QuantLib::Handle<QuantLib::YieldTermStructure> DividendTS, QuantLib::Handle<QuantLib::YieldTermStructure> RiskFreeTS, QuantLib::Handle<QuantLib::BlackVolTermStructure> BlackVolTS)", 
        "", "qlGeneralizedBlackScholesProcess"),
]

