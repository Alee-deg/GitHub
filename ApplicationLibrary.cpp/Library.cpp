#include "Book.h"
#include "BorrowerRecord.h"
#include "Library.h"

using namespace std; 
#include<ctime>
#include<stdlib.h>

Library::Library(string aName){
    this -> setName(aName); 
}

void Library::setName(string aName){
    this -> theName = aName; 
}
string Library::getName() const{
    return this -> theName; 
}

void Library::registerOneBorrower(string aBorrowerName){
    for(auto it : List){
        if(aBorrowerName == it -> getName()){
            return; 
        }
    }
    BorrowerRecord* newBorrower = new BorrowerRecord(aBorrowerName); 
    this -> List.push_back(newBorrower); 
}

void Library::addOneBook(Book *aBook){
    for(auto it : stocks){
        if(it -> getCatalogueNumber() == aBook -> getCatalogueNumber()){
            return; 
        }
    }
    stocks.push_back(aBook);  
}

void Library::displayBooksAvailableForLoan() const{
    for(auto it : stocks){
        if(it -> isAvailable()){
            it -> display();
        }
    }
}

void Library::displayBooksOnLoan() const{
    for(auto it : stocks){
        if(!(it -> isAvailable())){
            it -> display(); 
        }
    }
}

void Library::displayRegistedBorrower(){
    if(List.empty()){
        return; 
    } 
    for(auto it : List){
        it -> display(); 
    }
}

void Library::returnOneBook(string aCatalogueNumber) const {
    for(auto it : stocks){
        if(it -> getCatalogueNumber() == aCatalogueNumber){
            it -> display(); 
        }
    }
}

void Library::lendOneBook(string aCatalogueNumber, string aBorrower){
    Book* book = NULL; 
    for(auto it : stocks){
        if(it -> getCatalogueNumber() == aCatalogueNumber){
            if(it -> isAvailable()){
                book = it; 
                break; 
            }
        }
    }
    if(!book) return; 
    BorrowerRecord* borrower = NULL; 
    for(auto it : List){
        if(it -> getName() == aBorrower){
            borrower = it; 
            break; 
        }
    }
    if(!borrower){
        this -> registerOneBorrower(aBorrower); 
        borrower = List.back(); 
    }
    borrower->attachBook(book); 
    book->attachBorrower(borrower); 
}

void Library::returnOneBrorrowser(string aBorrowerName){
    for(auto it : List){
        if(it -> getName() == aBorrowerName){
            it -> display(); 
            it -> displayLendedBook(); 
            return; 
        }
    }
}