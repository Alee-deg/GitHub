#include "Course.h"
#include <iostream>
#include "Section.h"

Course::Course(string courseNo, string courseName, string credits, Course* course){
    this->setCourseName(courseName); 
    this->setCourseNo(courseNo); 
    this->setCredits(credits); 
    this->setCourse(course); 
}

void Course::setCourseName(string courseName){this->courseName = courseName;}
void Course::setCourseNo(string courseNo){this->courseNo = courseNo;}
void Course::setCredits(string credits){this->credits = credits;}
void Course::setCourse(Course* course){this->course = course;}

string Course::getCourseName() const{return this->courseName;}
string Course::getCourseNo() const{return this->courseNo;}
string Course::getCredits() const{return this->credits;}
Course* Course::getCourse() const{return this->course;}

void Course::display(){
    cout << "CourseNo: " << this->getCourseNo() << "\n";
    cout << "CourseName: " << this->getCourseName() << "\n"; 
    cout << "Credits: " << this->getCredits() << "\n";  
}

void Course::displaySections(){
    for(auto it : sections){
        it.second->display(); 
        cout << std::endl; 
    }
}; 
void Course::addCourses(Course* course){
    if(this->prerequisite.find(course->getCourseNo()) == this->prerequisite.end()){
        this->prerequisite.insert({course->getCourseNo(), course}); 
        cout << "Done!"; 
    }
    else{
        cout << "Course with " << this->getCourseNo() <<  "is already exists" << std::endl; 
    }
}
void Course::scheduleSection(string codeClass, string date, string time, string classroom, int numberOfStudent){
    if(this->sections.find(codeClass) == this->sections.end()){
        Section* newSection = new Section(codeClass, date, time, classroom, numberOfStudent, this); 
        this->sections.insert({codeClass, newSection}); 
    }
    else{
        cout << "The codeClass is already exists!"; 
    }
}
Course::~Course(){
    for(auto it : sections){
        delete it.second; 
    }
}