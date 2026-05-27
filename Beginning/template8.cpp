#include<iostream>
using namespace std; 
template <class T> class point{
    T a;
    T b; 
    public:
    point(T ord,T abs){
        a = ord; b = abs; 
    }
    void display(){
        cout << a << " " << b << "\n"; 
    }
}; 
int main(){
    point<int> pc(3, 5); pc.display(); 
    point<char> sd('s', 'a'); sd.display(); 
    point<double> as(2.3, 1.2); as.display(); 
    return 0; 
}