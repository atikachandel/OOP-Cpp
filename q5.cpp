#include<iostream> 
#include<fstream> 
using namespace std;

class Book
{
   int Bno;
   char Title[30];

public:
   int RBno(int bno)
   {
      if (bno == Bno)
         return Bno;
      else
         return 0;
   }
   void Enter()
   {
      cout << "\n ENTER BOOKNO AND BOOK TITLE: ";
      cin >> Bno;
      cin >> Title;
   }
   void Display()
   {
      cout << "Book Number :" << Bno << "  " << "Title :" << Title << endl;
   }
};
void addnew()
{
   fstream inoutfile;
   inoutfile.open("q5book.dat", ios::in | ios::out | ios::ate | ios::binary);
   if (!inoutfile)
   {
      inoutfile.close();
      inoutfile.open("q5book.dat", ios::out);
      inoutfile.close();
      inoutfile.open("q5book.dat", ios::in | ios::out | ios::ate | ios::binary);
   }
   Book S;
   inoutfile.seekp(0, ios::end);
   inoutfile.clear();
   int ch = 1;
   while (ch != 0)
   {
      S.Enter();
      inoutfile.write((char *)&S, sizeof(S));
      cout << "\n PRESS ZERO TO STOP: ";
      cin >> ch;
   }
   inoutfile.close();
}
void search()
{
   int bno;
   cout << "\n ENTER BOOK NO. TO DISPLAY: ";
   cin >> bno;
   Book d;
   fstream inoutfile;
   inoutfile.open("q5book.dat", ios::in | ios::out | ios::ate | ios::binary);
   inoutfile.seekp(0, ios::beg);
   while (inoutfile.read((char *)&d, sizeof(d)))
   {
      if (d.RBno(bno) != 0)
      {
         d.Display();
      }
   }
   inoutfile.close();
}
int main()
{
   addnew();
   search();
   return 0;
}