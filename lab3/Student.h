#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include <list>

class Section; 
class Transcript; 
class Student : public Person {
    private:
    string major; 
    string degree; 
    Transcript *transcript; 
    public:
    Student(); 
    Student(string ssn, string name, string major, string degree); 
    ~Student();
    
    void setMajor(string major); 
    void setDegree(string degree); 

    string getMajor() const; 
    string getDegree() const; 
    Transcript* getTranscript(); 

    void display() override; 
    void displayGrade(); 
}; 
#endif