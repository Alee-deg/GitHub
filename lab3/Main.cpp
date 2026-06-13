#include<iostream>
#include "Person.h"
#include "Professor.h"
#include "Student.h"
#include "Course.h"
#include "Section.h"
#include <vector>

using namespace std; 
int main(){
    vector<Person*> vec; 
    //Create student
    Person* newStudent1 = new Student("SSN1101H1", "Hili", "Computer Science", "Ungraduated"); 
    vec.push_back(newStudent1); 
    Person* newProfessor = new Professor("SSN1101H2", "Anna", "Assistance Professor", "Computer"); 
    vec.push_back(newProfessor); 
    //Create student
    Person* newStudent2 = new Student("SSN1101H2", "Parker", "Biology", "Ungraduated"); 
    vec.push_back(newStudent2); 
    //Create course
    Course prgrammingBasic("24MTH_1", "Lap trinh can ban", "3");
    Course dsa("24MTH_2", "DSA", "3"); 
    Course oop("24MTH_3", "OOP", "3"); 
    //Create section
    Section* section1 = prgrammingBasic.scheduleSection("24TTH2", "Wednesday", "8:00AM", "E203", 100); 
    Section* section3 = prgrammingBasic.scheduleSection("24TTH3", "Wednesday", "7:00AM", "E203", 100); 
    Section* section2 = dsa.scheduleSection("24TTH2", "Tuseday", "10:00AM", "E204", 80); 
    Section* sectionOOP = oop.scheduleSection("24TTH2", "Thursday", "7:30AM", "E303", 70); 
    //Add prerequisite
    dsa.addPrerequisite(&prgrammingBasic); 
    oop.addPrerequisite(&dsa); 
    
    section1->enroll(dynamic_cast<Student*>(newStudent1)); 
    section1->postGrade(dynamic_cast<Student*>(newStudent1), 9.25); 
    section2->enroll(dynamic_cast<Student*>(newStudent1)); 
    section2->postGrade(dynamic_cast<Student*>(newStudent1), 10); 
    sectionOOP->enroll(dynamic_cast<Student*>(newStudent1)); 
    sectionOOP->postGrade(dynamic_cast<Student*>(newStudent1), 10); 
    dynamic_cast<Student*>(newStudent1)->displayGrade(); 

    section1->enroll(dynamic_cast<Student*>(newStudent2)); 
    section1->postGrade(dynamic_cast<Student*>(newStudent2), 4.5); 
    section3->enroll(dynamic_cast<Student*>(newStudent2)); 
    section3->postGrade(dynamic_cast<Student*>(newStudent2), 10); 
    section2->enroll(dynamic_cast<Student*>(newStudent2)); 
    section2->postGrade(dynamic_cast<Student*>(newStudent2), 10);
    sectionOOP->enroll(dynamic_cast<Student*>(newStudent2)); 
    sectionOOP->postGrade(dynamic_cast<Student*>(newStudent2), 10);
    dynamic_cast<Student*>(newStudent2)->displayGrade(); 

    for(auto it : vec){
        it->display(); 
        std::cout << std::endl; 
    }
    for(auto it : vec){
        delete it; 
    }
    return 0; 
}