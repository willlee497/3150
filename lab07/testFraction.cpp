#include <iostream>
#include "BigFraction.h"

int main() {
    // Test 1: (1/2) + (1/3) = 5/6
    {
        BigFraction fracA{ bigint("1"), bigint("2") };
        BigFraction fracB{ bigint("1"), bigint("3") };
        BigFraction sum = addFractions(fracA, fracB);

        if(sum.first == bigint("5") && sum.second == bigint("6")) {
            std::cout << "Test 1 PASSED: 1/2 + 1/3 = 5/6\n";
        } else {
            std::cout << "Test 1 FAILED: got "
                      << sum.first << "/" << sum.second << "\n";
        }
    }

    // Test 2: (2/3) * (3/4) = (6/12)
    {
        BigFraction fracA{ bigint("2"), bigint("3") };
        BigFraction fracB{ bigint("3"), bigint("4") };
        BigFraction product = multiplyFractions(fracA, fracB);

        if(product.first == bigint("6") && product.second == bigint("12")) {
            std::cout << "Test 2 PASSED: (2/3)*(3/4) = 6/12\n";
        } else {
            std::cout << "Test 2 FAILED: got "
                      << product.first << "/" << product.second << "\n";
        }
    }

    // Test 3: Large fraction check
    {
        BigFraction fracA{ bigint("12345678901234567890"), bigint("99999999999999999999") };
        BigFraction fracB{ bigint("22222222222222222222"), bigint("88888888888888888888") };

        BigFraction sum     = addFractions(fracA, fracB);
        BigFraction product = multiplyFractions(fracA, fracB);

        std::cout << "Test 3 (Large Fractions):\n";
        std::cout << "   sum numerator: " << sum.first
                  << "\n   sum denominator: " << sum.second
                  << "\n   product numerator: " << product.first
                  << "\n   product denominator: " << product.second
                  << "\n";
    }

    return 0;
}
