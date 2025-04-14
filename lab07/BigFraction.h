#ifndef BIGFRACTION_H
#define BIGFRACTION_H

#include "bigint.h"
#include <utility>

/**
 * Fractions are stored as (numerator, denominator).
 * We'll pass them by value in our functions (not by const ref),
 * so that 'bigint' inside is not forced const.
 */
using BigFraction = std::pair<bigint, bigint>;

/**
 * @brief (a/b) + (c/d) = (ad + bc)/(bd)
 */
BigFraction addFractions(BigFraction lhs, BigFraction rhs);

/**
 * @brief (a/b) * (c/d) = (ac)/(bd)
 */
BigFraction multiplyFractions(BigFraction lhs, BigFraction rhs);

#endif
