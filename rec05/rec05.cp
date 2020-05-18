//Saimanasa Juluru
//Recitation 5
//Section A
//4 October 2019

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Student{
    friend ostream& operator<< (ostream& os, Student& curr_Student) {
        os << "Student Name: " << curr_Student.studentName << ", " << "Grades: ";

        for (size_t i = 0; i < curr_Student.studentGrades.size(); ++i) {
            cout << curr_Student.studentGrades[i] << " ";
        }
        return os;
    }
public:
    Student(const string& studentNames): studentName(studentNames), studentGrades(14,-1){}

    string getName() {return studentName;}
    void setGrade(const int& grade, const int& week){studentGrades[week] = grade;}


private:
    string studentName;
    vector<int>studentGrades;
};

class Section {
    friend ostream& operator<< (ostream& os, Section& curr_Section) {
        os << "Section: " << curr_Section.sectionName << ", " << curr_Section.sectionTime << "Students: " << endl;

        if (curr_Section.sectionStudents.size() == 0){
            os << "None" << endl;
        }
        else{
            for (size_t i = 0; i < curr_Section.sectionStudents.size(); ++i){
                cout << *curr_Section.sectionStudents[i] << endl;
            }
        }
        return os;
    }
public:
    Section(const string& mySection, const string& sectionDay, const int& classTime): sectionName(mySection), sectionTime(sectionDay, classTime){};

    vector<Student*> getStudents() {return sectionStudents;}

    void setGrade(const string& studentName, const int& grade, const int& position){
        for (size_t i = 0; i < sectionStudents.size(); ++i){
            if (sectionStudents[i]->getName() == studentName){
                sectionStudents[i]->setGrade(grade, position-1);
            }
        }
    }

    void addStudent(const string& studentName){
        sectionStudents.push_back(new Student(studentName));
    }

    ~Section(){
        for (size_t i=0; i<sectionStudents.size(); ++i){
            cout << "Deleting "<< sectionStudents[i]->getName() << endl;
            delete sectionStudents[i];
            sectionStudents[i] = nullptr;
        }
    }

    Section(const Section& new_sec): sectionName(new_sec.sectionName), sectionTime(new_sec.sectionTime) {
        //copy constructor with old constructor data
        for (size_t i = 0; i < sectionStudents.size(); ++i){
            sectionStudents.push_back(new Student(*new_sec.sectionStudents[i]));
        }
    }

private:
    class TimeSlot {
        friend ostream& operator<< (ostream& os, TimeSlot& curr_TimeSlot){
            int new_time;
            string tod;
            if (curr_TimeSlot.myTime > 12){
                new_time = (curr_TimeSlot.myTime - 12);
                tod = "PM";
            }
            else{
                new_time = (12-curr_TimeSlot.myTime);
                tod = "AM";
            }
            os << "Time Slot: [Day: " <<curr_TimeSlot.myDay << ", Start Time: " << new_time << tod << "]" << endl;
            return os;
        }
    public:
        TimeSlot(const string& slotDay, const int& slotTime): myDay(slotDay), myTime(slotTime) {};

    private:
        string myDay;
        int myTime;
    };

    string sectionName;
    TimeSlot sectionTime;
    vector<Student*> sectionStudents;

};


class LabWorker{
    friend ostream& operator <<(ostream& os, const LabWorker curr_Worker){
        if (curr_Worker.curr_section == nullptr){
            os << curr_Worker.labWorkerName << " does not have a section." << endl;
        }
        else{
            os << curr_Worker.labWorkerName << " has " << *curr_Worker.curr_section << endl;
        }
        return os;
    }
public:
    LabWorker(const string& name): labWorkerName(name) {}

    void addSection(Section& new_section){
        if (curr_section == nullptr){
            curr_section = &new_section;
        }
        else{
            cout << labWorkerName << " already has a section." << endl;
        }
    }

    void addGrade(const string& studentName, const int& studentGrade, const int& weekNum){
        curr_section->setGrade(studentName, studentGrade, weekNum);
    }
private:
    Section* curr_section;
    string labWorkerName;
};

// Test code
void doNothing(Section sec) { cout << sec << endl; }

int main() {

    cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    cout << secA2 << endl;

    cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    cout << secA2 << endl;

    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe( "Moe" );
    cout << moe << endl;

    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection( secA2 );
    cout << moe << endl;

    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection( secB3 );
    cout << jane << endl;

    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);
    moe.addGrade("Paul", 19, 1);
    moe.addGrade("George", 16, 1);
    moe.addGrade("Ringo", 7, 1);
    cout << moe << endl;

    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);
    moe.addGrade("Paul", 20, 3);
    moe.addGrade("Ringo", 0, 3);
    moe.addGrade("George", 16, 3);
    cout << moe << endl;

    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
         << "those students (or rather their records?)\n";

    //All their records should disappear

    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
         << "then make sure the following call works:\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n";

} // main
