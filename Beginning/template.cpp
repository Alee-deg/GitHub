#include<iostream>
using namespace std; 
template <class T> T myMin(T a, T b){
    if(a < b) return a; 
    else return b; 
}
int main(){
    int n = 4, p = 12; 
    float x = 2.5, y = 3.25; 
    cout << "min(n, p) = " <<myMin(n,p)<<"\n"; 
    cout << "min(x,y) = " <<myMin(x,y)<<"\n"; 
    return 0; 
}