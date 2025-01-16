#include "money.h"
#include <iomanip>
#include <algorithm>

namespace vsite::oop::v7
{
    money::money(int euro, int cent) : ukupno_cent(euro * 100 + cent) {}

    money& money::operator+=(const money& m) {
        ukupno_cent += m.ukupno_cent;
        return *this;
    }

    money& money::operator-=(const money& m) {
        ukupno_cent -= m.ukupno_cent;
        return *this;
    }

    std::ostream& operator<<(std::ostream& out, const money& m) {
        int euro = m.ukupno_cent / 100;
        int cent = std::abs(m.ukupno_cent % 100);
        out << euro << " eur " << std::setw(2) << std::setfill('0') << cent << " ct";
        return out;
    }


    std::istream& operator>>(std::istream& in, money& m) {
        int euro, cent;
        in >> euro >> cent;
        m.ukupno_cent = euro * 100 + cent;
        return in;
    }
}