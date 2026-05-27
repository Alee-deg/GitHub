#include<iostream>
using namespace std; 
class vector{
    private:
     int n; 
     float *v; 
    public:
        vector(); //Ham thiet lap khong tham so
        vector(int size); //Ham thiet lap mot tham so
        vector(int size, float *a); 
        ~vector(); //Ham huy bo, luon luon khong co tham so
        void display(); 
};
vector::vector(){
    int i; 
    cout<<"Tao doi tuong tai " <<this<<endl;
    cout<<"So chieu: "; cin>>n; 
    v = new float[n]; 
    cout<<"Xin cap phat vung bo nho  "<<n<<" So thuc tai"<<v<<endl; 
    for(i = 0; i < n; i ++){
        cout<<"Toa do thu "<<i + 1<<" : "; 
        cin>>v[i]; 
    }
}
vector::vector(int size){
    int i; 
    cout<<"Su dung ham thiet lap 1 tham so\n"; 
    cout<<"Tao doi tuong tai "<<this<<endl; 
    n = size; 
    cout <<"So chieu :"<<size<<endl; 
    v = new float [n]; 
    cout <<"Xin cap phat vung bo nho "<<n<<"so thuc tai"<<v<<endl; 
    for(i = 0; i < n; i++){
        cout<<"Toa do thu "<<i + 1<<" : "; 
        cin >> v[i]; 
    }
}
vector::vector(int size, float *a){
    int i; 
    cout<<"Su dung ham thiet lap 2 tham so\n"; 
    cout<<"Tao doi tuong tai "<<this<<endl; 
    n = size; 
    cout <<"So chieu :"<<n<<endl; 
    v = new float [n]; 
    cout <<"Xin cap phat vung bo nho "<<n<<" so thuc tai"<<v<<endl; 
    for(i = 0; i < n; i ++){
        v[i] = a[i]; 
    }
}
vector::~vector(){
    cout <<"Giai phong "<<v<<"cua doi tuong tai"<<this<<endl; 
    delete v; 
}
//Hien thi ket qua
void vector::display(){
    int i; 
    cout<<"Doi tuong tai: "<<this<<endl; 
    cout<<"So chieu :"<<n<<endl; 
    for(i = 0; i < n; i ++){
        cout<<v[i]<<""; 
        cout<<"\n"; 
    }
}
int main(){
    vector s1; 
    vector s4(s1); 
    s4.display(); 
    s1.display(); 
    vector s2(4); 
    s2.display(); 
    float a[3] = {1, 2, 3}; 
    vector s3(3, a); 
    s3.display(); 
    return 0; 
}