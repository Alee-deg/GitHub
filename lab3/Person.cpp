#include "Person.h"
#include <iostream>

Person::Person():Person("Unknow", "Unknow"){};

Person::Person(string ssn, string name){
    this->setName(name); 
    this->setSsn(ssn); 
}

Person::~Person(){
    cout << "Destructure Person" << endl; 
}

void Person::setSsn(string ssn){this->ssn = ssn;}
void Person::setName(string name){this->name = name;}

string Person::getName() const {return this->name;}
string Person::getSsn() const {return this->ssn;}

