#ifndef TREE_H
#define TREE_H
#include "Node.h"
class Root; 
class Tree: public Node{
    private:
    Root *root; 
    public:
    Tree(double value); 

    void setRoot(double value); 
    Root* getRoot() const; 

    void addLeaf(double value);
    void removeLeaf(double value);
    
    void addSubTree(Tree* subTree); 
    void removeSubTree(Tree* subTree);

    double calSum();
    
    void display() const override; 

}; 


#endif
