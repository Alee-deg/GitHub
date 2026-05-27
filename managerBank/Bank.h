#ifndef BANK_H
#define BANK_H
#include<iostream>
#include<string>
#include<unordered_map>
#include "Account.h"
#include "Current.h"
#include "Regular.h"

using namespace std;

class Bank{
    private:
    string name;
    string locate;
    unordered_map<int, Account*> Accounts; 
    public:
    Bank():Bank("", ""){}; 
    Bank(string name):Bank(name, ""){}; 
    Bank(string name, string locate); 
    ~Bank(){
        for(auto account : this -> Accounts){
            delete account.second; 
        }
    }
    string getName() const; 
    void setName(string name);
    string getLocate() const; 
    void setLocate(string locate); 
    void addRegularAccount(string name, int numberAccount);
    void addCurrentAccount(string name, int numberAccount); 
    void addRegularAccount(string name);
    void addCurrentAccount(string name); 
    void displayInfo() const;
    void displayAccount() const; 
    void drawMoney(int numberAccount, double money); 
    void depositMoney(int numberAccount, double money); 
    void deleteAccount(int numberAccount); 
}; 

#endif