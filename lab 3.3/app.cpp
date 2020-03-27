#include <iostream>
#include <string>
#include "reverse.h"

using namespace std;

int main() {
    cout << "Playing with int" << endl;
    int a[] = {10, 20, 30, 40, 50};
    cout << "Before: ";
    print(a, 5);
    reverse(a, 5);
    cout << "\nAfter: ";
    print(a, 5);

    cout << "\n\nPlaying with double" << endl;
    double b[] = {10.5, 20.5, 30.5, 40.5, 50.5, 60.5};
    cout << "Before: ";
    print(b, 6);
    reverse(b, 6);
    cout << "\nAfter: ";
    print(b, 6);

    cout << "\n\nPlaying with string" << endl;
    string c[] = {"ABC", "DE", "FGHI", "JK"};
    cout << "Before: ";
    print(c, 4);
    reverse(c, 4);
    cout << "\nAfter: ";
    print(c, 4);

    return 0;
}