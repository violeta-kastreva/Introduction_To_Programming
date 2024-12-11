#include "rationalResult.h"

#include <iostream>

void printRationalResult(const RationalResult &r) {
    if (!r.isValid) {
        std::cout << "invalid_rational_result";
        return;
    }

    std::cout << "Rational{numerator: " << r.res->numerator << ", denominator: " << r.res->denominator << "}";
}