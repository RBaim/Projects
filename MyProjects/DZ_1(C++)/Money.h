#pragma once

#include <iostream>

class Money {
public:
    Money();
    Money(const Money &mon);
    Money(double A);
    Money& operator+=(const Money &mon);
    Money& operator-=(const Money &A);
    Money& operator*=(double a);
    Money& operator/=(double a);
    friend Money operator+(const Money &mon1, const Money &mon2);
    friend Money operator-(const Money &mon1, const Money &mon2);
    friend Money operator/(const Money &mon1, const Money &mon2);
    friend std::ostream& operator << (std::ostream &stream, const Money &obj);
    friend std::istream& operator >> (std::istream &stream, Money &obj);
    friend Money operator*(const Money &mon, double a);
    friend Money operator*(double a, const Money &mon);
    friend Money operator/(const Money &mon, double a);
    friend bool operator>(const Money &mon1, const Money &mon2);
    friend bool operator<(const Money &mon1, const Money &mon2);
    friend bool operator>=(const Money &mon1, const Money &mon2);
    friend bool operator<=(const Money &mon1, const Money &mon2);
    friend bool operator==(const Money &mon1, const Money &mon2);
    Money &operator=(const Money &A);
    void Update(double a);
    double Real() const;
    int GetZ();
    int GetQ();
    static int Count();
private:
    static int CountObj;
    long z;
    unsigned char q;
};
