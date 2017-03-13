"""
 Python source for QuantLib addin in LibreOffice/Calc.
 Copyright (C) 2017 Lars Callenbach

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
    ("QuantLib::HestonProcess::Discretization",  "std::string", "string", "EnumeratedType", ""),
]


QuantLibTypes = [
    ("Constructor", "ql/processes/hestonprocess.hpp", 
        "QuantLib::HestonProcess(QuantLib::Handle<QuantLib::YieldTermStructure> RiskFreeRate, \
        QuantLib::Handle<QuantLib::YieldTermStructure> DividendYield, QuantLib::Handle<QuantLib::Quote> S0,\
        QuantLib::Real V0, QuantLib::Real Kappa, QuantLib::Real Theta, QuantLib::Real Sigma,\
        QuantLib::Real Rho, QuantLib::HestonProcess::Discretization D=QuantLib::HestonProcess::PartialTruncation)", 
        "", "qlHestonProcess"),
        
        
    ("EnumeratedType", "ql/processes/hestonprocess.hpp", "QuantLib::HestonProcess::Discretization", 
        "std::string", "PartialTruncation", "QuantLib::HestonProcess::PartialTruncation"),
    ("EnumeratedType", "ql/processes/hestonprocess.hpp", "QuantLib::HestonProcess::Discretization", 
        "std::string", "FullTruncation", "QuantLib::HestonProcess::FullTruncation"),
    ("EnumeratedType", "ql/processes/hestonprocess.hpp", "QuantLib::HestonProcess::Discretization", 
        "std::string", "Reflection", "QuantLib::HestonProcess::Reflection"),
    ("EnumeratedType", "ql/processes/hestonprocess.hpp", "QuantLib::HestonProcess::Discretization", 
        "std::string", "QuadraticExponential", "QuantLib::HestonProcess::QuadraticExponential"),
    ("EnumeratedType", "ql/processes/hestonprocess.hpp", "QuantLib::HestonProcess::Discretization", 
        "std::string", "NonCentralChiSquareVariance", "QuantLib::HestonProcess::NonCentralChiSquareVariance"),
]
