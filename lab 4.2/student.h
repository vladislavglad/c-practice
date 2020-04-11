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
    Student(int id, string name, vector<Course> courses): id(id), name(name), courses(courses), gpa(0.0) {}
    
    int getId() const {return id;}
    string getName() const {return name;}
    vector<Course> getCourses() const {return courses;}
    double getGPA() {calculateGPA(); return gpa;}

    void calculateGPA() {
        int totalCredits = 0;
        double totalGradePoints = 0.0;

        for (auto course : courses) {
            int currentCredits = course.getCredits();
            totalGradePoints += course.getNumericGrade() * currentCredits;
            totalCredits += currentCredits;
        }

        if (totalCredits != 0)
            gpa = totalGradePoints / totalCredits;
    }
};