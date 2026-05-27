#ifndef SUBJECT_H
#define SUBJECT_H

#include<string>
using namespace std;

class subject{
    private:
    int ID;  
    string name; 
    int numberOfCredits;
    string codeRoom; 
    public:
    subject(int ID, string name, int number, string codeRoom); 
    void setID(int ID);
    int getID() const;
    void setName(string name);
    string getName() const;
    void setNumberOfCredits(); 
    string getNumberOfCredits() const; 
    
    void attackStudent();
    void dettack();
    
    void attachLecture(); 

    void display(); 

    friend istream& operator>>(istream& is, const subject &sub); 
}; 
#endif