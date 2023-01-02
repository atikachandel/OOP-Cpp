#include <iostream>
#include <fstream>
#include <cctype>
#include <string.h>
using namespace std;
class Directory
{
   char Name[20];
   char Address[30];
   char areacode[10];
   char phno[15];

public:
   void register1();
   void show();
   int checkcode(char AC[])
   {
      return (strcmp(areacode, AC));
   }
   char *returnareacode()
   {
      return areacode;
   }
   char *returnpho()
   {
      return phno;
   }
};
void Directory::register1()
{
   cout << "\n ENTER NAME: ";
   cin.ignore();
   cin >> Name;
   cout << "\n ENTER ADDRESS: ";
   cin.ignore();
   cin >> Address;
   cout << "\n ENTER 3 DIGIT AREA CODE: ";
   cin.ignore();
   cin >> areacode;
   cout << "\n ENTER PHONE NUMBER: ";
   cin.ignore();
   cin >> phno;
}
void Directory::show()
{
   cout << "\n" << Name << "--" << Address << "--" << areacode << "--" << phno;
}
void display()
{
   Directory s2;
   fstream f;
   cout << "\n==DISPLAY==";
   cout << "\n--NAME--ADDRESS--AREACODE--PHONE--\n";
   f.open("TELE.dat", ios::in);
   f.seekg(0, ios::beg);
   while (f.read((char *)&s2, sizeof(s2)))
   {
      s2.show();
      cout << "\n==================================";
   }
   f.close();
}
void entry()
{
   Directory d1;
   fstream f;
   f.open("TELE.dat", ios::in | ios::out | ios::ate | ios::binary);
   if (!f)
   {
      f.close();
      f.open("TELE.dat", ios::out);
      f.close();
      f.open("TELE.dat", ios::in | ios::out | ios::ate | ios::binary);
   }
   while (f.read((char *)&d1, sizeof(d1)))
   {
   }
   f.clear();
   d1.register1();
   f.write((char *)&d1, sizeof(d1));
   f.close();
   display();
}
void areacodesort()
{
   Directory s1;
   fstream f;
   f.open("TELE.dat", ios::in | ios::out | ios::ate | ios::binary);
   if (!f)
   {
      f.close();
      f.open("TELE.dat", ios::out);
      f.close();
      f.open("TELE.dat", ios::in | ios::out | ios::ate | ios::binary);
   }
   f.seekg(0, ios::beg);
   while (f.read((char *)&s1, sizeof(s1)))
   {
   }
   f.clear();
   int location = f.tellg();
   cout << "\n LOCATION :" << location;
   int no_obj = location / sizeof(s1);
   cout << "\n NO OF OBJS : " << no_obj;
   // sorting
   Directory s[no_obj];
   f.seekg(0, ios::beg);
   for (int i = 0; i < no_obj; i++)
   {
      f.read((char *)&s[i], sizeof(s[i]));
   }
   Directory temp;
   for (int i = 0; i < no_obj - 1; i++)
   {
      for (int j = 0; j < no_obj - i - 1; j++)
      {
         if (strcmp(s[j].returnareacode(), s[j + 1].returnareacode()) > 0)
         {
            temp = s[j];
            s[j] = s[j + 1];
            s[j + 1] = temp;
         }
      }
   }
   f.clear();
   f.seekp(0, ios::beg);
   for (int i = 0; i < no_obj; i++)
   {
      f.write((char *)&s[i], sizeof(s[i]));
   }
   f.close();
   cout << "\n SORTED AREA CODE WISE: \n";
   display();
}
void delentry()
{
   fstream f1, f2;
   char ph[15];
   cout << "\n ENTER PHONE NUMBER OF ENTRY YOU WANT TO DELETE: ";
   cin >> ph;
   f1.open("TELE.dat", ios::in | ios::out | ios::ate | ios::binary);
   f2.open("temptele.dat", ios::out);
   f1.seekg(0, ios::beg);
   f2.seekp(0, ios::beg);
   Directory s;
   while (f1.read((char *)&s, sizeof(s)))
   {
      if (strcmp(ph, s.returnpho()) != 0)
      {
         f2.write((char *)&s, sizeof(s));
      }
      else
      {
         cout << "\n ENTRY FOUND TO BE DELETED.";
         s.show();
      }
   }
   f1.close();
   f2.close();
   remove("TELE.dat");
   rename("temptele.dat", "TELE.dat");
   display();
}
void copyabc()
{
   fstream f1, f2;
   char c[10] = "123";
   f1.open("TELE.dat", ios::in | ios::out | ios::ate | ios::binary);
   f2.open("TELEBACK.dat", ios::out);
   f1.seekg(0, ios::beg);
   f2.seekp(0, ios::beg);
   Directory s;
   while (f1.read((char *)&s, sizeof(s)))
   {
      if (s.checkcode(c) == 0)
      {
         cout << "\n COPYING: ";
         s.show();
         f2.write((char *)&s, sizeof(s));
      }
   }
   f2.clear();
   f2.close();
   cout << "\n ==DISPLAYING CONTENTS OF COPIED FILE:==";
   cout << "\n--NAME--ADDRESS--AREACODE--PHONE--\n";
   f2.open("TELEBACK.dat", ios::in);
   while (f2.read((char *)&s, sizeof(s)))
   {
      s.show();
      cout << "\n==================================";
   }
   f2.close();
}
int main()
{
   int ch = 1;
   while (ch != 0)
   {
      cout << "\n ==TELE.DAT==";
      cout << "\n1.NEW ENTRY\n2.SORT OBJECT ACCORDING TO AREA CODE\n3.INSERT A NEW ENTRY AT APPROPRIATE POSITION\n4.DELETE AN ENTRY BASED ON PHONE NUMBER\n5.COPY ABC ";
              cout << "\n ENTER CHOICE: ";
      cin >> ch;
      switch (ch)
      {
      case 1:
         entry();
         break;
      case 2:
         areacodesort();
         break;
      case 3:
         entry();
         areacodesort();
         break;
      case 4:
         delentry();
         break;
      case 5:
         copyabc();
         break;
      case 7:
         display();
         break;
      }
   }
   return 0;
}