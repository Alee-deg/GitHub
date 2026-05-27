#ifndef NODE_H
#define NODE_H
#define INF 1e9
class Tree; 
class Node{
    private:
    double value; 
    public:
    Node():Node(INF){}; 
    Node(double value); 

    void setValue(double value);
    double getValue() const; 

    void addChildNodeIsSubtree(Tree* root, Tree* subTree);
    void removeChildNodeIsSubtree(Tree* root, Tree* subTree); 

    void addLeaf(Tree* root, double value);
    void removeLeaf(Tree* root, double value); 

    double calSumValueOfANode(Tree* root);

    virtual void display() const;  
}; 
#endif