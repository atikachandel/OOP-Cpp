#include<iostream>
using namespace std;
class Employee
{
    char name[100];
    int empNo;
    char dept[50];
    int salary;
    public:
    inline void getdata()
    {
        cout<<"Enter Name:";
        cin>>name;
        cout<<"EmpNo:";
        cin>>empNo;
        cout<<"Department:";
        cin>>dept;
        cout<<"Salary:";
        cin>>salary;
    }
    void showdata()
    {
        cout<<"Name of the employee: "<<name<<endl;
        cout<<"Employee No: "<<empNo<<endl;
        cout<<"Department: "<<dept<<endl;
        cout<<"Salary: "<<salary;
    }
};
int main()
{
    Employee obj;
    obj.getdata();
    obj.showdata();
    return 0;
}