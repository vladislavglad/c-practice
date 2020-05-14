#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

namespace mystring {

class string {
	friend std::ostream &operator <<(std::ostream &os, const string &s);
	friend string operator +(const string &s1, const string &s2);
public:
	string(const char *cs="");
	string(const string &s);
	~string();
	string &operator =(const string &rhs);
	char &operator [](int index);
	string &operator +=(const string &s);
	int length() const;
	void clear();
private:
	char *cs;
};

}

#endif