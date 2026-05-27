#include<iostream>
using namespace std; 
class point{
    float x, y; 
    public:
    point(){
        cout << "point::point()\n"; 
        x = 0; 
        y = 0; 
    }
    point(float ox, float oy){
        cout << "point::point(float, float)\n"; 
        x = ox; 
        y = oy;
    }
    point(point &p){
        cout << "point::point(point &)\n"; 
        x = p.x; 
        y = p.y; 
    }
    void display(); 
    void move(float dx, float dy){
        x += dx; 
        y += dy; 
    }
    virtual void Identifier(){
        cout << "Diem khong mau \n"; 
    }
};
void point::display(){
    cout << "Toa do : "<<x<<" "<<y<<endl; 
    Identifier(); 
}
class coloredpoint : public point {
    unsigned int color; 
    public:
    coloredpoint():point(){
        cout << "coloredpoint::coloredpoint()\n"; 
        color = 0; 
    }
    coloredpoint(float ox, float oy, unsigned int c); 
    coloredpoint(coloredpoint &b):point((point &)b){
        cout << "coloredpoint::coloredpint(coloredpoint &)\n"; 
        color = b.color; 
    }
    void Identifier(){
        cout << "Mau : "<<color<<endl; 
    }
}; 
coloredpoint::coloredpoint(float ox, float oy, unsigned c):point(ox, oy){
    cout << "coloredpoint::coloredpoint(float, float, unsigned)\n"; 
    color = c; 
}
int main(){
    cout << "coloredpoint pc(2, 3, 5);\n"; 
    coloredpoint pc(2, 3, 5); 
    cout << "pc.display()\n"; 
    pc.display(); 
    cout << "point p(10, 20); \n"; 
    point p(10, 20); 
    cout << "p.display()\n"; 
    p.display(); 
    return 0; 
}