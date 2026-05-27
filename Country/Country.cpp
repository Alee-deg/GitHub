#include "Contry.h"

Country::Country(string name):Country(name, NULL){}; 
Country::Country(string name, City* capital){
    this -> setName(name);
    this -> setCapital(capital); 
}
Country::~Country(){
    for(auto city : Cities){
        delete city.second; 
    }
}

void Country::setName(string name){
    this -> name = name; 
}
string Country::getName() const{
    return this -> name; 
}
void Country::setCapital(City* capital){
    this -> Capital = capital; 
}
City* Country::getCapital() const{
    return this -> Capital; 
}

void Country::addNewCity(string nameOfCity, int population){
    if(this -> Cities.find(nameOfCity) == this -> Cities.end()){
        City* newCity = new City(nameOfCity, population);
        return;  
    }
    cout << "City was existed\n"; 
}

void Country::removeCity(string nameOfCity){
    if(this -> Cities.find(nameOfCity) == this -> Cities.end()){
        cout << "City is not exists\n"; 
        return; 
    }
    auto it = this -> Cities.find(nameOfCity);
    Cities.erase(it); 
}

void Country::changeCapital(City* City1, City* City2){
    if(this -> Cities.find(City1 -> getName()) == this -> Cities.end()){
        if(this -> Cities.find(City2 -> getName()) == this -> Cities.end()){
            return; 
        }
        else{
            City1 -> dettach();
            City2 -> attach(this);  
        }
    }
}

long long Country::sumPerson() const{
    long long sum = 0; 
    for(auto city : Cities){
        sum += city.second -> getPopulation();
    }
    return sum; 
}

void Country::displayInfoCity() const{
    for(auto city : Cities){
        city.second -> display();
    }
}

void Country::displayInfo() const{
    cout << "Name of Country: " << this -> getName() << endl; 
    cout << "Capital is: " << this -> Capital -> getName() << endl; 
}
