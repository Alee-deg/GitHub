#include "Student.h"
#include <iostream>
#include "Transcript.h"

Student::Student():Student("Unknow", "Unknow", "Unknow", "Unknow"){}; 
Student::Student(string ssn, string name, string major, string degree):Person(ssn, name){
    this->setMajor(major); 
    this->setDegree(degree); 
    this->transcript = new Transcript(); 
}; 
Student::~Student(){
    cout << "Destructure Student" << "\n"; 
    delete this->transcript; 
};
    
void Student::setMajor(string major){this->major = major;}
void Student::setDegree(string degree){this->degree = degree;}

string Student::getMajor() const{return this->major;}
string Student::getDegree() const{return this->degree;}
Transcript* Student::getTranscript(){return this->transcript;} 

void Student::display(){
    cout << "Ssn: " << this->getSsn() << "\n"; 
    cout << "Name: " << this->getName() << "\n"; 
    cout << "Major: " << this->getMajor() << "\n"; 
    cout << "Degree: " << this->getDegree() << "\n\n";  
}

void Student::displayGrade(){
    std::cout << "---------------------------" << "\n"; 
    std::cout << "Name: " << this->getName() << "\n";
    std::cout << "Grade" << "\n";  
    this->getTranscript()->displayTE(); 
    std::cout << "---------------------------" << "\n"; 
}