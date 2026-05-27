#include<iostream>
#include<cmath>
using namespace std; 
class point; 
class complex{
    float real, image; 
    public:
    complex(float r = 0, float i = 0){
        real = r; image = i; 
    }
    complex(point); 
    void display(){
        cout << real <<(image >= 0 ? "+j*":"-j*") << fabs(image) << endl; 
    }
}; 
class point{
    int x, y; 
    public:
    point(int ox = 0; int oy = 0){x = ox; y = oy; }
    friend complex::complex(point); 
}; 
complex::complex(point p){
    real = p.x; image = p.y; 
}
int main(){
    point a(3, 5); 
    complex c = a; c.display(); 
    return 0; 
}