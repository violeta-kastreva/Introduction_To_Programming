#pragma once

#include "rational.h"

struct Rational;

struct RationalResult {
    Rational *res;
    bool isValid;
};

void printRationalResult(const RationalResult &r);