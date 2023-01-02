#include<iostream>
using namespace std;
class stud
{
    string name;
    int roll;
    int marks[5];
    float avg;
    int total;
    public:
    void setdata(string n, int r, int m[5])
    {
        name=n;
        roll=r;
        total=0;
        for(int i=0; i<5; i++)
        {
            marks[i]=m[i];
            total+=m[i];
        }
        avg=total/5.0;
    }
    void average(int n,stud ob[])
    {
        float sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=ob[i].avg;
        }
        avg=sum/n;
    }
    void below(int n,stud ob[])
    {
        int c=0;
        for(int i=0; i<c; i++)
        {
            if (ob[i].avg<avg)
            {
                c++;
            }
            cout<<"No. of students below average marks: "<<c<<endl;
        }
    }
    void above(int n,stud ob[])
    {
        int c=0;
        for(int i=0; i<c; i++)
        {
            if (ob[i].avg>avg)
            {
                c++;
            }
            cout<<"No. of students above average marks: "<<c<<endl;
        }
    }
    void sort(int n,stud ob[])
    {
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if (ob[i].total>ob[j].total)
                {
                    stud a=ob[i];
                    ob[i]=ob[j];
                    ob[j]=a;
                }
            }
        }
    }
    void display_name()
    {
        cout<<"Name of student who secured the highest marks: "<<name<<endl;
    }
    void display_roll()
    {
        cout<<"Roll no. of student who secured the highest marks from bottom: "<<roll<<endl;
    }
};
int main()
{
    string n;
    int r,m[5],s;
    cout<<"Enter the no. of students: ";
    cin>>s;
    stud ob[5],a;
    for (int i=0;i<s;i++)
    {
        cout<<"Enter name: ";
        cin>>n;
        cout<<"Enter roll number: ";
        cin>>r;
        cout<<"Enter marks in 5 subjects: \n";
        for(int i=0;i<5;i++)
        {
            cin>>m[i];
        }
        ob[i].setdata(n,r,m);
    }
    a.average(s,ob);
    a.above(s,ob);
    a.below(s,ob);
    a.sort(s,ob);
    ob[s-1].display_name();
    ob[0].display_roll();
}