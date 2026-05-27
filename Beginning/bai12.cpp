#include<iostream>
using namespace std; 
class vector{
    int n; 
    float *v; 
    public:
    vector(); 
    vector(int size); 
    vector(int size, float *a); 
    vector(vector &); 
    vector & operator = (vector & b); 
    ~vector(); 
    void display(); 
}; 
vector::vector(){
    int i; 
    cout << "Tao doi tuong tai " << this << endl; 
    cout << "So chieu :"; cin >> n; 
    v = new float [n]; 
    cout << "Xin cap phat vung bo nho " <<n<< " so thuc tai"<<v<<endl; 
    for(i = 0; i < n; i++){
        cout <<"Toa do thu "<<i + 1<< " : "; 
        cin >> v[i]; 
    }
}
vector::vector(int size){
    int i; 
    cout << "Su dung ham thiet lap 1 tham so\n"; 
    cout << "Tao doi tuong tai "<< this << endl; 
    n = size; 
    cout <<"So chieu :"<< size << endl; 
    v = new float [n]; 
    cout << "Xin cap phat vung bo nho "<<n<<" so thuc tai"<< v << endl; 
    for(i = 0; i < n;i ++){
        cout << "Toa do thu " << i + 1 << " : "; 
        cin >> v[i]; 
    }
}
vector::vector(int size, float *a){
    int i; 
    cout << "Su dung ham thiet lap 2 tham so\n"; 
    cout << "Tao doi tuong tai " << this << endl; 
    n = size; 
    cout << "So chieu :" << n << endl; 
    v = new float [n]; 
    cout << "Xin cap phat vung bo nho " <<n<< " so thuc tai"<<v<<endl; 
    for(i = 0;i < n; i++){
        v[i] = a[i]; 
    }
}
vector::vector(vector &b){
    int i; 
    cout << "Su dung ham thiet lap sao chep\n"; 
    cout << "Tao doi tuong tai " << this << endl; 
    v = new float [n = b.n]; 
    cout << "Xin cap phat vung bo nho " <<n<< " so thuc tai "<<v<<endl; 
    for(i = 0; i < n; i ++){
        v[i] = b.v[i]; 
    }
}
vector::~vector(){
    cout <<"Giai phong "<<v<<"cua doi tuong tai"<<this<<endl; 
    delete v; 
}
vector & vector::operator=(vector & b){
    cout << "Goi operator = () cho " << this << " va" << &b << endl; 
    if(this != &b){
        cout <<"xoa vung nho dong "<<v<<" trong "<<this<<endl; 
        delete v; 
        v = new float [n = b.n]; 
        cout << "cap phat vung nho dong moi"<<v<<" trong"<<this<<endl; 
        for(int i = 0;i < n;i ++) v[i] = b.v[i]; 
    }
    else cout << "Hai doi tuong la mot\n"; 
    return *this; 
}
void vector::display(){
    int i; 
    cout <<"Doi tuong tai :"<<this<<endl; 
    cout <<"So chieu :"<<n<<endl; 
    for(i = 0; i < n; i++) cout << v[i] << " "; 
    cout << "\n"; 
}
int main(){
    vector s1; 
    s1.display(); 
    vector s2 = s1; 
    s2.display(); 
    vector s3(3); 
    s3 = s1; 
    s1 = s1; 
    return 0; 
}