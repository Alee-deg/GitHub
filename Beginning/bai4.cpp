#include<iostream>
using namespace std; 
class point{
    int x; 
    int y; 
    public:
        point(int ox = 1, int oy = 0){
            cout <<"Tao doi tuong: "<<this<<endl; 
            cout<<"Dung ham thiet lap hai tham so\n"; 
            x = ox; 
            y = oy; 
        }
        //Ham thiet lap sao chep
        point(point &p){
            cout <<"Tao doi tuong: "<<this<<endl; 
            cout <<"Dung ham thiet lap sao chep\n"; 
            x = p.x; y = p.y; 
        }
        void move(int dx, int dy){
            x += dx; y += dy; 
        }
        void display(); 
}; 
void point::display(){
    cout <<"Toa do: "<<x<<" "<<y<<"\n"; 
}
point fct(point &a){
    point b = a; 
    b.move(2, 3); 
    return b; 
}
int main(){
    point a(5, 2); 
    a.display(); 
    point b = fct(a); 
    b.display(); 
    return 0; 
}