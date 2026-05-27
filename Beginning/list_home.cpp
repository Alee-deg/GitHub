#include<iostream>
#include<stddef.h>
using namespace std; 
struct element{
    element *next; 
    void *content; 
}; 
class list{
    element *head; 
    element *current; 
    public:
    list(){
        head = NULL; current = head; 
    }
    ~list(); 
    void add(void *); 
    void first(){
        current = head;
    }
    void *nextlement(){
        void *adel = NULL; 
        if(current != NULL){
            adel = current -> content; 
            current = current -> next; 
        }
        return adel; 
    }
    int last(){return (current == NULL);}
}; 
list::~list(){
    element *suiv; 
    current = head; 
    while(current != NULL){
        suiv = current -> next; 
        delete current; 
        current = suiv; 
    }
}
void list::add(void *chose){
    element *adel = new element; 
    adel -> next = head; 
    adel -> content = chose; 
    head = adel; 
}
class point{
    int x, y; 
    public:
    point(int abs = 0, int ord = 0){
        x = abs; 
        y = ord; 
    }
    void display(){
        cout << " Toa do : "<<x<<" "<<y<<"\n"; 
    }
}; 
class list_points :public list, public point{
    public:
    list_points(){}
    void display(); 
}; 
void list_points::display(){
    first(); 
    while(!last()){
        point *ptr = (point *)nextlement(); 
        ptr -> display(); 
    }
}
int main(){
    list_points l; 
    point a(2, 3), b(5, 9), c(0, 8); 
    l.add(&a); l.display(); cout<<"-----------\n"; 
    l.add(&b); l.display(); cout<<"-----------\n"; 
    l.add(&c); l.display(); cout<<"-----------\n"; 
    return 0; 
}
