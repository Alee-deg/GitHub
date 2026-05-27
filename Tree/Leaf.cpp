#include "Leaf.h"

Leaf::Leaf(double value, Tree* isLeafOf):Node(value){
    this -> setIsLeafOf(isLeafOf); 
}

void Leaf::setIsLeafOf(Tree *isLeafOf){
    this -> isLeafOf = isLeafOf; 
}
Tree* Leaf::getIsLeafOf() const{
    return this -> isLeafOf; 
}

void Leaf::attachTree(Tree *root){
    this -> isLeafOf = root; 
}
void Leaf::detachTree(){
    this -> isLeafOf = nullptr; 
}
bool Leaf::isLeaf(){
    return this -> isLeafOf != nullptr; 
}

void Leaf::display() const{
    Node::display(); 
}