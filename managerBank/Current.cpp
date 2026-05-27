#include "Current.h"

void Current::setOverDrawLimit(double overDrawLimit){
    this -> overDrawLimit = overDrawLimit; 
}
double Current::getOverDrawLimit() const{
    return this -> overDrawLimit; 
}

void Current::drawMoney(double money){
    if(money > this -> getOverDrawLimit() + this -> getBalance()){
        cout << "Insufficient balance" << endl; 
    }
    else{
        if(money > this -> getBalance()){
            money -= this -> balance;
            this -> balance = 0;
            this -> overDrawLimit -= money; 
        }
        else{
            this -> balance -= money; 
        }
    }
}

void Current::depositMoney(double money){
    this -> balance += money; 
}

void Current::display() const {
    Account::display();
    cout <<"OverDrawLimit: " << this -> getOverDrawLimit() << endl;
    cout << "\n";  
}