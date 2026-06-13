#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <unordered_map>
#include <list>
class Section; 

using namespace std; 
class Course{
    string courseNo; 
    string courseName; 
    string credits; 
    std::list<Course*> prerequisite; 
    std::unordered_map<string, Section*> sections; 
    Course* course; 
    public:
    Course(string courseNo, string courseName, string credits, Course* course = nullptr);  
    ~Course(); 
    void setCourseNo(string courseNo); 
    void setCourseName(string courseName); 
    void setCredits(string credits); 
    void setCourse(Course *course);

    string getCourseNo() const; 
    string getCourseName() const; 
    string getCredits() const; 
    Course* getCourse() const; 
    std::list<Course*> getPrerequisite(); 

    Section* scheduleSection(string codeClass, string date, string time, string classroom, int numberOfStudent); 
    void addPrerequisite(Course* course); 
    void cancelSection(string codeClass);

    void displaySections(); 
    void display(); 
}; 
#endif