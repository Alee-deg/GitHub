#ifndef BORROWERRECORD_H
#define BORROWERRECORD_H
#include<iostream>
#include<string>
using namespace std; 
class BorrowerRecord{
    private:
    string b_id, b_name, b_phone, b_nbViolate, b_status; 
    public:
    BorrowerRecord(string b_id, string b_name, string b_phone, int b_nbViolate, string b_status); 

    void setID(string id); 
    void setName(string name); 
    void setPhone(string phone); 
    void setViolate(int nbViolate); 
    void setStatus(string status);
    
    string getID(); 
    string getName(); 
    string getPhone(); 
    string getnNBViolate(); 
    string getStatus(); 
}; 
#endif