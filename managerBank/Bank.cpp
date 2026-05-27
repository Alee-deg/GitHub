#include "Bank.h"
#include<cstdlib>

Bank::Bank(string name, string locate){
    this -> setName(name);
    this -> setLocate(locate); 
}

string Bank::getName() const{
    return this -> name; 
}
void Bank::setName(string name){
    this -> name = name; 
}
string Bank::getLocate() const{
    return this -> locate; 
}
void Bank::setLocate(string locate){
    this -> locate = locate; 
}

void Bank::addCurrentAccount(string name, int numberAccount){
    if(this -> Accounts.find(numberAccount) == Accounts.end()){
        int overDrawLimit = rand() % 1001; 
        Account* newAccount = new Current(name, numberAccount, overDrawLimit); 
        // Accounts[numberAccount] = newAccount; 
        Accounts.emplace(numberAccount, newAccount); 
    }
    else{
        cout << "Account is available\n"; 
    }
}
void Bank::addCurrentAccount(string name){
    int accountNumber; 
    while(1){
        accountNumber = 100000 + rand() % (1000000 - 100000 + 1); 
        if(Accounts.find(accountNumber) == Accounts.end()){
            break; 
        }
    }
    int overDrawLimit = rand() % 1001; 
    Account* newAccount = new Current(name, accountNumber, overDrawLimit); 
    Accounts.insert({accountNumber, newAccount}); 
}
void Bank::addRegularAccount(string name, int numberAccount){
    if(this -> Accounts.find(numberAccount) == Accounts.end()){
        Account* newAccount = new Regular(name, numberAccount); 
        // Accounts[numberAccount] = newAccount; 
        Accounts.insert({numberAccount, newAccount}); 
    }
    else{
        cout << "Accout is available\n"; 
    }
}
void Bank::addRegularAccount(string name){
    int accountNumber; 
    while(1){
        accountNumber = 100000 + rand() % (1000000 - 100000 + 1); 
        if(Accounts.find(accountNumber) == Accounts.end()){
            break; 
        }
    }
    Account* newAccount = new Regular(name, accountNumber); 
    Accounts.insert({accountNumber, newAccount}); 
}
void Bank::drawMoney(int numberAccount, double money){
    if(money < 0){
        cout << "DrawMoney is Invalid\n"; 
        return; 
    }
    if(this->Accounts.find(numberAccount) == Accounts.end()){
        cout << "Account is not available\n"; 
        return;
    }
    Account* acc = this -> Accounts.find(numberAccount) -> second; 
    acc->drawMoney(money); 
}
void Bank::depositMoney(int numberAccount, double money){
    if(money < 0){
        cout << "DrawMoney is Invalid\n";
        return; 
    }
    if(this -> Accounts.find(numberAccount) == Accounts.end()){
        cout << "Account is not available\n"; 
        return; 
    }
    Account* acc = this -> Accounts.find(numberAccount) -> second; 
    acc->depositMoney(money); 
}

void Bank::displayInfo() const{
    cout << "NameOfBank: " << this->getName() << endl;
    cout << "LocateOfBank: " << this -> getLocate() << endl;
    cout << "NumberOfAccount: " << this -> Accounts.size() << endl;
    cout << "\n"; 
}

void Bank::displayAccount() const{
    cout << "Accounts Current\n"; 
    for(auto account : Accounts){
        if(dynamic_cast<Current*>(account.second)){
            account.second->display(); 
        }
    }
    cout << "Accounts Regular\n";
    for(auto account : Accounts){
        if(dynamic_cast<Regular*>(account.second)){
            account.second->display(); 
        }
    }
}

void Bank::deleteAccount(int numberAccount){
    if(this -> Accounts.find(numberAccount) == Accounts.end()){
        cout << "Accout is not availble\n"; 
        return; 
    }
    auto account = Accounts.find(numberAccount); 
    Accounts.erase(account); 
    delete account -> second; 
}