#include <iostream>

#include "mystring.h"
#include "mystring_exception.h"

#define DEFAULT_SIZE 100

namespace mystring {

    char *strcpy(char *dest, const char *src);
    char *strcat(char *dest, const char *src);
    int strlen(const char *str);

    bool needs_resizing(int len1, int len2) {
        return (len1 + len2 + 1) > DEFAULT_SIZE;
    }

    string::string(const char* cs): cs(new char[DEFAULT_SIZE]) {
        strcpy(this->cs, cs);
    }

    string::string(const string &s): string(s.cs) {}

    void string::clear() {
        delete [] cs;
        cs = new char[DEFAULT_SIZE];
    }

	int string::length() const {
        return strlen(cs);
    }

    std::ostream &operator<<(std::ostream &os, const string &s) {

        char *temp = s.cs;
        while(*temp) {
            os << *temp;
            temp++;
        }

        return os;
    }

    string operator+(const string &s1, const string &s2) {
        string temp1 = s1;
        strcat(temp1.cs, s2.cs);

        return temp1;
    }

    string::~string() {
        delete [] cs;
    }

    string &string::operator=(const string &rhs) {
        this->clear();
        char *temp = strcpy(cs, rhs.cs);
        cs = temp;
        return *this;
    }

    string &string::operator+=(const string &s) {

        string temp(s.cs);
        char *start = strcat(cs, temp.cs);

        cs = start;

        return *this;
    }

    char &string::operator[](int index) {
        return cs[index];
    }

    int strlen(const char *str) {
        int counter = 0;
        while (*str) {
            counter++;
            str++;
        }
        return counter;
    }

    char *strcpy(char *dest, const char *src) {

        char *start = dest, *temp, *temp_start;

        if (needs_resizing( strlen(dest), strlen(src) )) {
            temp = new char[strlen(dest) + strlen(src) + 1];

            // Save pointer to the first index (to later retrieve it).
            temp_start = temp;

            // Copy contents of the original character array.
            while(*dest) {
                *temp = *dest;
                dest++;
                temp++;
            }

            // Overwrite the "start" pointer.
            start = temp_start;

            // dest is now resized (and pointing to the first element).
            dest = temp_start;
        }

        while (*src) {
            *dest = *src;
            dest++;
            src++;
        }

        *dest = '\0';
        return start;
    }

    char *strcat(char *dest, const char *src) {

        char *start = dest, *temp, *temp_start;
        if (needs_resizing( strlen(dest), strlen(src) )) {
            temp = new char[strlen(dest) + strlen(src) + 1];

            temp_start = temp;

            // Copy contents of the original character array.
            while(*dest) {
                *temp = *dest;
                dest++;
                temp++;
            }

            // Overwrite the "start" pointer.
            start = temp_start;

            // dest is now resized (and pointing to the first element).
            dest = temp_start;
        }

        // Approach to the trailing value.
        while(*dest)
            dest++;

        // leveraging functionality.
        strcpy(dest, src);

        return start;
    }
}