william lee
Lab: Week 2: Balanced Lists


This program:

Balanced Lists Lab Week 2

This code creates a list of 2n elements, each list having n copies of +1 followed by n copies of -1. It then uses a Fisher-Yates shuffle to randomize the order of these elements. After shuffling, the program checks if the prefix sums never occupy both negative and positive values, which indicates a “well-balanced” sequence. The program repeats this shuffling and checking process a specified number of times and reports the ratio of well-balanced sequences.

To compile, use a C++11 or later compiler. Once compiled, running the executable automatically triggers a set of tests (via doctest) and then prompts for two inputs: n (the half-size for the list) and the number of trials. It then prints out the ratio of valid (well-balanced) sequences. For large numbers of trials, this ratio should approach the theoretical value 2 / (n+1).

Include this code, the tests, and a one-page summary detailing your final ratio and total trials in your submission.