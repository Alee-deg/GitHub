#include<iostream>
#include<cmath>
using namespace std; 
class complex{
    float real, image; 
    public:
    complex(float r, float i){
        real = r; image = i; 
    }
    operator float(){
        cout << "Goi float() cho ham complex\n"; 
        return real; 
    }
    void display(){
        cout << real << (image >= 0 ? '+':'-') << "j*" << fabs(image) << endl; 
    }
}; 
int main(){
    complex a(3, 4); 
    complex b(5, 7); 
    float n1, n2; 
    n1 = a + 3; cout << "n1 = " << n1 << endl; 
    n2 = a + b; cout << "n2 = " << n2 << endl; 
    double z1, z2; 
    z1 = a + 3; cout << "z1 = " << z1 << endl; 
    z2 = a + b; cout << "z2 = " << z2 << endl; 
    return 0; 
}