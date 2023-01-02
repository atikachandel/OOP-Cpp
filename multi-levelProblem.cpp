#include<iostream>
using namespace std;
//MULTI-LEVEL INHERITANCE
class student{
    char name[50];
    int roll;
    student(){
        void getdata(){
            student::getdata();
            cout<<"Enter name of the student: "<<endl;
            cin>>name;
            cout<"Enter roll number of the student: "<<endl;
            cin>>roll;
        }
        void display(){
            student::display();
            cout<<"Enter name of the student: "<<endl;
            cin>>name;
            cout<<"Enter roll number of the student: "<<endl;
            cin>>roll; 
        }
    }
};
class sports:public student{
    float m1,float m2,float m3;
public:
	sports(int m){
		void getdata(float m1,float m2,float m3){
            sports::getdata(m)
		    cout<<"Enter marks 1: ";
		    cin>>m1;
		    cout<<"Enter marks 2: ";
		    cin>>m2;
		    cout<<"Enter marks 3: ";
		    cin>>m3;
        }	
        void display(float const m){
            sports::display(m)
            cout<<m1<<m2<m3;
        }
	}
};
class test:public sports{
	test(float p, float m1,float m2,float m3){
        double getdata(float m){
	            p=m1+m2+m3;
	            cout<<"Total marks: "<<p<<endl;
        }
        test::display(p){
            cout<<"Total marks: "<<p<<endl;
        }
    }
};
class result:public test{
public:
	result(){
    }
    double getdata(float tm)
    {
        result::getdata()
        float m1, m2, m3;
	    int p;
	    p=m1+m2+m3;
	    tm=p/3;
        
    }
    void display(float tm){
	    cout<<"Percentage= "<<tm<<endl;
    }
};
int main(){
	result r;
	return 0;
}