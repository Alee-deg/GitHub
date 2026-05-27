#include<iostream>
using namespace std; 
template <class T, class U>  T fct(T x, U y, T z){
    return x + y + z; 
} 
int main(){
    int n = 1, p = 2, q = 3; 
    float x = 2.5, y = 5.0; 
    cout << fct(n, x, p) << "\n"; 
    cout << fct(x, n, y) << "\n"; 
    cout << fct(n, p, q) << "\n"; 
    return 0;  
}