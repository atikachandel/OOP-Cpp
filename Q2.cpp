#include <iostream>
using namespace std;
class Employee
{
    char id[30];
    char name[50];
    int age;
    int basic;
    float gross=0.0;
    public:
    void input()
    {
        cout<<"Enter id of employee"<<endl;
        cin>>id;
        cout<<"Enter name of employee"<<endl;
        cin>>name;
        cout<<"Enter age of employee"<<endl;
        cin>>age;
        cout<<"Enter basic salary"<<endl;
        cin>>basic;
    }
    void calculate()
    {
        float da,hra;
        da=0.8*basic;
        hra=0.1* basic;
        gross=basic+da+hra;
    }
    void display()
    {
        cout<<"Id of employee : "<<id<<endl;
        cout<<"Name of employee : "<<name<<endl;
        cout<<"Age of employee : "<<age<<endl;
        cout<<"Gross salary : "<<gross<<endl;
    }
};
int main()
{
    int n;
    cout<<"Enter the number of employees"<<endl;
    cin>>n;
    Employee e[n];
    for (int i=0;i<n;i++)
    {
        e[i].input();
        e[i].calculate();
    }
    for (int i=0;i<n;i++)
    {
        e[i].display();
    }
    return 0;
}