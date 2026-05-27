#include<iostream>
using namespace std; 
class point{
    int x, y; 
    public:
        point(int abs = 0, int ord = 0){
            x = abs; y = ord; 
        }
        friend int coincide(point, point); 
}; 
int coincide(point p, point q){
    if(p.x == q.x && p.y == q.y) return 1; 
    else return 0; 
}
int main(){
    point a(1, 0), b(1), c;  
    if(coincide(a, b)) cout <<"a trung voi b\n"; 
    else cout << "a va b khac nhau\n"; 
    if(coincide(a, c)) cout <<"a trung voi c\n"; 
    else cout <<"a va c khac nhau\n"; 
    return 0; 
}