#include<iostream>
#include "Book.h"
#include "Library.h"
#include "BorrowerRecord.h"

using namespace std; 

int main(){
    vector<Book*> stocks; 
    Library HCMUS("HCMUS"); 
    Book* a = new Book("H121", "C", "FISHER"); 
    Book* b = new Book("LKD21", "Python", "NG.TH.L"); 
    stocks.push_back(a); 
    stocks.push_back(b); 
    HCMUS.addOneBook(b); 
    HCMUS.addOneBook(a); 
    HCMUS.registerOneBorrower("Haule"); 
    HCMUS.registerOneBorrower("NguyenHoang"); 
    HCMUS.lendOneBook("H121", "Haule"); 
    HCMUS.returnOneBrorrowser("Haule"); 
    cout << endl; 
    HCMUS.displayBooksOnLoan(); 
    HCMUS.displayRegistedBorrower();  
    HCMUS.displayBooksAvailableForLoan();
    for(auto x : stocks){
        delete x; 
    }
    return 0; 
}