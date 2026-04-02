#ifndef BORROWERRCORD_H
#define BORROWERRCORD_H

#include<string>
#include<vector>
using namespace std; 

class Book; 

class BorrowerRecord{
    string theName; 
    vector<Book*> lendedBook; 
    public:
    BorrowerRecord():BorrowerRecord(""){}; 
    BorrowerRecord(string name);
    BorrowerRecord(const BorrowerRecord &other);
    void setName(string name);
    string getName() const; 
    void displayLendedBook() const; 
    void attachBook(Book *aBook); 
    void detachBook(const Book *aBook); 
    void display() const; 
}; 

#endif