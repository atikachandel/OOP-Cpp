#include<iostream>
using namespace std;
class mcm{ 
    int m,cm;
public:
    mcm(int a=0,int b=0){
        m=a;
        cm=b;
    }
    void display(){
        cout<<m<<" meters and "<<cm<< "centimeters"<<endl;
    }

    mcm(finch obj){
        int t=obj.getfeet()*12+obj.getinch();
        float t1=t*2.54;
        m=t1/100;
        cm=t1-t*100;
    }
    int &getm(){
        return m;
    }
    int &getcm(){
        return cm;
    }
};
class finch{
    int f,i;
public:
    finch(int a,int b){
        f=a;
        i=b;
    }
    void display(){
        cout<<f<<" feet and "<<i<< "inches."<<endl;
    }
    int getinch(){
        return i;
    }
    int getfeet(){
        return f;
    }
};
/*
operator mcm{
    mcm temp;
    int t=f*12 + i;
    float t1= t*2.54;
    temp.getm()=t1/100;
    temp.getcm()=t1-t*100;
    return temp;
};
*/
int main(){
    finch obj1(7,8);
    mcm obj2;
    obj2=obj1;
    obj2.display();
    obj1.display();
}