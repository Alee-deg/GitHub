#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include<unordered_map>
#include "subject.h"
using namespace std; 

class student{
    private:
    int ID;
    string name;
    int trainingPoint;
    int Bonus; 
    string rating; 
    string position;  
    unordered_map<int, subject*> sub;  
    unordered_map<subject*, float> Grade;
    public:
    student(int ID, string name, int trainingPoint, int Bonus, string rating, string position); 
    
    void setID(int ID);
    int getID() const;
    void setName(string Name);
    string getName() const;
    void setTrainingPoint(int trainPoint);
    int getTrainingpoint() const;
    void setBonus(int Bonus);
    int getBonus() const;
    void setRating(string rating);
    string getRating() const;
    void setPosition(string pos);
    string getPosition() const;

    float GPA();
    int totalNumberOfSubjectsStudied() const;
    void displayGradesAndSubjects() const;
    int totalNumberOfArticles() const; 
    void displayAriticles() const;
    void inputGrades(); 
    bool eligibleToGraduate();
    int totalNumberOfCredits();
    float findGrade(); 

    void attachBook();
    void detachBook();

    void attachSubject();
    void detachSubject();

    void attachArticle();
    void detachArticle();
};

#endif