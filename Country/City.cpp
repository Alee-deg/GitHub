#include "City.h"

City::City(string name, int population):City(name, population, NULL){}; 
City::City(string name, int population, Country* country){
    this -> setName(name);
    this -> setPopulation(population);
    this -> setIsCapitalOf(country); 
}

void City::setName(string name){
    this -> name = name; 
}
string City::getName() const{
    return this -> name; 
}
void City::setPopulation(int population){
    this -> population = population;
}
int City::getPopulation() const{
    return this -> population; 
}
void City::setIsCapitalOf(Country* country){
    this -> isCapitalOf = country; 
}
Country* City::getIsCapitalOf() const{
    return this -> isCapitalOf; 
}

bool City::isCapital() const{
    return this -> isCapitalOf == NULL; 
}

void City::attach(Country* country){
    this -> isCapitalOf = country; 
}
void City::dettach(){
    this -> isCapitalOf = NULL; 
}

void City::display() const{
    cout << "Name of city: " << this -> getName() << endl;
    cout << "Population of city: " << this ->getPopulation() << endl; 
 //   cout << "Is Capital: " << this -> getIsCapitalOf() << endl;  
}