#include "Section.h"
#define ERROR -1e9
#include "Student.h"
#include "TE.h"
#include "Transcript.h" 
#include "Course.h"
#include <list>
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
void Section::setSectionNo(string sectionNo){this->sectionNo = sectionNo;}

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
void Section::enroll(Student* newStudent){
    bool flag = true; 
    if(this->comfirmSeatAvailability()){
        Course* course = this->getCourse(); 
        std::list<TE*> TEs = newStudent->getTranscript()->getTEs(); 
        std::list<Course*> prerequisites = course->getPrerequisite(); 
        for(auto it : prerequisites){
            flag = false; 
            for(auto TE : TEs){
                if(TE->getSection()->getCourse()->getCourseNo() == it->getCourseNo()){
                    if(TE->getGrade() >= 5.0){
                        flag = true; 
                    }
                    else{
                        flag = false; 
                    }
                }
            }
            if(!flag){
                break; 
            }
        }
        if(flag){
            this->students.insert({newStudent->getSsn(), newStudent}); 
            return;             
        }
    }
    std::cout << "Seating Capacity is fulled or failed the prerequisite courese" << "\n"; 
}
void Section::postGrade(Student* student, double grade){
    if(this->students.find(student->getSsn()) != this->students.end()){
        Transcript* trStudent = student->getTranscript();
        TE* newTE = new TE(this, grade); 
        trStudent->addTEs(newTE); 
        return; 
    }
    std::cout << "Student not yet register to learn" << "\n"; 
} 

bool Section::comfirmSeatAvailability(){return this->students.size() < 80;}

void Section::drop(Student* student){
    student->getTranscript()->dropSection(this); 
}

