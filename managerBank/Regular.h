#ifndef REGULAR_H
#define REGULAR_H
#include "Account.h"
class Regular : public Account{
    public:
    Regular(string name, int accountNumber):Account(name, accountNumber){}; 
    void drawMoney(double money) override; 
    void depositMoney(double money) override; 
    void display() const override; 
}; 

#endif