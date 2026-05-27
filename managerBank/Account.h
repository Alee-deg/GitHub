#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
#include<string>

using namespace std;
class Bank; 

class Account{
    protected:
    string name; 
    int accountNumber;
    double balance;
    Bank* linker; 
    public:
    Account(string name, int accountNumber):Account(name, accountNumber, 0){}
    Account(string name, int accountNumber, double balance); 

    void setName(string name); 
    string getName() const; 
    void setAccountNumber(int accountNumber);
    int getAccountNumber() const; 
    void setBalance(double balance);
    double getBalance() const; 

    virtual void display() const; 

    virtual void drawMoney(double money); 

    virtual void depositMoney(double money);
};
#endif