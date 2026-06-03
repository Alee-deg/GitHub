#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
class Student : public Person {
    private:
    string major; 
    string degree; 
    public:
    Student(); 
    Student(string ssn, string name, string major, string degree); 
    ~Student();
    
    void setMajor(string major); 
    void setDegree(string degree); 

    string getMajor() const; 
    string getDegree() const; 

    void display() override; 
}; 
#endif