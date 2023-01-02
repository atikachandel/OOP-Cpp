#include<iostream>
using namespace std;
int n;
class poly
{
    int *arr1 = (int*)malloc((n+1)* sizeof(int));
    int *arr2 = (int*)malloc((n+1)* sizeof(int));
    int *add1 = (int*)malloc((n+1)* sizeof(int));
    int *mul1 = (int*)malloc((n+1)* sizeof(int));
    public:
    void getdata()
    {
        int j=0;
        cout<<"Enter value for "<<j+1<< " polynomial:\n";
        for (int i=n; i>=0; i--)
        {
            cout<<"Enter value for x^"<<i<<"= ";
            cin>>arr1[i];
        }
        j++;
        cout<<"Enter value for "<<j+1<<" polynomial:\n";
        for(int i=n; i>=0; i--)
        {
            cout<<"Enter value for x^"<<i<<"= ";
            cin>>arr1[i];
        }
    }
    void add()
    {
        for(int j=n; j>=0; j--)
        {
            *((add1)+j)= *((arr1)+j) + *((arr2)+j);
        }
    }
    void mul()
    {
        for(int j=n; j>=0; j--)
        {
            mul1[j]= arr1[j] * arr2[j];
        }
    }
    void display1()
    {
        for(int i=n; i>=0; i--)
        {
            cout<<add1[i]<<"x^"<<i<<"+";
        }
        cout<<add1[0];
    }
    void display2()
    {
        for(int i=n; i>=0; i--)
        {
            cout<<mul1[i]<<"x^"<<i<<"+";
        }
        cout<<mul1[0];
    }
};
int main()
{
    cout<<"Enter degree of polynomial= ";
    cin>>n;
    poly p;
    p.getdata();
    p.add();
    p.mul();
    p.display1();
    cout<<endl;
    p.display2();
    return 0;
}
