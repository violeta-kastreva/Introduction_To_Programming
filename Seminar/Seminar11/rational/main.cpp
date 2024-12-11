#include "rational.h"
#include "rationalResult.h"

#include <iostream>

int main() {
    Rational r1{3,5};
    Rational r2{2,3};

    RationalResult res = mul(r1, r2);
    printRationalResult(res);
    delete res.res;

    Rational* dynRat = new Rational{5,6};
    if (!dynRat) {
        return 1;
    }

    std::cout << (*dynRat).numerator << ' ' << dynRat->denominator << '\n';

    delete dynRat;

    return 0;
}