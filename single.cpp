#include<iostream>
using namespace std;
//SINGLE INHERITANCE using constructor anmd destructor
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
class derived:public base{
public:
	derived(){
		cout<<"Constructor of derived class called"<<endl;
	}
	~derived()
	{
		cout<<"destructor of dervied class called"<<endl;
	}
};
int main(){
	derived d;
	return 0;
};