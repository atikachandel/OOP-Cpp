#include<iostream>
using namespace std;
class staff{
        string name;
        int code;
    public:
        void getdata(){
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter code: ";
            cin>>code;
        }
        void display(){
            cout<<"Name: "<<name<<endl;
            cout<<"Code: "<<code<<endl;
        }
};
class typist:public staff{
    int age;
public:
    void getdata(){
        cout<<"Enter age: ";
        cin>>age;
    }
    void display(){
        cout<<"Age: "<<age<<endl;
    }
};
int main(){
    typist t;
    t.staff::getdata();
    t.getdata();
    t.staff::display();
    t.display();
    return 0;
}
