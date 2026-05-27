#include<iostream>
#include<cmath>
using namespace std; 
class complex{
    float real, image; 
    public:
    complex(float r){
        cout << "Ham thiet lap dong vai tro cua ham toan tu chuyen kieu ngam dinh\n";
        this -> real  = r; this -> image = 0; 
    }
    complex(float r, float i){
        cout << "Ham thiet lap \n"; 
        real = r; image = i; 
    }
    void display(){
        cout << this -> real << " " << this -> image << "\n"; 
    }
    complex & operator=(complex &p){
        real = p.real; image = p.image; 
        cout << "gan complex  --> complex tu " << &p << " sang" << this << endl; 
        return *this; 
    }
    complex & operator=(float n){
        real = n; image = 0; 
        cout << "gan float -->complex "<< endl; 
        return *this; 
    }
}; 
int main(){
    complex a(3, 4); 
    a = 12; 
    a.display(); 
    return 0; 
}