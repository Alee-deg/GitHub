#include "Regular.h"

void Regular::drawMoney(double money){
    if(this -> getBalance() >= money){
        this -> balance -= money; 
    }
    else{
        cout << "Balance is lower drawMoney\n"; 
    }
}

void Regular::depositMoney(double money){
    Account::depositMoney(money); 
}

void Regular::display() const{
    Account::display(); 
    cout << "\n"; 
}