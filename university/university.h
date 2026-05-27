#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include<iostream>
#include<string>
#include<unordered_set>
class UniversitySchool; 

using namespace std; 

class University{
    private:
    string name; 
    unordered_set<UniversitySchool*> manager;  
    public:
    University():University(""){}; 
    University(string name);

    string getName() const;
    void setName(string name);

    void attachSchool(UniversitySchool* school); 
    void dettachSchool(UniversitySchool* school); 

    void displayInf() const;
    void displaySchool() const; 
}; 
#endif