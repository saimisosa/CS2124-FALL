//
// Created by Saimanasa Juluru on 10/20/19.
//
#include "Course.h"
#include "Student.h"
//#include <iostream>
//#include <string>
//#include <vector>
using namespace std;
namespace BrooklynPoly {
    ostream& operator<<(ostream& os, const Course& rhs) {
        os << rhs.Course::getName() << ": ";
        if (rhs.students.size() == 0) {
            os << "No students.";
        }
        else {
            for (Student* students : rhs.students) {
                os << students->getName();
            }
        }
        return os;
    };
    Course::Course(const string& courseName) : name(courseName) {};
    const string& Course::getName() const { return name; }
    bool Course::addStudent(Student* studentName) {
        for (Student* s : students) {
            if (s == studentName) {
                return false;
            }
        }
        students.push_back(studentName);
        return true;
    }
    void Course::removeStudentsFromCourse() {
        for (Student *s : students) {
            s->removedFromCourse(this);
        }
        students.clear()

    }
}