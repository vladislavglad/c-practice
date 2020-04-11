#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include "student.h"

using namespace std;

void load(string fname, set<Student, greater<Student>> &students);
void print(set<Student, greater<Student>> &students);

int main() {
    try {
        //"global" set container.
        set<Student, greater<Student>> students;

        load("student.dat", students);

        print(students);

    } catch(string error) {
        cout << error << endl;
        exit(1);
    }
    return 0;
}

void load(string fname, set<Student, greater<Student>> &students) {
    ifstream ifs(fname);
    if (!ifs) throw string("No such file");

    //declare and initialize temporary vars.
    int id, code, credits;
    id = code = credits = 0;
    string name = "No_name";
    char grade = 'X';

    while (!ifs.eof()) {
        ifs >> id;
        ifs >> name;

        //some more local variables.
        vector<Course> courses;
        int flag;

        ifs >> flag;
        while (flag != -1) {
            code = flag;
            ifs >> credits;
            ifs >> grade;
            Course course(code, credits, grade);
            courses.push_back(course);

            ifs >> flag;
        }

        Student student(id, name, courses);
        students.insert(student);
    }
    ifs.close();
}

void print(set<Student, greater<Student>> &students) {
    auto iter = students.begin();

    for (iter; iter != students.end(); ++iter) {
        cout << *iter;
    }
    cout << '\n' << students.size() << " records processed" << endl;
}