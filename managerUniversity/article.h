#ifndef ARTICLE_H
#define ARTICLE_H

#include<string>
using namespace std;

class article{
    private:
    string ID;
    string name;
    string rating;
    string magazineName; 
    public:
    article(string ID, string name, string rating, string magazineName);
    
    void setID(string ID);
    string getID() const;
    void setName(string name);
    string getName() const;
    void setRating(string rating);
    string getRating() const; 
    void setMagazineName(string mangazineName);
    string getMangazineName() const; 

    void attach();
    void dettach();
    
    void display(); 

    friend istream &operator>>(istream &is, const article &art);
};
#endif