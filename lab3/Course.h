#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <unordered_map>

using namespace std; 
class Course{
    string courseNo; 
    string courseName; 
    string credits; 
    std::unordered_map<string, Course*> prerequisite; 
    Course* course; 
    public:
    Course(string courseNo, string courseName, string credits, Course* course = nullptr);  
    void setCourseNo(string courseNo); 
    void setCourseName(string courseName); 
    void setCredits(string credits); 
    void setCourse(Course *course); 

    string getCourseNo() const; 
    string getCourseName() const; 
    string getCredits() const; 
    Course* getCourse() const; 

    void addCourses(Course* course); 
    void display(); 
}; 
#endif