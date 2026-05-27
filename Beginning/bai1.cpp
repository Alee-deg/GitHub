#include<iostream>
#include<math.h>
using namespace std; 
class tamgiac{
    private:
     float a, b, c; 
    public:
     void nhap(); 
     void in(); 
    private:
     int loaitg(); 
     float dientich(); 
}; 
void tamgiac::nhap(){
    do {
        cout<<"Canh a: "; cin >> a; 
        cout<<"Canh b: "; cin >> b; 
        cout<<"Canh c: "; cin >> c;  
    } while(a + b <= c || b + c <= a || c + a <= b); 
}
void tamgiac::in(){
    cout<<"Do dai ba canh: "<<a<<" "<<b<<" "<<c<<"\n"; 
    cout<<"Dien tich tam giac : "<<dientich()<<"\n"; 
    switch(loaitg()){
        case 1: cout <<"Tam giac deu\n"; break; 
        case 2: cout <<"Tam giac vuong can\n"; break; 
        case 3: cout <<"Tam giac vuong\n"; break; 
        case 4: cout <<"Tam giac thuong\n"; break; 
    }
}
float tamgiac::dientich(){
    return (0.25*sqrt((a + b + c)*(a + b - c)*(a-b+c)*(-a + b + c))); 
}
int tamgiac::loaitg(){
    if(a == b || b == c || c == a)
        if(a == b && b == c)
            return 1; 
        else if(a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b)
            return 2; 
        else return 3; 
    else if(a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b)
        return 4; 
        else return 5; 
}
int main(){
    tamgiac tg; 
    tg.nhap(); 
    tg.in(); 
    return 0; 
}