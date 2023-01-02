//4.WAP to swap two integers using pass by reference. 
#include<iostream>
using namespace std;
void swap(int *n1, int *n2)
{
    int k;
    k=*n1;
    *n1=*n2;
    *n2=k;
}
int main()
{
    int n1,n2;
    cout<<"Enter 1st number:";
    cin>>n1;
    cout<<"Enter 2nd number:";
    cin>>n2;
    cout<<"Before swapping\n";
    cout<<n1<<"  "<<n2;
    cout<<"\nAfter swapping\n";
    swap(&n1, &n2);
    cout<<n1<<"  "<<n2<<endl;
    return 0;
}
    