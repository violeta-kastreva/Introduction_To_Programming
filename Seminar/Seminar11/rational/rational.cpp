#include "rational.h"

#include <iostream>


bool isValid(const Rational &r) {
    return r.denominator != 0;
}

RationalResult mul(const Rational &r1, const Rational &r2) {
    if (!isValid(r1) || !isValid(r2)) {
        return RationalResult{nullptr, false};
    }

    Rational* res = new(std::nothrow) Rational{r1.numerator * r2.numerator, r1.denominator * r2.denominator};
    return RationalResult{
        res,
        res != nullptr
    };
}

void printRational(const Rational &r) {
    if (!isValid(r)) {
        std::cout << "invalid_rational";
        return;
    }

    std::cout << "Rational{numerator: " << r.numerator << ", denominator: " << r.denominator << "}";
}