#include<iostream>
using namespace std; 
class counter{
    static int count; 
    public:
        counter(); 
        ~counter(); 
        static void counter_display(); 
}; 
int counter::count = 0; //Khoi tao gia tri cho ham thanh phan static
void counter::counter_display(){
    cout << "Hien dang co "<< count <<" Doi tuong\n"; 
}
counter::counter(){
    cout <<"++Tao : bay gio co "<<++count<<" doi tuong\n"; 
}
counter:: ~counter(){
    cout <<"--Xoa : bay gio con "<<--count<<" doi tuong\n"; 
}
int main(){
    void fct(); 
    counter a; 
    fct(); 
    counter::counter_display(); 
    counter b; 
    return 0; 
}
void fct(){
    counter u; 
    counter::counter_display(); //goi qua ten lop
    counter v; 
    v.counter_display(); //goi qua doi tuong
}