#ifndef LIBRARY_H
#define LIBRARY_H

using namespace std;
#include<string>
#include<unordered_map>
#include "student.h"
#include "lecture.h"

class Department{
    private:
    int ID;
    string Name; 
    //first luu ma so sinh vien
    unordered_map<int, student*> students;
    //frist luu ma can bo
    unordered_map<int, lecture*> lectures; 
    public:
    //constructure
    Department(int ID, string name);

    void setID(int ID);
    int getID() const;
    void setName(string name);
    string getName() const; 

    void addStudent(student* st);
    void addLecture(lecture* lec); 
    void listStudensHaveFiveAboveArticles() const;
    void getStudentsWithTheMaximumTrainingPoints() const;
    void getGradeAverage() const;
    void getLecturesNotYetArticles() const;
    void updateInformationByCodeNumber(); 
    void deleteInformation(int ID);
}; 
#endif