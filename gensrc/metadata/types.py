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
    ("QuantLib::Vector",        "double",     "double",    "interfaceToVector", "interfaceFromVector", 1),
    ("QuantLib::Matrix",        "double",     "double",    "interfaceToMatrix", "interfaceFromMatrix", 2),
    ("QuantLib::BigInteger",    "long",       "long",      "Default", "Default"),
    ("QuantLib::Integer",       "long",       "long",      "Default", "Default"),
    ("QuantLib::Natural",       "long",       "long",      "Default", "Default"),
    ("QuantLib::Real",          "double",     "double",    "Default", "Default"),
    ("QuantLib::Rate",          "double",     "double",    "Default", "Default"),
    ("QuantLib::Spread",        "double",     "double",    "Default", "Default"),
    ("QuantLib::DiscountFactor","double",     "double",    "Default", "Default"),
    ("QuantLib::Probability",   "double",     "double",    "Default", "Default"),
    ("QuantLib::Volatility",    "double",     "double",    "Default", "Default"),
    ("bool",                    "int",        "long",      "Default", "Default"),
    ("int",                     "int",        "long",      "Default", "Default"),
    ("double",                  "double",     "double",    "Default", "Default"),
    ("std::string",             "std::string","string",    "interfaceToString", "Default"),
]
