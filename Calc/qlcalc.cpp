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

#include <qlcalc.hpp>
#include <addin.hpp>
#include <init.hpp>
#include <idlconversions.hpp>

#define STRFROMANSI(s)      IDL_string( s, strlen( s ), RTL_TEXTENCODING_MS_1252 )

using namespace QuantLib;
using namespace Addin;


// addin interface functions

SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlGeneralizedBlackScholesProcess(const IDL_any &ObjectId_any, const IDL_any &Quote_any, const IDL_any &DividendTS_any, const IDL_any &RiskFreeTS_any, const IDL_any &BlackVolTS_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_GeneralizedBlackScholesProcess(Quote_any, DividendTS_any, RiskFreeTS_any, BlackVolTS_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlGeneralizedBlackScholesProcess:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlUpfrontCdsHelper(const IDL_any &ObjectId_any, const IDL_any &Upfront_any, const IDL_any &RunningSpread_any, const IDL_any &Tenor_any, const IDL_any &SettlementDays_any, const IDL_any &Calendar_any, const IDL_any &Frequency_any, const IDL_any &PaymentConvention_any, const IDL_any &Rule_any, const IDL_any &DayCounter_any, const IDL_any &RecoveryRate_any, const IDL_any &DiscountCurve_any, const IDL_any &UpfrontSettlementDays_any, const IDL_any &SettlesAccrual_any, const IDL_any &PaysAtDefaultTime_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_UpfrontCdsHelper(Upfront_any, RunningSpread_any, Tenor_any, SettlementDays_any, Calendar_any, Frequency_any, PaymentConvention_any, Rule_any, DayCounter_any, RecoveryRate_any, DiscountCurve_any, UpfrontSettlementDays_any, SettlesAccrual_any, PaysAtDefaultTime_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlUpfrontCdsHelper:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlZeroCurve(const IDL_any &ObjectId_any, const SEQSEQ(IDL_any) &Dates_any, const SEQSEQ(IDL_any) &ZeroRates_any, const IDL_any &DayCounterDayCounter_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_ZeroCurve(Dates_any, ZeroRates_any, DayCounterDayCounter_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlZeroCurve:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlInterpolation2D(const IDL_any &ObjectId_any, const IDL_any &Interpolator2DID_any, const SEQSEQ(IDL_any) &XVector_any, const SEQSEQ(IDL_any) &YVector_any, const SEQSEQ(IDL_any) &ZData_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new Addin_AddinInterpolation2D(Interpolator2DID_any, XVector_any, YVector_any, ZData_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlInterpolation2D:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlInterpolatedHazardRateCurve(const IDL_any &ObjectId_any, const IDL_any &Interpolator_any, const SEQSEQ(IDL_any) &Dates_any, const SEQSEQ(IDL_any) &HazardRates_any, const IDL_any &DayCounter_any, const IDL_any &Calendar_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_InterpolatedHazardRateCurve(Interpolator_any, Dates_any, HazardRates_any, DayCounter_any, Calendar_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlInterpolatedHazardRateCurve:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlSpreadCdsHelper(const IDL_any &ObjectId_any, const IDL_any &RunningSpread_any, const IDL_any &Tenor_any, const IDL_any &SettlementDays_any, const IDL_any &Calendar_any, const IDL_any &Frequency_any, const IDL_any &PaymentConvention_any, const IDL_any &Rule_any, const IDL_any &DayCounter_any, const IDL_any &RecoveryRate_any, const IDL_any &DiscountCurve_any, const IDL_any &SettlesAccrual_any, const IDL_any &PaysAtDefaultTime_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_SpreadCdsHelper(RunningSpread_any, Tenor_any, SettlementDays_any, Calendar_any, Frequency_any, PaymentConvention_any, Rule_any, DayCounter_any, RecoveryRate_any, DiscountCurve_any, SettlesAccrual_any, PaysAtDefaultTime_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlSpreadCdsHelper:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlPlainVanillaPayoff(const IDL_any &ObjectId_any, const IDL_any &OptionType_any, const IDL_any &Strike_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_PlainVanillaPayoff(OptionType_any, Strike_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlPlainVanillaPayoff:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlPiecewiseDefaultCurve(const IDL_any &ObjectId_any, const IDL_any &Traits_any, const IDL_any &Interpolator_any, const IDL_any &ReferenceDate_any, const SEQSEQ(IDL_any) &BootstrapInstruments_any, const IDL_any &DayCounter_any, const IDL_any &Accuracy_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_PiecewiseDefaultCurve(Traits_any, Interpolator_any, ReferenceDate_any, BootstrapInstruments_any, DayCounter_any, Accuracy_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlPiecewiseDefaultCurve:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlAnalyticEuropeanEngine(const IDL_any &ObjectId_any, const IDL_any &GeneralizedBlackSchlolesProcess_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_AnalyticEuropeanEngine(GeneralizedBlackSchlolesProcess_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlAnalyticEuropeanEngine:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlEuropeanExercise(const IDL_any &ObjectId_any, const IDL_any &ExerciseDate_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_EuropeanExercise(ExerciseDate_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlEuropeanExercise:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlFloatingRateBond(const IDL_any &ObjectId_any, const IDL_any &SettlementDays_any, const IDL_any &faceAmount_any, const IDL_any &StartDate_any, const IDL_any &MaturityDate_any, const IDL_any &CouponFrequency_any, const IDL_any &Calendar_any, const IDL_any &IborIndex_any, const IDL_any &AccrualDayCounter_any, const IDL_any &AccrualConvention_any, const IDL_any &PaymentConvention_any, const IDL_any &FixingDays_any, const SEQSEQ(IDL_any) &Gearings_any, const SEQSEQ(IDL_any) &Spreads_any, const SEQSEQ(IDL_any) &Caps_any, const SEQSEQ(IDL_any) &Floors_any, const IDL_any &InArrears_any, const IDL_any &Redemption_any, const IDL_any &IssueDate_any, const IDL_any &StubDate_any, const IDL_any &Rule_any, const IDL_any &EndOfMonth_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_FloatingRateBond(SettlementDays_any, faceAmount_any, StartDate_any, MaturityDate_any, CouponFrequency_any, Calendar_any, IborIndex_any, AccrualDayCounter_any, AccrualConvention_any, PaymentConvention_any, FixingDays_any, Gearings_any, Spreads_any, Caps_any, Floors_any, InArrears_any, Redemption_any, IssueDate_any, StubDate_any, Rule_any, EndOfMonth_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlFloatingRateBond:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlEuribor365(const IDL_any &ObjectId_any, const IDL_any &Tenor_any, const IDL_any &ForwardCurve_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_Euribor365(Tenor_any, ForwardCurve_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlEuribor365:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlSwapRateHelper(const IDL_any &ObjectId_any, const IDL_any &Rate_any, const IDL_any &Tenor_any, const IDL_any &Calendar_any, const IDL_any &FixedFrequency_any, const IDL_any &FixedConvention_any, const IDL_any &FixedDayCounter_any, const IDL_any &IborIndex_any, const IDL_any &Spread_any, const IDL_any &FwdStartPeriod_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_SwapRateHelper(Rate_any, Tenor_any, Calendar_any, FixedFrequency_any, FixedConvention_any, FixedDayCounter_any, IborIndex_any, Spread_any, FwdStartPeriod_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlSwapRateHelper:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlDepositRateHelper(const IDL_any &ObjectId_any, const IDL_any &Rate_any, const IDL_any &Period_any, const IDL_any &FixingDays_any, const IDL_any &Calendar_any, const IDL_any &BusinessDayConvention_any, const IDL_any &EndOfMonth_any, const IDL_any &DayCounter_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_DepositRateHelper(Rate_any, Period_any, FixingDays_any, Calendar_any, BusinessDayConvention_any, EndOfMonth_any, DayCounter_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlDepositRateHelper:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlEuribor(const IDL_any &ObjectId_any, const IDL_any &Tenor_any, const IDL_any &ForwardCurve_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_Euribor(Tenor_any, ForwardCurve_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlEuribor:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlInterpolation1D(const IDL_any &ObjectId_any, const IDL_any &Interpolator1DID_any, const SEQSEQ(IDL_any) &XVector_any, const SEQSEQ(IDL_any) &YVector_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new Addin_AddinInterpolation1D(Interpolator1DID_any, XVector_any, YVector_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlInterpolation1D:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlSchedule(const IDL_any &ObjectId_any, const IDL_any &EffectiveDate_any, const IDL_any &TerminationDate_any, const IDL_any &Period_any, const IDL_any &Calendar_any, const IDL_any &Convention_any, const IDL_any &TerminationConvention_any, const IDL_any &Rule_any, const IDL_any &EndOfMonth_any, const IDL_any &FirstDate_any, const IDL_any &NextToLastDate_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_Schedule(EffectiveDate_any, TerminationDate_any, Period_any, Calendar_any, Convention_any, TerminationConvention_any, Rule_any, EndOfMonth_any, FirstDate_any, NextToLastDate_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlSchedule:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlFuturesRateHelper(const IDL_any &ObjectId_any, const IDL_any &Price_any, const IDL_any &IborStartDate_any, const IDL_any &IborIndex_any, const IDL_any &ConvexityAdjustment_any, const IDL_any &Type_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_FuturesRateHelper(Price_any, IborStartDate_any, IborIndex_any, ConvexityAdjustment_any, Type_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlFuturesRateHelper:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlSimpleQuote(const IDL_any &ObjectId_any, const IDL_any &Value_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_SimpleQuote(Value_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlSimpleQuote:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlFraRateHelper(const IDL_any &ObjectId_any, const IDL_any &Rate_any, const IDL_any &MonthsToStart_any, const IDL_any &MonthsToEnd_any, const IDL_any &FixingDays_any, const IDL_any &Calendar_any, const IDL_any &Convention_any, const IDL_any &EndOfMonth_any, const IDL_any &DayCounter_any, const IDL_any &Pillar_any, const IDL_any &CustomPillarDate_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_FraRateHelper(Rate_any, MonthsToStart_any, MonthsToEnd_any, FixingDays_any, Calendar_any, Convention_any, EndOfMonth_any, DayCounter_any, Pillar_any, CustomPillarDate_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlFraRateHelper:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlDiscountCurve(const IDL_any &ObjectId_any, const SEQSEQ(IDL_any) &Dates_any, const SEQSEQ(IDL_any) &Discounts_any, const IDL_any &DayCounter_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_DiscountCurve(Dates_any, Discounts_any, DayCounter_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlDiscountCurve:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlBlackVarianceSurface(const IDL_any &ObjectId_any, const IDL_any &ReferenceDate_any, const IDL_any &Calendar_any, const SEQSEQ(IDL_any) &Dates_any, const SEQSEQ(IDL_any) &Strikes_any, const SEQSEQ(IDL_any) &BlackVolMatrix_any, const IDL_any &DayCounter_any, const IDL_any &LowerExtrapolation_any, const IDL_any &UpperExtrapolation_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_BlackVarianceSurface(ReferenceDate_any, Calendar_any, Dates_any, Strikes_any, BlackVolMatrix_any, DayCounter_any, LowerExtrapolation_any, UpperExtrapolation_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlBlackVarianceSurface:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlPiecewiseYieldCurve(const IDL_any &ObjectId_any, const IDL_any &Traits_any, const IDL_any &Interpolator_any, const IDL_any &ReferenceDate_any, const SEQSEQ(IDL_any) &BootstrapInstruments_any, const IDL_any &DayCounter_any, const IDL_any &Accuracy_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_PiecewiseYieldCurve(Traits_any, Interpolator_any, ReferenceDate_any, BootstrapInstruments_any, DayCounter_any, Accuracy_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlPiecewiseYieldCurve:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlVanillaOption(const IDL_any &ObjectId_any, const IDL_any &StrikedTypePayoff_any, const IDL_any &Exercise_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_VanillaOption(StrikedTypePayoff_any, Exercise_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlVanillaOption:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlFixedRateBond(const IDL_any &ObjectId_any, const IDL_any &SettlementDays_any, const IDL_any &CouponCalendar_any, const IDL_any &FaceAmount_any, const IDL_any &StartDate_any, const IDL_any &MaturityDate_any, const IDL_any &Tenor_any, const SEQSEQ(IDL_any) &Coupons_any, const IDL_any &AccrualDayCounter_any, const IDL_any &AccrualConvention_any, const IDL_any &PaymentConvention_any, const IDL_any &Redemption_any, const IDL_any &IssueDate_any, const IDL_any &StubDate_any, const IDL_any &Rule_any, const IDL_any &EndOfMonth_any, const IDL_any &PaymentCalendar_any, const IDL_any &ExCouponPeriod_any, const IDL_any &ExCouponCalendar_any, const IDL_any &ExCouponConvention_any, const IDL_any &ExCouponEndOfMonth_any) {
    try { 
        IDL_string ObjectId;
        std::string ObjectId_cpp;
        if(ObjectId_any.hasValue()) { 
            scalarAnyToIDL(ObjectId_any, ObjectId);
            scalarInterfaceToCpp(ObjectId, ObjectId_cpp, interfaceToString);
        }
        
        ObjectHandler::Repository::instance().storeObject(ObjectId_cpp,
            boost::shared_ptr<ObjectHandler::Object>(new QuantLib_FixedRateBond(SettlementDays_any, CouponCalendar_any, FaceAmount_any, StartDate_any, MaturityDate_any, Tenor_any, Coupons_any, AccrualDayCounter_any, AccrualConvention_any, PaymentConvention_any, Redemption_any, IssueDate_any, StubDate_any, Rule_any, EndOfMonth_any, PaymentCalendar_any, ExCouponPeriod_any, ExCouponCalendar_any, ExCouponConvention_any, ExCouponEndOfMonth_any)));
        std::string returnValue = ObjectId_cpp;
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlFixedRateBond:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlBlackVolTermStructureBlackVol(const IDL_any &ObjectId_any, const IDL_any &Maturity_any, const IDL_any &Strike_any, const IDL_any &Extrapolate_any) {
    try {
        QuantLib::Volatility returnValue;
        returnValue = QuantLib_BlackVolTermStructure::blackVol(ObjectId_any, Maturity_any, Strike_any, Extrapolate_any);
        // return value
        IDL_double returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlBlackVolTermStructureBlackVol:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlDefaultTSHazardRate(const IDL_any &ObjectId_any, const IDL_any &Date_any, const IDL_any &Extrapolate_any) {
    try {
        QuantLib::Probability returnValue;
        returnValue = QuantLib_DefaultProbabilityTermStructure::hazardRate(ObjectId_any, Date_any, Extrapolate_any);
        // return value
        IDL_double returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlDefaultTSHazardRate:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlInterpolatedValue2D(const IDL_any &ObjectId_any, const IDL_any &X_any, const IDL_any &Y_any, const IDL_any &Extrapolate_any) {
    try {
        QuantLib::Real returnValue;
        returnValue = QuantLib_Interpolation2D::addinOperator(ObjectId_any, X_any, Y_any, Extrapolate_any);
        // return value
        IDL_double returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlInterpolatedValue2D:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlQuoteValue(const IDL_any &ObjectId_any) {
    try {
        QuantLib::Real returnValue;
        returnValue = QuantLib_Quote::value(ObjectId_any);
        // return value
        IDL_double returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlQuoteValue:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlDayCounterYearFraction(const IDL_any &ObjectId_any, const IDL_any &StartDate_any, const IDL_any &EndDate_any) {
    try {
        double returnValue;
        returnValue = QuantLib_DayCounter::yearFraction(ObjectId_any, StartDate_any, EndDate_any);
        // return value
        IDL_double returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlDayCounterYearFraction:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlCalendarAdvance(const IDL_any &ObjectId_any, const IDL_any &StartDate_any, const IDL_any &Period_any, const IDL_any &BusinessDayConvention_any, const IDL_any &EndOfMonth_any) {
    try {
        QuantLib::Date returnValue;
        returnValue = QuantLib_Calendar::advance(ObjectId_any, StartDate_any, Period_any, BusinessDayConvention_any, EndOfMonth_any);
        // return value
        IDL_long returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, interfaceFromDate);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlCalendarAdvance:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlDefaultTSSurvivalProbability(const IDL_any &ObjectId_any, const IDL_any &Date_any, const IDL_any &Extrapolate_any) {
    try {
        QuantLib::Probability returnValue;
        returnValue = QuantLib_DefaultProbabilityTermStructure::survivalProbability(ObjectId_any, Date_any, Extrapolate_any);
        // return value
        IDL_double returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlDefaultTSSurvivalProbability:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlInstrumentSetPricingEngine(const IDL_any &ObjectId_any, const IDL_any &PricingEngine_any) {
    try {
        QuantLib_Instrument::setPricingEngine(ObjectId_any, PricingEngine_any);
        std::string returnString=std::string("OK");
        SEQSEQ(IDL_any) retAnyArray;
        retAnyArray.realloc(1);
        SEQ(IDL_any) retAnyVector(1);
        IDL_string s = STRFROMASCII( returnString.c_str() );
        retAnyVector[0] = CSS::uno::makeAny( s );
        retAnyArray[0] = retAnyVector;
        return retAnyArray;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlInstrumentSetPricingEngine:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlInterpolatedValue1D(const IDL_any &ObjectId_any, const IDL_any &X_any, const IDL_any &Extrapolate_any) {
    try {
        QuantLib::Real returnValue;
        returnValue = QuantLib_Interpolation::addinOperator(ObjectId_any, X_any, Extrapolate_any);
        // return value
        IDL_double returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlInterpolatedValue1D:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlInstrumentNPV(const IDL_any &ObjectId_any) {
    try {
        QuantLib::Real returnValue;
        returnValue = QuantLib_Instrument::NPV(ObjectId_any);
        // return value
        IDL_double returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlInstrumentNPV:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlYieldTSDiscount(const IDL_any &ObjectId_any, const IDL_any &Date_any) {
    try {
        QuantLib::DiscountFactor returnValue;
        returnValue = QuantLib_YieldTermStructure::discount(ObjectId_any, Date_any);
        // return value
        IDL_double returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlYieldTSDiscount:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlInstrumentIsExpired(const IDL_any &ObjectId_any) {
    try {
        bool returnValue;
        returnValue = QuantLib_Instrument::isExpired(ObjectId_any);
        // return value
        IDL_long returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlInstrumentIsExpired:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlDefaultTSDefaultProbability(const IDL_any &ObjectId_any, const IDL_any &Date_any, const IDL_any &Extrapolate_any) {
    try {
        QuantLib::Probability returnValue;
        returnValue = QuantLib_DefaultProbabilityTermStructure::defaultProbability(ObjectId_any, Date_any, Extrapolate_any);
        // return value
        IDL_double returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlDefaultTSDefaultProbability:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlCalendarName(const IDL_any &ObjectId_any) {
    try {
        std::string returnValue;
        returnValue = QuantLib_Calendar::name(ObjectId_any);
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlCalendarName:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlCalendarIsHoliday(const IDL_any &ObjectId_any, const IDL_any &Date_any) {
    try {
        bool returnValue;
        returnValue = QuantLib_Calendar::isHoliday(ObjectId_any, Date_any);
        // return value
        IDL_long returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlCalendarIsHoliday:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlDefaultTSDefaultDensity(const IDL_any &ObjectId_any, const IDL_any &Date_any, const IDL_any &Extrapolate_any) {
    try {
        QuantLib::Probability returnValue;
        returnValue = QuantLib_DefaultProbabilityTermStructure::defaultDensity(ObjectId_any, Date_any, Extrapolate_any);
        // return value
        IDL_double returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlDefaultTSDefaultDensity:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlCalendarIsBusinessDay(const IDL_any &ObjectId_any, const IDL_any &Date_any) {
    try {
        bool returnValue;
        returnValue = QuantLib_Calendar::isBusinessDay(ObjectId_any, Date_any);
        // return value
        IDL_long returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlCalendarIsBusinessDay:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlDayCounterDayCount(const IDL_any &ObjectId_any, const IDL_any &StartDate_any, const IDL_any &EndDate_any) {
    try {
        QuantLib::BigInteger returnValue;
        returnValue = QuantLib_DayCounter::dayCount(ObjectId_any, StartDate_any, EndDate_any);
        // return value
        IDL_long returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlDayCounterDayCount:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlDayCounterName(const IDL_any &ObjectId_any) {
    try {
        std::string returnValue;
        returnValue = QuantLib_DayCounter::name(ObjectId_any);
        // return value
        IDL_string returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, convertToIdl);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlDayCounterName:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlScheduleDates(const IDL_any &ObjectId_any) {
    try {
        std::vector<QuantLib::Date> returnValue;
        returnValue = QuantLib_Schedule::dates(ObjectId_any);
        // return value
        SEQSEQ(IDL_long) returnValueCalc;
        interfaceFromCpp(returnValue, returnValueCalc, interfaceFromDate);
        SEQSEQ(IDL_any) returnValueAny;
        idlConversionToAny(returnValueCalc, returnValueAny);
        return returnValueAny;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlScheduleDates:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};
SEQSEQ(IDL_any) SAL_CALL CalcAddins_impl::qlSettingsSetEvaluationDate(const IDL_any &Date_any) {
    try {
        Addin_AddinSettings_setEvaluationDate(Date_any);
        std::string returnString=std::string("OK");
        SEQSEQ(IDL_any) retAnyArray;
        retAnyArray.realloc(1);
        SEQ(IDL_any) retAnyVector(1);
        IDL_string s = STRFROMASCII( returnString.c_str() );
        retAnyVector[0] = CSS::uno::makeAny( s );
        retAnyArray[0] = retAnyVector;
        return retAnyArray;
    } catch (const std::exception &e) {
        do {
            std::ostringstream errorMsg; 
            errorMsg << "ERROR: qlSettingsSetEvaluationDate:  " << e.what();
            SEQSEQ(IDL_any) retAnyArray;
            retAnyArray.realloc(1);
            SEQ(IDL_any) retAnyVector(1);
            IDL_string s = STRFROMASCII( errorMsg.str().c_str() );
            retAnyVector[0] = CSS::uno::makeAny( s );
            retAnyArray[0] = retAnyVector;
            return retAnyArray;
        } while (false);
    }
};




// addin constructor and helper functions

CalcAddins_impl::CalcAddins_impl() throw ()  {
    Addin::initializeAddin();

funcMap[STRFROMANSI("qlGeneralizedBlackScholesProcess")] = STRFROMANSI("qlGeneralizedBlackScholesProcess");
funcDesc[STRFROMANSI("qlGeneralizedBlackScholesProcess")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlGeneralizedBlackScholesProcess")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlGeneralizedBlackScholesProcess")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlGeneralizedBlackScholesProcess")].push_back(STRFROMANSI("Quote"));
argDesc[STRFROMANSI("qlGeneralizedBlackScholesProcess")].push_back(STRFROMANSI("QuantLib::Quote"));
argName[STRFROMANSI("qlGeneralizedBlackScholesProcess")].push_back(STRFROMANSI("DividendTS"));
argDesc[STRFROMANSI("qlGeneralizedBlackScholesProcess")].push_back(STRFROMANSI("QuantLib::YieldTermStructure"));
argName[STRFROMANSI("qlGeneralizedBlackScholesProcess")].push_back(STRFROMANSI("RiskFreeTS"));
argDesc[STRFROMANSI("qlGeneralizedBlackScholesProcess")].push_back(STRFROMANSI("QuantLib::YieldTermStructure"));
argName[STRFROMANSI("qlGeneralizedBlackScholesProcess")].push_back(STRFROMANSI("BlackVolTS"));
argDesc[STRFROMANSI("qlGeneralizedBlackScholesProcess")].push_back(STRFROMANSI("QuantLib::BlackVolTermStructure"));
funcMap[STRFROMANSI("qlUpfrontCdsHelper")] = STRFROMANSI("qlUpfrontCdsHelper");
funcDesc[STRFROMANSI("qlUpfrontCdsHelper")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("Upfront"));
argDesc[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("QuantLib::Rate"));
argName[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("RunningSpread"));
argDesc[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("QuantLib::Rate"));
argName[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("Tenor"));
argDesc[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("QuantLib::Period"));
argName[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("SettlementDays"));
argDesc[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("QuantLib::Integer"));
argName[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("Calendar"));
argDesc[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("QuantLib::Calendar"));
argName[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("Frequency"));
argDesc[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("QuantLib::Frequency"));
argName[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("PaymentConvention"));
argDesc[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("QuantLib::BusinessDayConvention"));
argName[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("Rule"));
argDesc[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("QuantLib::DateGeneration::Rule"));
argName[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("DayCounter"));
argDesc[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("QuantLib::DayCounter"));
argName[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("RecoveryRate"));
argDesc[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("QuantLib::Real"));
argName[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("DiscountCurve"));
argDesc[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("QuantLib::YieldTermStructure"));
argName[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("UpfrontSettlementDays"));
argDesc[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("QuantLib::Natural"));
argName[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("SettlesAccrual"));
argDesc[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("bool (default value true)"));
argName[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("PaysAtDefaultTime"));
argDesc[STRFROMANSI("qlUpfrontCdsHelper")].push_back(STRFROMANSI("bool (default value true)"));
funcMap[STRFROMANSI("qlZeroCurve")] = STRFROMANSI("qlZeroCurve");
funcDesc[STRFROMANSI("qlZeroCurve")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlZeroCurve")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlZeroCurve")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlZeroCurve")].push_back(STRFROMANSI("Dates"));
argDesc[STRFROMANSI("qlZeroCurve")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlZeroCurve")].push_back(STRFROMANSI("ZeroRates"));
argDesc[STRFROMANSI("qlZeroCurve")].push_back(STRFROMANSI("QuantLib::Real"));
argName[STRFROMANSI("qlZeroCurve")].push_back(STRFROMANSI("DayCounterDayCounter"));
argDesc[STRFROMANSI("qlZeroCurve")].push_back(STRFROMANSI("QuantLib::DayCounter (default value QuantLib::Actual365Fixed())"));
funcMap[STRFROMANSI("qlInterpolation2D")] = STRFROMANSI("qlInterpolation2D");
funcDesc[STRFROMANSI("qlInterpolation2D")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlInterpolation2D")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlInterpolation2D")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlInterpolation2D")].push_back(STRFROMANSI("Interpolator2DID"));
argDesc[STRFROMANSI("qlInterpolation2D")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlInterpolation2D")].push_back(STRFROMANSI("XVector"));
argDesc[STRFROMANSI("qlInterpolation2D")].push_back(STRFROMANSI("QuantLib::Real"));
argName[STRFROMANSI("qlInterpolation2D")].push_back(STRFROMANSI("YVector"));
argDesc[STRFROMANSI("qlInterpolation2D")].push_back(STRFROMANSI("QuantLib::Real"));
argName[STRFROMANSI("qlInterpolation2D")].push_back(STRFROMANSI("ZData"));
argDesc[STRFROMANSI("qlInterpolation2D")].push_back(STRFROMANSI("QuantLib::Matrix"));
funcMap[STRFROMANSI("qlInterpolatedHazardRateCurve")] = STRFROMANSI("qlInterpolatedHazardRateCurve");
funcDesc[STRFROMANSI("qlInterpolatedHazardRateCurve")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlInterpolatedHazardRateCurve")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlInterpolatedHazardRateCurve")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlInterpolatedHazardRateCurve")].push_back(STRFROMANSI("Interpolator"));
argDesc[STRFROMANSI("qlInterpolatedHazardRateCurve")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlInterpolatedHazardRateCurve")].push_back(STRFROMANSI("Dates"));
argDesc[STRFROMANSI("qlInterpolatedHazardRateCurve")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlInterpolatedHazardRateCurve")].push_back(STRFROMANSI("HazardRates"));
argDesc[STRFROMANSI("qlInterpolatedHazardRateCurve")].push_back(STRFROMANSI("QuantLib::Rate"));
argName[STRFROMANSI("qlInterpolatedHazardRateCurve")].push_back(STRFROMANSI("DayCounter"));
argDesc[STRFROMANSI("qlInterpolatedHazardRateCurve")].push_back(STRFROMANSI("QuantLib::DayCounter"));
argName[STRFROMANSI("qlInterpolatedHazardRateCurve")].push_back(STRFROMANSI("Calendar"));
argDesc[STRFROMANSI("qlInterpolatedHazardRateCurve")].push_back(STRFROMANSI("QuantLib::Calendar"));
funcMap[STRFROMANSI("qlSpreadCdsHelper")] = STRFROMANSI("qlSpreadCdsHelper");
funcDesc[STRFROMANSI("qlSpreadCdsHelper")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("RunningSpread"));
argDesc[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("QuantLib::Rate"));
argName[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("Tenor"));
argDesc[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("QuantLib::Period"));
argName[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("SettlementDays"));
argDesc[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("QuantLib::Integer"));
argName[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("Calendar"));
argDesc[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("QuantLib::Calendar"));
argName[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("Frequency"));
argDesc[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("QuantLib::Frequency"));
argName[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("PaymentConvention"));
argDesc[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("QuantLib::BusinessDayConvention"));
argName[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("Rule"));
argDesc[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("QuantLib::DateGeneration::Rule"));
argName[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("DayCounter"));
argDesc[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("QuantLib::DayCounter"));
argName[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("RecoveryRate"));
argDesc[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("QuantLib::Real"));
argName[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("DiscountCurve"));
argDesc[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("QuantLib::YieldTermStructure"));
argName[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("SettlesAccrual"));
argDesc[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("bool (default value true)"));
argName[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("PaysAtDefaultTime"));
argDesc[STRFROMANSI("qlSpreadCdsHelper")].push_back(STRFROMANSI("bool (default value true)"));
funcMap[STRFROMANSI("qlPlainVanillaPayoff")] = STRFROMANSI("qlPlainVanillaPayoff");
funcDesc[STRFROMANSI("qlPlainVanillaPayoff")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlPlainVanillaPayoff")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlPlainVanillaPayoff")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlPlainVanillaPayoff")].push_back(STRFROMANSI("OptionType"));
argDesc[STRFROMANSI("qlPlainVanillaPayoff")].push_back(STRFROMANSI("QuantLib::Option::Type"));
argName[STRFROMANSI("qlPlainVanillaPayoff")].push_back(STRFROMANSI("Strike"));
argDesc[STRFROMANSI("qlPlainVanillaPayoff")].push_back(STRFROMANSI("QuantLib::Real"));
funcMap[STRFROMANSI("qlPiecewiseDefaultCurve")] = STRFROMANSI("qlPiecewiseDefaultCurve");
funcDesc[STRFROMANSI("qlPiecewiseDefaultCurve")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlPiecewiseDefaultCurve")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlPiecewiseDefaultCurve")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlPiecewiseDefaultCurve")].push_back(STRFROMANSI("Traits"));
argDesc[STRFROMANSI("qlPiecewiseDefaultCurve")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlPiecewiseDefaultCurve")].push_back(STRFROMANSI("Interpolator"));
argDesc[STRFROMANSI("qlPiecewiseDefaultCurve")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlPiecewiseDefaultCurve")].push_back(STRFROMANSI("ReferenceDate"));
argDesc[STRFROMANSI("qlPiecewiseDefaultCurve")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlPiecewiseDefaultCurve")].push_back(STRFROMANSI("BootstrapInstruments"));
argDesc[STRFROMANSI("qlPiecewiseDefaultCurve")].push_back(STRFROMANSI("QuantLib::BootstrapHelper<QuantLib::DefaultProbabilityTermStructure>"));
argName[STRFROMANSI("qlPiecewiseDefaultCurve")].push_back(STRFROMANSI("DayCounter"));
argDesc[STRFROMANSI("qlPiecewiseDefaultCurve")].push_back(STRFROMANSI("QuantLib::DayCounter"));
argName[STRFROMANSI("qlPiecewiseDefaultCurve")].push_back(STRFROMANSI("Accuracy"));
argDesc[STRFROMANSI("qlPiecewiseDefaultCurve")].push_back(STRFROMANSI("QuantLib::Real"));
funcMap[STRFROMANSI("qlAnalyticEuropeanEngine")] = STRFROMANSI("qlAnalyticEuropeanEngine");
funcDesc[STRFROMANSI("qlAnalyticEuropeanEngine")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlAnalyticEuropeanEngine")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlAnalyticEuropeanEngine")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlAnalyticEuropeanEngine")].push_back(STRFROMANSI("GeneralizedBlackSchlolesProcess"));
argDesc[STRFROMANSI("qlAnalyticEuropeanEngine")].push_back(STRFROMANSI("QuantLib::GeneralizedBlackScholesProcess"));
funcMap[STRFROMANSI("qlEuropeanExercise")] = STRFROMANSI("qlEuropeanExercise");
funcDesc[STRFROMANSI("qlEuropeanExercise")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlEuropeanExercise")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlEuropeanExercise")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlEuropeanExercise")].push_back(STRFROMANSI("ExerciseDate"));
argDesc[STRFROMANSI("qlEuropeanExercise")].push_back(STRFROMANSI("QuantLib::Date"));
funcMap[STRFROMANSI("qlFloatingRateBond")] = STRFROMANSI("qlFloatingRateBond");
funcDesc[STRFROMANSI("qlFloatingRateBond")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("SettlementDays"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("QuantLib::Natural"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("faceAmount"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("QuantLib::Real"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("StartDate"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("MaturityDate"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("CouponFrequency"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("QuantLib::Frequency"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("Calendar"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("QuantLib::Calendar"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("IborIndex"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("QuantLib::IborIndex"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("AccrualDayCounter"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("QuantLib::DayCounter"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("AccrualConvention"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("QuantLib::BusinessDayConvention (default value QuantLib::Following)"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("PaymentConvention"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("QuantLib::BusinessDayConvention (default value QuantLib::Following)"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("FixingDays"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("QuantLib::Natural (default value QuantLib::Null<QuantLib::Natural>())"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("Gearings"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("QuantLib::Real (default value std::vector<QuantLib::Real>(1, 1.0))"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("Spreads"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("QuantLib::Spread (default value std::vector<QuantLib::Spread>(1, 0.0))"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("Caps"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("QuantLib::Rate (default value std::vector<QuantLib::Rate>())"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("Floors"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("QuantLib::Rate (default value std::vector<QuantLib::Rate>())"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("InArrears"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("bool (default value false)"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("Redemption"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("QuantLib::Real (default value 100.0)"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("IssueDate"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("QuantLib::Date (default value QuantLib::Date())"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("StubDate"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("QuantLib::Date (default value QuantLib::Date())"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("Rule"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("QuantLib::DateGeneration::Rule (default value QuantLib::DateGeneration::Backward)"));
argName[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("EndOfMonth"));
argDesc[STRFROMANSI("qlFloatingRateBond")].push_back(STRFROMANSI("bool (default value false)"));
funcMap[STRFROMANSI("qlEuribor365")] = STRFROMANSI("qlEuribor365");
funcDesc[STRFROMANSI("qlEuribor365")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlEuribor365")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlEuribor365")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlEuribor365")].push_back(STRFROMANSI("Tenor"));
argDesc[STRFROMANSI("qlEuribor365")].push_back(STRFROMANSI("QuantLib::Period"));
argName[STRFROMANSI("qlEuribor365")].push_back(STRFROMANSI("ForwardCurve"));
argDesc[STRFROMANSI("qlEuribor365")].push_back(STRFROMANSI("QuantLib::YieldTermStructure (default value QuantLib::Handle<QuantLib::YieldTermStructure>())"));
funcMap[STRFROMANSI("qlSwapRateHelper")] = STRFROMANSI("qlSwapRateHelper");
funcDesc[STRFROMANSI("qlSwapRateHelper")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("Rate"));
argDesc[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("QuantLib::Rate"));
argName[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("Tenor"));
argDesc[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("QuantLib::Period"));
argName[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("Calendar"));
argDesc[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("QuantLib::Calendar"));
argName[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("FixedFrequency"));
argDesc[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("QuantLib::Frequency"));
argName[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("FixedConvention"));
argDesc[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("QuantLib::BusinessDayConvention"));
argName[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("FixedDayCounter"));
argDesc[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("QuantLib::DayCounter"));
argName[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("IborIndex"));
argDesc[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("QuantLib::IborIndex"));
argName[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("Spread"));
argDesc[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("QuantLib::Quote"));
argName[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("FwdStartPeriod"));
argDesc[STRFROMANSI("qlSwapRateHelper")].push_back(STRFROMANSI("QuantLib::Period"));
funcMap[STRFROMANSI("qlDepositRateHelper")] = STRFROMANSI("qlDepositRateHelper");
funcDesc[STRFROMANSI("qlDepositRateHelper")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlDepositRateHelper")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlDepositRateHelper")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlDepositRateHelper")].push_back(STRFROMANSI("Rate"));
argDesc[STRFROMANSI("qlDepositRateHelper")].push_back(STRFROMANSI("QuantLib::Rate"));
argName[STRFROMANSI("qlDepositRateHelper")].push_back(STRFROMANSI("Period"));
argDesc[STRFROMANSI("qlDepositRateHelper")].push_back(STRFROMANSI("QuantLib::Period"));
argName[STRFROMANSI("qlDepositRateHelper")].push_back(STRFROMANSI("FixingDays"));
argDesc[STRFROMANSI("qlDepositRateHelper")].push_back(STRFROMANSI("QuantLib::Natural"));
argName[STRFROMANSI("qlDepositRateHelper")].push_back(STRFROMANSI("Calendar"));
argDesc[STRFROMANSI("qlDepositRateHelper")].push_back(STRFROMANSI("QuantLib::Calendar"));
argName[STRFROMANSI("qlDepositRateHelper")].push_back(STRFROMANSI("BusinessDayConvention"));
argDesc[STRFROMANSI("qlDepositRateHelper")].push_back(STRFROMANSI("QuantLib::BusinessDayConvention"));
argName[STRFROMANSI("qlDepositRateHelper")].push_back(STRFROMANSI("EndOfMonth"));
argDesc[STRFROMANSI("qlDepositRateHelper")].push_back(STRFROMANSI("bool"));
argName[STRFROMANSI("qlDepositRateHelper")].push_back(STRFROMANSI("DayCounter"));
argDesc[STRFROMANSI("qlDepositRateHelper")].push_back(STRFROMANSI("QuantLib::DayCounter"));
funcMap[STRFROMANSI("qlEuribor")] = STRFROMANSI("qlEuribor");
funcDesc[STRFROMANSI("qlEuribor")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlEuribor")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlEuribor")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlEuribor")].push_back(STRFROMANSI("Tenor"));
argDesc[STRFROMANSI("qlEuribor")].push_back(STRFROMANSI("QuantLib::Period"));
argName[STRFROMANSI("qlEuribor")].push_back(STRFROMANSI("ForwardCurve"));
argDesc[STRFROMANSI("qlEuribor")].push_back(STRFROMANSI("QuantLib::YieldTermStructure (default value QuantLib::Handle<QuantLib::YieldTermStructure>())"));
funcMap[STRFROMANSI("qlInterpolation1D")] = STRFROMANSI("qlInterpolation1D");
funcDesc[STRFROMANSI("qlInterpolation1D")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlInterpolation1D")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlInterpolation1D")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlInterpolation1D")].push_back(STRFROMANSI("Interpolator1DID"));
argDesc[STRFROMANSI("qlInterpolation1D")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlInterpolation1D")].push_back(STRFROMANSI("XVector"));
argDesc[STRFROMANSI("qlInterpolation1D")].push_back(STRFROMANSI("QuantLib::Real"));
argName[STRFROMANSI("qlInterpolation1D")].push_back(STRFROMANSI("YVector"));
argDesc[STRFROMANSI("qlInterpolation1D")].push_back(STRFROMANSI("QuantLib::Real"));
funcMap[STRFROMANSI("qlSchedule")] = STRFROMANSI("qlSchedule");
funcDesc[STRFROMANSI("qlSchedule")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("EffectiveDate"));
argDesc[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("TerminationDate"));
argDesc[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("Period"));
argDesc[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("QuantLib::Period"));
argName[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("Calendar"));
argDesc[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("QuantLib::Calendar"));
argName[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("Convention"));
argDesc[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("QuantLib::BusinessDayConvention"));
argName[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("TerminationConvention"));
argDesc[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("QuantLib::BusinessDayConvention"));
argName[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("Rule"));
argDesc[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("QuantLib::DateGeneration::Rule"));
argName[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("EndOfMonth"));
argDesc[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("bool (default value 0)"));
argName[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("FirstDate"));
argDesc[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("NextToLastDate"));
argDesc[STRFROMANSI("qlSchedule")].push_back(STRFROMANSI("QuantLib::Date"));
funcMap[STRFROMANSI("qlFuturesRateHelper")] = STRFROMANSI("qlFuturesRateHelper");
funcDesc[STRFROMANSI("qlFuturesRateHelper")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlFuturesRateHelper")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlFuturesRateHelper")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlFuturesRateHelper")].push_back(STRFROMANSI("Price"));
argDesc[STRFROMANSI("qlFuturesRateHelper")].push_back(STRFROMANSI("QuantLib::Real"));
argName[STRFROMANSI("qlFuturesRateHelper")].push_back(STRFROMANSI("IborStartDate"));
argDesc[STRFROMANSI("qlFuturesRateHelper")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlFuturesRateHelper")].push_back(STRFROMANSI("IborIndex"));
argDesc[STRFROMANSI("qlFuturesRateHelper")].push_back(STRFROMANSI("QuantLib::IborIndex"));
argName[STRFROMANSI("qlFuturesRateHelper")].push_back(STRFROMANSI("ConvexityAdjustment"));
argDesc[STRFROMANSI("qlFuturesRateHelper")].push_back(STRFROMANSI("QuantLib::Rate"));
argName[STRFROMANSI("qlFuturesRateHelper")].push_back(STRFROMANSI("Type"));
argDesc[STRFROMANSI("qlFuturesRateHelper")].push_back(STRFROMANSI("QuantLib::Futures::Type"));
funcMap[STRFROMANSI("qlSimpleQuote")] = STRFROMANSI("qlSimpleQuote");
funcDesc[STRFROMANSI("qlSimpleQuote")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlSimpleQuote")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlSimpleQuote")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlSimpleQuote")].push_back(STRFROMANSI("Value"));
argDesc[STRFROMANSI("qlSimpleQuote")].push_back(STRFROMANSI("QuantLib::Real"));
funcMap[STRFROMANSI("qlFraRateHelper")] = STRFROMANSI("qlFraRateHelper");
funcDesc[STRFROMANSI("qlFraRateHelper")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("Rate"));
argDesc[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("QuantLib::Rate"));
argName[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("MonthsToStart"));
argDesc[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("QuantLib::Natural"));
argName[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("MonthsToEnd"));
argDesc[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("QuantLib::Natural"));
argName[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("FixingDays"));
argDesc[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("QuantLib::Natural"));
argName[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("Calendar"));
argDesc[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("QuantLib::Calendar"));
argName[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("Convention"));
argDesc[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("QuantLib::BusinessDayConvention"));
argName[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("EndOfMonth"));
argDesc[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("bool"));
argName[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("DayCounter"));
argDesc[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("QuantLib::DayCounter"));
argName[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("Pillar"));
argDesc[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("QuantLib::Pillar::Choice"));
argName[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("CustomPillarDate"));
argDesc[STRFROMANSI("qlFraRateHelper")].push_back(STRFROMANSI("QuantLib::Date"));
funcMap[STRFROMANSI("qlDiscountCurve")] = STRFROMANSI("qlDiscountCurve");
funcDesc[STRFROMANSI("qlDiscountCurve")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlDiscountCurve")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlDiscountCurve")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlDiscountCurve")].push_back(STRFROMANSI("Dates"));
argDesc[STRFROMANSI("qlDiscountCurve")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlDiscountCurve")].push_back(STRFROMANSI("Discounts"));
argDesc[STRFROMANSI("qlDiscountCurve")].push_back(STRFROMANSI("QuantLib::Real"));
argName[STRFROMANSI("qlDiscountCurve")].push_back(STRFROMANSI("DayCounter"));
argDesc[STRFROMANSI("qlDiscountCurve")].push_back(STRFROMANSI("QuantLib::DayCounter (default value QuantLib::Actual365Fixed())"));
funcMap[STRFROMANSI("qlBlackVarianceSurface")] = STRFROMANSI("qlBlackVarianceSurface");
funcDesc[STRFROMANSI("qlBlackVarianceSurface")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlBlackVarianceSurface")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlBlackVarianceSurface")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlBlackVarianceSurface")].push_back(STRFROMANSI("ReferenceDate"));
argDesc[STRFROMANSI("qlBlackVarianceSurface")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlBlackVarianceSurface")].push_back(STRFROMANSI("Calendar"));
argDesc[STRFROMANSI("qlBlackVarianceSurface")].push_back(STRFROMANSI("QuantLib::Calendar"));
argName[STRFROMANSI("qlBlackVarianceSurface")].push_back(STRFROMANSI("Dates"));
argDesc[STRFROMANSI("qlBlackVarianceSurface")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlBlackVarianceSurface")].push_back(STRFROMANSI("Strikes"));
argDesc[STRFROMANSI("qlBlackVarianceSurface")].push_back(STRFROMANSI("QuantLib::Real"));
argName[STRFROMANSI("qlBlackVarianceSurface")].push_back(STRFROMANSI("BlackVolMatrix"));
argDesc[STRFROMANSI("qlBlackVarianceSurface")].push_back(STRFROMANSI("QuantLib::Matrix"));
argName[STRFROMANSI("qlBlackVarianceSurface")].push_back(STRFROMANSI("DayCounter"));
argDesc[STRFROMANSI("qlBlackVarianceSurface")].push_back(STRFROMANSI("QuantLib::DayCounter"));
argName[STRFROMANSI("qlBlackVarianceSurface")].push_back(STRFROMANSI("LowerExtrapolation"));
argDesc[STRFROMANSI("qlBlackVarianceSurface")].push_back(STRFROMANSI("QuantLib::BlackVarianceSurface::Extrapolation"));
argName[STRFROMANSI("qlBlackVarianceSurface")].push_back(STRFROMANSI("UpperExtrapolation"));
argDesc[STRFROMANSI("qlBlackVarianceSurface")].push_back(STRFROMANSI("QuantLib::BlackVarianceSurface::Extrapolation"));
funcMap[STRFROMANSI("qlPiecewiseYieldCurve")] = STRFROMANSI("qlPiecewiseYieldCurve");
funcDesc[STRFROMANSI("qlPiecewiseYieldCurve")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlPiecewiseYieldCurve")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlPiecewiseYieldCurve")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlPiecewiseYieldCurve")].push_back(STRFROMANSI("Traits"));
argDesc[STRFROMANSI("qlPiecewiseYieldCurve")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlPiecewiseYieldCurve")].push_back(STRFROMANSI("Interpolator"));
argDesc[STRFROMANSI("qlPiecewiseYieldCurve")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlPiecewiseYieldCurve")].push_back(STRFROMANSI("ReferenceDate"));
argDesc[STRFROMANSI("qlPiecewiseYieldCurve")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlPiecewiseYieldCurve")].push_back(STRFROMANSI("BootstrapInstruments"));
argDesc[STRFROMANSI("qlPiecewiseYieldCurve")].push_back(STRFROMANSI("QuantLib::BootstrapHelper<QuantLib::YieldTermStructure>"));
argName[STRFROMANSI("qlPiecewiseYieldCurve")].push_back(STRFROMANSI("DayCounter"));
argDesc[STRFROMANSI("qlPiecewiseYieldCurve")].push_back(STRFROMANSI("QuantLib::DayCounter"));
argName[STRFROMANSI("qlPiecewiseYieldCurve")].push_back(STRFROMANSI("Accuracy"));
argDesc[STRFROMANSI("qlPiecewiseYieldCurve")].push_back(STRFROMANSI("QuantLib::Real"));
funcMap[STRFROMANSI("qlVanillaOption")] = STRFROMANSI("qlVanillaOption");
funcDesc[STRFROMANSI("qlVanillaOption")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlVanillaOption")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlVanillaOption")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlVanillaOption")].push_back(STRFROMANSI("StrikedTypePayoff"));
argDesc[STRFROMANSI("qlVanillaOption")].push_back(STRFROMANSI("QuantLib::StrikedTypePayoff"));
argName[STRFROMANSI("qlVanillaOption")].push_back(STRFROMANSI("Exercise"));
argDesc[STRFROMANSI("qlVanillaOption")].push_back(STRFROMANSI("QuantLib::Exercise"));
funcMap[STRFROMANSI("qlFixedRateBond")] = STRFROMANSI("qlFixedRateBond");
funcDesc[STRFROMANSI("qlFixedRateBond")] = STRFROMANSI("Consructor.");
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("SettlementDays"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("QuantLib::Natural"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("CouponCalendar"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("QuantLib::Calendar"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("FaceAmount"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("QuantLib::Real"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("StartDate"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("MaturityDate"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("Tenor"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("QuantLib::Period"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("Coupons"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("QuantLib::Rate"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("AccrualDayCounter"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("QuantLib::DayCounter"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("AccrualConvention"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("QuantLib::BusinessDayConvention (default value QuantLib::Following)"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("PaymentConvention"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("QuantLib::BusinessDayConvention (default value QuantLib::Following)"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("Redemption"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("QuantLib::Real (default value 100.0)"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("IssueDate"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("QuantLib::Date (default value QuantLib::Date())"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("StubDate"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("QuantLib::Date (default value QuantLib::Date())"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("Rule"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("QuantLib::DateGeneration::Rule (default value QuantLib::DateGeneration::Backward)"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("EndOfMonth"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("bool (default value false)"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("PaymentCalendar"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("QuantLib::Calendar (default value QuantLib::Calendar())"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("ExCouponPeriod"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("QuantLib::Period (default value QuantLib::Period())"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("ExCouponCalendar"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("QuantLib::Calendar (default value QuantLib::Calendar())"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("ExCouponConvention"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("QuantLib::BusinessDayConvention (default value QuantLib::Unadjusted)"));
argName[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("ExCouponEndOfMonth"));
argDesc[STRFROMANSI("qlFixedRateBond")].push_back(STRFROMANSI("bool (default value false)"));
funcMap[STRFROMANSI("qlBlackVolTermStructureBlackVol")] = STRFROMANSI("qlBlackVolTermStructureBlackVol");
funcDesc[STRFROMANSI("qlBlackVolTermStructureBlackVol")] = STRFROMANSI("return type: QuantLib::Volatility.");
argName[STRFROMANSI("qlBlackVolTermStructureBlackVol")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlBlackVolTermStructureBlackVol")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlBlackVolTermStructureBlackVol")].push_back(STRFROMANSI("Maturity"));
argDesc[STRFROMANSI("qlBlackVolTermStructureBlackVol")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlBlackVolTermStructureBlackVol")].push_back(STRFROMANSI("Strike"));
argDesc[STRFROMANSI("qlBlackVolTermStructureBlackVol")].push_back(STRFROMANSI("QuantLib::Real"));
argName[STRFROMANSI("qlBlackVolTermStructureBlackVol")].push_back(STRFROMANSI("Extrapolate"));
argDesc[STRFROMANSI("qlBlackVolTermStructureBlackVol")].push_back(STRFROMANSI("bool"));
funcMap[STRFROMANSI("qlDefaultTSHazardRate")] = STRFROMANSI("qlDefaultTSHazardRate");
funcDesc[STRFROMANSI("qlDefaultTSHazardRate")] = STRFROMANSI("return type: QuantLib::Probability.");
argName[STRFROMANSI("qlDefaultTSHazardRate")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlDefaultTSHazardRate")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlDefaultTSHazardRate")].push_back(STRFROMANSI("Date"));
argDesc[STRFROMANSI("qlDefaultTSHazardRate")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlDefaultTSHazardRate")].push_back(STRFROMANSI("Extrapolate"));
argDesc[STRFROMANSI("qlDefaultTSHazardRate")].push_back(STRFROMANSI("bool (default value false)"));
funcMap[STRFROMANSI("qlInterpolatedValue2D")] = STRFROMANSI("qlInterpolatedValue2D");
funcDesc[STRFROMANSI("qlInterpolatedValue2D")] = STRFROMANSI("return type: QuantLib::Real.");
argName[STRFROMANSI("qlInterpolatedValue2D")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlInterpolatedValue2D")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlInterpolatedValue2D")].push_back(STRFROMANSI("X"));
argDesc[STRFROMANSI("qlInterpolatedValue2D")].push_back(STRFROMANSI("QuantLib::Real"));
argName[STRFROMANSI("qlInterpolatedValue2D")].push_back(STRFROMANSI("Y"));
argDesc[STRFROMANSI("qlInterpolatedValue2D")].push_back(STRFROMANSI("QuantLib::Real"));
argName[STRFROMANSI("qlInterpolatedValue2D")].push_back(STRFROMANSI("Extrapolate"));
argDesc[STRFROMANSI("qlInterpolatedValue2D")].push_back(STRFROMANSI("bool"));
funcMap[STRFROMANSI("qlQuoteValue")] = STRFROMANSI("qlQuoteValue");
funcDesc[STRFROMANSI("qlQuoteValue")] = STRFROMANSI("return type: QuantLib::Real.");
argName[STRFROMANSI("qlQuoteValue")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlQuoteValue")].push_back(STRFROMANSI("std::string"));
funcMap[STRFROMANSI("qlDayCounterYearFraction")] = STRFROMANSI("qlDayCounterYearFraction");
funcDesc[STRFROMANSI("qlDayCounterYearFraction")] = STRFROMANSI("return type: double.");
argName[STRFROMANSI("qlDayCounterYearFraction")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlDayCounterYearFraction")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlDayCounterYearFraction")].push_back(STRFROMANSI("StartDate"));
argDesc[STRFROMANSI("qlDayCounterYearFraction")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlDayCounterYearFraction")].push_back(STRFROMANSI("EndDate"));
argDesc[STRFROMANSI("qlDayCounterYearFraction")].push_back(STRFROMANSI("QuantLib::Date"));
funcMap[STRFROMANSI("qlCalendarAdvance")] = STRFROMANSI("qlCalendarAdvance");
funcDesc[STRFROMANSI("qlCalendarAdvance")] = STRFROMANSI("return type: QuantLib::Date.");
argName[STRFROMANSI("qlCalendarAdvance")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlCalendarAdvance")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlCalendarAdvance")].push_back(STRFROMANSI("StartDate"));
argDesc[STRFROMANSI("qlCalendarAdvance")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlCalendarAdvance")].push_back(STRFROMANSI("Period"));
argDesc[STRFROMANSI("qlCalendarAdvance")].push_back(STRFROMANSI("QuantLib::Period"));
argName[STRFROMANSI("qlCalendarAdvance")].push_back(STRFROMANSI("BusinessDayConvention"));
argDesc[STRFROMANSI("qlCalendarAdvance")].push_back(STRFROMANSI("QuantLib::BusinessDayConvention"));
argName[STRFROMANSI("qlCalendarAdvance")].push_back(STRFROMANSI("EndOfMonth"));
argDesc[STRFROMANSI("qlCalendarAdvance")].push_back(STRFROMANSI("bool"));
funcMap[STRFROMANSI("qlDefaultTSSurvivalProbability")] = STRFROMANSI("qlDefaultTSSurvivalProbability");
funcDesc[STRFROMANSI("qlDefaultTSSurvivalProbability")] = STRFROMANSI("return type: QuantLib::Probability.");
argName[STRFROMANSI("qlDefaultTSSurvivalProbability")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlDefaultTSSurvivalProbability")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlDefaultTSSurvivalProbability")].push_back(STRFROMANSI("Date"));
argDesc[STRFROMANSI("qlDefaultTSSurvivalProbability")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlDefaultTSSurvivalProbability")].push_back(STRFROMANSI("Extrapolate"));
argDesc[STRFROMANSI("qlDefaultTSSurvivalProbability")].push_back(STRFROMANSI("bool (default value false)"));
funcMap[STRFROMANSI("qlInstrumentSetPricingEngine")] = STRFROMANSI("qlInstrumentSetPricingEngine");
funcDesc[STRFROMANSI("qlInstrumentSetPricingEngine")] = STRFROMANSI("return type: void.");
argName[STRFROMANSI("qlInstrumentSetPricingEngine")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlInstrumentSetPricingEngine")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlInstrumentSetPricingEngine")].push_back(STRFROMANSI("PricingEngine"));
argDesc[STRFROMANSI("qlInstrumentSetPricingEngine")].push_back(STRFROMANSI("QuantLib::PricingEngine"));
funcMap[STRFROMANSI("qlInterpolatedValue1D")] = STRFROMANSI("qlInterpolatedValue1D");
funcDesc[STRFROMANSI("qlInterpolatedValue1D")] = STRFROMANSI("return type: QuantLib::Real.");
argName[STRFROMANSI("qlInterpolatedValue1D")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlInterpolatedValue1D")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlInterpolatedValue1D")].push_back(STRFROMANSI("X"));
argDesc[STRFROMANSI("qlInterpolatedValue1D")].push_back(STRFROMANSI("QuantLib::Real"));
argName[STRFROMANSI("qlInterpolatedValue1D")].push_back(STRFROMANSI("Extrapolate"));
argDesc[STRFROMANSI("qlInterpolatedValue1D")].push_back(STRFROMANSI("bool"));
funcMap[STRFROMANSI("qlInstrumentNPV")] = STRFROMANSI("qlInstrumentNPV");
funcDesc[STRFROMANSI("qlInstrumentNPV")] = STRFROMANSI("return type: QuantLib::Real.");
argName[STRFROMANSI("qlInstrumentNPV")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlInstrumentNPV")].push_back(STRFROMANSI("std::string"));
funcMap[STRFROMANSI("qlYieldTSDiscount")] = STRFROMANSI("qlYieldTSDiscount");
funcDesc[STRFROMANSI("qlYieldTSDiscount")] = STRFROMANSI("return type: QuantLib::DiscountFactor.");
argName[STRFROMANSI("qlYieldTSDiscount")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlYieldTSDiscount")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlYieldTSDiscount")].push_back(STRFROMANSI("Date"));
argDesc[STRFROMANSI("qlYieldTSDiscount")].push_back(STRFROMANSI("QuantLib::Date"));
funcMap[STRFROMANSI("qlInstrumentIsExpired")] = STRFROMANSI("qlInstrumentIsExpired");
funcDesc[STRFROMANSI("qlInstrumentIsExpired")] = STRFROMANSI("return type: bool.");
argName[STRFROMANSI("qlInstrumentIsExpired")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlInstrumentIsExpired")].push_back(STRFROMANSI("std::string"));
funcMap[STRFROMANSI("qlDefaultTSDefaultProbability")] = STRFROMANSI("qlDefaultTSDefaultProbability");
funcDesc[STRFROMANSI("qlDefaultTSDefaultProbability")] = STRFROMANSI("return type: QuantLib::Probability.");
argName[STRFROMANSI("qlDefaultTSDefaultProbability")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlDefaultTSDefaultProbability")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlDefaultTSDefaultProbability")].push_back(STRFROMANSI("Date"));
argDesc[STRFROMANSI("qlDefaultTSDefaultProbability")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlDefaultTSDefaultProbability")].push_back(STRFROMANSI("Extrapolate"));
argDesc[STRFROMANSI("qlDefaultTSDefaultProbability")].push_back(STRFROMANSI("bool (default value false)"));
funcMap[STRFROMANSI("qlCalendarName")] = STRFROMANSI("qlCalendarName");
funcDesc[STRFROMANSI("qlCalendarName")] = STRFROMANSI("return type: std::string.");
argName[STRFROMANSI("qlCalendarName")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlCalendarName")].push_back(STRFROMANSI("std::string"));
funcMap[STRFROMANSI("qlCalendarIsHoliday")] = STRFROMANSI("qlCalendarIsHoliday");
funcDesc[STRFROMANSI("qlCalendarIsHoliday")] = STRFROMANSI("return type: bool.");
argName[STRFROMANSI("qlCalendarIsHoliday")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlCalendarIsHoliday")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlCalendarIsHoliday")].push_back(STRFROMANSI("Date"));
argDesc[STRFROMANSI("qlCalendarIsHoliday")].push_back(STRFROMANSI("QuantLib::Date"));
funcMap[STRFROMANSI("qlDefaultTSDefaultDensity")] = STRFROMANSI("qlDefaultTSDefaultDensity");
funcDesc[STRFROMANSI("qlDefaultTSDefaultDensity")] = STRFROMANSI("return type: QuantLib::Probability.");
argName[STRFROMANSI("qlDefaultTSDefaultDensity")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlDefaultTSDefaultDensity")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlDefaultTSDefaultDensity")].push_back(STRFROMANSI("Date"));
argDesc[STRFROMANSI("qlDefaultTSDefaultDensity")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlDefaultTSDefaultDensity")].push_back(STRFROMANSI("Extrapolate"));
argDesc[STRFROMANSI("qlDefaultTSDefaultDensity")].push_back(STRFROMANSI("bool (default value false)"));
funcMap[STRFROMANSI("qlCalendarIsBusinessDay")] = STRFROMANSI("qlCalendarIsBusinessDay");
funcDesc[STRFROMANSI("qlCalendarIsBusinessDay")] = STRFROMANSI("return type: bool.");
argName[STRFROMANSI("qlCalendarIsBusinessDay")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlCalendarIsBusinessDay")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlCalendarIsBusinessDay")].push_back(STRFROMANSI("Date"));
argDesc[STRFROMANSI("qlCalendarIsBusinessDay")].push_back(STRFROMANSI("QuantLib::Date"));
funcMap[STRFROMANSI("qlDayCounterDayCount")] = STRFROMANSI("qlDayCounterDayCount");
funcDesc[STRFROMANSI("qlDayCounterDayCount")] = STRFROMANSI("return type: QuantLib::BigInteger.");
argName[STRFROMANSI("qlDayCounterDayCount")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlDayCounterDayCount")].push_back(STRFROMANSI("std::string"));
argName[STRFROMANSI("qlDayCounterDayCount")].push_back(STRFROMANSI("StartDate"));
argDesc[STRFROMANSI("qlDayCounterDayCount")].push_back(STRFROMANSI("QuantLib::Date"));
argName[STRFROMANSI("qlDayCounterDayCount")].push_back(STRFROMANSI("EndDate"));
argDesc[STRFROMANSI("qlDayCounterDayCount")].push_back(STRFROMANSI("QuantLib::Date"));
funcMap[STRFROMANSI("qlDayCounterName")] = STRFROMANSI("qlDayCounterName");
funcDesc[STRFROMANSI("qlDayCounterName")] = STRFROMANSI("return type: std::string.");
argName[STRFROMANSI("qlDayCounterName")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlDayCounterName")].push_back(STRFROMANSI("std::string"));
funcMap[STRFROMANSI("qlScheduleDates")] = STRFROMANSI("qlScheduleDates");
funcDesc[STRFROMANSI("qlScheduleDates")] = STRFROMANSI("return type: std::vector<QuantLib::Date>.");
argName[STRFROMANSI("qlScheduleDates")].push_back(STRFROMANSI("ObjectId"));
argDesc[STRFROMANSI("qlScheduleDates")].push_back(STRFROMANSI("std::string"));
funcMap[STRFROMANSI("qlSettingsSetEvaluationDate")] = STRFROMANSI("qlSettingsSetEvaluationDate");
funcDesc[STRFROMANSI("qlSettingsSetEvaluationDate")] = STRFROMANSI("return type: void.");
argName[STRFROMANSI("qlSettingsSetEvaluationDate")].push_back(STRFROMANSI("Date"));
argDesc[STRFROMANSI("qlSettingsSetEvaluationDate")].push_back(STRFROMANSI("QuantLib::Date"));


}

// XAddIn
/*
 * Not used by Calc, so return an empty string
 */
OUString CalcAddins_impl::getProgrammaticFuntionName(
                      const OUString& aDisplayName) throw (RuntimeException) {
    return OUString(); // not used by calc ?
}

OUString CalcAddins_impl::getDisplayFunctionName(
                 const OUString& aProgrammaticName) throw (RuntimeException) {
    return funcMap[ aProgrammaticName ];
}

OUString CalcAddins_impl::getFunctionDescription(
                  const OUString& aProgrammaticName) throw (RuntimeException) {
    return funcDesc[ aProgrammaticName ];
}

OUString CalcAddins_impl::getDisplayArgumentName(
                     const OUString& aProgrammaticName, ::sal_Int32 nArgument) 
    throw (RuntimeException) {
    std::map< STRING, std::vector < STRING > >::const_iterator i =
        argName.find(aProgrammaticName);
    if (i == argName.end())
        return STRFROMASCII("no help available");
    else {
        std::vector < STRING >v = i->second;
        return v[nArgument];
    }
}

OUString CalcAddins_impl::getArgumentDescription(
                                        const OUString& aProgrammaticName, 
                                        ::sal_Int32 nArgument) 
    throw (RuntimeException) {
    std::map< STRING, std::vector < STRING > >::const_iterator i =
        argDesc.find(aProgrammaticName);
    if (i == argDesc.end())
        return STRFROMASCII("no help available");
    else {
        std::vector < STRING >v = i->second;
        return v[nArgument];
    }
}

OUString CalcAddins_impl::getProgrammaticCategoryName(
                  const OUString& aProgrammaticName) throw (RuntimeException) {
    return STRFROMASCII( "Add-In" );
}

OUString CalcAddins_impl::getDisplayCategoryName(
                  const OUString& aProgrammaticName) throw (RuntimeException) {
    return STRFROMASCII( "Add-In" );
}

//XServiceName
OUString CalcAddins_impl::getServiceName() throw (RuntimeException) {
    return STRFROMASCII( _serviceName_ );
}

//XServiceInfo
static OUString getImplementationName_CalcAddins_impl() 
    throw (RuntimeException) {
    return STRFROMASCII( _implName_ );
}

OUString CalcAddins_impl::getImplementationName() throw (RuntimeException) {
    return getImplementationName_CalcAddins_impl();
}

::sal_Bool CalcAddins_impl::supportsService(OUString const & serviceName) 
    throw (RuntimeException) {
    return serviceName.compareToAscii( _serviceName_ ) == 0 || 
        serviceName.compareToAscii( _AddserviceName_ ) == 0;
}

static Sequence<OUString> getSupportedServiceNames_CalcAddins_impl() 
    throw (RuntimeException) {
    Sequence< OUString > name(2);
    name[0] = STRFROMASCII( _serviceName_ );
    name[1] = STRFROMASCII( _AddserviceName_ );
    return name;
}

Sequence< OUString > CalcAddins_impl::getSupportedServiceNames() 
    throw (RuntimeException) {
    return getSupportedServiceNames_CalcAddins_impl();
}

//XLocalizable
void CalcAddins_impl::setLocale(const lang::Locale& eLocale) 
    throw (RuntimeException) {
    locale = eLocale;
}

lang::Locale CalcAddins_impl::getLocale() throw (RuntimeException) {
    return locale;
}

static Reference< XInterface > 
SAL_CALL create_CalcAddins_impl(Reference<XComponentContext> const & xContext) 
{
    return static_cast< ::cppu::OWeakObject * > ( new CalcAddins_impl );
}

static struct ::cppu::ImplementationEntry s_component_entries[] = {
    { create_CalcAddins_impl, getImplementationName_CalcAddins_impl,
      getSupportedServiceNames_CalcAddins_impl, 
      ::cppu::createSingleComponentFactory, 0, 0 },
    { 0, 0, 0, 0, 0, 0 }
};


extern "C" {
	SAL_DLLPUBLIC_EXPORT  void SAL_CALL component_getImplementationEnvironment(
                                            sal_Char const ** ppEnvTypeName, 
                                            uno_Environment ** ppEnv) {
		*ppEnvTypeName = CPPU_CURRENT_LANGUAGE_BINDING_NAME;
	}

	SAL_DLLPUBLIC_EXPORT  sal_Bool SAL_CALL component_writeInfo(lang::XMultiServiceFactory * xMgr, 
                                          registry::XRegistryKey * xRegistry) { 
		return ::cppu::component_writeInfoHelper( xMgr, xRegistry, 
                                                  s_component_entries );
	}

	SAL_DLLPUBLIC_EXPORT  void * SAL_CALL component_getFactory( sal_Char const * implName,
		lang::XMultiServiceFactory * xMgr, registry::XRegistryKey * xRegistry) {
		return ::cppu::component_getFactoryHelper(implName, xMgr, xRegistry, 
                                                  s_component_entries );
	}
}