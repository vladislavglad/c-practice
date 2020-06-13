#include <iostream>

#include "mystring.h"
#include "mystring_exception.h"

#define DEFAULT_SIZE 100

namespace mystring {
    
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

    int strlen(const char *str) {
        int counter = 0;
        while (*str) {
            counter++;
            str++;
        }
        return counter;
    }

    bool needs_resizing(char* s1, const char* s2) {
        return (strlen(s1) + strlen(s2) + 1) > DEFAULT_SIZE;
    }

    char* adjust_buffer_size(char* s1, const char* s2) {
        char *temp = new char[strlen(s1) + strlen(s2) + 1];
        return strcpy(temp, s1);
    }

    string::string(const char* cs): cs(new char[DEFAULT_SIZE]) {

        if ( needs_resizing(this->cs, cs) )
            this->cs = adjust_buffer_size(this->cs, cs);
        strcpy(this->cs, cs);
    }

    string::string(const string &s): string(s.cs) {}

    void string::clear() {
        delete [] cs;
        cs = new char[DEFAULT_SIZE];
        *cs = '\0';
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
        
        char *temp = s1.cs;
        if ( needs_resizing(s1.cs, s2.cs) )
            temp = adjust_buffer_size(s1.cs, s2.cs);

        string new_string = temp;
        strcat(new_string.cs, s2.cs);

        return new_string;
    }

    string::~string() {
        delete [] cs;
    }

    string &string::operator=(const string &rhs) {
        this->clear();

        char *temp = cs;
        if ( needs_resizing(cs, rhs.cs) )
            temp = adjust_buffer_size(cs, rhs.cs);

        temp = strcpy(temp, rhs.cs);
        cs = temp;
        return *this;
    }

    string &string::operator+=(const string &s) {

        // Make a copy of the object 
        // (in case string is added in place with itself).
        string s2 = s;

        char *temp = cs, *temp2 = s2.cs;
        if ( needs_resizing(temp, temp2) )
            temp = adjust_buffer_size(temp, temp2);

        cs = strcat(temp, temp2);
        
        return *this;
    }

    char &string::operator[](int index) {
        if ( index > strlen(cs) - 1 ) {
            char msg[] = "Index out of bounds!";
            throw MystringException(msg);
        }
        return cs[index];
    }
}