#include<iostream>
using namespace std; 
class A{
    float x, y; 
    public:
    void set(float ox, float oy){
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
}; 
class C : public virtual A{
}; 
class D : public B, public C{
}; 
int main(){
    D d; 
    cout << "d.B::set(2, 3); \n";
    d.B::set(2, 3); 
    cout << "d.C::getx() = "; cout << d.C::getx()<<endl; 
    cout << "d.B::getx() = "; cout << d.B::getx()<<endl;
    cout << "d.C::gety() = "; cout << d.C::gety()<<endl;
    cout << "d.B::gety() = "; cout << d.B::gety()<<endl; 

    cout << "d.C::set(10, 20); \n"; 
    d.C::set(10, 20); 
    cout << "d.C::getx() = "; cout<<d.C::getx()<<endl; 
    cout << "d.B::getx() = "; cout<<d.B::getx()<<endl; 
    cout << "d.C::gety() = "; cout<<d.C::gety()<<endl; 
    cout << "d.C::gety() = "; cout<<d.B::gety()<<endl; 
    return 0; 
}