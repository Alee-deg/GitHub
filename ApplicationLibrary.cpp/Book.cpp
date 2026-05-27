#include "Book.h"
#include<iostream>

using namespace std; 

Book::Book(string aCatalogueNumber, string aTitle, string anAuthor){
    this -> setAuthor(anAuthor); 
    this -> setCatalogueNumber(aCatalogueNumber); 
    this -> setTitle(aTitle);
}
void Book::setAuthor(string author){
    this -> theAuthor = author; 
}
void Book::setCatalogueNumber(string number){
    this -> theCatalogueNumber = number; 
}
void Book::setTitle(string Title){
    this -> theTitle = Title; 
}
string Book::getAuthor() const{
    return this -> theAuthor; 
}
string Book::getCatalogueNumber() const{
    return this -> theCatalogueNumber; 
}
string Book::getTitle() const{
    return this -> theTitle; 
}
BorrowerRecord* Book::getBorrower() const{
    return this -> br; 
}
bool Book::isAvailable(){
    return br == NULL; 
}
void Book::display(){
    cout << "Number Id: " << getCatalogueNumber() << " ||" << " Author: " << getAuthor() << " ||" << " Title: " << getTitle() << endl; 
}
void Book::attachBorrower(BorrowerRecord *aBorrower){
    this -> br = aBorrower;
}
void Book::detachBorrower(){
    this -> br = NULL;
}

