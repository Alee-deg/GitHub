#include<iostream>
using namespace std; 
template <class T> T m(T a, T b){
    if(a < b) return a; 
    else return b; 
} 
template <class T> T m(T a, T b, T c){
    return m(m(a, b), c); 
}
template <class T> T m(T *t, int n){
    T res = t[0]; 
    for(int i = 1; i < n; i ++){
        if(res > t[i])
            res = t[i]; 
    }
    return res; 
}
int main(){
    int n = 12, p = 15, q = 2;
    float x = 3.5, y = 4.25, z = 0.25; 
    int t[6] = {2, 3, 4, -1, 21}; 
    char c[4] = {'w', 'q', 'a', 'Q'}; 
    cout << m(n,p) << "\n"; 
    cout << m(n, p, q) << "\n"; 
    cout << m(x, y) << "\n"; 
    cout << m(x, y, z) << "\n"; 
    cout << m(t, 6) << "\n"; 
    cout << m(c, 4) << "\n"; 
    return 0; 
}