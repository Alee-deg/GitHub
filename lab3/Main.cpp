#include<iostream>
#include "Person.h"
#include "Professor.h"
#include "Student.h"
#include "Course.h"
#include <vector>

using namespace std; 
int main(){
    vector<Person*> vec; 
    Person* newStudent = new Student("SSN1101H1", "Hili", "Computer Science", "Ungraduated"); 
    vec.push_back(newStudent); 
    Person* newProfessor = new Professor("SSN1101H2", "Anna", "Assistance Professor", "Computer"); 
    vec.push_back(newProfessor); 
    Person* newStudent1 = new Student("SSN1101H2", "Parker", "Biology", "Ungraduated"); 
    vec.push_back(newStudent1); 
    Course newCourse("24MTH", "Lap trinh", "3");
    
    newCourse.scheduleSection("24TTH2", "23-3-2025", "8:00PM", "E203", 100); 

    for(auto it : vec){
        it->display(); 
    }
    for(auto it : vec){
        delete it; 
    }
    return 0; 
}