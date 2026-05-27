#ifndef LIBRARY_H
#define LIBRARY_H
#include<string>
#include<pqxx/pqxx>
#include<unordered_map>
#include "Book.h"
#include "BorrowerRecord.h"
using namespace std; 
class Library{
    private:
    string name; 
    unordered_map<string, Book*> stocks; 
    unordered_map<string, BorrowerRecord*> borrowers; 
    public:
    Library(string name){this -> setName(name);}
    ~Library(); 
    
    void setName(string name){this -> name = name;}
    string getName() const{return this -> name;}

    void menu(); 

    void addBorrowerRecord(); 
    void p_addBorrowerRecord(string id, BorrowerRecord* newBor); 
    void removeBorrowerRecord(); 
    void p_removeBorrowerRecord(string id); 
    void updateBorrowerRecord(); 
    void p_updateBorrowerRecord(string id, string name, string phone, int violations, string status); 

    void addBook(); 
    void p_addBook(string id, Book* newBook); 
    void removeBook(); 
    //void updateBook();

    //void lendOneBook(); 
    //void returnOneBook(); 
    //void updateInfoBook(); 

    //void displayBookAvailableForLoan(); 
    //void getInfoABook(); 
    //void getInfoABorrowerRecord(); 
    //void displayInfoAllBook(); 
};
#endif