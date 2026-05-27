#include "Tree.h"
#include "Root.h"

Tree::Tree(double value):Node(value){
    this -> setRoot(value); 
}

void Tree::setRoot(double value){
    Root* newRoot = new Root(value);
    this -> root = newRoot;  
}
Root* Tree::getRoot() const{
    return this -> root; 
}

void Tree::addLeaf(double value){
    this -> root->addLeaf(value); 
}
void Tree::removeLeaf(double value){
    this -> root -> removeLeaf(value); 
}

void Tree::addSubTree(Tree* subTree){
    this -> root -> addSubTree(subTree); 
}
void Tree::removeSubTree(Tree* subTree){
    this -> root -> removerSubTree(subTree); 
}

double Tree::calSum(){
    return this -> root -> calSum(); 
}

void Tree::display() const{
    this -> root -> display(); 
}



