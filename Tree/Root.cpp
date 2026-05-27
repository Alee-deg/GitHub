#include "Root.h"
#include "Leaf.h"
#include<iostream>

using namespace std; 

Root::Root(double value){
    this -> setValue(value); 
}

void Root::setValue(double value){
    this -> value = value; 
}
double Root::getValue() const{
    return this -> value; 
}

void Root::addLeaf(double value){
    Node* leaf = new Leaf(value); 
    Nodes.insert(leaf); 
}

void Root::removeLeaf(double value) {
    // Không tăng it ở đây nữa
    for (auto it = Nodes.begin(); it != Nodes.end(); ) { 
        if (Leaf* leaf = dynamic_cast<Leaf*>(*it)) { // Cast và kiểm tra luôn
            if (leaf->getValue() == value) {
                delete *it;          // 1. Giải phóng bộ nhớ (đối tượng Leaf)
                it = Nodes.erase(it); // 2. Xóa khỏi danh sách và cập nhật it
                // return;           // Thêm return nếu bạn chỉ muốn xóa 1 cái lá duy nhất
                continue;            // Tiếp tục vòng lặp mà không cần it++
            }
        }
        it++; // Chỉ tăng it nếu không xóa gì ở bước này
    }
}

void Root::addSubTree(Tree* subTree){
    if(Nodes.find(subTree) == Nodes.end()){
        Nodes.insert(subTree); 
    }
    else{
        cout << "subTree is available\n"; 
    }
}

void Root::removerSubTree(Tree* subTree){
    if(Nodes.find(subTree) == Nodes.end()){
        cout << "subTree is not available\n"; 
    }
    else{
        auto it = Nodes.find(subTree); 
        Nodes.erase(it); 
    }
}

double Root::calSum(){
    double sum = this -> getValue();
    for(auto &node : Nodes){
        if(dynamic_cast<Tree*>(node)){
            sum += node->calSumValueOfANode((Tree*)node); 
        }
        else{
            sum += node -> getValue(); 
        }
    }
    return sum; 
}

void Root::display() const{
    cout << this -> getValue() << endl; 
    cout << "Value of Child\n"; 
    for(auto &node : Nodes){
        node -> display();  
    }
}

