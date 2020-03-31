#include "rational.h"
#include "rational_exception.h"
#include <iostream>

int get_divisor(int a, int b) {
    if(b == 0)
        return a;
    return get_divisor(b, a % b);
}

Rational::Rational(int num, int denom) : num(num), denom(denom) {
    if (denom == 0) {
        throw RationalException("Can't have 0 denom.");
    } else {
        int divisor = get_divisor(num, denom);
        this->num = num / divisor;
        this->denom = denom / divisor;
    }
}

Rational::Rational(int num) : Rational(num, 1) {}

Rational::Rational() : Rational(0, 1) {}

Rational::Rational(const Rational &other) : Rational(other.num, other.denom) {}

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
    int divisor = get_divisor(num, denom);
    num /= divisor;
    denom /= divisor;

    //Reference to the current instance.
    return *this;
};

Rational &Rational::subInPlace(const Rational &other) {return addInPlace(other.neg());}

Rational &Rational::mulInPlace(const Rational &other) {
    num = num * other.num;
    denom = denom * other.denom;
    int divisor = get_divisor(num, denom);
    num /= divisor;
    denom /= divisor;

    return *this;
}

Rational &Rational::divInPlace(const Rational &other) {return mulInPlace(other.inv());}

int Rational::compareTo(const Rational &other) const {
    //Find difference and inspect it.
    int temp = this->num * other.denom - other.num * this->denom;

    if (temp > 0) return 1;
    else if (temp < 0) return -1;
    else return 0;
}

bool Rational::equals(const Rational &other) const {return compareTo(other) == 0;}

void Rational::print(std::ostream &os) const {
    os << num;
    if (denom != 1)
        os << "/" << denom;
}