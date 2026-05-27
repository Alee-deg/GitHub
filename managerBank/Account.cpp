#include "Account.h"

Account::Account(string name, int accountNumber, double balance){
    this -> setName(name);
    this -> setAccountNumber(accountNumber);
    this -> setBalance(balance); 
}

void Account::setName(string name){
    this -> name = name; 
}
string Account::getName() const{
    return this -> name; 
}
void Account::setBalance(double balance){
    this -> balance = balance; 
}
double Account::getBalance() const{
    return this -> balance; 
}
void Account::setAccountNumber(int accountNumber){
    this -> accountNumber = accountNumber; 
}
int Account::getAccountNumber() const{
    return this -> accountNumber; 
}

void Account::display() const{
    cout << "NameOfAccount: " << this -> getName() << endl;
    cout << "AccountNumber: " << this -> getAccountNumber() << endl; 
    cout << "Balance: " << this -> getBalance() << endl;
}

void Account::drawMoney(double money){}; 

void Account::depositMoney(double money){
    this -> balance += money; 
}
