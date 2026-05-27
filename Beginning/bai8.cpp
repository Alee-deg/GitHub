#include<iostream>
using namespace std; 
class matrix; 
class vect{
    double v[3]; 
    public:
    vect(double v1 = 0, double v2 = 0, double v3 = 0){
        v[0] = v1; v[1] = v2; v[2] = v3; 
    }
    friend vect prod(matrix, vect); 
    void display(){
        int i; 
        for(int i = 0; i < 3; i ++){
            cout<<v[i]<<" "; 
            cout << endl; 
        }
    }
}; 
class matrix{
    double mat[3][3]; 
    public:
    matrix(double t[3][3]){
        int i, j; 
        for(i = 0; i < 3; i ++){
            for(j = 0; j < 3; j++){
                mat[i][j] = t[i][j]; 
            }
        }
    }
    friend vect prod (matrix, vect);
}; 
vect prod(matrix m, vect x){
    int i, j; 
    double sum; 
    vect res; 
    for(i = 0; i < 3; i ++){
        for(j = 0, sum = 0; j < 3; j ++){
            sum += m.mat[i][j]*x.v[j]; 
            res.v[i] = sum; 
        }
    }
    return res; 
}
int main(){ 
    vect w(1, 2, 3); 
    vect res;
    double tb[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    matrix a = tb; 
    res = prod(a, w); res.display(); 
    return 0; 
}