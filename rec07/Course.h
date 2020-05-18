//
// Created by Saimanasa Juluru on 10/20/19.
//

#ifndef REC07_COURSE_H
#define REC07_COURSE_H
#include<iostream>
#include<string>
#include<vector>
namespace BrooklynPoly {
    class Student;
    class Course {
        friend std::ostream& operator<<(std::ostream& os, const Course& rhs);
    public:
        // Course methods needed by Registrar
        Course(const std::string& courseName);
        const std::string& getName() const;
        bool addStudent(Student* studentName);
        void removeStudentsFromCourse();

    private:
        std::string name;
        std::vector<Student*> students;
    };
}
#endif //REC07_COURSE_H
