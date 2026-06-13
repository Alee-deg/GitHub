#ifndef SECTION_H
#define SECTION_H
#include <string>
#include "Course.h"
#include <iostream>
#include <unordered_map>

class Student; 
using namespace std; 
class Section{
    private:
    string sectionNo; 
    string dayOfWeek, timeOfDay; 
    string room; 
    int seatingCapacity;
    Course* course;  
    unordered_map<string, Student*> students; 
    void setCourse(Course* course); 
    public:
    Section(string sectionNo, string dayOfWeek, string timeOfDay, string room, int seatingCapacity, Course* course = nullptr); 
    void setSectionNo(string sectionNo); 
    void setDayOfWeek(string dayOfWeek); 
    void setTimeOfDay(string timeOfDay); 
    void setRoom(string room); 
    void setSeatingCapacity(int seatingCapacity);

    string getSectionNo() const; 
    string getDayOfWeek() const; 
    string getTimeOfDay() const; 
    string getRoom() const; 
    int getSeatingCapacity() const;
    Course* getCourse() const;  
    void display(); 
    void enroll(Student *newStudent); 
    void drop(Student* student); 
    void postGrade(Student* student, double grade);  
    bool comfirmSeatAvailability(); 
}; 
#endif //SECTION_H