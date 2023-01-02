#include <iostream>
#include <fstream>
#include <cctype>
#include <string.h>
using namespace std;
class student
{
   int roll;
   float marks[8];
   float sgpa;
   float prsgpa;
   float cgpa;
   int semester;
   char branch[15];
   int batch;

public:
   student() {}
   void getdata()
   {
      cout << "\n ENTER ROLL NO: ";
      cin >> roll;
      for (int i = 0; i < 8; i++)
      {
         cout << "\n ENTER MARKS IN SUBJECT" << i + 1 << " : ";
         cin >> marks[i];
      }
      cout << "\n ENTER SEMESTER: ";
      cin >> semester;
      cout << "\n ENTER BRANCH￾CSE/IT/CSCE/CSSE/ECE/EEE/MECH/CIVIL/BIOTECH: ";
      cin.ignore();
      cin >> branch;
      cout << "\n ENTER BATCH YEAR: ";
      cin >> batch;
      prsgpa = 0;
   }
   void sgpacalc()
   {
      // ASSUMING FIRST TWO SUBJECTS HAVING 4 CRED, NEXT TWO AS 3 AND SO ON...
      float sum = 0;
      sum = ((marks[0] / 10) * 4) + ((marks[1] / 10) * 4) + ((marks[2] / 10) * 3) + ((marks[3] / 10) * 3) + ((marks[4] / 10) * 2) + ((marks[5] / 10) * 2) + ((marks[6] / 10) * 1) + ((marks[7] / 10) * 1);
      float cred = 20;
      sgpa = (sum / cred);
      if (semester == 1)
      {
         cgpa = sgpa;
      }
   }

   void cgpacalc()
   {
      if (semester == 1)
      {
         cgpa == sgpa;
      }
      else
      {
         int y = semester - 1;
         float temp;
         for (int i = 0; i < y; i++)
         {
            cout << "\n ENTER PAST SGPA FOR SEMESTER-" << i + 1 << ": ";
            cin >> temp;
            prsgpa += temp;
         }
         cgpa = ((prsgpa) + sgpa) / semester;
      }
   }
   int returnroll()
   {
      return roll;
   }
   void display()
   {
      cout << "\n ROLL NUMBER: " << roll << "\nSEMESTER: " << semester << "\nBRANCH : " << branch << "\n BATCH : " << batch;
      cout << "\n MARKS: \n";
      for (int i = 0; i < 8; i++)
      {
         cout << "\n MARKS IN SUBJECT " << i + 1 << ": " << marks[i];
      }
      cout << "\n SGPA: " << sgpa;
      cout << "\n CGPA: " << cgpa;
   }
   void edit()
   {
      for (int i = 0; i < 8; i++)
      {
         cout << "\n ENTER MARKS IN SUBJECT" << i + 1 << " : ";
         cin >> marks[i];
      }
      sgpacalc();
      cgpacalc();
   }
   char *returnbranch()
   {
      return branch;
   }
   int returnbatch()
   {
      return batch;
   }
   int returnsem()
   {
      return semester;
   }
};

void display()
{
   student s2;
   fstream f;
   cout << "\n==DISPLAY==";
   f.open("KIIT.dat", ios::in);
   f.seekg(0, ios::beg);
   while (f.read((char *)&s2, sizeof(s2)))
   {
      s2.display();
      cout << "\n=======================";
   }
   f.close();
}

void entry()
{
   student s1;
   fstream f;
   f.open("KIIT.dat", ios::in | ios::out | ios::ate | ios::binary);
   if (!f)
   {
      f.close();
      f.open("KIIT.dat", ios::out);
      f.close();
      f.open("KIIT.dat", ios::in | ios::out | ios::ate | ios::binary);
   }
   while (f.read((char *)&s1, sizeof(s1)))
   {
   }
   f.clear();
   s1.getdata();
   s1.sgpacalc();
   s1.cgpacalc();
   f.write((char *)&s1, sizeof(s1));
   f.close();
   display();
}

void redit()
{
   int chkroll;
   int flag = 0;
   cout << "\n ENTER ROLL NUMBER OF THE ENTRY YOU WISH TO EDIT: ";
   cin >> chkroll;
   student s;
   fstream f;
   f.open("KIIT.dat", ios::in | ios::out | ios::ate | ios::binary);
   f.seekg(0, ios::beg);
   while (f.read((char *)&s, sizeof(s)))
   {
      if (s.returnroll() == chkroll)
      {
         cout << "\n ENTRY FOUND: ";
         s.display();
         break;
      }
   }
   cout << "\n ==EDIT==";
   s.edit();
   cout << "\n ==DISPLAY AFTER EDIT: ";
   s.display();
   int size = sizeof(s);
   f.seekp(-size, ios::cur);
   f.write((char *)&s, sizeof(s));
   f.close();
   display();
}

void delentry()
{
   fstream f1, f2;
   int nroll;
   cout << "\n ENTER ROLL NUMBER OF ENTRY YOU WANT TO DELETE: ";
   cin >> nroll;
   f1.open("KIIT.dat", ios::in | ios::out | ios::ate | ios::binary);
   f2.open("tempkiit.dat", ios::out);
   f1.seekg(0, ios::beg);
   f2.seekp(0, ios::beg);
   student s;
   while (f1.read((char *)&s, sizeof(s)))
   {
      if (nroll != s.returnroll())
      {
         f2.write((char *)&s, sizeof(s));
      }
      else
      {
         cout << "\n ENTRY FOUND TO BE DELETED.";
         s.display();
      }
   }
   f1.close();
   f2.close();
   remove("KIIT.dat");
   rename("tempkiit.dat", "KIIT.dat");
   display();
}
void batchsort()
{
   student s1;
   fstream f;
   f.open("KIIT.dat", ios::in | ios::out | ios::ate | ios::binary);
   if (!f)
   {
      f.close();
      f.open("KIIT.dat", ios::out);
      f.close();
      f.open("KIIT.dat", ios::in | ios::out | ios::ate | ios::binary);
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
   student s[no_obj];
   f.seekg(0, ios::beg);
   for (int i = 0; i < no_obj; i++)
   {
      f.read((char *)&s[i], sizeof(s[i]));
   }
   student temp;
   for (int i = 0; i < no_obj - 1; i++)
   {
      for (int j = 0; j < no_obj - i - 1; j++)
      {
         if (s[j].returnbatch() > s[j + 1].returnbatch())
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
   cout << "\n SORTED BATCH WISE: \n";
   display();
}
void branchsort()
{
   student s1;
   fstream f;
   f.open("KIIT.dat", ios::in | ios::out | ios::ate | ios::binary);
   if (!f)
   {
      f.close();
      f.open("KIIT.dat", ios::out);
      f.close();
      f.open("KIIT.dat", ios::in | ios::out | ios::ate | ios::binary);
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
   student s[no_obj];
   f.seekg(0, ios::beg);
   for (int i = 0; i < no_obj; i++)
   {
      f.read((char *)&s[i], sizeof(s[i]));
   }
   student temp;
   for (int i = 0; i < no_obj - 1; i++)
   {
      for (int j = 0; j < no_obj - i - 1; j++)
      {
         if (strcmp(s[j].returnbranch(), s[j + 1].returnbranch()) > 0)
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
   cout << "\n SORTED BRANCH WISE: \n";
   display();
}
void semestersort()
{
   student s1;
   fstream f;
   f.open("KIIT.dat", ios::in | ios::out | ios::ate | ios::binary);
   if (!f)
   {
      f.close();
      f.open("KIIT.dat", ios::out);
      f.close();
      f.open("KIIT.dat", ios::in | ios::out | ios::ate | ios::binary);
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
   student s[no_obj];
   f.seekg(0, ios::beg);
   for (int i = 0; i < no_obj; i++)
   {
      f.read((char *)&s[i], sizeof(s[i]));
   }
   student temp;
   for (int i = 0; i < no_obj - 1; i++)
   {
      for (int j = 0; j < no_obj - i - 1; j++)
      {
         if (s[j].returnsem() > s[j + 1].returnsem())
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
   cout << "\n SORTED SEMESTER WISE: \n";
   display();
}
void delall()
{
   remove("KIIT.dat");
}
int main()
{
   int ch = 1;
   while (ch != 0)
   {
      cout << "\n ==KIIT GRAING SYSTEM==";
      cout << "\n1.NEW ENTRY AND CALCULATE SGPA/CGPA\n2.EDIT RESULTS AND CALCULATE SGPA /CGPA\n3.DELETE AN ENTRY\n4.SORT BATCHWISE ";
      cout << "\n5.SORT BRANCHWISE\n6.SORT SEMESTERWISE\n7.DISPLAY ALL.\n8.DELETE ALL ";
      cout << "\n ENTER CHOICE: ";
      cin >> ch;
      switch (ch)
      {
      case 1:
         entry();
         break;
      case 2:
         redit();
         break;
      case 3:
         delentry();
         break;
      case 4:
         batchsort();
         break;
      case 5:
         branchsort();
         break;
      case 6:
         semestersort();
         break;
      case 7:
         display();
         break;
      case 8:
         delall();
         break;
      }
   }
   return 0;
}