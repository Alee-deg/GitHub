#ifndef LIBRARY_H
#define LIBRARY_H

#include<iostream>
#include<string>
#include<vector>
#include "book.h"
#include "borrowerRecord.h"

using namespace std; 

class Library{
    string theName; 
    vector<Book*> stocks; 
    vector<BorrowerRecord*> List; 
    public:
    Library():Library(""){} 
    Library(string aName); 
    ~Library(){
        for(auto it : List){
            delete it; 
        }
    }
    void setName(string aName);
    string getName() const;  
    void registerOneBorrower(string aBorrowerName); 
    void displayRegistedBorrower(); 
    void addOneBook(Book *aBook); 
    void displayBooksAvailableForLoan() const; 
    void displayBooksOnLoan() const; 
    void lendOneBook(string aBorrower, int ID); 
    void returnOneBook(string aCatalogueNumber);  
    void returnOneBrorrowser(string aBorrowerName, int ID); 
}; 
#endif