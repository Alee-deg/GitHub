#include<iostream>
#include<cmath>
using namespace std; 
class complex{
    float real, image; 
    public:
    complex(float r){
        cout << "Ham thiet lap dong vai tro cua ham toan tu chuyen kieu ngam dinh\n"; 
        real = r; image = 0; 
    }
    complex(float r, float i){
        cout << "Ham thiet lap hai tham so\n"; 
        real = r; image = i; 
    }
    void display(){
        cout << real << (image >= 0 ? "+j*" : "-j*") << fabs(image) << endl; 
    }
    friend complex operator+(complex, complex); 
}; 
complex operator+(complex a, complex b){
    complex c(0, 0); 
    c.real = a.real + b.real; 
    c.image = a.image + b.image; 
    return c; 
}
int main(){
    complex a(3, 4), b(9, 4); 
    a = b + 5; a.display(); 
    a = 2 + b; a.display();
    return 0;  
}