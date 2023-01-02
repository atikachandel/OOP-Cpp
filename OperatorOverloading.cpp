//Using Member Function
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
    complex operator +(complex c){ //return type operator sign(class name variable)
        complex temp; //class name variable;
        temp.real=real+c.real;
        temp.img=img+c.img;
        return temp;
    }
    void display(){
        cout<<real<<" + "<<img<<"i";
    }
};
int main(){
    complex c1(18,1),c2(2,3),c3(5,2),c4;
    c4=c1+c2+c3;
    c4.display();
    return 0;
};




