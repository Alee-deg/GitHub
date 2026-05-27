#include "university.h"
#include "universitySchool.h"

University::University(string name){
    this -> setName(name); 
}
string University::getName() const{
    return this -> name; 
}
void University::setName(string name){
    this -> name = name; 
}

void University::attachSchool(UniversitySchool *school){
    if(this -> manager.find(school) == this -> manager.end()){
        this -> manager.insert(school); 
        school -> attachUniversity(this); 
    }
}

void University::dettachSchool(UniversitySchool *school){
    if(this -> manager.find(school) == this -> manager.end()){
        cout << "School is not available\n"; 
        return; 
    } 
    auto temp = this -> manager.find(school); 
    (*temp) ->dettachUniversity();  
    this -> manager.erase(temp); 
}

void University::displayInf() const{
    cout << this -> getName() << endl;  
}

void University::displaySchool() const{
    cout << "member Of University" << endl; 
    for(auto &school : manager){
        school ->displayInfo(); 
    }
}
