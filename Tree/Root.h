#ifndef ROOT_H
#define ROOT_H
#include<unordered_set>
#include "Node.h"
#include "Leaf.h"

using namespace std; 

class Root{
    private:
    double value;
    unordered_set<Node*> Nodes; 
    public:
    Root(double value); 
    ~Root(){
        for(auto &node : Nodes){
            if(dynamic_cast<Leaf*>(node)){
                delete node; 
            }
        }
    }

    void setValue(double value); 
    double getValue() const; 

    void addLeaf(double value); 
    void removeLeaf(double value); 

    void addSubTree(Tree *subTree);
    void removerSubTree(Tree* subTree); 

    double calSum();
    
    void display() const; 

}; 
#endif