#include <iostream>
#include <string>
#include "rational_exception.h"
#include "rational.h"

int Rational::gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

Rational::Rational(int num, int denom) {
    if (denom == 0) {
        throw RationalException("Can't have 0 denom.");
    } else {
        int x = gcd(num, denom);
        this->num = num / x;
        this->denom = denom / x;
    }
}

Rational::Rational(int num) {
    this->num = num;
    this->denom = 1;
}

Rational::Rational() {
    num = 0;
    denom = 1;
}

Rational::Rational(const Rational &other) {
    if (denom == 0) 
        throw RationalException("Can't have 0 denom.");

    num = other.num;
    denom = other.denom;
    int x = gcd(num, denom);

    this->num = num / x;
    this->denom = denom / x;
}

Rational Rational::neg() const {return Rational(-num, denom);}

Rational Rational::inv() const {return Rational(denom, num);}

int Rational::getNumerator() const {return num;}

int Rational::getDenominator() const {return denom;}

Rational Rational::add(const Rational &other) const {return Rational(num * other.denom + other.num * denom, denom * other.denom);}

Rational Rational::sub(const Rational &other) const {return add(other.neg());}

Rational Rational::mul(const Rational &other) const {return Rational(num * other.num, denom * other.denom);}

Rational Rational::div(const Rational &other) const {return mul(other.inv());}

Rational &Rational::addInPlace(const Rational &other) {
    num = num * other.denom + other.num * denom;
    denom = denom * other.denom;
    int x = gcd(num, denom);
    num /= x;
    denom /= x;

    //Reference of the current instance.
    return *this;
};

Rational &Rational::subInPlace(const Rational &other) {addInPlace(other.neg());}

Rational &Rational::mulInPlace(const Rational &other) {
    num = num * other.num;
    denom = denom * other.denom;
    int x = gcd(num, denom);
    num /= x;
    denom /=x;

    return *this;
}

Rational &Rational::divInPlace(const Rational &other) {mulInPlace(other.inv());}

int Rational::compareTo(const Rational &other) const {
    Rational temp = sub(other);

    if (temp.num > 0 && temp.denom > 0) return 1;
    else if (temp.num < 0 || temp.denom < 0) return -1;
    else return 0;
}

bool Rational::equals(const Rational &other) const {return compareTo(other) == 0;}

void Rational::print(std::ostream &os) const {
    os << num;
    if (denom != 1)
        os << "/" << denom;
}