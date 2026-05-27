#include<iostream>
using namespace std; 
class point{
    int x, y; 
    public:
        point(int ox, int oy){x = ox; y = oy;} // Ham thiet lap
        void move(int, int); 
        void display(); 
}; 
void point::move(int dx, int dy){
    x += dx; 
    y += dy; 
}
void point::display(){
    cout <<"Toa do: "<<x<<" "<<y<<"\n"; 
}
int main(){
    point a(5, 2); 
    a.display(); 
    a.move(-2,4); a.display(); 
    point b(1, -1); b.display(); 
    return 0; 
}