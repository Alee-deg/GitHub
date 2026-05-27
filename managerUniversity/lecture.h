#ifndef LECTURE_H
#define LECTURE_H

#include<string>
using namespace std;

class lecture{
    private:
    string degree; 
    string type;
    int ID;
    string Name;
    float HSL;
    float Bonus;
    string rating; 
    string position; 
    public:
    lecture(int ID, string Name, string HSL,
        string Bonus, string Type, string degree, string position);

    void setID(int ID);
    int getID() const;
    void setName(string Name);
    string getName() const;
    void setHSL(float HSL);
    string getHSL() const;
    void setBonus(float bonus);
    string getBonus() const;  
    void setType(string Type);
    string getType() const; 
    void setRating(string rating);
    string getRating() const; 
    void setDegree(string degree); 
    string getDegree() const; 
    void setPosition(string position);
    string getPos() const; 

    int totalNumberOfSubjectsBeingTaught();
    void displaySubjectBeingTaught();
    int totalNumberOfScientificArticles();
    void dislayScientificArticles(); 

    void attachBook();
    void dettachBook();

    void attachArticle();
    void dettachArticle();

    void attachSubject();
    void dettachSubject();

    void display();

    friend istream &operator>>(istream &is, const lecture &lec);
}; 
#endif