README

Lab: Randomly Generated Balanced Lists
Author: William Lee
Lab: Week 2: Balanced Lists

Overview
This C++ program generates a vector of 2·n symbols, consisting of n copies of +1 followed by n copies of -1. It then applies a Fisher-Yates shuffle to randomly permute the list. After shuffling, the program checks whether the partial sums remain entirely non-negative or entirely non-positive. If a single shuffled sequence never shows both negative and positive partial sums, it is considered “well-balanced.” The program repeats this many times and calculates the proportion of well-balanced sequences observed.

Compilation and Execution
A C++ compiler with support for C++11 (or later) is required. The program uses doctest, which is already included in the source file.
To compile, run a command such as:
g++ -std=c++11 main.cpp -o balanced_lists
This produces an executable named balanced_lists.
Running ./balanced_lists first executes unit tests. If the tests pass, the program prompts for n (the half-size of the sequence) and the number of trials. After running those trials, the program outputs the ratio of valid (well-balanced) sequences.

Example
Enter the half-size of the sequence (n): 4
Enter the number of trials: 10000
Ratio of well-balanced sequences: 0.39
This result is typically close to the theoretical value 0.4 for n = 4.

Explanation
The function buildBalancedList(n) returns a vector of size 2n containing n copies of +1 and n copies of -1.
The function randomPermutation arranges the elements uniformly at random using a Fisher-Yates shuffle.
The function hasSingleSignPrefix checks the prefix sums of the shuffled list. If the sums become both negative and positive at any point, it returns false. Otherwise, it returns true.
The function estimateValidProportion(n, trials) repeats the create-and-shuffle process for the given number of trials. It tallies how many permutations pass the single-sign-prefix check, then returns (validCount / trials).


Expected Proportions
For large trials, the ratio of valid sequences converges to approximately 2/(n+1). For n = 1, the ratio should be close to 1.0, for n = 4 around 0.4, and for n = 5 about 0.3333.

End of README