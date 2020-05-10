#include <iostream>
#include "cstring.h"

using namespace mystring;
using std::cout;
using std::endl;

int main() {

    // Using strlen()
    char myString[100] = "Hello";
    cout << "myString contains: " << myString << endl;
    cout << "strlen of the myString is: " << strlen(myString) << endl;

    // Using strcpy()
    char src[100] = "World";
    char dest[100];
    cout << "strcpy of src into dest: " << strcpy(dest, src) << endl;

    // Using strcat()
    strcat(dest, " ");
    cout << "strcat: " << strcat(myString, src) << endl;

    // Using strchr()
	const char *pos = strchr(myString, 'e');
	if (!pos)
		cout << "'e' not found in " << myString << endl;
	else
		cout << "'e' found at position " << (pos - myString) << " in " << myString << endl;

    // Using strrchr()
    char s1[100] = "Hello";
    pos = strrchr(s1, 'l');
	if (!pos)
		cout << "'l' not found in " << s1 << endl;
	else
		cout << "'l' last found at position " << (pos - s1) << " in " << s1 << endl;

    // Using strcmp()
    char s2[100] = "Apple";
    char s3[100] = "Banana";
    cout << "strcmp " << s2 << " and " << s3 << " " << strcmp(s2, s3) << endl;
    cout << "strcmp " << s3 << " and " << s2 << " " << strcmp(s3, s2) << endl;
    cout << "strcmp " << s2 << " and " << s2 << " " << strcmp(s2, s2) << endl;


    return 0;
}
