#include<iostream>
#include<cmath>
using namespace std; 
class complex{
    float real, image; 
    public:
    complex(){
        real = 0; image = 0; 
    }
    complex(float r){
        real = r; image = 0; 
    }
    complex(float r, float i){
        real = r; image = i; 
    }
    operator float(){
        return real; 
    }
    void display(){
        cout << real << (image >= 0 ? '+':'-') << "j*" << fabs(image) << endl; 
    }
    complex operator+(complex b){
        complex c; 
        c.real = real + b.real; 
        c.image = image + b.image; 
        return c; 
    }
}; 
int main(){
    cout << "a = "; 
    complex a(-2, 5); 
    a.display(); 
    cout << "b = "; 
    complex b(3, 4); 
    b.display(); 
    cout << "c = a + b : ";
    complex c; 
    c = a + b; 
    c.display(); 
    cout<<"d = 3 + c : "; 
    complex d;
    d = complex(3)+c;
    d.display();
    cout << "float x = a : ";
    float x = a;
    cout << x << endl;
    return 0;
}