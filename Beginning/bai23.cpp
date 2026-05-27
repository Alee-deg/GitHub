#include<iostream>
using namespace std; 
class point{
    float x, y; 
    public:
    void display(){
        cout << "Goi ham point::display() \n"; 
        cout << "Toa do :"<<x<<" "<<y<<endl; 
    }
    void move(float dx, float dy){
        x += dx; 
        y += dy; 
    }
}; 
int main(){
    cout << "Diem p \n"; 
    point p; 
    p.display(); 
    return 0; 
}