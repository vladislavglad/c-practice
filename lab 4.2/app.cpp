#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include "student.h"

using namespace std;

void load(string fname, set<Student> &students);
void print(set<Student> &students);

int main() {
    try {
        set<Student> students;

        load("student.dat", students);

        print(students);

        // ofstream ofs("result.dat");
        // if (!ofs) throw string("No output file");
    } catch(string error) {
        cout << error << endl;
        exit(1);
    }
    return 0;
}

//first prototype.
void load(string fname, set<Student> &students) {
    ifstream ifs(fname);
    if (!ifs) throw string("No such file");

    vector<Course> courses;
    int id, code, credits;
    string name;
    char grade;

    ifs >> id;
    ifs >> name;
    ifs >> code;
    ifs >> credits;
    ifs >> grade;

    Course course(code, credits, grade);
    courses.push_back(course);

    Student student(id, name, courses);

    ifs.close();
}

//need to figure out.
void print(set<Student> &students) {
    auto iter = students.begin();

    // Student student();
    // cout << student.getId() << endl;
    // cout << student.getName() << endl;
    // cout << student.getGPA() << endl;
}