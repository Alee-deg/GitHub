#include "Section.h"
#define ERROR 1e9

Section::Section(string sectionNo, string dayOfWeek, string timeOfDay, string room, int seatingCapacity, Course* course){
    this->setCourse(course); 
    this->setSectionNo(sectionNo); 
    this->setDayOfWeek(dayOfWeek);
    this->setTimeOfDay(timeOfDay); 
    this->setRoom(room); 
    this->setSeatingCapacity(seatingCapacity); 
}

void Section::setCourse(Course* course){this->course = course;}
void Section::setDayOfWeek(string dayOfWeek){this->dayOfWeek = dayOfWeek;}
void Section::setTimeOfDay(string timeOfDay){this->timeOfDay = timeOfDay;}
void Section::setRoom(string room){this->room = room;}
void Section::setSeatingCapacity(int seatingCapacity){
    if(seatingCapacity < 0){
        this->seatingCapacity = ERROR; 
    }
    else this->seatingCapacity = seatingCapacity;
}
void Section::setCourse(Course* course){this->course = course;}

string Section::getSectionNo() const{return this->sectionNo;}
Course* Section::getCourse() const{return this->course;}
string Section::getDayOfWeek() const{return this->dayOfWeek;}
string Section::getRoom() const{return this->room;}
int Section::getSeatingCapacity() const {return this->seatingCapacity;}
string Section::getTimeOfDay() const{return this->timeOfDay;}

void Section::display(){
    cout << "SectionNo: " << this->getSectionNo() << std::endl;
    cout << "dayOfWeek: " << this->getDayOfWeek() << std::endl; 
    cout << "timeOfDay: " << this->getTimeOfDay() << std::endl; 
    cout << "Room: "      << this->getRoom()      << std::endl; 
    cout << "seatingCapacity: " << this->getSeatingCapacity() << std::endl; 
    cout << "NameCourse: " << this->getCourse()->getCourseName() << std::endl;
}


