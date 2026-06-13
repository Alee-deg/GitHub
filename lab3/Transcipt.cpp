#include "Transcript.h"
#include "TE.h"
#include "Section.h"   
#include <iostream> 
void Transcript::addTEs(TE* newTE){
    for(auto it : this->TEs){
        if(it == newTE){
            std::cout << "TE is already exists" << "\n"; 
            return; 
        }
    }
    this->TEs.push_back(newTE); 
}

void Transcript::dropSection(Section* section){
    for(auto it : this->TEs){
        if(it->getSection() == section){
            this->TEs.remove(it); 
            return; 
        }
    }
    std::cout << "Section is not found" << "\n"; 
};

std::list<TE*> Transcript::getTEs(){return this->TEs;}

Transcript::~Transcript(){
    for(auto it : this->TEs){
        delete it; 
    }
}

void Transcript::displayTE(){
    for(auto it : this->TEs){
        it->dislay(); 
    }
}