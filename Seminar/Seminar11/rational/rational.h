#pragma once

#include "rationalResult.h"

struct RationalResult;

struct Rational {
    int numerator;
    int denominator;
};

bool isValid(const Rational &r);
RationalResult mul(const Rational &r1, const Rational &r2);
void printRational(const Rational &r);