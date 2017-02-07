#include<iostream>
#include<string>
#include<cstring>

using namespace std;

#ifndef STUTYPE
#define STUTYPE

class stuType{

private:

char ssNum[12];
char fname[21];
char lname[21];
float gpa;

public:

   stuType(void)
   {
      *ssNum=NULL;
      *fname=NULL;
      *lname=NULL;
      gpa=0;
   }
   stuType(char ssNumin[],char fnamein[], char lnamein[],float gpain )
   {
      strcpy(ssNum, ssNumin);
      strcpy(fname, fnamein);
      strcpy(lname, lnamein);
      gpa=gpain;
   }
void setssNum (char new_ssNum[])
{
   strcpy(ssNum, new_ssNum);
}
const char* getssNum(void)
{
   return ssNum;
}
void setfname (char new_fname[])
{
   strcpy(fname, new_fname);
}
const char* getfname(void)
{
   return fname;
}
void setlname (char new_lname[])
{
   strcpy(lname, new_lname);
}
const char* getlname(void)
{
   return lname;
}
void setgpa (float new_gpa)
{
   gpa = new_gpa;
}
float getgpa(void)
{
   return gpa;
}

friend istream& operator>> (istream &in, stuType stu);
friend ostream& operator<< (ostream &out, stuType stu);
};
#endif
