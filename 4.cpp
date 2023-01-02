#include<iostream>
using namespace std;
class student
{
    int roll;
    char name[50];
    float m,c,p,e,h;
    float total;
    public:
    inline void input()
    {
        cout<<"Enter roll no.: ";
        cin>>roll;
        cout<<"Name: ";
        cin>>name;
        cout<<"Marks in Math: ";
        cin>>m;
        cout<<"Marks in Chemistry: ";
        cin>>c;
        cout<<"Marks in Physics: ";
        cin>>p;
        cout<<"Marks in English: ";
        cin>>e;
        cout<<"Marks in Hindi: ";
        cin>>h;
    }
    void calculateTotal()
    {
        total=m+p+c+e+h;
        cout<<"Total marks: "<<total<<endl;
    }
    void grade()
    {
        if (total)>90 && (total)<100
            cout<<"O";
        else if (total)>80 && (total)<90
            cout<<"E";
        else if (total)>70 && (total)<80
            cout<<"A";
        else if (total)>60 && (total)<70
            cout<<"B";
        else if (total)>50 && (total)<60
            cout<<"C"
        else (total)<50 
            cout<<"Fail";
    }
    void output()
    {
        cout<<"Roll: "<<roll<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Total Marks: "<<total<<endl;
    }
};
int main()
{
    student obj;
    obj.input();
    obj.calculateTotal();
    obj.grade();
    obj.output();
}