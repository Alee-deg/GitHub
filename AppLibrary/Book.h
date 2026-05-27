#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include<string>
using namespace std; 
class Book{
    private:
    string idBook, theAuthor, theTitle, intro;
    double price; 
    int quantity; 
    public:
    Book(string idBook, string author, string title, string intro, double price, int quantity); 

    void setIdBook(string idBook);
    void setAuthor(string author); 
    void setTitle(string title); 
    void setIntro(string intro); 
    void setPrice(double price); 
    void setQuantity(int quantity); 

    string getIdBook() const; 
    string getAuthor() const; 
    string getTitle() const; 
    string getIntro() const; 
    double getPrice() const;
    int getQuantity() const;  
}; 
#endif