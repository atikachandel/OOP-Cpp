#include<iostream>
using namespace std;
class book
{
    string bookname, bookauthor;
    double price;

public:
    book()
    {
    }
    void setDetails(string n, string a, double p)
    {
        bookname = n;
        bookauthor = a;
        price = p;
    }
    void printBook()
    {
        cout << "Book name : " << bookname << endl;
        cout << "Book author : " << bookauthor << endl;
        cout << "Price : " << price << endl;
    }
    friend void display(int x);
};
void display(int x)
{
    string bookname, bookauthor;
    double price;

    book arr[x];

    for (int i = 0; i < x; i++)
    {
        cout << "Enter the book name\n";
        cin >> bookname;
        cout << "Enter the author \n";
        cin >> bookauthor;
        cout << "Enter the book price\n";
        cin >> price;
        arr[i].setDetails(bookname, bookauthor, price);
    }
    for (int i = 0; i < x; i++)
    {
        cout << "Details of book " << (i + 1) << "  are:\n";
        arr[i].printBook();
    }
}
int main()
{
    int x;
    cout << "Enter the number of books\n";
    cin >> x;
    display(x);
}