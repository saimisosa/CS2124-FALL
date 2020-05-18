//
// Created by Saimanasa Juluru on 10/20/19.
//

#ifndef REC07_STUDENT_H
#define REC07_STUDENT_H
#include<iostream>
#include<string>
#include<vector>
namespace BrooklynPoly {
    class Course;
    class Student {
        friend std::ostream& operator<<(std::ostream& os, const Student& rhs);
    public:
        Student(const std::string& studentName);
        const std::string& getName() const;
        bool addCourse(Course* courseName);
        void removedFromCourse(Course* courseName);
    private:
        std::string name;
        std::vector<Course*> courses;
    };
}
#endif //REC07_STUDENT_H
