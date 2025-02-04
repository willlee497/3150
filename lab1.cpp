#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>

using namespace std;

/**
 * Returns true if all prefix sums of 'data' are >= 0; false otherwise.
 */
bool checkPrefixNonNegative(const int data[], int length) {
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += data[i];
        if (sum < 0) {
            return false;
        }
    }
    return true;
}

/**
 * Returns true if all prefix sums of 'data' are <= 0; false otherwise.
 */
bool checkPrefixNonPositive(const int data[], int length) {
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += data[i];
        if (sum > 0) {
            return false;
        }
    }
    return true;
}

/* ------------------------------ TEST CASES ------------------------------ */

TEST_CASE("Case 1: Alternating array starting with +1") {
    int arr[] = {1, -1, 1, -1};
    CHECK(checkPrefixNonNegative(arr, 4) == true);
    CHECK(checkPrefixNonPositive(arr, 4) == false);
}

TEST_CASE("Case 2: Array that goes negative") {
    int arr[] = {1, -1, -1, 1};
    CHECK(checkPrefixNonNegative(arr, 4) == false);
    CHECK(checkPrefixNonPositive(arr, 4) == false);
}

TEST_CASE("Case 3: Array valid for non-positive prefix") {
    int arr[] = {-1, 1, -1, 1};
    CHECK(checkPrefixNonNegative(arr, 4) == false);
    CHECK(checkPrefixNonPositive(arr, 4) == true);
}

TEST_CASE("Case 4: Array with all -1 values") {
    int arr[] = {-1, -1, -1, -1};
    CHECK(checkPrefixNonNegative(arr, 4) == false);
    CHECK(checkPrefixNonPositive(arr, 4) == true);
}

TEST_CASE("Case 5: Array with all +1 values") {
    int arr[] = {1, 1, 1, 1};
    CHECK(checkPrefixNonNegative(arr, 4) == true);
    CHECK(checkPrefixNonPositive(arr, 4) == false);
}

/* ------------------------------ MAIN FUNCTION ------------------------------ */

int main(int argc, char** argv) {
    // Run doctest-based tests
    doctest::Context context;
    context.applyCommandLine(argc, argv);
    int testResult = context.run();
    if (context.shouldExit()) {
        return testResult;
    }

    // Prompt user for array input
    cout << "\nEnter the number of elements for the array: ";
    int arraySize;
    cin >> arraySize;

    if (arraySize <= 0) {
        cout << "Error: Array size must be a positive integer." << endl;
        return 1;
    }

    // Dynamically allocate array
    int* arr = new int[arraySize];
    cout << "Enter " << arraySize << " numbers (each should be either +1 or -1):" << endl;
    for (int i = 0; i < arraySize; ++i) {
        cin >> arr[i];
    }

    // Perform checks
    bool nonNeg = checkPrefixNonNegative(arr, arraySize);
    bool nonPos = checkPrefixNonPositive(arr, arraySize);

    // Output results
    cout << "\nResults:" << endl;
    cout << "Prefix sums never go below zero: " << (nonNeg ? "true" : "false") << endl;
    cout << "Prefix sums never go above zero: " << (nonPos ? "true" : "false") << endl;

    delete[] arr;
    return testResult;
}