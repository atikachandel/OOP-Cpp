//3.WAP to find area of a circle, a rectangle and a triangle, using concept of function overloading
#include<iostream>
#include<conio.h>
using namespace std;
const float pi=3.14;
float area(float n, float b,float h)
{
float ar;
ar=0.5*b*h;
return ar;
}
float area(float r)
{
float ar;
ar=pi*r*r;
return ar;
}
float area(float l,float b)
{
float ar;
ar=l*b;
return ar;
}
int main()
{
    float b,h,r,l;
    float result;
    cout<<"\nEnter the base & hieght of triangle: \n";
    cin>>b>>h;
    result=area(0.5,b,h);
    cout<<"Area of triangle: "<<result;
    cout<<"\nEnter the radius of circle: \n";
    cin>>r;
    result=area(r);
    cout<<"Area of circle: "<<result;
    cout<<"\nEnter the length & width of rectangle: \n";
    cin>>l>>b;
    result=area(l,b);
    cout<<"Area of rectangle: "<<result;
    return 0;
    getch();
}
