#include "Money.h"

int Money::CountObj = 0;

Money::Money() : z(0), q(0) { CountObj++; }

int Money::Count() {
    return CountObj;
}

Money::Money(const Money &mon) {
    z = mon.z;
    q = mon.q;
    CountObj++;
}

Money::Money(double a) {
    this->Update(a);
    CountObj++;
}

Money& Money::operator=(const Money &mon) {
    if (this != &mon) {
        z = mon.z;
        q = mon.q;
    }
    return *this;
}

Money operator+(const Money &mon1, const Money &mon2) {
    Money res;
    res.z = mon1.z + mon2.z;
    res.q = (mon1.q + mon2.q) % 100;
    int k = mon1.q + mon2.q;
    while (k >= 100) {
        res.z += 1;
        k -= 100;
    }
    return res;
}

Money operator-(const Money &mon1, const Money &mon2) {
    Money res;
    res.z = mon1.z - mon2.z;
    if (mon1.q - mon2.q >= 0) {
        res.q = mon1.q - mon2.q;
    }
    else {
        res.q = mon1.q - mon2.q + 100;
        res.z--;
    }
    return res;
}

double Money::Real() const {
    return (double)(z + (double)q / 100.0);
}

void Money::Update(double a) {
    z = (int)a;
    a -= (int)a;
    a *= 100;
    if ((int)a < 100) {
        q = (int)a;
        if (a < 0) {
            q *= -1;
        }
    }
    else {
        int des = 0;
        a = (int)a;
        if (a < 0) {
            a *= -1;
        }
        a -= 100;
        z += 1;
        q = a;
    }
    while (q >= 100) {
        z += 1;
        q -= 100;
    }
}

Money operator/(const Money &mon1, const Money &mon2) {
    Money res;
    res.Update(mon1.Real() / mon2.Real());
    return res;
}

std::ostream& operator << (std::ostream &stream, const Money &obj) {
    stream << obj.z << ",";
    if ((int)(obj.q) < 10) {
        stream << "0";
    }
    stream << (int)(obj.q);
    return stream;
}

std::istream& operator >> (std::istream &stream, Money &obj) {
    int k;
    stream >> obj.z;
    stream >> k;
    obj.q = k%100;
    while (k >= 100) {
        obj.z += 1;
        k -= 100;
    }
    return stream;
}

Money operator*(const Money &mon, double a) {
    Money res;
    res.Update(mon.Real() * a);
    return res;
}

Money operator*(double a, const Money &mon) {
    return operator*(mon, a);
}

Money operator/(const Money &mon, double a) {
    Money res;
    res.Update(mon.Real() / a);
    return res;
}

bool operator>(const Money &mon1, const Money &mon2) {
    if (mon1.z > mon2.z) {
        return true;
    }
    if (mon1.z < mon2.z) {
        return false;
    }
    if (mon1.q > mon2.q) {
        return true;
    }
    if (mon1.q < mon2.q) {
        return false;
    }
    return false;
}

bool operator<(const Money &mon1, const Money &mon2) {
    return operator>(mon2, mon1);
}

bool operator>=(const Money &mon1, const Money &mon2) {
    if (mon1.z > mon2.z) {
        return true;
    }
    if (mon1.z < mon2.z) {
        return false;
    }
    if (mon1.q > mon2.q) {
        return true;
    }
    if (mon1.q < mon2.q) {
        return false;
    }
    return true;
}

bool operator<=(const Money &mon1, const Money &mon2) {
    return operator>=(mon2, mon1);
}

bool operator==(const Money &mon1, const Money &mon2) {
    if (mon1.z == mon2.z && mon1.q == mon2.q) {
        return true;
    }
    return false;
}

Money& Money::operator+=(const Money &mon) {
    z += mon.z;
    q += (q + mon.q) % 100;
    while (q >= 100) {
        z += 1;
        q -= 100;
    }
    return *this;
}

Money& Money::operator-=(const Money &mon) {
    z -= mon.z;
    if (q - mon.q >= 0) {
        q -= mon.q;
    }
    else {
        q -= mon.q + 100;
        z--;
    }
    return *this;
}

Money& Money::operator*=(double a) {
    Update(Real()*a);
    return *this;
}

Money& Money::operator/=(double a) {
    Update(Real() / a);
    return *this;
}

int Money::GetZ() {
    return z;
}

int Money::GetQ() {
    return (int)q;
}
