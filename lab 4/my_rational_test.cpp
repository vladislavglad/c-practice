#include <iostream>
#include <string>
#include "rational.h"
#include "rational_exception.h"

using namespace std;

void print(Rational &r);

int main() {
    try {
        //Constructing Rational.
        Rational r1(2, 4);
        print(r1);

        //Inverse.
        Rational r2 = r1.inv();
        print(r2);

        //Addition.
        Rational r3 = r1.add(r2);
        print(r3);

        //0 denom.
        Rational r4(1, 0);

        return 0;
    } catch (RationalException e) {
        cout << e.getWhat() << endl;
        exit(1);
    }
}

void print(Rational &r) {
    cout << r.getNumerator() << "/";
    cout << r.getDenominator() << endl;
}