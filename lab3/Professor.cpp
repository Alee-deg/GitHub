#include "Professor.h"
#include <iostream>

Professor::Professor():Professor("Unknow", "Unknow", "Unknow", "Unknow"){}; 
Professor::Professor(string ssn, string name, string title, string department):Person(ssn, name){
    this->setSsn(ssn); 
    this->setTitle(title); 
}
Professor::~Professor(){
    cout << "Destructure Professor" << "\n"; 
}

void Professor::setTitle(string title){this->title = title;}
void Professor::setDepartment(string department){this->department = department;}

string Professor::getTitle() const {return this->title;}
string Professor::getDeparment() const {return this->department;}
void Professor::display() {
    cout << "Ssn: " << getSsn() << "\n"; 
    cout << "Name: " << this->getName() << "\n";
    cout << "Title: " << this->getTitle() << "\n"; 
    cout << "Department: " <<this->getDeparment() << "\n";  
}

