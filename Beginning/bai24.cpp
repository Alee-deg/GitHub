#include<iostream>
using namespace std; 
class point{
    float x, y; 
    public:
    float getx(){return x;}
    float gety(){return y;}
    point(){x = 0; y = 0;}
    point(float ox, float oy){x = ox; y = oy;}
    point(point &p){
        x = p.x;
        y = p.y; 
    }
    void display(){
        cout << "Goi ham point::display()\n"; 
        cout <<"Toa do :"<<x<<" "<<y<<endl; 
    }
    void move(float dx, float dy){
        x += dx; 
        y += dy; 
    }
}; 
class coloredpoint : public point{
    unsigned int color; 
    public:
    coloredpoint() : point(){
        color = 0; 
    }
    coloredpoint(float ox, float oy, unsigned int c); 
    coloredpoint(coloredpoint &b):point(b.getx(), b.gety()){
        cout << "Goi ham thiet lap sao chep" << " coloredpoint::coloredpoint(coloredpoint &) \n"; 
        color = b.color; 
    }
    void display(){
        cout << "Ham coloredpoint::display()\n"; 
        point::display(); 
        cout << "Mau "<<color<<endl; 
    }
}; 
coloredpoint::coloredpoint(float ox, float oy, unsigned c):point(ox, oy){
    color = c; 
}
int main(){
    coloredpoint pc(2, 3, 5); 
    cout << "pc = "; 
    pc.display(); 
    cout << "coloredpoint qc = pc; \n"; 
    coloredpoint qc = pc; 
    cout << "qc = "; 
    qc.display(); 
    return 0; 
}