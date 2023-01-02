#include<iostream>
using namespace std;
class FRACTION 
{
    int num,deno;
    public:
    void getdata(int a,int b)
    {
        num=a;
        deno=b;
    }
    void show()
    {
        cout<<num<<"/"<<deno<<endl;
    }
    void add(FRACTION p,FRACTION q)
    {
        deno= p.deno * q.deno;
        num=((deno/p.deno)*p.num)+((deno/q.deno)*q.num);
        simplify();
    }
    void sub(FRACTION &m,FRACTION &n)
    {
        deno= m.deno * n.deno;
        num=((deno/m.deno)*m.num)-((deno/n.deno)*n.num);
        if (num==0)
        {
            cout<<"\nSub = 0"<<endl;
        }
        else if(deno==0)
        {
            cout<<"\nSub : undefined"<<endl;
        }
        else
        {
            simplify();
        }
    }
    void mul(FRACTION *A, FRACTION *B)
    {
        deno=A->deno * B->deno;
        num=A->num * B->num;
        simplify();
    }
    int gcd(int num,int deno)
    {
        if (num==0)
        {
            return deno;
        }
        return gcd(deno%num , num);
    }
    int lcm(int num, int deno)
    {
        return (num/gcd(num,deno))*deno;
    }
    void simplify()
    {
        int lcm1 = lcm(num,deno);
        int m =  deno;
        deno = lcm1/num;
        num = lcm1/m;
    }
    void display()
    {
        cout<<"\nAdd: "<<num<<"/"<<deno<<endl;
    }
    void display1()
    {
        if (num!=0)
        cout<<"\nSub: "<<num<<"/"<<deno<<endl;
    }
    void display2()
    {
        if (num!=0)
        {
            cout<<"\nMul: "<<num<<"/"<<deno<<endl;
        }
    }
};
int main()
{
    int num,deno;
    FRACTION F[2],F1,F2,F3;
    for (int i=0;i<2;i++)
    {
        cout<<"Enter value for fraction "<<i+1<<endl;
        cout<<"Enter the numerator: ";
        cin>>num;
        cout<<"Enter the denominator: ";
        cin>>deno;
        F[i].getdata(num,deno);
    }
    for (int i=0;i<2; i++)
    {
        cout<<"\nFRACTION "<<i+1<<":";
        F[i].show();
    }
    F1.add(F[0],F[1]);
    F2.sub(F[0],F[1]);
    F3.mul(&F[0],&F[1]);

    F1.display();
    F2.display1();
    F3.display2();
    return 0;
}