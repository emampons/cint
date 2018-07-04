#ifndef CINT_BIGINT_H
#define CINT_BIGINT_H

#include <vector>
#include <string>

class BigInt {
private:
    std::vector<int> digits;


public:
    BigInt();
    explicit BigInt(int );
    explicit BigInt(std::string);
    ~BigInt();

    // Addition
    BigInt operator+(const BigInt& big);
    BigInt& operator+=(const BigInt& big);
    // Multiplication
    //BigInt operator*(const BigInt& big);
    //BigInt& operator*=(const BigInt& big );
    // Subtraction
    //BigInt operator-(const BigInt& big);
    //BigInt& operator-=(const BigInt& big);
    // Division
    //BigInt operator/(const BigInt& big);
    //BigInt& operator/=(const BigInt& big);

    std::string to_string();


};
#endif //CINT_BIGINT_H
