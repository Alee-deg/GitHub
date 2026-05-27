#include<iostream>
using namespace std; 
class point{
    float x, y; 
    public:
    point(){
        cout << "point::point"; 
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
    virtual ~point(){
        cout << "point::~point()\n"; 
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
class threedimpoint : public point{
    float z; 
    public:
    threedimpoint(){
        z = 0; 
    }
    threedimpoint(float ox, float oy, float oz):point(ox, oy){
        cout << "threedimpoint::threedimpoint(float, float, float)\n"; 
        z = oz; 
    }
    threedimpoint(threedimpoint &p) :point(p){
        z = p.z; 
    }
    ~threedimpoint(){
        cout << "threedimpoint::~threedimpoint()"; 
    }
    void Identifier(){
        cout << "Toa do z : "<<z<<endl; 
    }
}; 
class coloredthreedimpoint : public threedimpoint{
    unsigned color; 
    public:
    coloredthreedimpoint(){
        color = 0; 
    }
    coloredthreedimpoint(float ox, float oy, float oz, unsigned c) : threedimpoint(ox, oy, oz){
        cout << "coloredthreedimpoint::coloredthreedimpoint(float, float, float, unsigned)\n"; 
        color = c; 
    }
    coloredthreedimpoint(coloredthreedimpoint &p) :threedimpoint(p){
        color = p.color; 
    }
    ~coloredthreedimpoint(){
        cout << "coloredthreedimpoint::~coloredthreedimpoint()\n"; 
    }
    void Identifier(){
        cout<<"Diem mau : "<<color<<endl; 
    }
}; 
int main(){
    point *p0 = new point(2, 10); 
    point *p1 = new threedimpoint(2, 3, 5); 
    point *p2 = new coloredthreedimpoint(2, 3, 4, 10); 
    delete p1; 
    delete p2; 
    return 0; 
}