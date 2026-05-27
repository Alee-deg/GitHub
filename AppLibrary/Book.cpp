#include "Book.h"
#include<stdexcept>

Book::Book(string idBook, string author, string title, string intro, double price, int quantity){
    this -> setIdBook(idBook); 
    this -> setAuthor(author); 
    this -> setIntro(intro); 
    this -> setTitle(title); 
    this -> setPrice(price); 
    this -> setQuantity(quantity); 
}

void Book::setIdBook(string idBook){
    if(idBook.empty()){
        throw std::invalid_argument("ID cannot be left blank!"); 
    }
    this -> idBook = idBook; 
}
void Book::setAuthor(string author){
    if(author.empty()){
        throw std::invalid_argument("Name of Author cannot be left blank!"); 
    }
    this -> theAuthor = author; 
}
void Book::setIntro(string intro){
    if(intro.empty()){
        throw std::invalid_argument("Intro cannot be left blank!"); 
    }
    this -> intro = intro; 
}
void Book::setPrice(double price){
    if(price < 0){
        throw std::invalid_argument("Price of book cannot less then 0"); 
    }
    this -> price = price; 
}
void Book::setQuantity(int quantity){
    if(quantity < 0){
        throw std::invalid_argument("Quantity book cannot less then 0"); 
    }
    this -> quantity = quantity; 
}
void Book::setTitle(string title){
    if(title.empty()){
        throw std::invalid_argument("Title cannot be left blank!"); 
    }
    this -> theTitle = title; 
}

