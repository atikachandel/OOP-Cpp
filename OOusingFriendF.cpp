//Using Friend Function
#include<iostream>
using namespace std;
class complex{
    int real,img;
public:
    complex(){
        real=0;
        img=0;
    }
    complex(float r, float i){
        real=r;
        img=i;
    }
friend complex operator+(int c, complex c2);
void display(){
    cout<<real<<" + "<<img<<"i";
}
};
complex operator +(int c, complex c2){ //return type operator sign(class name variable)
    complex temp; //class name variable;
    temp.real = c + c2.real;
    temp.img = c + c2.img;
    return temp;
}
int main(){
    complex c1(5,1),c2(7,2),c3,c4;
    //c3=operator + (c1,c2);
    c4=10+(c1,c2);
    c4.display();
    return 0;
};




