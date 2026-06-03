#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <unordered_map>
class Section; 

using namespace std; 
class Course{
    string courseNo; 
    string courseName; 
    string credits; 
    std::unordered_map<string, Course*> prerequisite; 
    std::unordered_map<string, Section*> sections; 
    Course* course; 
    public:
    Course(string courseNo, string courseName, string credits, Course* course = nullptr);  
    ~Course(); 
    void setCourseNo(string courseNo); 
    void setCourseName(string courseName); 
    void setCredits(string credits); 
    void setCourse(Course *course); 
    void scheduleSection(string codeClass, string date, string time, string classroom, int numberOfStudent); 

    string getCourseNo() const; 
    string getCourseName() const; 
    string getCredits() const; 
    Course* getCourse() const; 
    void displaySections(); 
    void addCourses(Course* course); 
    void display(); 
}; 
#endif