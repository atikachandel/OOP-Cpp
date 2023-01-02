#include<iostream>
using namespace std;
class vector
{
    int size,x,y,z;
    int *coord;
    public:
    void input();
    void display();
    void modify();
    void multiply();
    void multiplyAll();
    void divide();
    void add();
};
void vector::input()
{
    cout<<"Enter vector for x-coordinate: ";
    cin>>x;
    cout<<"Enter vector for y-coordinate: ";
    cin>>y;
    cout<<"Enter vector for z-coordinate: ";
    cin>>z;
    cout<<"The vector is: "<<x<<"i + "<<y<<" j + "<<z<<"k"<<endl;
}
void vector::modify()
{
    cout<<"Enter new vector for x-coordinate: ";
    cin>>x;
    cout<<"Enter new vector for y-coordinate: ";
    cin>>y;
    cout<<"Enter new vector for z-coordinate: ";
    cin>>z;
    cout<<"The vector is: "<<x<<"i + "<<y<<" j + "<<z<<"k"<<endl;
}
void vector::multiply()
{
    int scalar;
    char axis;
    cout<<endl<<"Enter the scalar to multiply to any one axis: ";
    cin>>scalar;
    cout<<"Enter the axis(x,y,z) you want to multiply the scalar with: ";
    cin>>axis;
    if (axis=='x')
    x=scalar*x;
    else if(axis=='y')
    y=scalar*y;
    else if (axis=='z')
    z=scalar*z;
    cout<<"The new vector is: "<<x<<"i+ "<<y<<"j+ "<<z<<"k"<<endl;
}
void vector::multiplyAll()
{
    int scalar;
    cout<<"\nEnter the scalar to multiply to all the axes: ";
    cin>>scalar;
    x=scalar*x;
    y=scalar*y;
    z=scalar*z;
    cout<<"The new vector is: "<<x<<"i + "<<y<<" j + "<<z<<"k";
}
void vector::display()
{
    cout<<"\nThe vector in desired form: P("<<x<< "," <<y<< "," <<z<< ")"<<endl;
}
void vector::add()
{
    int scalar,a,b,c;
    cout<<"Enter the scalar to be added to all the axes: ";
    cin>>scalar;
    a=scalar+x;    
    b=scalar+y;    
    c=scalar+z;
    cout<<"The new vector is " <<a<<"i+ "<<b<<"j+ "<<c<<"k "<<endl;
}
void vector::divide()
{
    float scalar,a,b,c;
    cout<<"Enter the scalar to be divided by all the axes: ";
    cin>>scalar;
    a=x/scalar;
    b=y/scalar;
    c=z/scalar;
    cout<<"The new vector is: "<<a<<"i + "<<b<<" j + "<<c<<"k"<<endl;
}
int main()
{
    vector v;
    v.input();
    v.modify();
    v.multiply();
    v.multiplyAll();
    v.display();
    v.add();
    v.divide();
    return 0;
}