#include "Node.h"
#include "Leaf.h"
#include "Root.h"
#include "Tree.h"

#include<iostream>

using namespace std;

int main(){
    Tree *testTree = new Tree(10); 
    Tree *leftTree = new Tree(5);
    testTree->addChildNodeIsSubtree(testTree, leftTree); 
    testTree->addLeaf(15);
    leftTree->addLeaf(2);
    leftTree->addLeaf(7); 
    testTree->display(); 
    cout << testTree->calSumValueOfANode(testTree) << endl;
    cout << "\n";  
    testTree->removeLeaf(5);
    testTree -> display();  
    delete testTree; 
    delete leftTree; 
    return 0; 
}