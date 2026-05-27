#include<iostream>
using namespace std; 
class point{
    float x, y; 
    public:
    point(float ox, float oy){
        cout << "++Constr.point\n"; 
        x = ox; 
        y = oy; 
    }
    ~point(){
        cout <<"--Destr.point\n"; 
    }
    void display(){
        cout << "Toa do : "<<x<<" "<<y<<"\n"; 
    }
}; 
class col{
    unsigned color; 
    public:
    col(unsigned c){
        cout << "++Constr.col\n"; 
        color = c; 
    }
    ~col(){
        cout << "--Destr.col\n"; 
    }
    void display(){
        cout << "Mau : "<<color<<"\n"; 
    }
}; 
class coloredpoint :public point, public col{
    public:
    coloredpoint(float ox, float oy, unsigned c) : point(ox, oy), col(c){
        cout << "++Constr.coloredpoint\n"; 
    }
    ~coloredpoint(){
        cout << "--Destr.coloredpoint\n"; 
    }
    void display(){
        point::display(); 
        col::display(); 
    }
}; 
int main(){
    coloredpoint p(3, 9, 2); 
    cout << "----------------\n"; 
    p.display(); 
    cout << "----------------\n"; 
    p.point::display(); 
    cout << "----------------\n"; 
    p.col::display(); 
    cout << "----------------\n"; 
    return 0; 
}