#include "universitySchool.h"

UniversitySchool::UniversitySchool(string name, string locate, University* isMember){
    this -> setName(name); 
    this -> setLocate(locate);
    this -> setUniversity(isMember); 
}

string UniversitySchool::getName() const{
    return this -> name; 
}
void UniversitySchool::setName(string name){
    this -> name = name; 
}

string UniversitySchool::getLocate() const{
    return this -> locate;
}
void UniversitySchool::setLocate(string locate){
    this -> locate = locate; 
}

University* UniversitySchool::getUniversity() const{ 
    return this -> isMember; 
}

void UniversitySchool::setUniversity(University *univer){
    this -> isMember = univer; 
}

void UniversitySchool::attachUniversity(University* univer){
    this -> isMember = univer; 
}

void UniversitySchool::dettachUniversity(){
    this -> isMember = NULL; 
}

bool UniversitySchool::isMem() const{
    return this -> isMember == NULL; 
}
void UniversitySchool::displayInfo() const{
    cout << "NameOfSchool: " << this -> getName() << endl;
    cout << "LocateOfSchool: " << this -> getLocate() << endl;
    cout << "isMemberOf: "; 
    if(!this->isMem()){
        this -> getUniversity() -> displayInf(); 
    }
    else{
        cout << "Not yet is member" << endl; 
    }
}