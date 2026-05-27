#ifndef CURRENT_H
#define CURRENT_H
#include<iostream>
#include<string>
#include "Account.h"

class Current: public Account{
    private:
    double overDrawLimit;
    public:
    Current(string name, int accountNumber, double overDrawLimit):
    Account(name, accountNumber){
        this -> setOverDrawLimit(overDrawLimit); 
    }

    void setOverDrawLimit(double overDrawLimit); 
    double getOverDrawLimit() const;

    void drawMoney(double money) override;
    void depositMoney(double money) override; 
    void display() const override; 
    

};


#endif