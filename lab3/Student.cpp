#include "Student.h"
#include <iostream>

Student::Student():Student("Unknow", "Unknow", "Unknow", "Unknow"){}; 
Student::Student(string ssn, string name, string major, string degree):Person(ssn, name){
    this->setMajor(major); 
    this->setDegree(degree); 
}; 
Student::~Student(){
    cout << "Destructure Student" << "\n"; 
};
    
void Student::setMajor(string major){this->major = major;}; 
void Student::setDegree(string degree){this->degree = degree;}; 

string Student::getMajor() const{return this->major;}; 
string Student::getDegree() const{return this->degree;}; 
void Student::display(){
    cout << "Ssn: " << this->getSsn() << "\n"; 
    cout << "Name: " << this->getName() << "\n"; 
    cout << "Major: " << this->getMajor() << "\n"; 
    cout << "Degree: " << this->getDegree() << "\n";  
}