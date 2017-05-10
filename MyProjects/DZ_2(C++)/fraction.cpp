#include "fraction.h"
#include "Exc.h"

Fraction::Fraction(int size_a, int start) : Array(size_a, start) {
    if (size_a > maxlenght) throw ErrorSizeLimit();
    array_f = new unsigned char[maxlenght];
    lenght_f = size_a;
    for (int i = 0; i < maxlenght; i++)
        array_f[i] = start;
}

Fraction::Fraction(const Fraction& p_fr) : Array(p_fr) {
    array_f = new unsigned char[maxlenght];
    for (int i = 0; i < p_fr.lenght_f; i++)
        array_f[i] = p_fr.array_f[i];
    lenght_f = p_fr.lenght_f;
}

int nod(int x, int y) {
    while (x != y) {
        if (x > y) x = x - y;
        else y = y - x;
    }
        return y;
}

int Fraction::ToInt_f() const {
    int res = 0;
    for (int i = 0; i < lenght_f; i++)
        res += (int)pow(10, i) * (int)array_f[lenght_f - 1 - i];
    return res;
}

void Fraction::InputVals(int num_1, int num_2) {
    if (num_2 < 0) throw DevNilFraction(num_1);
    try {
        InputVal(num_1);
    }
    catch (ErrorSizeLimit) {
        throw ErrorSizeLimit();
    }
    int numc = num_2;
    int count = 0;
    while (numc != 0) {
        count++;
        numc /= 10;
    }
    if(count > maxlenght) throw ErrorSizeLimit();
    for (int i = count - 1; i >= 0; i--) {
        array_f[i] = num_2 % 10;
        num_2 /= 10;
    }
    lenght_f = count;
}

void Fraction::NOD() {
    if (!nod(ToInt(), ToInt_f())) throw DevNilFraction(ToInt());
    InputVals(ToInt() / nod(ToInt(), ToInt_f()), ToInt_f() / nod(ToInt(), ToInt_f()));
}

Fraction Fraction::operator + (const Fraction& op2) {
    Fraction res;
    try {
        res.InputVals(ToInt()*op2.ToInt_f() + ToInt_f()*op2.ToInt(), ToInt_f()*op2.ToInt_f());
    }
    catch (ErrorSizeLimit) {
        throw ErrorSizeLimit();
    }
    res.NOD();
    return res;
}

Fraction operator - (const Fraction& op1, const Fraction& op2) {
    Fraction res;
    if (op1.ToInt()*op2.ToInt_f() - op1.ToInt_f()*op2.ToInt() < 0) throw ErrorMinusFraction(op1.ToInt(), op1.ToInt_f(), op2.ToInt(), op2.ToInt_f());
    if (!op1.ToInt_f()*op2.ToInt_f()) throw DevNilFraction(op1.ToInt()*op2.ToInt_f() - op1.ToInt_f()*op2.ToInt());
    res.InputVals(op1.ToInt()*op2.ToInt_f() - op1.ToInt_f()*op2.ToInt(), op1.ToInt_f()*op2.ToInt_f());
    res.NOD();
    return res;
}

Fraction operator * (const Fraction& op1, const Fraction& op2) {
    Fraction res;
    try {
        res.InputVals(op1.ToInt()*op2.ToInt(), op1.ToInt_f()*op2.ToInt_f());
    }
    catch (ErrorSizeLimit) {
        throw ErrorSizeLimit();
    }
    res.NOD();
    return res;
}

Fraction& Fraction::operator = (const Fraction& op) {
    if (this != &op) {
        Array::operator = (op);
        lenght_f = op.lenght_f;
        for (int i = 0; i < lenght_f; i++)
            array_f[i] = op.array_f[i];
    }
    return *this;
}

bool operator > (const Fraction& op1, const Fraction& op2) {
    if (double(double(op1.ToInt()) / double(op1.ToInt_f())) > double(double(op2.ToInt()) / double(op2.ToInt_f())))
        return true;
    return false;
}

bool operator < (const Fraction& op1, const Fraction& op2) {
    return operator > (op2, op1);
}

bool operator == (const Fraction& op1, const Fraction& op2) {
    if (op1.ToInt() == op2.ToInt() && op1.ToInt_f() == op2.ToInt_f())
        return true;
    return false;
}

bool operator >= (const Fraction& op1, const Fraction& op2) {
    if (operator > (op1, op2) || operator == (op1, op2))
        return true;
    return false;
}

bool operator <= (const Fraction& op1, const Fraction& op2) {
    return operator >= (op2, op1);
}

std::ostream& operator << (std::ostream& stream, const Fraction& obj) {
    stream << obj.ToInt() << '/' << obj.ToInt_f();
    return stream;
}

std::istream& operator >> (std::istream& stream, Fraction& obj) {
    int input1, input2;
    stream >> input1 >> input2;
    if (!input2) throw DevNilFraction(input1);
    if (input1 < 0 || input2 < 0) throw ErrorNumWrite();
    try {
        obj.InputVals(input1, input2);
    }
    catch (ErrorSizeLimit) {
        throw ErrorSizeLimit();
    }
    return stream;
}
