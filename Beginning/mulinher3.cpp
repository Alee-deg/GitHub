#include<iostream>
using namespace std; 
class A{
    float x, y; 
    public:
    A(){x = 0; y = 0;}
    A(float ox, float oy){
        cout << "A::A(float, float)\n"; 
        x = ox; y = oy;
    }
    float getx(){
        return x; 
    }
    float gety(){
        return y; 
    }
}; 
class B : public virtual A{
    public:
    B(float ox, float oy):A(ox, oy){
        cout << "B::B(float, float)\n"; 
    }
}; 
class C : public virtual A{
    public:
    C(float ox, float oy):A(ox, oy){
        cout << "C::C(float, float)\n"; 
    }
}; 
class D : public B, public C{
    public:
    D(float ox, float oy):A(ox, oy), B(10, 4), C(1, 1){
        cout << "D::D(float, float);\n"; 
    }
}; 
int main(){
    D d(2, 3); 
    cout << "D d(2, 3)\n"; 
    cout << "d.C::getx() = "; cout << d.C::getx()<<endl; 
    cout << "d.B::getx() = "; cout << d.B::getx()<<endl; 
    cout << "d.C::getx() = "; cout << d.C::gety()<<endl; 
    cout << "d.B::getx() = "; cout << d.B::gety()<<endl;
    
    cout << "D d1(10, 20);\n"; 
    D d1(10, 20); 
    cout << "d.C::getx() = "; cout << d1.C::getx()<<endl; 
    cout << "d.B::getx() = "; cout << d1.B::gety()<<endl; 
    cout << "d.C::getx() = "; cout << d1.C::getx()<<endl;
    cout << "d.B::getx() = "; cout << d1.B::gety()<<endl;
    return 0; 
}
