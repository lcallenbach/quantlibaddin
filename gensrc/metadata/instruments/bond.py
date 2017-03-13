
# intended just to have the type:

QuantLibTypes = [
    ("Constructor", "ql/instruments/bond.hpp", "QuantLib::Bond(QuantLib::Natural settlementDays, QuantLib::Calendar calendar, QuantLib::Date issueDate = QuantLib::Date(), QuantLib::Leg coupons = QuantLib::Leg())", "", "qlBond"),
]



QuantLibTypes = [
   ("MemberFunction", "ql/instruments/bond.hpp",
        "QuantLib::Bond()", "QuantLib::Real cleanPrice()",
        "qlBondCleanPrice"),
    ("MemberFunction", "ql/instruments/bond.hpp",
        "QuantLib::Bond()", "QuantLib::Real dirtyPrice()",
        "qlBondDirtyPrice")
]

