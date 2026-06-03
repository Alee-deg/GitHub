#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "Person.h"
class Professor: public Person{
    private:
    string title; 
    string department; 
    public:
    Professor(); 
    Professor(string ssn, string name, string title, string department); 
    ~Professor(); 

    void setTitle(string title);
    void setDepartment(string department); 
    
    string getTitle() const; 
    string getDeparment() const; 

    void display() override; 
}; 
#endif
