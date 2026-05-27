#include<iostream>
#include<cmath>
using namespace std; 
class complex{
    float real, image; 
    public:
    complex(float r = 0, float i = 0){
        real = r; image = i; 
    }
    void display(){
        cout << real << (image >= 0 ? '+' : '-') << "j*"<< fabs(image) << endl; 
    }
    complex operator+(complex b){
        cout << "Goi toi complex :: operator+(float, complex)\n"; 
        complex c; 
        c.real = this -> real + b.real; 
        c.image = this -> image + b.image; 
        return c; 
    }
    friend complex operator+(float x, complex b); 
}; 
complex operator+(float x, complex b){
    cout << "Goi toi operator+(float, complex)\n"; 
    complex c; 
    c.real = x + b.real; 
    c.image = b.image; 
    return c; 
}
int main(){
    complex a(-2, 5); 
    complex b(3, 4); 
    cout << "Hai so phuc: \n"; 
    cout << "a = "; 
    a.display(); 
    cout << "b = "; 
    b.display(); 
    cout << "Tong hai so phuc:\n"; 
    complex c; 
    c = a + b; 
    cout << "c = "; 
    c.display(); 
    cout << "Tang them phan thuc cua a 3 don vi\n"; 
    complex d; 
    d = 3 + a; 
    cout << "d = "; 
    d.display(); 
    return 0; 
}