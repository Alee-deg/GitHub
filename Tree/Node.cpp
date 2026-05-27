#include "Node.h"
#include "Tree.h"
#include<iostream>
using namespace std; 
Node::Node(double value){
    this -> setValue(value); 
}

void Node::setValue(double value){
    if(value == INF){
        cout << "Pleas enter again\n"; 
        return; 
    }
    this -> value = value; 
}
double Node::getValue() const{
    return this -> value; 
}

void Node::addChildNodeIsSubtree(Tree *root, Tree* subTree){
    root ->addSubTree(subTree); 
}
void Node::removeChildNodeIsSubtree(Tree *root, Tree *subTree){
    root ->removeSubTree(subTree); 
}

void Node::addLeaf(Tree *root, double value){
    root -> addLeaf(value); 
}
void Node::removeLeaf(Tree* root, double value){
    root -> removeLeaf(value); 
}

double Node::calSumValueOfANode(Tree* root){
    return root -> calSum(); 
}
void Node::display() const{

    cout << this -> getValue() << endl; 
}
