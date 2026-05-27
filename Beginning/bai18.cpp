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
        cout << "Ham thiet lap \n"; 
        real = r; image = i; 
    }
    complex(complex &b){
        cout <<"Ham thiet lap sao chep lai " << &b << " Sang" << this << endl; 
        real = b.real; image = b.image; 
    }
}; 
void fct(complex p){
    cout << "Goi fct\n"; 
}
int main(){
    complex a(3, 4); 
    a = complex(12); 
    a = 12; 
    fct(4); 
    return 0; 
}