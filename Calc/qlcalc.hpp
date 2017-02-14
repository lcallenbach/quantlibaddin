/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*	
 Copyright (C) 2004, 2005, 2006, 2008 Eric Ehlers
 Copyright (C) 2009 Roland Lichters
 Copyright (C) 2016 Lars Callenbach

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*
    http://wiki.services.openoffice.org/wiki/Calc/Add-In/Simple_Calc_Add-In
    http://wiki.services.openoffice.org/wiki/CompleteAddIn
    http://quantlib.org/quantlibaddin
*/

#ifndef quantlib_calcaddins_hpp
#define quantlib_calcaddins_hpp

#include <cppuhelper/implbase4.hxx> //4-parameter template will be used
#include <cppuhelper/factory.hxx>
#include <cppuhelper/implementationentry.hxx>

#include <uno/lbnames.h>

#include <com/sun/star/sheet/XAddIn.hpp>
#include <com/sun/star/lang/XServiceName.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <quantlib/XCalcAddins.hpp>

#include <cstdlib>
#include <cmath>

#include <ql/quantlib.hpp>

#include <init.hpp>
#include <idlconversions.hpp>

#define _serviceName_ "quantlib.CalcAddins"
#define _implName_ "quantlib.CalcAddins_impl.CalcAddins"
#define _AddserviceName_ "com.sun.star.sheet.AddIn"

using namespace ::rtl;
using namespace ::com::sun::star;
using namespace ::com::sun::star::uno;

#define STRING              ::rtl::OUString

//4-parameter template
class CalcAddins_impl 
    : public ::cppu::WeakImplHelper4< ::quantlib::XCalcAddins, sheet::XAddIn,
                                      lang::XServiceName, lang::XServiceInfo> {
    //Locale
    lang::Locale locale;
       
    std::map< STRING, STRING > funcMap;                 // function names
    std::map< STRING, STRING > funcDesc;                // function descriptions
    std::map< STRING, std::vector < STRING > > argName; // parameter names
    std::map< STRING, std::vector < STRING > > argDesc; // parameter description
public:
    //XCalcAddins
    /**************************************************************************
     * Start declaring methods here ...
     * Eric has put these into separate header files that are included at the
     * bottom of the class decleration with #include <<Addins/Calc/qlo_all.hpp>
     *************************************************************************/
    
    // addin interface functions

    SEQSEQ(IDL_any) SAL_CALL qlFloatingRateBond(const IDL_any &ObjectId_any, const IDL_any &SettlementDays_any, const IDL_any &FaceAmount_any, const IDL_any &StartDate_any, const IDL_any &MaturityDate_any, const IDL_any &CouponFrequency_any, const IDL_any &Calendar_any, const IDL_any &IborIndex_any, const IDL_any &AccrualDayCounter_any, const IDL_any &AccrualConvention_any, const IDL_any &PaymentConvention_any, const IDL_any &FixingDays_any, const SEQSEQ(IDL_any) &Gearings_any, const SEQSEQ(IDL_any) &Spreads_any, const SEQSEQ(IDL_any) &Caps_any, const SEQSEQ(IDL_any) &Floors_any, const IDL_any &InArrears_any, const IDL_any &Redemption_any, const IDL_any &IssueDate_any, const IDL_any &StubDate_any, const IDL_any &Rule_any, const IDL_any &EndOfMonth_any);
    SEQSEQ(IDL_any) SAL_CALL qlDiscountingBondEngine(const IDL_any &ObjectId_any, const IDL_any &DiscountCurve_any, const IDL_any &IncludeSettlementDaysFlows_any);
    SEQSEQ(IDL_any) SAL_CALL qlPiecewiseDefaultCurve(const IDL_any &ObjectId_any, const IDL_any &Traits_any, const IDL_any &Interpolator_any, const IDL_any &ReferenceDate_any, const SEQSEQ(IDL_any) &BootstrapInstruments_any, const IDL_any &DayCounter_any, const IDL_any &Accuracy_any);
    SEQSEQ(IDL_any) SAL_CALL qlEuribor365(const IDL_any &ObjectId_any, const IDL_any &Tenor_any, const IDL_any &ForwardCurve_any);
    SEQSEQ(IDL_any) SAL_CALL qlUpfrontCdsHelper(const IDL_any &ObjectId_any, const IDL_any &Upfront_any, const IDL_any &RunningSpread_any, const IDL_any &Tenor_any, const IDL_any &SettlementDays_any, const IDL_any &Calendar_any, const IDL_any &Frequency_any, const IDL_any &PaymentConvention_any, const IDL_any &Rule_any, const IDL_any &DayCounter_any, const IDL_any &RecoveryRate_any, const IDL_any &DiscountCurve_any, const IDL_any &UpfrontSettlementDays_any, const IDL_any &SettlesAccrual_any, const IDL_any &PaysAtDefaultTime_any);
    SEQSEQ(IDL_any) SAL_CALL qlSpreadCdsHelper(const IDL_any &ObjectId_any, const IDL_any &RunningSpread_any, const IDL_any &Tenor_any, const IDL_any &SettlementDays_any, const IDL_any &Calendar_any, const IDL_any &Frequency_any, const IDL_any &PaymentConvention_any, const IDL_any &Rule_any, const IDL_any &DayCounter_any, const IDL_any &RecoveryRate_any, const IDL_any &DiscountCurve_any, const IDL_any &SettlesAccrual_any, const IDL_any &PaysAtDefaultTime_any);
    SEQSEQ(IDL_any) SAL_CALL qlEuribor(const IDL_any &ObjectId_any, const IDL_any &Tenor_any, const IDL_any &ForwardCurve_any);
    SEQSEQ(IDL_any) SAL_CALL qlDiscountingSwapEngine(const IDL_any &ObjectId_any, const IDL_any &DiscountCurve_any, const IDL_any &IncludeSettlementDaysFlows_any, const IDL_any &SettlementDate_any, const IDL_any &NpvDate_any);
    SEQSEQ(IDL_any) SAL_CALL qlInterpolation2D(const IDL_any &ObjectId_any, const IDL_any &Interpolator2DID_any, const SEQSEQ(IDL_any) &XVector_any, const SEQSEQ(IDL_any) &YVector_any, const SEQSEQ(IDL_any) &ZData_any);
    SEQSEQ(IDL_any) SAL_CALL qlBondHelper(const IDL_any &ObjectId_any, const IDL_any &Price_any, const IDL_any &Bond_any, const IDL_any &UseCleanPrice_any);
    SEQSEQ(IDL_any) SAL_CALL qlAnalyticEuropeanEngine(const IDL_any &ObjectId_any, const IDL_any &GeneralizedBlackSchlolesProcess_any);
    SEQSEQ(IDL_any) SAL_CALL qlSimpleQuote(const IDL_any &ObjectId_any, const IDL_any &Value_any);
    SEQSEQ(IDL_any) SAL_CALL qlDiscountCurve(const IDL_any &ObjectId_any, const SEQSEQ(IDL_any) &Dates_any, const SEQSEQ(IDL_any) &Discounts_any, const IDL_any &DayCounter_any);
    SEQSEQ(IDL_any) SAL_CALL qlFraRateHelper(const IDL_any &ObjectId_any, const IDL_any &Rate_any, const IDL_any &MonthsToStart_any, const IDL_any &MonthsToEnd_any, const IDL_any &FixingDays_any, const IDL_any &Calendar_any, const IDL_any &Convention_any, const IDL_any &EndOfMonth_any, const IDL_any &DayCounter_any, const IDL_any &Pillar_any, const IDL_any &CustomPillarDate_any);
    SEQSEQ(IDL_any) SAL_CALL qlVanillaOption(const IDL_any &ObjectId_any, const IDL_any &StrikedTypePayoff_any, const IDL_any &Exercise_any);
    SEQSEQ(IDL_any) SAL_CALL qlFixedRateBondHelper(const IDL_any &ObjectId_any, const IDL_any &Price_any, const IDL_any &SettlementDays_any, const IDL_any &FaceAmount_any, const IDL_any &Schedule_any, const SEQSEQ(IDL_any) &Coupons_any, const IDL_any &DayCounter_any, const IDL_any &PaymentConv_any, const IDL_any &Redemption_any, const IDL_any &Date_any, const IDL_any &PaymentCalendar_any, const IDL_any &ExCouponPeriod_any, const IDL_any &ExCouponCalendar_any, const IDL_any &ExCouponConvention_any, const IDL_any &ExCouponEndOfMonth_any, const IDL_any &UseCleanPrice_any);
    SEQSEQ(IDL_any) SAL_CALL qlDepositRateHelper(const IDL_any &ObjectId_any, const IDL_any &Rate_any, const IDL_any &Period_any, const IDL_any &FixingDays_any, const IDL_any &Calendar_any, const IDL_any &BusinessDayConvention_any, const IDL_any &EndOfMonth_any, const IDL_any &DayCounter_any);
    SEQSEQ(IDL_any) SAL_CALL qlFixedRateBond(const IDL_any &ObjectId_any, const IDL_any &SettlementDays_any, const IDL_any &CouponCalendar_any, const IDL_any &FaceAmount_any, const IDL_any &StartDate_any, const IDL_any &MaturityDate_any, const IDL_any &Tenor_any, const SEQSEQ(IDL_any) &Coupons_any, const IDL_any &AccrualDayCounter_any, const IDL_any &AccrualConvention_any, const IDL_any &PaymentConvention_any, const IDL_any &Redemption_any, const IDL_any &IssueDate_any, const IDL_any &StubDate_any, const IDL_any &Rule_any, const IDL_any &EndOfMonth_any, const IDL_any &PaymentCalendar_any, const IDL_any &ExCouponPeriod_any, const IDL_any &ExCouponCalendar_any, const IDL_any &ExCouponConvention_any, const IDL_any &ExCouponEndOfMonth_any);
    SEQSEQ(IDL_any) SAL_CALL qlBlackVarianceSurface(const IDL_any &ObjectId_any, const IDL_any &ReferenceDate_any, const IDL_any &Calendar_any, const SEQSEQ(IDL_any) &Dates_any, const SEQSEQ(IDL_any) &Strikes_any, const SEQSEQ(IDL_any) &BlackVolMatrix_any, const IDL_any &DayCounter_any, const IDL_any &LowerExtrapolation_any, const IDL_any &UpperExtrapolation_any);
    SEQSEQ(IDL_any) SAL_CALL qlZeroCurve(const IDL_any &ObjectId_any, const SEQSEQ(IDL_any) &Dates_any, const SEQSEQ(IDL_any) &ZeroRates_any, const IDL_any &DayCounterDayCounter_any);
    SEQSEQ(IDL_any) SAL_CALL qlSwapRateHelper(const IDL_any &ObjectId_any, const IDL_any &Rate_any, const IDL_any &Tenor_any, const IDL_any &Calendar_any, const IDL_any &FixedFrequency_any, const IDL_any &FixedConvention_any, const IDL_any &FixedDayCounter_any, const IDL_any &IborIndex_any, const IDL_any &Spread_any, const IDL_any &FwdStartPeriod_any);
    SEQSEQ(IDL_any) SAL_CALL qlVanillaSwap(const IDL_any &ObjectId_any, const IDL_any &Type_any, const IDL_any &Nominal_any, const IDL_any &FixedSchedule_any, const IDL_any &FixedRate_any, const IDL_any &FixedDayCount_any, const IDL_any &FloatSchedule_any, const IDL_any &IborIndex_any, const IDL_any &Spread_any, const IDL_any &FloatingDayCount_any, const IDL_any &PaymentConvention_any);
    SEQSEQ(IDL_any) SAL_CALL qlPlainVanillaPayoff(const IDL_any &ObjectId_any, const IDL_any &OptionType_any, const IDL_any &Strike_any);
    SEQSEQ(IDL_any) SAL_CALL qlInterpolation1D(const IDL_any &ObjectId_any, const IDL_any &Interpolator1DID_any, const SEQSEQ(IDL_any) &XVector_any, const SEQSEQ(IDL_any) &YVector_any);
    SEQSEQ(IDL_any) SAL_CALL qlEuropeanExercise(const IDL_any &ObjectId_any, const IDL_any &ExerciseDate_any);
    SEQSEQ(IDL_any) SAL_CALL qlPiecewiseYieldCurve(const IDL_any &ObjectId_any, const IDL_any &Traits_any, const IDL_any &Interpolator_any, const IDL_any &ReferenceDate_any, const SEQSEQ(IDL_any) &BootstrapInstruments_any, const IDL_any &DayCounter_any, const IDL_any &Accuracy_any);
    SEQSEQ(IDL_any) SAL_CALL qlRiskyFixedBond(const IDL_any &ObjectId_any, const IDL_any &Name_any, const IDL_any &Ccy_any, const IDL_any &RecoveryRate_any, const IDL_any &DefaultTS_any, const IDL_any &Schedule_any, const IDL_any &Rate_any, const IDL_any &DayCounter_any, const IDL_any &PaymentConvention_any, const SEQSEQ(IDL_any) &Notionals_any, const IDL_any &YieldTS_any);
    SEQSEQ(IDL_any) SAL_CALL qlSchedule(const IDL_any &ObjectId_any, const IDL_any &EffectiveDate_any, const IDL_any &TerminationDate_any, const IDL_any &Period_any, const IDL_any &Calendar_any, const IDL_any &Convention_any, const IDL_any &TerminationConvention_any, const IDL_any &Rule_any, const IDL_any &EndOfMonth_any, const IDL_any &FirstDate_any, const IDL_any &NextToLastDate_any);
    SEQSEQ(IDL_any) SAL_CALL qlInterpolatedHazardRateCurve(const IDL_any &ObjectId_any, const IDL_any &Interpolator_any, const SEQSEQ(IDL_any) &Dates_any, const SEQSEQ(IDL_any) &HazardRates_any, const IDL_any &DayCounter_any, const IDL_any &Calendar_any);
    SEQSEQ(IDL_any) SAL_CALL qlGeneralizedBlackScholesProcess(const IDL_any &ObjectId_any, const IDL_any &Quote_any, const IDL_any &DividendTS_any, const IDL_any &RiskFreeTS_any, const IDL_any &BlackVolTS_any);
    SEQSEQ(IDL_any) SAL_CALL qlFuturesRateHelper(const IDL_any &ObjectId_any, const IDL_any &Price_any, const IDL_any &IborStartDate_any, const IDL_any &IborIndex_any, const IDL_any &ConvexityAdjustment_any, const IDL_any &Type_any);
    SEQSEQ(IDL_any) SAL_CALL qlCalendarIsBusinessDay(const IDL_any &ObjectId_any, const IDL_any &Date_any);
    SEQSEQ(IDL_any) SAL_CALL qlInstrumentIsExpired(const IDL_any &ObjectId_any);
    SEQSEQ(IDL_any) SAL_CALL qlCalendarIsHoliday(const IDL_any &ObjectId_any, const IDL_any &Date_any);
    SEQSEQ(IDL_any) SAL_CALL qlDefaultTSDefaultDensity(const IDL_any &ObjectId_any, const IDL_any &Date_any, const IDL_any &Extrapolate_any);
    SEQSEQ(IDL_any) SAL_CALL qlInterpolatedValue1D(const IDL_any &ObjectId_any, const IDL_any &X_any, const IDL_any &Extrapolate_any);
    SEQSEQ(IDL_any) SAL_CALL qlInstrumentSetPricingEngine(const IDL_any &ObjectId_any, const IDL_any &PricingEngine_any);
    SEQSEQ(IDL_any) SAL_CALL qlDefaultTSSurvivalProbability(const IDL_any &ObjectId_any, const IDL_any &Date_any, const IDL_any &Extrapolate_any);
    SEQSEQ(IDL_any) SAL_CALL qlBlackVolTermStructureBlackVol(const IDL_any &ObjectId_any, const IDL_any &Maturity_any, const IDL_any &Strike_any, const IDL_any &Extrapolate_any);
    SEQSEQ(IDL_any) SAL_CALL qlDefaultTSDefaultProbability(const IDL_any &ObjectId_any, const IDL_any &Date_any, const IDL_any &Extrapolate_any);
    SEQSEQ(IDL_any) SAL_CALL qlCalendarName(const IDL_any &ObjectId_any);
    SEQSEQ(IDL_any) SAL_CALL qlCalendarAdvance(const IDL_any &ObjectId_any, const IDL_any &StartDate_any, const IDL_any &Period_any, const IDL_any &BusinessDayConvention_any, const IDL_any &EndOfMonth_any);
    SEQSEQ(IDL_any) SAL_CALL qlYieldTSDiscount(const IDL_any &ObjectId_any, const IDL_any &Date_any);
    SEQSEQ(IDL_any) SAL_CALL qlDayCounterDayCount(const IDL_any &ObjectId_any, const IDL_any &StartDate_any, const IDL_any &EndDate_any);
    SEQSEQ(IDL_any) SAL_CALL qlRiskyBondCurrency(const IDL_any &ObjectId_any);
    SEQSEQ(IDL_any) SAL_CALL qlQuoteValue(const IDL_any &ObjectId_any);
    SEQSEQ(IDL_any) SAL_CALL qlDayCounterName(const IDL_any &ObjectId_any);
    SEQSEQ(IDL_any) SAL_CALL qlInterpolatedValue2D(const IDL_any &ObjectId_any, const IDL_any &X_any, const IDL_any &Y_any, const IDL_any &Extrapolate_any);
    SEQSEQ(IDL_any) SAL_CALL qlScheduleDates(const IDL_any &ObjectId_any);
    SEQSEQ(IDL_any) SAL_CALL qlDayCounterYearFraction(const IDL_any &ObjectId_any, const IDL_any &StartDate_any, const IDL_any &EndDate_any);
    SEQSEQ(IDL_any) SAL_CALL qlInstrumentNPV(const IDL_any &ObjectId_any);
    SEQSEQ(IDL_any) SAL_CALL qlDefaultTSHazardRate(const IDL_any &ObjectId_any, const IDL_any &Date_any, const IDL_any &Extrapolate_any);
    SEQSEQ(IDL_any) SAL_CALL qlSettingsSetEvaluationDate(const IDL_any &Date_any);


    /*************************************************************************
     * ... and stop declaring methods here.
     *************************************************************************/

    //XAddIn
    OUString SAL_CALL getProgrammaticFuntionName(const OUString& aDisplayName)
        throw (RuntimeException);
    OUString SAL_CALL getDisplayFunctionName(const OUString& aProgrammaticName) 
        throw (RuntimeException);
    OUString SAL_CALL getFunctionDescription(const OUString& aProgrammaticName) 
        throw (RuntimeException);
    OUString SAL_CALL getDisplayArgumentName(const OUString& aProgrammaticName,
                                             ::sal_Int32 nArgument) 
        throw (RuntimeException);
    OUString SAL_CALL getArgumentDescription(const OUString& aProgrammaticName,
                                             ::sal_Int32 nArgument) 
        throw (RuntimeException);
    OUString SAL_CALL getProgrammaticCategoryName(
                                             const OUString& aProgrammaticName) 
        throw (RuntimeException);
    OUString SAL_CALL getDisplayCategoryName(const OUString& aProgrammaticName)
        throw (RuntimeException);

    //XServiceName
    OUString SAL_CALL getServiceName() throw (RuntimeException);

    //XServiceInfo
    OUString SAL_CALL getImplementationName() throw (RuntimeException);
    ::sal_Bool SAL_CALL supportsService(const OUString& ServiceName) 
        throw (RuntimeException);
    Sequence< OUString > SAL_CALL getSupportedServiceNames() 
        throw (RuntimeException);

    //XLocalizable
    void SAL_CALL setLocale(const lang::Locale& eLocale) 
        throw (RuntimeException);
    lang::Locale SAL_CALL getLocale() throw (RuntimeException);

    /**************************************************************************
     * RL: Declare constructor and desctructor here, following Eric's example.
     *     This is to initialize QuantLibAddin's repository and set up
     *     descriptions for the function wizard.
     *     Implemented in funcdef.cpp
     *************************************************************************/
    CalcAddins_impl() throw ();
    virtual ~CalcAddins_impl() {};

};

#endif