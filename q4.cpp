#include <iostream>
#include <fstream>
using namespace std;

class Applicant
{
   char Rno[10];
   char name[30];
   int A_score;

public:
   void enroll()
   {
      cout << "\n ENTER ROLL NUMBER, NAME AND SCORE: ";
      cin >> Rno;
      cin >> name;
      cin >> A_score;
   }
   void Status()
   {
      cout << "ROLL NUMBER : " << Rno << ", " << "NAME :" << name << ", "<<" A_score : "<< A_score<< endl;
           }
      int ReturnScore(){if (A_score >= 70) return 3;
   else return 0;
}
}
;
void addnew()
{
   fstream inoutfile;
   inoutfile.open("q4apply.dat", ios::in | ios::out | ios::ate | ios::binary);
   if (!inoutfile)
   {
      inoutfile.close();
      inoutfile.open("q4apply.dat", ios::out);
      inoutfile.close();
      inoutfile.open("q4apply.dat", ios::in | ios::out | ios::ate | ios::binary);
   }
   int n, i, c, c1;
   Applicant S;
   inoutfile.seekp(0, ios::end);
   inoutfile.clear();
   int ch = 1;
   while (ch != 0)
   {
      S.enroll();
      inoutfile.write((char *)&S, sizeof(S));
      cout << "\n PRESS ZERO TO STOP: ";
      cin >> ch;
   }
   inoutfile.close();
}
void dis70()
{
   Applicant d;
   fstream inoutfile;
   inoutfile.open("q4apply.dat", ios::in | ios::out | ios::ate | ios::binary);
   inoutfile.seekp(0, ios::beg);
   while (inoutfile.read((char *)&d, sizeof(d)))
   {
      if (d.ReturnScore() != 0)
      {
         d.Status();
      }
   }
   inoutfile.close();
}

int main()
{
   addnew();
   dis70();
   return 0;
}
