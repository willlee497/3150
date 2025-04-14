#include "bigint.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <limits>

// ---------------------
//  Constructors
// ---------------------
bigint::bigint() {
    str = "0"; 
}

bigint::bigint(std::string s) {
    if(!is_bigint(s))
        throw std::runtime_error("Invalid Big Integer has been fed."); 
    str = s;
}

bigint::bigint(long long int n) {
    str = std::to_string(n);
}

bigint::bigint(int n) {
    str = std::to_string(n);
}

bigint::bigint(long int n) {
    str = std::to_string(n);
}

bigint::bigint(const bigint &n) {
    str = n.str;
}

// ---------------------
//  Stream Overloads
// ---------------------
std::ostream &operator<<(std::ostream &stream, const bigint &n) {
    stream << n.str;
    return stream;
}
std::istream &operator>>(std::istream &stream, bigint &n) {
    stream >> n.str;
    return stream;
}

// ---------------------
//  + Operators
// ---------------------
bigint bigint::operator + (bigint const &n) {
    bigint ans;
    ans.str = add(str, n.str);
    return ans;
}
bigint operator + (bigint const &n1, int n2) {
    bigint ans;
    ans.str = bigint::add(n1.str, std::to_string(n2));
    return ans;
}
bigint operator + (int n1, bigint const &n2) {
    bigint ans;
    ans.str = bigint::add(std::to_string(n1), n2.str);
    return ans;
}
bigint operator + (bigint const &n1, long int n2) {
    bigint ans;
    ans.str = bigint::add(n1.str, std::to_string(n2));
    return ans;
}
bigint operator + (long int n1, bigint const &n2) {
    bigint ans;
    ans.str = bigint::add(std::to_string(n1), n2.str);
    return ans;
}
bigint operator + (bigint const &n1, long long int n2) {
    bigint ans;
    ans.str = bigint::add(n1.str, std::to_string(n2));
    return ans;
}
bigint operator + (long long int n1, bigint const &n2) {
    bigint ans;
    ans.str = bigint::add(std::to_string(n1), n2.str);
    return ans;
}
bigint& bigint::operator += (bigint const n) {
    this->str = add(this->str, n.str);
    return *this;
}

// ---------------------
//  - Operators
// ---------------------
bigint bigint::operator - (bigint const &n) {
    bigint ans;
    ans.str = subtract(str, n.str);
    return ans;
}
bigint operator - (bigint const &n1, int n2) {
    bigint ans;
    ans.str = bigint::subtract(n1.str, std::to_string(n2));
    return ans;
}
bigint operator - (int n1, bigint const &n2) {
    bigint ans;
    ans.str = bigint::subtract(std::to_string(n1), n2.str);
    return ans;
}
bigint operator - (bigint const &n1, long int n2) {
    bigint ans;
    ans.str = bigint::subtract(n1.str, std::to_string(n2));
    return ans;
}
bigint operator - (long int n1, bigint const &n2) {
    bigint ans;
    ans.str = bigint::subtract(std::to_string(n1), n2.str);
    return ans;
}
bigint operator - (bigint const &n1, long long int n2) {
    bigint ans;
    ans.str = bigint::subtract(n1.str, std::to_string(n2));
    return ans;
}
bigint operator - (long long int n1, bigint const &n2) {
    bigint ans;
    ans.str = bigint::subtract(std::to_string(n1), n2.str);
    return ans;
}
bigint& bigint::operator -= (bigint const n) {
    this->str = subtract(this->str, n.str);
    return *this;
}

// ---------------------
//  * Operators
// ---------------------
bigint bigint::operator * (bigint const &n) {
    bigint ans;
    ans.str = multiply(str, n.str);
    return ans;
}
bigint operator * (bigint const &n1, int n2) {
    bigint ans;
    ans.str = bigint::multiply(n1.str, std::to_string(n2));
    return ans;
}
bigint operator * (int n1, bigint const &n2) {
    bigint ans;
    ans.str = bigint::multiply(std::to_string(n1), n2.str);
    return ans;
}
bigint operator * (bigint const &n1, long int n2) {
    bigint ans;
    ans.str = bigint::multiply(n1.str, std::to_string(n2));
    return ans;
}
bigint operator * (long int n1, bigint const &n2) {
    bigint ans;
    ans.str = bigint::multiply(std::to_string(n1), n2.str);
    return ans;
}
bigint operator * (bigint const &n1, long long int n2) {
    bigint ans;
    ans.str = bigint::multiply(n1.str, std::to_string(n2));
    return ans;
}
bigint operator * (long long int n1, bigint const &n2) {
    bigint ans;
    ans.str = bigint::multiply(std::to_string(n1), n2.str);
    return ans;
}
bigint& bigint::operator *= (bigint const n) {
    this->str = multiply(this->str, n.str);
    return *this;
}

// ---------------------
//  / Operators
// ---------------------
bigint bigint::operator / (bigint const &n) {
    bigint ans;
    ans.str = divide(str, n.str);
    return ans;
}
bigint operator / (bigint const &n1, int n2) {
    bigint ans;
    ans.str = bigint::divide(n1.str, std::to_string(n2));
    return ans;
}
bigint operator / (int n1, bigint const &n2) {
    bigint ans;
    ans.str = bigint::divide(std::to_string(n1), n2.str);
    return ans;
}
bigint operator / (bigint const &n1, long int n2) {
    bigint ans;
    ans.str = bigint::divide(n1.str, std::to_string(n2));
    return ans;
}
bigint operator / (long int n1, bigint const &n2) {
    bigint ans;
    ans.str = bigint::divide(std::to_string(n1), n2.str);
    return ans;
}
bigint operator / (bigint const &n1, long long int n2) {
    bigint ans;
    ans.str = bigint::divide(n1.str, std::to_string(n2));
    return ans;
}
bigint operator / (long long int n1, bigint const &n2) {
    bigint ans;
    ans.str = bigint::divide(std::to_string(n1), n2.str);
    return ans;
}
bigint& bigint::operator /= (bigint const n) {
    this->str = divide(this->str, n.str);
    return *this;
}

// ---------------------
//  % Operators
// ---------------------
bigint bigint::operator % (bigint const &n) {
    bigint ans;
    ans.str = mod(str, n.str);
    return ans;
}
bigint operator % (bigint const &n1, int n2) {
    bigint ans;
    ans.str = bigint::mod(n1.str, std::to_string(n2));
    return ans;
}
bigint operator % (int n1, bigint const &n2) {
    bigint ans;
    ans.str = bigint::mod(std::to_string(n1), n2.str);
    return ans;
}
bigint operator % (bigint const &n1, long int n2) {
    bigint ans;
    ans.str = bigint::mod(n1.str, std::to_string(n2));
    return ans;
}
bigint operator % (long int n1, bigint const &n2) {
    bigint ans;
    ans.str = bigint::mod(std::to_string(n1), n2.str);
    return ans;
}
bigint operator % (bigint const &n1, long long int n2) {
    bigint ans;
    ans.str = bigint::mod(n1.str, std::to_string(n2));
    return ans;
}
bigint operator % (long long int n1, bigint const &n2) {
    bigint ans;
    ans.str = bigint::mod(std::to_string(n1), n2.str);
    return ans;
}
bigint& bigint::operator %= (bigint const n) {
    this->str = mod(this->str, n.str);
    return *this;
}

// ---------------------
//  ++, --
// ---------------------
bigint& bigint::operator ++ () { // pre
    this->str = add(this->str, "1");
    return *this;
}
bigint bigint::operator ++ (int) { // post
    this->str = add(this->str, "1");
    return *this;
}
bigint& bigint::operator -- () { // pre
    this->str = subtract(this->str, "1");
    return *this;
}
bigint bigint::operator -- (int) { // post
    this->str = subtract(this->str, "1");
    return *this;
}

// ---------------------
//  Comparison Operators
// ---------------------
bool bigint::operator > (bigint const &n) {
    return is_strictlyMaximum(str, n.str);
}
bool operator > (bigint const &n1, int n2) {
    return bigint::is_strictlyMaximum(n1.str, std::to_string(n2));
}
bool operator > (int n1, bigint const &n2) {
    return bigint::is_strictlyMaximum(std::to_string(n1), n2.str);
}
bool operator > (bigint const &n1, long int n2) {
    return bigint::is_strictlyMaximum(n1.str, std::to_string(n2));
}
bool operator > (long int n1, bigint const &n2) {
    return bigint::is_strictlyMaximum(std::to_string(n1), n2.str);
}
bool operator > (bigint const &n1, long long int n2) {
    return bigint::is_strictlyMaximum(n1.str, std::to_string(n2));
}
bool operator > (long long int n1, bigint const &n2) {
    return bigint::is_strictlyMaximum(std::to_string(n1), n2.str);
}

bool bigint::operator < (bigint const &n) {
    return is_strictlyMinimum(str, n.str);
}
bool operator < (bigint const &n1, int n2) {
    return bigint::is_strictlyMinimum(n1.str, std::to_string(n2));
}
bool operator < (int n1, bigint const &n2) {
    return bigint::is_strictlyMinimum(std::to_string(n1), n2.str);
}
bool operator < (bigint const &n1, long int n2) {
    return bigint::is_strictlyMinimum(n1.str, std::to_string(n2));
}
bool operator < (long int n1, bigint const &n2) {
    return bigint::is_strictlyMinimum(std::to_string(n1), n2.str);
}
bool operator < (bigint const &n1, long long int n2) {
    return bigint::is_strictlyMinimum(n1.str, std::to_string(n2));
}
bool operator < (long long int n1, bigint const &n2) {
    return bigint::is_strictlyMinimum(std::to_string(n1), n2.str);
}

bool bigint::operator >= (bigint const &n) {
    return is_maximum(str, n.str);
}
bool operator >= (bigint const &n1, int n2) {
    return bigint::is_maximum(n1.str, std::to_string(n2));
}
bool operator >= (int n1, bigint const &n2) {
    return bigint::is_maximum(std::to_string(n1), n2.str);
}
bool operator >= (bigint const &n1, long int n2) {
    return bigint::is_maximum(n1.str, std::to_string(n2));
}
bool operator >= (long int n1, bigint const &n2) {
    return bigint::is_maximum(std::to_string(n1), n2.str);
}
bool operator >= (bigint const &n1, long long int n2) {
    return bigint::is_maximum(n1.str, std::to_string(n2));
}
bool operator >= (long long int n1, bigint const &n2) {
    return bigint::is_maximum(std::to_string(n1), n2.str);
}

bool bigint::operator <= (bigint const &n) {
    return is_minimum(str, n.str);
}
bool operator <= (bigint const &n1, int n2) {
    return bigint::is_minimum(n1.str, std::to_string(n2));
}
bool operator <= (int n1, bigint const &n2) {
    return bigint::is_minimum(std::to_string(n1), n2.str);
}
bool operator <= (bigint const &n1, long int n2) {
    return bigint::is_minimum(n1.str, std::to_string(n2));
}
bool operator <= (long int n1, bigint const &n2) {
    return bigint::is_minimum(std::to_string(n1), n2.str);
}
bool operator <= (bigint const &n1, long long int n2) {
    return bigint::is_minimum(n1.str, std::to_string(n2));
}
bool operator <= (long long int n1, bigint const &n2) {
    return bigint::is_minimum(std::to_string(n1), n2.str);
}

bool bigint::operator == (bigint const &n) {
    return (this->str == n.str);
}
bool operator == (bigint const &n1, int n2) {
    return (n1.str == std::to_string(n2));
}
bool operator == (int n1, bigint const &n2) {
    return (std::to_string(n1) == n2.str);
}
bool operator == (bigint const &n1, long int n2) {
    return (n1.str == std::to_string(n2));
}
bool operator == (long int n1, bigint const &n2) {
    return (std::to_string(n1) == n2.str);
}
bool operator == (bigint const &n1, long long int n2) {
    return (n1.str == std::to_string(n2));
}
bool operator == (long long int n1, bigint const &n2) {
    return (std::to_string(n1) == n2.str);
}

bool bigint::operator != (bigint const &n) {
    return (this->str != n.str);
}
bool operator != (bigint const &n1, int n2) {
    return (n1.str != std::to_string(n2));
}
bool operator != (int n1, bigint const &n2) {
    return (std::to_string(n1) != n2.str);
}
bool operator != (bigint const &n1, long int n2) {
    return (n1.str != std::to_string(n2));
}
bool operator != (long int n1, bigint const &n2) {
    return (std::to_string(n1) != n2.str);
}
bool operator != (bigint const &n1, long long int n2) {
    return (n1.str != std::to_string(n2));
}
bool operator != (long long int n1, bigint const &n2) {
    return (std::to_string(n1) != n2.str);
}

// ---------------------
//  Additional statics
// ---------------------
bigint bigint::_big_max(bigint &a, bigint &b) {
    bigint ans;
    ans.str = maximum(a.str, b.str);
    return ans;
}
bigint bigint::_big_min(bigint &a, bigint &b) {
    bigint ans;
    ans.str = minimum(a.str, b.str);
    return ans;
}
bigint bigint::_big_abs(bigint &a) {
    bigint ans;
    ans.str = abs(a.str);
    return ans;
}
bigint bigint::_big_pow(bigint &a, bigint &b) {
    bigint ans;
    ans.str = pow(a.str, b.str);
    return ans;
}
bigint bigint::_big_sqrt(bigint &a) {
    bigint ans;
    ans.str = sqrt(a.str);
    return ans;
}
bigint bigint::_big_log2(bigint &a) {
    bigint ans;
    ans.str = log2(a.str);
    return ans;
}
bigint bigint::_big_log10(bigint &a) {
    bigint ans;
    ans.str = log10(a.str);
    return ans;
}
bigint bigint::_big_logwithbase(bigint &a, bigint &b) {
    bigint ans;
    ans.str = logwithbase(a.str, b.str);
    return ans;
}
bigint bigint::_big_antilog2(bigint &a) {
    bigint ans;
    ans.str = antilog2(a.str);
    return ans;
}
bigint bigint::_big_antilog10(bigint &a) {
    bigint ans;
    ans.str = antilog10(a.str);
    return ans;
}
void bigint::_big_swap(bigint &a, bigint &b) {
    swap(a.str, b.str);
}
bigint bigint::_big_reverse(bigint &a) {
    bigint ans;
    ans.str = reverse(a.str);
    return ans;
}
bigint bigint::_big_gcd(bigint &a, bigint &b) {
    bigint ans;
    ans.str = gcd(a.str, b.str);
    return ans;
}
bigint bigint::_big_lcm(bigint &a, bigint &b) {
    bigint ans;
    ans.str = lcm(a.str, b.str);
    return ans;
}
bigint bigint::_big_fact(bigint &a) {
    bigint ans;
    ans.str = fact(a.str);
    return ans;
}
bool bigint::_big_isPalindrome(bigint &a) {
    return isPalindrome(a.str);
}
bool bigint::_big_isPrime(bigint &a) {
    return isPrime(a.str);
}
bigint bigint::_to_bigint(std::string s) {
    bigint ans;
    ans.str = s;
    return ans;
}
bigint bigint::_to_bigint(int n) {
    bigint ans;
    ans.str = std::to_string(n);
    return ans;
}
bigint bigint::_to_bigint(long int n) {
    bigint ans;
    ans.str = std::to_string(n);
    return ans;
}
bigint bigint::_to_bigint(long long int n) {
    bigint ans;
    ans.str = std::to_string(n);
    return ans;
}

// ---------------------
//  Internal static defs
// ---------------------
bool bigint::is_bigint(std::string s) {
    if(s[0] == '-')
        s.erase(0,1);
    for(unsigned long long int i = 0; i < s.length(); ++i) {
        if(!(s[i] >= '0' && s[i] <= '9'))
            return false;
    }
    return true;
}

std::string bigint::add(std::string str1, std::string str2) {
    int str1_len = str1.length();
    int str2_len = str2.length();
    std::string sum = "";

    if(str1_len == 0 && str2_len == 0) {
        sum = "0";
    } else if(str1[0] == '-' && str2[0] == '-') {
        if(str1_len == 1 && str2_len == 1) {
            sum = "0";
        } else {
            sum = "-" + add(str1.erase(0, 1), str2.erase(0, 1));
        }
    } else if(str1[0] == '-') {
        sum = subtract(str2, str1.erase(0, 1));
    } else if(str2[0] == '-') {
        sum = subtract(str1, str2.erase(0, 1));
    } else {
        int i, j, track_sum, carry = 0;
        for(i = str1_len-1, j = str2_len-1; i >= 0 && j >= 0; --i, --j) {
            track_sum = (str1[i]-'0') + (str2[j]-'0') + carry;
            carry = track_sum/10;
            track_sum = track_sum%10;
            sum = std::to_string(track_sum) + sum;
        }
        while(i >= 0) {
            track_sum = (str1[i--]-'0') + carry;
            carry = track_sum/10;
            track_sum = track_sum%10;
            sum = std::to_string(track_sum) + sum;
        }
        while(j >= 0) {
            track_sum = (str2[j--]-'0') + carry;
            carry = track_sum/10;
            track_sum = track_sum%10;
            sum = std::to_string(track_sum) + sum;
        }
        if(carry) {
            sum = std::to_string(carry) + sum;
        }
    }
    return trim(sum);
}

std::string bigint::subtract(std::string str1, std::string str2) {
    if(str1 == str2)
        return "0";

    int str1_len = str1.length();
    int str2_len = str2.length();
    std::string sum = "";

    if(str1[0] == '-' && str2[0] == '-') {
        bigint t1(str1.erase(0,1));
        bigint t2(str2.erase(0,1));
        std::string temp = subtract(t2.str, t1.str);
        bigint mx(maximum(t2.str, t1.str));
        if(temp[0] != '-' && mx.str == t1.str) {
            sum = "-" + temp;
        } else {
            sum = temp;
        }
    } else if(str1[0] == '-') {
        sum = "-" + add(str1.erase(0,1), str2);
    } else if(str2[0] == '-') {
        sum = add(str1, str2.erase(0,1));
    } else {
        // Implementation
        if(str1_len < str2_len) {
            std::string tp = str1;
            str1 = str2;
            str2 = tp;
            sum = "-" + subtract(str1, str2);
            return trim(sum);
        } else if(str1_len == str2_len) {
            bigint a(str1);
            bigint b(str2);
            bigint mx(maximum(a.str, b.str));
            if(mx.str == str2) {
                std::string tp = str1;
                str1 = str2;
                str2 = tp;
                sum = "-" + subtract(str1, str2);
                return trim(sum);
            }
        }
        int carry = 0;
        for(int i=str1_len-1, j=str2_len-1; i>=0 || j>=0; i--, j--){
            int val1 = (i>=0) ? str1[i]-'0':0;
            int val2 = (j>=0) ? str2[j]-'0':0;
            int track_sum = val1 - val2 - carry;
            if(track_sum < 0) {
                track_sum += 10;
                carry = 1;
            } else {
                carry = 0;
            }
            sum = std::to_string(track_sum) + sum;
        }
    }
    return trim(sum);
}

std::string bigint::multiply(std::string str1, std::string str2) {
    bool neg = false;
    if(str1[0] == '-' && str2[0] == '-') {
        str1.erase(0,1);
        str2.erase(0,1);
    } else if(str1[0] == '-') {
        neg = true;
        str1.erase(0,1);
    } else if(str2[0] == '-') {
        neg = true;
        str2.erase(0,1);
    }
    if(str1=="0" || str2=="0") return "0";

    int n1 = str1.size();
    int n2 = str2.size();
    std::vector<int> result(n1+n2, 0);

    for(int i=n1-1; i>=0; i--){
        for(int j=n2-1; j>=0; j--){
            int mul = (str1[i]-'0')*(str2[j]-'0');
            mul += result[i+j+1];
            result[i+j+1] = mul%10;
            result[i+j] += mul/10;
        }
    }

    std::string ans;
    for(int c: result){
        if(!(ans.empty() && c==0))
            ans.push_back(c+'0');
    }
    if(ans.empty()) ans="0";
    if(neg && ans!="0") ans='-' + ans;
    return ans;
}

std::string bigint::divide(std::string str1, std::string str2) {
    if(str2=="0") {
        return "0"; // or throw
    }
    if(str1=="0") return "0";
    if(str1 == str2) return "1";

    bool neg = false;
    if(str1[0]=='-' && str2[0]=='-') {
        str1.erase(0,1);
        str2.erase(0,1);
    } else if(str1[0]=='-') {
        neg=true;
        str1.erase(0,1);
    } else if(str2[0]=='-') {
        neg=true;
        str2.erase(0,1);
    }
    if(is_strictlyMaximum(str2,str1)) {
        return "0";
    }
    if(str2=="1") {
        if(neg && str1!="0") return "-"+str1;
        else return str1;
    }

    // if str2 is small enough for shortDivide
    if(str2.size()<=19) {
        unsigned long long int s2 = std::stoull(str2);
        std::string ans=shortDivide(str1,s2);
        if(neg && ans!="0") ans='-'+ans;
        return ans;
    }

    // big approach
    std::string ans="0";
    while(str1 == maximum(str1,str2)) {
        int lenDiff = str1.size()-str2.size();
        if(lenDiff>0 && str1[0]>=str2[0]) {
            ans=add(ans, pow("10",std::to_string(lenDiff)));
            str1=subtract(str1,multiply(str2,pow("10",std::to_string(lenDiff))));
        } else if(lenDiff>0) {
            ans=add(ans, pow("10",std::to_string(lenDiff-1)));
            str1=subtract(str1,multiply(str2,pow("10",std::to_string(lenDiff-1))));
        } else {
            ans=add(ans,"1");
            str1=subtract(str1,str2);
        }
    }
    if(neg && ans!="0") ans='-'+ans;
    return ans;
}

std::string bigint::mod(std::string str1, std::string str2) {
    std::string tmp = multiply(divide(str1,str2), str2);
    return subtract(str1, tmp);
}

std::string bigint::shortDivide(std::string s1, unsigned long long int divisor) {
    std::string ans;
    long long int idx=0;
    long long int temp = s1[idx]-'0';
    while(temp<divisor && idx<(long long int)s1.size()-1) {
        temp=temp*10 + (s1[++idx]-'0');
    }
    while((long long int)s1.size()>idx) {
        ans.push_back((temp/divisor)+'0');
        temp=(temp%divisor)*10 + s1[++idx]-'0';
    }
    if(ans.size()==0) ans="0";
    return ans;
}

// max/min logic
std::string bigint::maximum(std::string str1, std::string str2) {
    bool bothNeg=false;
    if(str1[0]=='-' && str2[0]=='-') {
        bothNeg=true;
        str1.erase(0,1);
        str2.erase(0,1);
    } else if(str1[0]=='-') {
        return trim(str2);
    } else if(str2[0]=='-') {
        return trim(str1);
    }
    std::string ret;
    if(str1.size()>str2.size()) ret=str1;
    else if(str1.size()<str2.size()) ret=str2;
    else {
        if(str1>str2) ret=str1; else ret=str2;
    }
    if(bothNeg) {
        // if ret is str1 => actually str2 is bigger negative
        // but let's replicate the logic from the library
        if(ret==str1) {
            // means str1 is bigger => -str1 is more negative
            // so maximum is -str2
            // but let's keep consistent with library
            // we do: if str1 is bigger => we actually return "-" + str2
            // But let's just do what original code does:
            return "-" + trim(str2);
        } else {
            return "-" + trim(str1);
        }
    }
    return trim(ret);
}
bool bigint::is_maximum(std::string str1, std::string str2) {
    return (maximum(str1,str2)==str1);
}
bool bigint::is_strictlyMaximum(std::string str1, std::string str2) {
    if(str1==str2) return false;
    return (maximum(str1,str2)==str1);
}
std::string bigint::minimum(std::string str1, std::string str2) {
    std::string mx = maximum(str1,str2);
    if(mx==str1) return str2;
    return str1;
}
bool bigint::is_minimum(std::string str1, std::string str2) {
    return (minimum(str1,str2)==str1);
}
bool bigint::is_strictlyMinimum(std::string str1, std::string str2) {
    if(str1==str2) return false;
    return (minimum(str1,str2)==str1);
}

std::string bigint::trim(std::string s) {
    if(s=="0") return s;
    if(s[0]=='-') {
        int i=1; while(i<(int)s.size() && s[i]=='0') { s.erase(i,1); }
        return s;
    } else {
        int i=0; while(i<(int)s.size()-1 && s[i]=='0') { s.erase(i,1); }
        return s;
    }
}

// absolute
std::string bigint::abs(std::string s) {
    if(s[0]=='-') s.erase(0,1);
    return s;
}

std::string bigint::pow(std::string str1, std::string str2) {
    if(str2=="0") return "1";
    if(str1=="0") {
        // 0^neg => ?
        // For brevity:
        return "0";
    }
    bool neg=false;
    if(str1[0]=='-') {
        str1.erase(0,1);
        if((str2.back()-'0')%2!=0) {
            neg=true;
        }
    } else if(str2[0]=='-') {
        // a^(negative) => ~ 1/a^(abs(neg)) => 0
        return "0"; 
    }
    std::string base=str1;
    while(str2!="1") {
        str1=multiply(str1, base);
        str2=subtract(str2,"1");
    }
    if(neg && str1!="0") str1='-'+str1;
    return str1;
}

std::string bigint::sqrt(std::string s) {
    if(s=="0") return "0";
    if(s[0]=='-') {
        // no real sqrt for negative in normal sense
        return s; 
    }
    // approximate approach from library
    unsigned long long s_len=s.size();
    std::string low, high;
    if(s_len&1) {
        low=pow("10", std::to_string((s_len)/2));
        high=pow("10", std::to_string((s_len+1)/2));
    } else {
        low=pow("10", std::to_string((s_len-2)/2));
        high=pow("10", std::to_string((s_len)/2));
    }
    std::string mid, sq, prev;
    while(true) {
        mid=divide(add(low,high),"2");
        sq=multiply(mid,mid);
        if(mid==prev) break;
        if(is_maximum(sq,s)==true && sq!=s) {
            high=mid;
        } else {
            low=mid;
        }
        prev=mid;
    }
    return mid;
}

std::string bigint::log2(std::string s) {
    if(s=="0" || s[0]=='-') return "0"; 
    std::string cnt="0";
    while(is_strictlyMaximum(s,"0")) {
        s=divide(s,"2");
        cnt=add(cnt,"1");
    }
    return subtract(cnt,"1");
}

std::string bigint::log10(std::string s) {
    if(s=="0" || s[0]=='-') return "0";
    // approximate => numDigits-1
    return std::to_string(s.size()-1);
}

std::string bigint::logwithbase(std::string val, std::string base) {
    std::string lval=log2(val);
    std::string lbase=log2(base);
    return divide(lval,lbase);
}

std::string bigint::antilog2(std::string s) {
    return pow("2", s);
}
std::string bigint::antilog10(std::string s) {
    return pow("10", s);
}
void bigint::swap(std::string &str1, std::string &str2) {
    std::string tmp=str1;
    str1=str2;
    str2=tmp;
}
std::string bigint::reverse(std::string s) {
    bool neg=false;
    if(s[0]=='-'){ neg=true; s.erase(0,1); }
    int beg=0, end=s.size()-1;
    while(beg<end) {
        char c=s[beg];
        s[beg]=s[end];
        s[end]=c;
        beg++; end--;
    }
    if(neg) s='-'+s;
    return s;
}
std::string bigint::gcd(std::string str1, std::string str2) {
    while(is_strictlyMaximum(str2,"0")){
        std::string tmp=mod(str1,str2);
        str1=str2;
        str2=tmp;
    }
    return str1;
}
std::string bigint::lcm(std::string str1, std::string str2) {
    return divide(multiply(str1,str2), gcd(str1,str2));
}
std::string bigint::fact(std::string s) {
    if(s[0]=='-') {
        throw std::runtime_error("Factorial negative not defined.");
    }
    if(s=="0") return "1";
    std::string ans="1";
    while(s!="0") {
        ans=multiply(ans,s);
        s=subtract(s,"1");
    }
    return ans;
}
bool bigint::isPalindrome(std::string s) {
    if(s[0]=='-') s.erase(0,1);
    int beg=0, end=s.size()-1;
    while(beg<end) {
        if(s[beg]!=s[end]) return false;
        beg++; end--;
    }
    return true;
}
bool bigint::isPrime(std::string s) {
    if(maximum(s,"2")!=s) return false;
    std::string sq=sqrt(s);
    for(std::string i="2"; is_maximum(sq,i); i=add(i,"1")) {
        if(mod(s,i)=="0") return false;
    }
    return true;
}
