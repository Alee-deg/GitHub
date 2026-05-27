#include<iostream>
using namespace std; 
class point{
    float x, y; 
    public:
    point(){
        x = 0; y = 0; 
    }
    point(float ox, float oy){
        x = ox; y = oy; 
    }
    point(point &p){
        x = p.x; y = p.y; 
    }
    void display(){
        cout << "Goi ham point::display() \n"; 
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
    coloredpoint():point(){
        color = 0; 
    }
    coloredpoint(float ox, float oy, unsigned int c):point(ox, oy){
        color = c; 
    }
    coloredpoint(coloredpoint &b):point((point &)b){
        color = b.color; 
    }
    void display(){
        cout << "Ham coloredpoint::display()\n"; 
        point::display(); 
        cout << "Mau " << color << endl; 
    }
}; 
int main(){
    point *adp; 
    coloredpoint pc(2, 3, 5); 
    pc.display(); 
    cout << "adp = &pc \n"; 
    adp=&pc; 
    adp -> move(2, 3);
    cout << "adp -> move(2, 3)\n"; 
    pc.display(); 
    adp -> display(); 
    return 0;  
}