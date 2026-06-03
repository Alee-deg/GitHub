#ifndef PERSION_H
#define PERSION_H
#include<string>
using namespace std; 
class Person{
    private:
    string ssn; 
    string name; 
    public:
    Person(); 
    Person(string ssn, string name); 

    virtual ~Person(); 

    void setSsn(string ssn);
    void setName(string name); 
    
    string getSsn() const; 
    string getName() const; 
    void virtual display() = 0; 
}; 
#endif