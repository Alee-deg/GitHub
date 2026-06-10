#include "Course.h"
#include <iostream>

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
    for(auto it : this->prerequisite){
        cout << "CoursesNo: " << it.first << std::endl;
        cout << "CoureseName: " << it.second->getCourseName() << std::endl;  
    }
}

void Course::addCourses(Course* course){
    if(this->prerequisite.find(course->getCourseNo()) == this->prerequisite.end()){
        this->prerequisite.insert({course->getCourseNo(), course}); 
        cout << "Done!"; 
    }
    else{
        cout << "Course with " << this->getCourseNo() <<  "is already exists" << std::endl; 
    }
}