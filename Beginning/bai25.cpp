#include<iostream>
using namespace std; 
class point{
    float x, y;
    public:
    point(){x = 0; y = 0;}
    point(float ox, float oy){x = ox; y = oy;}
    point(point &p){x = p.x; y = p.y;}
    void display(){
        cout << "Goi ham point::display()\n"; 
        cout << "Toa do :"<<x<<" "<<y<<endl; 
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
    coloredpoint(float ox, float oy, unsigned int c):point(ox, oy){
        color = c; 
    }
    coloredpoint(coloredpoint &b):point((point &)b){
        color = b.color; 
    }
    void display(){
        cout << "Mau "<<color<<endl; 
    }
}; 
int main(){
    coloredpoint m(2, 3, 5); 
    cout <<"Diem m \n"; 
    m.display(); 
    cout << "coloredpoint p = m; \n";
    coloredpoint p = m; 
    cout << "Diem p \n"; 
    p.display(); 
    return 0;  
}