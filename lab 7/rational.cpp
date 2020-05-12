#include <iostream>

#include "gcd.h"
#include "rational.h"
#include "rational_exception.h"

Rational::Rational(int num, int denom) : num(num), denom(denom) {
    if (denom == 0) {
        throw RationalException("Can't have 0 denom.");
    } else {
        int divisor = gcd(num, denom);
        this->num = num / divisor;
        this->denom = denom / divisor;
    }
}

int Rational::getNumerator() const {return num;}
int Rational::getDenominator() const {return denom;}

Rational Rational::operator-() const {return Rational(-num, denom);}
Rational Rational::inv() const {return Rational(denom, num);}

Rational &Rational::operator+=(const Rational &r) {
    num = num * r.denom + r.num * denom;
    denom = denom * r.denom;
    int divisor = gcd(num, denom);
    num /= divisor;
    denom /= divisor;

    //Reference to the current instance.
    return *this;
}

Rational &Rational::operator-=(const Rational &r) {return operator+=(r.operator-());}

Rational &Rational::operator*=(const Rational &r) {
    num = num * r.num;
    denom = denom * r.denom;
    int divisor = gcd(num, denom);
    num /= divisor;
    denom /= divisor;

    return *this;
}

Rational &Rational::operator/=(const Rational &r) {
    return operator*=(r.inv());
}

int Rational::compareTo(const Rational &r) const {
    //Find difference and inspect it.
    int temp = num * r.denom - r.num * denom;

    if (temp > 0) return 1;
    else if (temp < 0) return -1;
    else return 0;
}

void Rational::print(std::ostream &os) const {
    os << num;
    if (denom != 1)
        os << "/" << denom;
}

Rational operator+(const Rational &r1, const Rational &r2) {
    Rational temp(r1.getNumerator(), r1.getDenominator());
    return temp+=r2;
}

Rational operator-(const Rational &r1, const Rational &r2) {
    Rational temp(r1.getNumerator(), r1.getDenominator());
    return temp-=r2;
}

Rational operator*(const Rational &r1, const Rational &r2) {
    Rational temp(r1.getNumerator(), r1.getDenominator());
    return temp*=r2;
}

Rational operator/(const Rational &r1, const Rational &r2) {
    Rational temp(r1.getNumerator(), r1.getDenominator());
    return temp/=r2;
}

bool operator==(const Rational &r1, const Rational &r2) {
    Rational temp(r1.getNumerator(), r1.getDenominator());
    return temp.compareTo(r2) == 0;
}

std::ostream &operator<<(std::ostream &os, const Rational &r) {
    Rational temp(r.getNumerator(), r.getDenominator());
    temp.print(os);
    return os;
}