#include<iostream>
using namespace std;
//MULTI-LEVEL INHERITANCE
class base{
public:
	base(){
		cout<<"Constructor of base class called"<<endl;
	}
	~base()
	{
		cout<<"destructor of base class called"<<endl;
	}
};
class derived1:public base{
public:
	derived1(){
		cout<<"Constructor of derived class 1 called"<<endl;
	}
	~derived1()
	{
		cout<<"destructor of derived class 1 called"<<endl;
	}
};
class derived2:public derived1{
public:
	derived2(){
		cout<<"Constructor of derived class 2 called"<<endl;
	}
	~derived2()
	{
		cout<<"destructor of dervied class 2 called"<<endl;
	}
};
int main(){
	derived2 d;
	return 0;
}