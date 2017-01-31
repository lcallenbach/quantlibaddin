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
    ("Constructor", "ql/instruments/bonds/fixedratebond.hpp", 
        "QuantLib::FixedRateBond(QuantLib::Natural SettlementDays, QuantLib::Calendar CouponCalendar, QuantLib::Real FaceAmount, QuantLib::Date StartDate, QuantLib::Date MaturityDate, QuantLib::Period Tenor, std::vector<QuantLib::Rate> Coupons, QuantLib::DayCounter AccrualDayCounter, QuantLib::BusinessDayConvention AccrualConvention = QuantLib::Following, QuantLib::BusinessDayConvention PaymentConvention = QuantLib::Following, QuantLib::Real Redemption = 100.0, QuantLib::Date IssueDate = QuantLib::Date(), QuantLib::Date StubDate = QuantLib::Date(), QuantLib::DateGeneration::Rule Rule = QuantLib::DateGeneration::Backward, bool EndOfMonth = false, QuantLib::Calendar PaymentCalendar = QuantLib::Calendar(), QuantLib::Period ExCouponPeriod = QuantLib::Period(), QuantLib::Calendar ExCouponCalendar = QuantLib::Calendar(), QuantLib::BusinessDayConvention ExCouponConvention = QuantLib::Unadjusted, bool ExCouponEndOfMonth = false)", 
        "", "qlFixedRateBond"),
]

