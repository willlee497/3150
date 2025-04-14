#include <iostream>
#include <chrono>
#include "BigFraction.h"

int main()
{
    using namespace std::chrono;

    const int NUM_ITER = 100000;

    // 1) Timing int
    {
        auto start = high_resolution_clock::now();
        int sum = 0;
        for(int i = 0; i < NUM_ITER; i++){
            sum += i;
        }
        auto end = high_resolution_clock::now();
        auto dur = duration_cast<microseconds>(end - start).count();
        std::cout << "[int sum 0..99999] time: " << dur << " us\n";
    }

    // 2) Timing long long
    {
        auto start = high_resolution_clock::now();
        long long sum = 0;
        for(long long i = 0; i < NUM_ITER; i++){
            sum += i;
        }
        auto end = high_resolution_clock::now();
        auto dur = duration_cast<microseconds>(end - start).count();
        std::cout << "[long long sum 0..99999] time: " << dur << " us\n";
    }

    // 3) Timing BigFraction
    {
        auto start = high_resolution_clock::now();
        BigFraction bigSum{ bigint("0"), bigint("1") };
        for(int i = 1; i <= NUM_ITER; i++){
            BigFraction term{ bigint(std::to_string(i)), bigint("1") };
            bigSum = addFractions(bigSum, term);
        }
        auto end = high_resolution_clock::now();
        auto dur = duration_cast<microseconds>(end - start).count();
        std::cout << "[BigFraction sum (1..99999 / 1)] time: " << dur << " us\n";
    }

    return 0;
}
