#include <iostream>

#include "mystring.h"
#include "mystring_exception.h"

#define DEFAULT_SIZE 10000

namespace mystring {

    char *strcpy(char *dest, const char *src);
    char *strcat(char *dest, const char *src);
    int strlen(const char *str);

    string::string(const char* cs): cs(new char[DEFAULT_SIZE]) {
        strcpy(this->cs, cs);
    }

    string::string(const string &s): cs(new char[DEFAULT_SIZE]) {
        strcpy(cs, s.cs);
    }

    void string::clear() {
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

    char *end_pointer(char* str) {
        return &str[strlen(str)];
    }

    string operator+(const string &s1, const string &s2) {
        char *temp = strcat(s1.cs, s2.cs);

        return string(temp);
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
        char *start = dest;

        while (*src) {
            *dest = *src;
            dest++;
            src++;
        }

        *dest = '\0';
        return start;
    }

    char *strcat(char *dest, const char *src) {
        char *start = dest;

        // Approach to the trailing value.
        while(*dest)
            dest++;

        // leveraging functionality.
        strcpy(dest, src);

        return start;
    }
}