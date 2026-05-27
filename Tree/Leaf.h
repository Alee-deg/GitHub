#ifndef LEAF_H
#define LEAF_H
#include "Tree.h"
class Leaf:public Node{
    private:
    Tree* isLeafOf; 
    public:
    Leaf(double value):Leaf(value, nullptr){}; 
    Leaf(double value, Tree* isLeafOf);

    void setIsLeafOf(Tree* isLeafOf); 
    Tree* getIsLeafOf() const; 

    void attachTree(Tree* root); 
    void detachTree(); 

    bool isLeaf(); 

    void display() const override; 

}; 
#endif