#ifndef UNIVERSITYSCHOOL_H
#define UNIVERSITYSCHOOL_H
#include "university.h"
#include<iostream>
#include<string>

using namespace std; 

class UniversitySchool{
    private:
    string name;
    string locate;
    University *isMember; 
    public:
    UniversitySchool():UniversitySchool("", "", NULL){}; 
    UniversitySchool(string name, string locate):UniversitySchool(name, locate, NULL){}; 
    UniversitySchool(string name, string locate, University* isMember);

    string getName() const; 
    void setName(string name);

    string getLocate() const;
    void setLocate(string locate);

    University *getUniversity() const;
    void setUniversity(University *univer); 

    bool isMem() const;

    void attachUniversity(University* univer); 
    void dettachUniversity(); 

    void displayInfo() const; 

}; 
#endif