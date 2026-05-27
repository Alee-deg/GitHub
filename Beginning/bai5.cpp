#include<iostream>
using namespace std; 
class counter{
    static int count; 
    public:
        counter(); 
        ~counter(); 
}; 
int counter::count = 0; // Khoi tao gia tri cho thanh phan static
// ham thiet lap
counter::counter(){
    cout <<"++Tao: bay gio co "<<++count<<" doi tuong\n"; 
}
counter:: ~counter(){
    cout <<"--Xoa: bay gio con "<<--count<<" doi tuong\n"; 
}
int main(){
    void fct(); 
    counter a; 
    fct(); 
    counter b; 
}
void fct(){
    counter u, v; 
}