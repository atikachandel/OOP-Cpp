#include<iostream>
using namespace std;
//MULTIPLE INHERITANCE
class base1{
public:
	base1(){
		cout<<"Constructor of base 1 class called"<<endl;
	}
	~base1()
	{
		cout<<"destructor of base 1 class called"<<endl;
	}
};
class base2{
public:
	base2(){
		cout<<"Constructor of base 2 class called"<<endl;
	}
	~base2()
	{
		cout<<"destructor of base 2 class called"<<endl;
	}
};
class derived:public base1,public base2{
public:
	derived(){
		cout<<"Constructor of derived class called"<<endl;
	}
	~derived()
	{
		cout<<"destructor of derived class called"<<endl;
	}
};
int main(){
	derived d;
	return 0;
}
