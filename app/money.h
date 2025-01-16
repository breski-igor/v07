#pragma once
#include <iostream>


namespace vsite::oop::v7
{

    class money {
    private:
        int ukupno_cent;

    public:
        money(int euro = 0, int cent = 0);

        int get_total() const { return ukupno_cent; }

        money& operator+=(const money& other);
        money& operator-=(const money& other);

        friend std::ostream& operator<<(std::ostream& out, const money& m);
        friend std::istream& operator>>(std::istream& in, money& m);
    };

}
