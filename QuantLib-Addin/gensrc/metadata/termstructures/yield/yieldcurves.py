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
    ("Constructor", "ql/termstructures/yield/zerocurve.hpp", 
        "QuantLib::ZeroCurve(std::vector<QuantLib::Date> Dates, std::vector<QuantLib::Real> ZeroRates, QuantLib::DayCounter DayCounterDayCounter=QuantLib::Actual365Fixed())", 
        "", "qlZeroCurve"),
    ("Constructor", "ql/termstructures/yield/discountcurve.hpp", 
        "QuantLib::DiscountCurve(std::vector<QuantLib::Date> Dates, std::vector<QuantLib::Real> Discounts, QuantLib::DayCounter DayCounter=QuantLib::Actual365Fixed())", 
        "", "qlDiscountCurve"),
    ("MemberFunction", "ql/termstructures/yieldtermstructure.hpp",
        "QuantLib::YieldTermStructure()", "QuantLib::DiscountFactor discount(QuantLib::Date Date)",
        "qlYieldTSDiscount")
]

