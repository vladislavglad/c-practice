#ifndef MYSTRING_EXCEPTION
#define MYSTRING_EXCEPTION

using namespace std;

class MystringException {
    public:
        MystringException(char* what) : what(what) {}
        char* getWhat() {return what;}
    private:
        char* what;
};

#endif