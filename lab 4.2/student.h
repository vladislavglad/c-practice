#include <iostream>
#include <vector>
#include <string>
#include "course.h"

using namespace std;

class Student {
private:
    int id;
    string name;
    vector<Course> courses;
    double gpa;
public:
    Student(int id, string name, vector<Course> courses): id(id), name(name), courses(courses), gpa(calculateGPA()) {}
    
    int getId() const {return id;}
    string getName() const {return name;}
    vector<Course> getCourses() const {return courses;}
    double const getGPA() {return gpa;}

    bool operator>(const Student &other) const {return gpa > other.gpa;}
    bool operator<(const Student &other) const {return gpa < other.gpa;}

    double calculateGPA() {
        int totalCredits = 0;
        double totalGradePoints = 0.0;

        for (auto course : courses) {
            int currentCredits = course.getCredits();
            totalGradePoints += course.getNumericGrade() * currentCredits;
            totalCredits += currentCredits;
        }

        if (totalCredits != 0)
            gpa = totalGradePoints / totalCredits;
        else
            gpa = 0.0;

        return getGPA();
    }

    ostream &print(ostream &os) const {
        os << id << " " << name << ": " << gpa << endl;
        for (auto course : courses) {
            os << "\t" << course.getCode() << " ";
            os << "(" << course.getCredits() << " credits): ";
            os << course.getLetterGrade() << endl;
        }
        return os;
    };
};

inline ostream &operator<<(ostream &os, const Student &s) {s.print(os);}