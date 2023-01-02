//1
#include<iostream>
using namespace std;
class c2;
class c1
{
	int value1;
	public:
	void input(int x)
	{
		value1=x;
	}
	void display(void)
	{
		cout<<"Number 1: "<<value1<<"\n";
	}
	friend void swap(c1 &,c2 &);
};
class c2
{
	int value2;
	public:
	void input(int x)
	{
		value2=x;
	}
	void display(void)
	{
		cout<<"Number 2: "<<value2<<"\n";
	}
	friend void swap(c1 &,c2 &);
};
void swap(c1 &n1,c2 &n2)	
{
	int temp;
	temp=n1.value1;
	n1.value1=n2.value2;
	n2.value2=temp;
}
int main()
{
	c1 c;
	c2 d;
	c.input(10);
	d.input(20);
	cout<<"Before swapping"<<"\n";
	

c.display();
	d.display();
	cout<<"After swapping"<<"\n";
	swap(c,d);
	c.display();
	d.display();
	return 0;
}