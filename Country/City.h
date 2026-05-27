#ifndef CITY_H
#define CITY_H
#include<iostream>
#include<string>
using namespace std; 
class Country; 
class City{
    private:
    string name; 
    int population; 
    Country* isCapitalOf;
    public:
    City(string name, int population); 
    City(string name, int population, Country* country);
    
    void setName(string name);
    string getName() const;
    void setPopulation(int population); 
    int getPopulation() const; 
    void setIsCapitalOf(Country* country);
    Country* getIsCapitalOf() const; 

    bool isCapital() const;

    void attach(Country* country);
    void dettach();

    void display() const; 

}; 
#endif