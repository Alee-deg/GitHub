#include "TE.h"
#include "Section.h"
#include <iostream>
TE::TE(Section* section, double grade){
    this->setSection(section); 
    this->setGrade(grade); 
}

void TE::setGrade(double grade){
    if(grade < 0){
        std::cout << "Invalid data" << "\n"; 
        return; 
    }
    this->grade = grade;
}
void TE::setSection(Section* section){this->section = section;}
Section* TE::getSection(){return this->section;}
double TE::getGrade(){return this->grade;}

void TE::dislay(){
    std::cout << "CourseNo: " << this->getSection()->getCourse()->getCourseNo() << std::endl; 
    std::cout << "Name course: " << this->getSection()->getCourse()->getCourseName() << std::endl; 
    std::cout << "Grade: " << this->getGrade() << std::endl; 
}; 