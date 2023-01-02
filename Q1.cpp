/*1.Define a class to represent a bank account. Include the following members: 
Data Members 
b) Name of the depositor        
b) Account number  
c) Type of account 
d) Balance amount in the account 
Member Functions 
a) To assign initial value 
b) To deposit an amount 
c) To withdraw an amount after checking the balance 
d) To display name and balance 
Write a main program to test the program.*/

#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
class account
{
    public:
    char name[20];
    int AccNo,balance;
    char Acc_type[20];
    void InitialValues()
    {
        cout<<"Account Holder's Name:";
        cin>>name;
        cout<<"Enter account number:";
        cin>>AccNo;
        cout<<"Enter account type:";
        cin>>Acc_type;
        cout<<"Balance:";
        cin>>balance;
    }
    void deposit()
    {
        int bal;
        cout<<"\nEnter the amount to deposit: ";
        cin>>bal;
        balance+=bal;
        cout<<"\nAccount deposited successfully";
        cout<<"\nYour new balance: "<<balance;
    }
    void check()
    {
        int bal;
        cout<<"\nYour balance: "<<balance;
        cout<<"\nEnter amount to withdraw: ";
        cin>>bal;
        if(bal<=balance)
        {
            balance-=bal;
            cout<<"\nBalance remained: "<<balance;
        }
        else
        {
            exit(0);
        }
    }
    void display()
    {
        cout<<"\nName:";
        cin>>name;
        cout<<"\nBalance: "<<balance;
    }
};
int main()
{
    int i;
    account details;
    details.InitialValues();
    cout<<"\nRequired Information contains\n1. Account Holder's Details\n2. Deposit\n3. Withdraw\nEnter your choice\n";
    cin>>i;
    if(i==1)
    {
        details.display();
    }
    else if(i==2)
    {
        details.deposit();
    }
    else if(i==3)
    {
        details.check();
    }
}