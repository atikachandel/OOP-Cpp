#include<iostream>
using namespace std;
class student{
protected:
    int roll;
    int m1,m2;
public:
    void getdata(){
        cout<<"Enter roll number: ";
        cin>>roll;
        cout<<"Enter marks of 2 subjects: "<<endl;
        cin>>m1>>m2;
    }
};
class sports{
protected:
    int m;
public:
    void getdata(){
        cout<<"Enter sports marks: ";
        cin>>m;
    }
};
class result:public student, public sports{
    int total;
    float avg;
public:
    void display(){
        total=m1+m2+m;
        avg=total/3.0;
        cout<<"roll number "<<roll<<" has secured ";
        cout<<avg<<" average marks";
    }
};
int main()
{
    result r;
    r.student::getdata();
    r.sports::getdata();
    r.display();
}