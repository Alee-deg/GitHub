#ifndef BOOK_H
#define BOOK_H

#include<string>
#include "BorrowerRecord.h"
using namespace std; 

class Book{
    string theCatalogueNumber; 
    string theAuthor; 
    string theTitle; 
    BorrowerRecord *br = NULL; 
    public:
    Book():Book("", "", ""){}
    Book(string aCatalogueNumber, string aTitle, string anAuthor); 
    void setCatalogueNumber(string aCatalogueNumber); 
    string getCatalogueNumber() const;
    void setTitle(string aTitle); 
    string getTitle() const; 
    void setAuthor(string anAuthor);
    string getAuthor() const;
    void attachBorrower(BorrowerRecord *aBorrower); 
    void detachBorrower(); 
    bool isAvailable(); 
    void display(); 
}; 

#endif