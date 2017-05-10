#pragma once

#include "Money.h"

class Account {
public:
    Account();
    Account(const Account &acc);
    Account(char *name, int num, double proc, Money &sum, char currency);
    ~Account();
    void NewName(char *newname);
    void RemoveSum(const Money &rem);
    void PutSum(const Money &put);
    void Percentages();
    void Dollars();
    void Euro();
    void Rub();
    static int Count();
    friend std::ostream& operator << (std::ostream &stream, const Account &obj);
    friend std::istream& operator >> (std::istream &stream, Account &obj);
    std::string towords();
private:
    static int CountObj;
    std::string _towords(int numb);
    char Ñurrency;
    char Name[32];
    int Num;
    double Proc;
    Money Sum;
};