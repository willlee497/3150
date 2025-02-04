William Lee's Lab 1: Array Prefix Sum Checker

This program evaluates if an array of +1 and -1 values satisfies two key conditions for its cumulative sums (prefix sums):

Non-negative: The prefix sum never drops below 0.
Non-positive: The prefix sum never exceeds 0.
It runs automated tests using the doctest framework and allows you to manually check arrays through an interactive mode.

Requirements
To use this program, you’ll need:

A C++ compiler (like g++).
The doctest.h library file for unit testing.
(Ensure this file is in the same directory as your code or accessible in your compiler's include path.)
Compilation Steps
Open a terminal and navigate to the folder containing prefix_sums.cpp.

Compile the code using:

g++ -std=c++17 prefix_sums.cpp -o prefix_sums

Running the Program
Execute the program by typing:

./prefix_sums

The program will perform the following steps:

Run Tests:
Automated unit tests (powered by doctest) will execute first. Results are shown in the terminal.

Interactive Check:
Once testing is complete, the program will prompt you to:

Specify the number of elements in the array.
Enter the array values (limited to +1 or -1).
After processing, the program will confirm whether the array meets the prefix sum conditions.

Quick Reference
Compile Command:

g++ -std=c++17 prefix_sums.cpp -o prefix_sums

Run Command:

./prefix_sums

Testing Details:
Built-in unit tests automatically run before the interactive part begins.