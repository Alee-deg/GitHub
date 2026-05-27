#ifndef COUNTRY_H
#define COUNTRY_H
#include "City.h"
#include<unordered_map>
class Country{
    private:
    string name;
    City* Capital; 
    unordered_map<string, City*> Cities; 
    public:
    Country(string name);
    Country(string name, City* capital); 
    ~Country(); 

    void setName(string name);
    string getName() const; 
    void setCapital(City* capital); 
    City* getCapital() const; 

    void addNewCity(string nameOfCity, int population);
    void removeCity(string nameOfCity); 
    void changeCapital(City* nameOfCity1, City* nameOfCity2);

    long long sumPerson() const; 
    void displayInfoCity() const;
    void displayInfo() const; 
}; 
#endif