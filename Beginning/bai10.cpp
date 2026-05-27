#include<iostream>
#include<math.h>
using namespace std; 
class complex{
    float real, image; 
    public:
    complex(float r = 0, float i = 0){
        real = r; image = i; 
    }
    void display(){
        cout << real << (image >= 0 ? '+' : '-') << "j*" << fabs(image) << endl; 
    }
    complex operator+(const complex &b){
        complex c; 
        c.real = this -> real + b.real;
        c.image = this -> image + b.image; 
        return c;  
    }
}; 
int main(){
    complex a(-2, 5); 
    complex b(3, 4); 
    cout << "Hai so phuc: \n"; 
    a.display(); 
    b.display(); 
    cout << "tong hai so phuc: \n";
    complex c; 
    c = a + b; 
    c.display(); 
    return 0;  
}