#include<iostream>
#include<cmath>
using namespace std; 
class complex; 
class point{
    int x, y; 
    public:
    point(int ox = 0, int oy = 0){
        x = ox; y = oy; 
    }
    operator complex(); 
}; 
class complex{
    float real, image; 
    public:
    complex(float r = 0, float i = 0){
        real = r; image = i;
    }
    friend point::operator complex(); 
    void display(){
        cout << real <<(image >= 0 ? "+j*":"-j*") << fabs(image) << endl; 
    }
}; 
point::operator complex(){
    complex r(x, y); 
    cout << "Chuyen doi " << x << " " << y << " thanh " << r.real<< " + " << r.image << endl; 
    return r; 
}
int main(){
    point a(2, 5); complex c; 
    c = (complex) a; c.display();
    point b(9, 12);
    c = b; c.display(); 
    return 0; 
}