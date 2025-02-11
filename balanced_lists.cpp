#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>
#include <vector>
#include <algorithm> // for std::swap, std::count
#include <cstdlib>   // for rand, srand
#include <ctime>     // for time

// -------------------------------------------------------------------
// 1. Build a balanced list of size 2*n: n copies of +1, n copies of -1
// -------------------------------------------------------------------
std::vector<int> buildBalancedList(int n) {
    // Start with n copies of +1
    std::vector<int> result(n, 1);
    // Append n copies of -1
    result.insert(result.end(), n, -1);
    return result;
}

// -------------------------------------------------------------------
// 2. Perform a Fisher-Yates style random permutation of the vector
// -------------------------------------------------------------------
void randomPermutation(std::vector<int>& arr) {
    for (int i = arr.size() - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(arr[i], arr[j]);
    }
}

// -------------------------------------------------------------------
// 3. Check if the partial sums never achieve both negative and positive
//    values. This implies the path is always at/above zero or always at/below zero.
// -------------------------------------------------------------------
bool hasSingleSignPrefix(const std::vector<int>& arr) {
    int prefixSum = 0;
    bool seenNegative = false;
    bool seenPositive = false;

    for (int x : arr) {
        prefixSum += x;
        if (prefixSum < 0) {
            seenNegative = true;
        }
        if (prefixSum > 0) {
            seenPositive = true;
        }
        // If we've seen both negative and positive partial sums, it's invalid
        if (seenNegative && seenPositive) {
            return false;
        }
    }
    // If partial sums have never been both <0 and >0, we say it's valid
    return true;
}

// -------------------------------------------------------------------
// 4. Conduct many trials, each time building, shuffling, checking
//    Returns the proportion of valid sequences in [0..1].
// -------------------------------------------------------------------
double estimateValidProportion(int n, int numTrials) {
    int validCount = 0;
    for (int i = 0; i < numTrials; ++i) {
        std::vector<int> seq = buildBalancedList(n);
        randomPermutation(seq);
        if (hasSingleSignPrefix(seq)) {
            ++validCount;
        }
    }
    return static_cast<double>(validCount) / numTrials;
}

// -------------------------------------------------------------------
// 5. Unit Tests (using doctest)
// -------------------------------------------------------------------
TEST_CASE("Test buildBalancedList()") {
    int n = 4;
    std::vector<int> data = buildBalancedList(n);
    // The list should have 2*n elements
    CHECK(data.size() == static_cast<size_t>(2*n));
    // Check the count of +1 and -1
    CHECK(std::count(data.begin(), data.end(), 1) == n);
    CHECK(std::count(data.begin(), data.end(), -1) == n);
}

TEST_CASE("Test randomPermutation()") {
    std::vector<int> v = {1, 1, -1, -1};
    randomPermutation(v);
    // We still should have 2 ones and 2 minus ones
    CHECK(std::count(v.begin(), v.end(), 1) == 2);
    CHECK(std::count(v.begin(), v.end(), -1) == 2);
}

TEST_CASE("Test hasSingleSignPrefix()") {
    // This sequence remains at prefix sums: 1 -> 0 -> 1 -> 0 -> 1 -> 0
    CHECK(hasSingleSignPrefix({1, -1, 1, -1, 1, -1}));
    // This one eventually goes negative and positive
    CHECK_FALSE(hasSingleSignPrefix({1, 1, -1, -1, -1, 1}));
    // Remains above zero or zero
    CHECK(hasSingleSignPrefix({1, 1, -1, -1}));
    // Goes below zero then above
    CHECK_FALSE(hasSingleSignPrefix({-1, 1, 1, -1, -1}));
}

// -------------------------------------------------------------------
// 6. main() - runs the tests, then performs user-driven trials
// -------------------------------------------------------------------
int main() {
    // First, run all doctest tests
    doctest::Context context;
    int testResult = context.run();
    if (testResult != 0) {
        std::cerr << "Unit tests failed. Exiting...\n";
        return testResult; 
    }

    // Set seed for randomization
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Prompt the user for n and number of trials
    int n = 0, trials = 0;
    std::cout << "Enter the half-size of the sequence (n): ";
    std::cin >> n;
    std::cout << "Enter the number of trials: ";
    std::cin >> trials;

    // Compute the proportion
    double ratio = estimateValidProportion(n, trials);
    std::cout << "Ratio of well-balanced sequences: " << ratio << std::endl;

    return 0; 
}
