#include <iostream>
#include <fstream>
#include <string.h>
#include <cctype>
using namespace std;
class PROD
{
   char PCODE[10];
   char DESC[10];
   int stock;

public:
   void enter()
   {
      cout << "\n ENTER CODE--DESCRIPTION--STOCK AMT: ";
      cin >> PCODE >> DESC >> stock;
   }
   void show()
   {
      cout << "\nCODE--DESC--STOCK\n";
      cout << PCODE << "--" << DESC << "--" << stock;
   }
   void update()
   {
      cout << "\n ENTER NEW VALUE OF STOCK: ";
      cin >> stock;
   }
   char *returncode()
   {
      return PCODE;
   }
};
void display();
void addnew()
{
   fstream inoutfile;
   inoutfile.open("q6stock.dat", ios::in | ios::out | ios::ate | ios::binary);
   if (!inoutfile)
   {
      inoutfile.close();
      inoutfile.open("q6stock.dat", ios::out);
      inoutfile.close();
      inoutfile.open("q6stock.dat", ios::in | ios::out | ios::ate | ios::binary);
   }
   PROD S;
   inoutfile.seekp(0, ios::end);
   inoutfile.clear();
   int ch = 1;
   while (ch != 0)
   {
      S.enter();
      inoutfile.write((char *)&S, sizeof(S));
      cout << "\n PRESS ZERO TO STOP: ";
      cin >> ch;
   }
   inoutfile.close();
}
void searchedit()
{
   PROD S;
   fstream inoutfile;
   inoutfile.open("q6stock.dat", ios::in | ios::out | ios::ate | ios::binary);
   inoutfile.seekp(0, ios::beg);
   char pc[10];
   int size = sizeof(S);
   cout << "\n ENTER PRODUCT CODE TO UPDATE: ";
   cin >> pc;
   while (inoutfile.read((char *)&S, sizeof(S)))
   {
      if (strcmp(pc, S.returncode()) == 0)
      {
         S.update();
         inoutfile.seekp(-size, ios::cur);
         inoutfile.write((char *)&S, sizeof(S));
      }
   }
   inoutfile.close();
   display();
}
void display()
{
   PROD S;
   fstream inoutfile;
   inoutfile.open("q6stock.dat", ios::in | ios::out | ios::ate | ios::binary);
   inoutfile.seekp(0, ios::beg);
   while (inoutfile.read((char *)&S, sizeof(S)))
   {
      S.show();
   }
   inoutfile.close();
}
int main()
{
   addnew();
   cout << "\n BEFORE UPDATION: \n";
   display();
   searchedit();
   cout << "\n AFTER UPDATION: \n";
   display();
   return 0;
}