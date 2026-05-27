#include<iostream>
#include<cmath>
using namespace std; 
class complex{
    float real, image; 
    public:
    complex(float r, float i){
        real = r; image = i; 
    }
    complex(complex &b){
        cout << "Ham thiet lap sao chep\n";
        real = b.real; image = b.image; 
    }
    operator float(){
        cout<<"Goi float() cho complex\n"; 
        return real; 
    }
    void display(){
        cout << real << (image >= 0 ? '+':'-') << "j*" << fabs(image) << endl; 
    }
}; 
void fct(float n){
    cout << "Goi fct voi tham so : "<<n<<endl; 
}
int main(){
    complex a(3, 4); 
    fct(6); 
    fct(a); 
    return 0; 
}