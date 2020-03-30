#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
    private:
        int num;
        int denom;
        static int gcd(int a, int b);
    public:
        Rational(int num, int denom);
        Rational(int num);
        Rational();
        Rational(const Rational &other);

        Rational neg() const;
        Rational inv() const;

        int getNumerator() const;
        int getDenominator() const;

        Rational add(const Rational &other) const;
        Rational sub(const Rational &other) const;
        Rational mul(const Rational &other) const;
        Rational div(const Rational &other) const;

        Rational &addInPlace(const Rational &other);
        Rational &subInPlace(const Rational &other);
        Rational &mulInPlace(const Rational &other);
        Rational &divInPlace(const Rational &other);

        int compareTo(const Rational &other) const;
        bool equals(const Rational &other) const;

        void print(std::ostream &os) const;
};

inline std::ostream &operator <<(std::ostream &os, const Rational &r) {r.print(os);}

#endif