#include<iostream>
using namespace std; 
class O{
    float o; 
    public:
    O(float oo){
        cout << "O::O(float)\n"; 
        o = oo; 
    }
}; 
class A :public O{
    float x, y; 
    public:
    A(float oo, float ox, float oy):O(oo){
        cout << "A::A(float, float, float)\n"; 
        x = ox; y = oy; 
    }
    float getx(){
        return x; 
    }
    float gety(){
        return y; 
    }
}; 
class B :public virtual A{
    public:
    B(float oo, float ox, float oy) : A(oo, ox, oy){
        cout << "B::B(float, float, float)\n"; 
    }
}; 
class C :public virtual A{
    public:
    C(float oo, float ox, float oy):A(oo, ox, oy){
        cout << "C::C(float, float, float)\n"; 
    }
}; 
class D :public B, public C{
    public:
    D(float oo, float ox, float oy): A(oo, ox, oy), B(oo, 10, 4), C(oo, 1, 1){
        cout << "D::D(float, float, float);\n"; 
    }
}; 
int main(){
    D d(2, 3, 5); 
    cout << "D d(2, 3, 5)\n"; 
    cout << "d.C::getx() = "; cout<<d.C::getx()<<endl; 
    cout << "d.B::getx() = "; cout<<d.B::getx()<<endl;
    cout << "d.C::gety() = "; cout<<d.C::gety()<<endl;
    cout << "d.B::gety() = "; cout<<d.B::gety()<<endl;
    D d1(10, 20, 30); 
    cout << "d.C::getx() = "; cout<<d1.C::getx()<<endl; 
    cout << "d1.B::getx() = "; cout<<d1.B::getx()<<endl; 
    cout << "d1.C::getx() = "; cout<<d1.C::gety()<<endl; 
    cout << "d1.B::getx() = "; cout<<d1.B::gety()<<endl; 
    return 0;  
}