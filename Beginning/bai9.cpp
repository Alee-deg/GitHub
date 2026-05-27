#include<iostream>
using namespace std; 
class matrix; 
class vector{
    static int n; // so chieu cua vec to
    float *v; 
    public:
    vector(); 
    vector(float *); 
    vector(vector &); //Ham thiet lap sao chep
    ~vector(); 
    void display(); 
    static int &Size(){
        return n; 
    }
    friend vector prod(matrix &, vector &); 
    friend class matrix; 
}; 
int vector::n = 0; 
// Ham thanh phan cua lop vector
vector::vector(){
    int i;
    v = new float [n]; 
    for(i = 0; i < n;i ++){
        cout <<"Toa do thu "<<i + 1<<" : "; 
        cin >> v[i]; 
    }
}
vector::vector(float *a){
    for(int i = 0;i < n;i ++){
        v[i] = a[i]; 
    }
}
vector::vector(vector &b){
    int i; 
    for(i = 0;i < n;i ++){
        v[i] = b.v[i]; 
    }
}
vector::~vector(){
    delete v; 
}
void vector::display(){
    for(int i = 0; i < n; i++){
        cout << v[i] << " "; 
        cout << "\n"; 
    }
}
class matrix{
    static int n; //so chieu cua vector
    vector *m; // vung chua cac toa do
    public:
    matrix(); 
    ~matrix(); 
    void display();
    static int &Size(){
        return n;
    }
    friend vector prod(matrix &, vector &); 
}; 
int matrix::n = 0; 
// Ham thanh phan cua lop matrix
matrix::matrix(){
    int i; 
    m = new vector [n]; 
}
matrix::~matrix(){
    delete m; 
}
void matrix::display(){
    for(int i = 0; i < n; i++){ 
        m[i].display(); 
    }
}
//Ham prod
vector prod(matrix &m, vector &v){
    float *a = new float[vector::Size()]; 
    int i, j; 
    for(i = 0; i < matrix::Size();i ++){
        a[i] = 0; 
        for(j = 0; j < vector::Size(); j ++){
            a[i] += m.m[i].v[j]*v.v[j]; 
        }
    }
    return vector(a); 
}
int main(){
    int size; 
    cout <<"Kich thuoc cua vector "; cin >> size; 
    vector::Size() = size; 
    matrix::Size() = size; 
    cout <<"Tao mot vector \n"; 
    vector v; 
    cout << "v = \n"; 
    v.display(); 
    cout<<"Tao mot ma tran \n"; 
    matrix m; 
    cout <<"m = \n"; 
    m.display(); 
    cout <<"Tich m*v \n"; 
    vector u = prod(m, v); 
    u.display();
    return 0; 
}
