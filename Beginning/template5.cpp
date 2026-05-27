#include<iostream>
using namespace std; 
template <class T> void mySwap(T &a, T &b){
    T temp; 
    temp = a; 
    a = b; 
    b = temp; 
} 
int main(){
    int i = 10, j = 20; 
    float x = 10.1, y = 23.1; 
    cout << "I J ban dau: " <<i<<" "<<j<<endl; 
    cout << "X Y ban dau: " <<x<<" "<<y<<endl; 
    mySwap(i, j); 
    mySwap(x, y); 
    cout << "I J sau khi doi cho: "<<i<<" "<<j<<endl; 
    cout << "X Y sau khi doi cho: "<<x<<" "<<y<<endl; 
    return 0; 
}