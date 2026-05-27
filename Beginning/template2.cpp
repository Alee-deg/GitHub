#include<iostream>
using namespace std; 
template<class T> T myMin(T a, T b){
    if(a < b) return a; 
    else return b; 
}
int main(){
    char * adr1 = "DHDK"; 
    char * adr2 = "CDSD"; 
    cout << "min (adr1; adr2) = " << min(adr1, adr2); 
    return 0; 
}