#include "BigFraction.h"

BigFraction addFractions(BigFraction lhs, BigFraction rhs)
{
    // (a/b) + (c/d) = (ad + bc) / (bd)
    bigint numerator   = lhs.first  * rhs.second + lhs.second * rhs.first;
    bigint denominator = lhs.second * rhs.second;
    return { numerator, denominator };
}

BigFraction multiplyFractions(BigFraction lhs, BigFraction rhs)
{
    // (a/b) * (c/d) = (ac) / (bd)
    bigint numerator   = lhs.first  * rhs.first;
    bigint denominator = lhs.second * rhs.second;
    return { numerator, denominator };
}
