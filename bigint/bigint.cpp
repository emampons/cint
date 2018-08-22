#include <iostream>
#include <sstream>
#include "bigint.h"


BigInt::BigInt() = default;

BigInt::BigInt(long long number) {
    while(number > 0){
        if()
        digits.push_back(number%10);
        number /= 10;
    }
}

struct NotABigIntException: public std::exception
{
    virtual const char* what() const throw()
    {
        return "This is not a valid big integer";
    }
} NotABigIntException;


BigInt::BigInt(std::string number) {
    std::size_t found = number.find_first_not_of("1234567890");
    // Makes sure string only contains numbers and no other characters
    if(found == std::string::npos){
        unsigned long length = number.length();
        while(length){
            char temp = number[length-1];
            int place = temp - '0';
            digits.push_back(place);
            length--;
        }

    }
    else {
        throw NotABigIntException;
    }

}





BigInt::~BigInt() = default;


BigInt BigInt::operator+(const BigInt &big) {
    BigInt ref = *this;
    ref += big;
    return ref;
}

BigInt& BigInt::operator+=(const BigInt& big) {
    auto this_iterator = digits.begin();
    auto that_iterator = big.digits.begin();
    int sum = 0;

    while(this_iterator != digits.end() || that_iterator != big.digits.end()){

        if(that_iterator != big.digits.end()){
            sum += *that_iterator;
            ++that_iterator;
        }
        if(this_iterator != digits.end()){
            sum += *this_iterator;
        }
        else{
            //accounts for when second number is longer than first
            digits.push_back(0);
            this_iterator = digits.end()-1;
        }

        *this_iterator = sum % 10;
        ++this_iterator;
        sum /= 10;

    }
    if(sum)
        digits.push_back(1);
    return *this;
}


BigInt &BigInt::operator+=(long long) {

    return *this;
}


BigInt BigInt::operator-(const BigInt& big) {
    BigInt ref = *this;
    ref -= big;
    return ref;
}

BigInt& BigInt::operator-=(const BigInt& big) {
    auto this_iterator = digits.begin();
    auto that_iterator = big.digits.begin();
    int difference = 0;
    while(that_iterator != big.digits.end() || this_iterator != digits.end()){
        int borrow = 0;
        if(this_iterator != digits.end()){

        }
    }
    return *this;
}



BigInt BigInt::operator*(const BigInt &big) {
    BigInt ref = *this;
    ref *= big;
    return ref;
}

BigInt& BigInt::operator*=(const BigInt& big) {
    auto this_iterator = digits.begin();
    auto that_iterator = big.digits.begin();
    BigInt ret (1);
    for(;this_iterator != digits.end(); this_iterator++){
        for(; that_iterator != big.digits.end(); that_iterator++){
            ret += *that_iterator * *this_iterator;
        }



    }
    return *this;
}

// TODO - Fix order
std::string BigInt::to_string() {
    std::ostringstream stream;
    for(auto &a: digits)
        stream<<a;
    std::string ret = stream.str();
    std::reverse(ret.begin(), ret.end());
    return ret;
}

std::array<int> BigInt::resize() {
    return nullptr;
}





