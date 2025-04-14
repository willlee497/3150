#include <iostream>
#include <chrono>
#include <string>

using namespace std;

int main() {
    auto start = chrono::high_resolution_clock::now();
    string shortString = "short";
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken (short string): " << duration.count() << " microseconds" << endl;

    cout << "-------" << endl;

    start = chrono::high_resolution_clock::now();
    string longString = "this is a long string - this string should be on the heap";
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken (long string): " << duration.count() << " microseconds" << endl;

    return 0;
}
