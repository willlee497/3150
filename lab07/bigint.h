

//2) `bigint.h` (Declarations Only)

//Below is Roshan Gupta’s single-file library **split** so that only **declarations** are in the header. The big definitions are in `bigint.cpp`. This prevents multiple definitions.

#ifndef BIGINT_H
#define BIGINT_H

#include <string>
#include <stdexcept>

class bigint {
private:
    std::string str; 

    // Internal static helpers - declarations only:
    static bool is_bigint(std::string s);
    static std::string add(std::string str1, std::string str2);
    static std::string subtract(std::string str1, std::string str2);
    static std::string multiply(std::string str1, std::string str2);
    static std::string divide(std::string str1, std::string str2);
    static std::string mod(std::string str1, std::string str2);
    static std::string shortDivide(std::string s1, unsigned long long int divisor);
    static std::string maximum(std::string str1, std::string str2);
    static bool is_maximum(std::string str1, std::string str2);
    static bool is_strictlyMaximum(std::string str1, std::string str2);
    static std::string minimum(std::string str1, std::string str2);
    static bool is_minimum(std::string str1, std::string str2);
    static bool is_strictlyMinimum(std::string str1, std::string str2);
    static std::string trim(std::string s);
    static std::string abs(std::string s);
    static std::string pow(std::string str1, std::string str2);
    static std::string sqrt(std::string s);
    static std::string log2(std::string s);
    static std::string log10(std::string s);
    static std::string logwithbase(std::string val, std::string base);
    static std::string antilog2(std::string s);
    static std::string antilog10(std::string s);
    static void swap(std::string &str1, std::string &str2);
    static std::string reverse(std::string s);
    static std::string gcd(std::string str1, std::string str2);
    static std::string lcm(std::string str1, std::string str2);
    static std::string fact(std::string s);
    static bool isPalindrome(std::string s);
    static bool isPrime(std::string s);

public:
    // Constructors
    bigint();
    bigint(std::string s);
    bigint(long long int n);
    bigint(int n);
    bigint(long int n);
    bigint(const bigint &n);

    // Stream operators
    friend std::ostream &operator << (std::ostream &stream, const bigint &n);
    friend std::istream &operator >> (std::istream &stream, bigint &n);

    // + operators
    bigint operator + (bigint const &n);
    friend bigint operator + (bigint const &n1, int n2);
    friend bigint operator + (int n1, bigint const &n2);
    friend bigint operator + (bigint const &n1, long int n2);
    friend bigint operator + (long int n1, bigint const &n2);
    friend bigint operator + (bigint const &n1, long long int n2);
    friend bigint operator + (long long int n1, bigint const &n2);
    bigint& operator += (bigint const n);

    // - operators
    bigint operator - (bigint const &n);
    friend bigint operator - (bigint const &n1, int n2);
    friend bigint operator - (int n1, bigint const &n2);
    friend bigint operator - (bigint const &n1, long int n2);
    friend bigint operator - (long int n1, bigint const &n2);
    friend bigint operator - (bigint const &n1, long long int n2);
    friend bigint operator - (long long int n1, bigint const &n2);
    bigint& operator -= (bigint const n);

    // * operators
    bigint operator * (bigint const &n);
    friend bigint operator * (bigint const &n1, int n2);
    friend bigint operator * (int n1, bigint const &n2);
    friend bigint operator * (bigint const &n1, long int n2);
    friend bigint operator * (long int n1, bigint const &n2);
    friend bigint operator * (bigint const &n1, long long int n2);
    friend bigint operator * (long long int n1, bigint const &n2);
    bigint& operator *= (bigint const n);

    // / operators
    bigint operator / (bigint const &n);
    friend bigint operator / (bigint const &n1, int n2);
    friend bigint operator / (int n1, bigint const &n2);
    friend bigint operator / (bigint const &n1, long int n2);
    friend bigint operator / (long int n1, bigint const &n2);
    friend bigint operator / (bigint const &n1, long long int n2);
    friend bigint operator / (long long int n1, bigint const &n2);
    bigint& operator /= (bigint const n);

    // % operators
    bigint operator % (bigint const &n);
    friend bigint operator % (bigint const &n1, int n2);
    friend bigint operator % (int n1, bigint const &n2);
    friend bigint operator % (bigint const &n1, long int n2);
    friend bigint operator % (long int n1, bigint const &n2);
    friend bigint operator % (bigint const &n1, long long int n2);
    friend bigint operator % (long long int n1, bigint const &n2);
    bigint& operator %= (bigint const n);

    // ++ and --
    bigint& operator ++ ();   // pre
    bigint operator ++ (int); // post
    bigint& operator -- ();   // pre
    bigint operator -- (int); // post

    // Comparison operators
    bool operator > (bigint const &n);
    friend bool operator > (bigint const &n1, int n2);
    friend bool operator > (int n1, bigint const &n2);
    friend bool operator > (bigint const &n1, long int n2);
    friend bool operator > (long int n1, bigint const &n2);
    friend bool operator > (bigint const &n1, long long int n2);
    friend bool operator > (long long int n1, bigint const &n2);

    bool operator < (bigint const &n);
    friend bool operator < (bigint const &n1, int n2);
    friend bool operator < (int n1, bigint const &n2);
    friend bool operator < (bigint const &n1, long int n2);
    friend bool operator < (long int n1, bigint const &n2);
    friend bool operator < (bigint const &n1, long long int n2);
    friend bool operator < (long long int n1, bigint const &n2);

    bool operator >= (bigint const &n);
    friend bool operator >= (bigint const &n1, int n2);
    friend bool operator >= (int n1, bigint const &n2);
    friend bool operator >= (bigint const &n1, long int n2);
    friend bool operator >= (long int n1, bigint const &n2);
    friend bool operator >= (bigint const &n1, long long int n2);
    friend bool operator >= (long long int n1, bigint const &n2);

    bool operator <= (bigint const &n);
    friend bool operator <= (bigint const &n1, int n2);
    friend bool operator <= (int n1, bigint const &n2);
    friend bool operator <= (bigint const &n1, long int n2);
    friend bool operator <= (long int n1, bigint const &n2);
    friend bool operator <= (bigint const &n1, long long int n2);
    friend bool operator <= (long long int n1, bigint const &n2);

    bool operator == (bigint const &n);
    friend bool operator == (bigint const &n1, int n2);
    friend bool operator == (int n1, bigint const &n2);
    friend bool operator == (bigint const &n1, long int n2);
    friend bool operator == (long int n1, bigint const &n2);
    friend bool operator == (bigint const &n1, long long int n2);
    friend bool operator == (long long int n1, bigint const &n2);

    bool operator != (bigint const &n);
    friend bool operator != (bigint const &n1, int n2);
    friend bool operator != (int n1, bigint const &n2);
    friend bool operator != (bigint const &n1, long int n2);
    friend bool operator != (long int n1, bigint const &n2);
    friend bool operator != (bigint const &n1, long long int n2);
    friend bool operator != (long long int n1, bigint const &n2);

    // Additional static methods for big_abs, big_pow, big_gcd, etc.
    static bigint _big_max(bigint &a, bigint &b);
    static bigint _big_min(bigint &a, bigint &b);
    static bigint _big_abs(bigint &a);
    static bigint _big_pow(bigint &a, bigint &b);
    static bigint _big_sqrt(bigint &a);
    static bigint _big_log2(bigint &a);
    static bigint _big_log10(bigint &a);
    static bigint _big_logwithbase(bigint &a, bigint &b);
    static bigint _big_antilog2(bigint &a);
    static bigint _big_antilog10(bigint &a);
    static void _big_swap(bigint &a, bigint &b);
    static bigint _big_reverse(bigint &a);
    static bigint _big_gcd(bigint &a, bigint &b);
    static bigint _big_lcm(bigint &a, bigint &b);
    static bigint _big_fact(bigint &a);
    static bool _big_isPalindrome(bigint &a);
    static bool _big_isPrime(bigint &a);
    static bigint _to_bigint(std::string s);
    static bigint _to_bigint(int n);
    static bigint _to_bigint(long int n);
    static bigint _to_bigint(long long int n);
};

#endif
