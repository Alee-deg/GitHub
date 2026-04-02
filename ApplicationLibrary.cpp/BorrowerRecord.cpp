#include "BorrowerRecord.h"
#include "Book.h"
#include<iostream>

using namespace std; 

BorrowerRecord::BorrowerRecord(string name){ 
    this -> setName(name); 
}
string BorrowerRecord::getName() const{
    return this -> theName; 
}
void BorrowerRecord::setName(string name){
    this -> theName = name; 
}
void BorrowerRecord::attachBook(Book *aBook){
    for(auto book : lendedBook){
        if(book -> getCatalogueNumber() == aBook -> getCatalogueNumber()){
            return;  
        }
    }
    lendedBook.push_back(aBook); 
}

void BorrowerRecord::detachBook(const Book* aBook) {
    for (auto it = lendedBook.begin(); it != lendedBook.end(); ++it) {
        if ((*it)->getCatalogueNumber() == aBook->getCatalogueNumber()) {
            // delete *it;   // Delete the book pointed to by 'it'
            lendedBook.erase(it);   // Erase it from vector, don't increment ‘it’, because elements after erased element are shifted
            return;   // Return immediately after a match is found and deleted
        }
    }
}

void BorrowerRecord::displayLendedBook() const{
    if(!lendedBook.empty()){
        for(auto it: lendedBook){
            it -> display(); 
        }
    }
}

BorrowerRecord::BorrowerRecord(const BorrowerRecord &other){
    this -> theName = other.getName(); 
    this -> lendedBook = other.lendedBook; 
}

void BorrowerRecord::display() const{
    cout << "Name: " << this -> getName() << endl; 
}