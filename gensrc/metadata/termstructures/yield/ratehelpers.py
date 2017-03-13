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
    ("Constructor", "ql/termstructures/yield/ratehelpers.hpp", 
        "QuantLib::DepositRateHelper(QuantLib::Rate Rate, QuantLib::Period Period, QuantLib::Natural FixingDays, QuantLib::Calendar Calendar, QuantLib::BusinessDayConvention BusinessDayConvention, bool EndOfMonth, QuantLib::DayCounter DayCounter)", 
        "", "qlDepositRateHelper"),
    ("Constructor", "ql/termstructures/yield/ratehelpers.hpp", 
        "QuantLib::SwapRateHelper(QuantLib::Rate Rate, QuantLib::Period Tenor, QuantLib::Calendar Calendar, QuantLib::Frequency FixedFrequency, QuantLib::BusinessDayConvention FixedConvention, QuantLib::DayCounter FixedDayCounter, boost::shared_ptr<QuantLib::IborIndex> IborIndex, QuantLib::Handle<QuantLib::Quote> Spread, QuantLib::Period FwdStartPeriod)", 
        "", "qlSwapRateHelper"),
    ("Constructor", "ql/termstructures/yield/ratehelpers.hpp", 
        "QuantLib::FraRateHelper(QuantLib::Rate Rate, QuantLib::Natural MonthsToStart, QuantLib::Natural MonthsToEnd, QuantLib::Natural FixingDays, QuantLib::Calendar Calendar, QuantLib::BusinessDayConvention Convention, bool EndOfMonth, QuantLib::DayCounter DayCounter, QuantLib::Pillar::Choice Pillar, QuantLib::Date CustomPillarDate = QuantLib::Date())", 
        "", "qlFraRateHelper"),
    ("Constructor", "ql/termstructures/yield/ratehelpers.hpp", 
        "QuantLib::FuturesRateHelper(QuantLib::Real Price, QuantLib::Date IborStartDate, boost::shared_ptr<QuantLib::IborIndex> IborIndex, QuantLib::Rate ConvexityAdjustment, QuantLib::Futures::Type Type)", 
        "", "qlFuturesRateHelper"),
    ("Constructor", "ql/termstructures/yield/oisratehelper.hpp", 
        "QuantLib::OISRateHelper(QuantLib::Natural SettlementDays, QuantLib::Period Tenor, QuantLib::Handle<QuantLib::Quote> FixedRate, boost::shared_ptr<QuantLib::OvernightIndex> OvernightIndex, QuantLib::Handle<QuantLib::YieldTermStructure> DiscountingCurve = QuantLib::Handle<QuantLib::YieldTermStructure>())", 
        "", "qlOISRateHelper"),
]

