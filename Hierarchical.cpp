#include<iostream>
#include<string.h>
using namespace std;
class person{
protected:
    string name, gender;
    int age;
public:
    void getdata(){
        cout<<"Name: ";
        cin>>ws;
        getline(cin,name);
        cout<<"Gender: ";
        cin>>gender;
        cout<<"age: ";
        cin>>age;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Gender: "<<gender<<endl;
        cout<<"Age: "<<age<<endl;
    }
};
class employee:public person{
protected:
    char company[100];
    float salary;
public:
    void getdata(){
        person::getdata();
        cout<<"Company Name: ";
        cin>>company;
        cout<<"Salary: "<<endl;
        cin>>salary;
    }
    void display(){
        person::display();
        cout<<"Company Name: "<<company<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};
class student:public person{
protected:
        string inst, l;
public:
    void getdata(){
        person::getdata();
        cout<<"Institute name:";
        cin>>inst;
        cout<<"level: ";
        cin>>l;
    }
    void display(){
        person::display();
        cout<<"Institute name: "<<inst<<endl;
        cout<<"Level: "<<l;
    }
};
int main(){
    employee e;
    e.getdata();
    e.display();
    student s;
    
    s.getdata();
    
    s.display();
    return 0;
}