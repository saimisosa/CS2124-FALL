//
// Created by Saimanasa Juluru on 10/20/19.
//

#include "Student.h"
#include "Course.h"
//#include <iostream>
//#include <vector>
//#include <string>
using namespace std;
namespace BrooklynPoly {

    ostream& operator<<(ostream& os, const Student& rhs) {
        os << rhs.Student::getName() << ": ";
        if (rhs.courses.size() == 0) {
            os << "No courses.";
        }
        else {
            for (Course* cour : rhs.courses) {
                os << cour->getName() << " ";
            }
        }
        return os;
    }
    Student::Student(const string& studentName) : studentName(name) {};
    const string& Student::getName() const { return name; }
    bool Student::addCourse(Course* courseName) {
        for (Course* c : courses) {
            if (c == courseName) {
                return false;
            }
        }
        courses.push_back(courseName);
        return true;
    }
    void Student::removedFromCourse(Course* courseName) {
        size_t courseind = courses.size();

        for (size_t i = 0; i < courses.size(); i++) {
            if ((courses[i]) == courseName) {
                courseind = i;
            }
        }
        while (courseind < courses.size()){
            courses[courseind] = courses[courseind+1];
            courseind +=1;
        }
        courses.pop_back();
    }