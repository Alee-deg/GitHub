#include<iostream>
#include<stddef.h>
using namespace std; 
class point{
    static int npt; 
    static int npt_dyn; 
    int x, y; 
    public:
    point(int ox = 0, int oy = 0){
        x = ox; y = oy; 
        npt ++; 
        cout <<"++Tong so diem : " << npt << endl; 
    }
    ~point(){
        npt --; 
        cout << "--Tong so diem: " << npt << endl; 
    }
    void * operator new (size_t sz){
        npt_dyn ++; 
        cout << "   Co " << npt_dyn << " diem dong " << endl; 
        return ::new char[sz]; 
    }
    void operator delete(void *dp){
        npt_dyn --; 
        cout << "   Co "<<npt_dyn<<" diem dong " << endl; 
        ::delete(dp); 
    }
}; 
int point::npt = 0; 
int point::npt_dyn = 0; 
int main(){
    point *p1, *p2; 
    point a(3, 5); 
    p1 = new point(1, 3); 
    point b; 
    p2 = new point(2, 0); 
    delete p1; 
    point c(2); 
    delete p2; 
    return 0; 
}