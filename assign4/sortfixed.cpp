/*
 *   Name:MatthewMatze
 *   Date:2-3-14
 *   Class:CSC1720
 *   Location:
 *   Statement:This program takes in an input file
 *   of Student Info, sorts it into an array of Students
 *   based on lastname or first name when needed. The
 *   array is then outputted to an output file where the
 *   array is sorted.
*/

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<cmath>
#include<cstring>
#include"stuType.h"

 using namespace std;

istream& operator>> (istream&in, stuType stu);

ostream& operator<< (ostream &out, stuType stu);

/*
*loadArr-the functions loads an *stuType array with elements until eof
*
*pre-condition:
*the input stream is established, student array is empty or
*can be emptied along with *count.
*post-condition:
*the array is loaded with *count<=100000 values.
*/
void loadArr(istream &in,stuType *student[],int *count);


/*
*sortArr-arrange the elements in ascending order(shellsort)
*according to last name and first name with in the last name
*pre-condition:
*the unsorted array of *stuType and the number of elements in the array
*post-condition:
*the sorted array by last name and first name with in the last name
*/
void sortArr(stuType *student[],int cnt);

/*
*exchange-references to two elements exchange places.
*pre-condition:
*references to two *stuType to exchange are established.
*post-condition:
*the *stuType referenced have exchanged places.
*/
void exchange(stuType *a,stuType *b);

/*
*printArr-output the content so *stuType array to the output
*stream indicated.
*pre-condition:
*the output stream is established, the *stuType array has count
*number of elements tos end to the stream
*post-condition:
*the *stuType and count have not been altered. The output stream
*will beat the end of the output.
*/
void printArr(ostream &out,stuType *student[],int count);


int main(void)
{

   int count=0;
   stuType *student[100001];//need an extra one to avoid
   //a potential seg-fault in the load

   clock_t startL,stopL,startS,stopS,startP,stopP;

   char filenameIN[30];
   char filenameOUT[30];

   ifstream in;
   ofstream out;
   cout<<"Please entera file name(nospaces):";
   cin>>filenameIN;
   in.open(filenameIN);
   if(in.fail()){
      cerr<<"Problem input file\n"<<endl;
      exit(1);
   }

   cout<<"Please enter a filename for results(nospaces):";
   cin>>filenameOUT;
   out.open(filenameOUT);
   if(out.fail()){
      cerr<<"Problem output file\n"<<endl;
      exit(1);
   }


   startL=clock();
   loadArr(in,student,&count);
   stopL=clock();
   double loadT=(double)(stopL-startL)/CLOCKS_PER_SEC;
   cout<<fixed<<setprecision(2)<<setw(3)<<"loadtime:"<<loadT<<endl;
   int cnt=count;
   startS=clock();
   sortArr(student,cnt);
   stopS=clock();
   double sortT=(double)(stopS-startS)/CLOCKS_PER_SEC;
   cout<<fixed<<setprecision(2)<<setw(3)<<"sorttime:"<<sortT<<endl;

   startP=clock();
   printArr(out, student,count);
   stopP=clock();
   double printT=(double)(stopP-startP)/CLOCKS_PER_SEC;
   cout<<fixed<<setprecision(2)<<setw(3)<<"printtime:"<<printT<<endl;

   double totTime=loadT+sortT+printT;
   cout<<"TotalRunTime:"<<totTime<<endl;

   in.close();
   out.close();

   return 0;
}

//==========================================================================
void loadArr(istream &in, stuType *student[],int*count){
   int i=0;
   student[i]=new stuType;
   char ssNum[12];
   char fname[21];
   char lname[21];
   float gpa;
   in>>ssNum>>fname>>lname>>gpa;
   student[i]->setssNum(ssNum);
   student[i]->setfname(fname);
   student[i]->setlname(lname);
   student[i]->setgpa(gpa);
   while(!in.eof()){
      i++;
      student[i]=new stuType;
      in>>ssNum>>fname>>lname>>gpa;
      student[i]->setssNum(ssNum);
      student[i]->setfname(fname);
      student[i]->setlname(lname);
      student[i]->setgpa(gpa);
   }
   *count=i;
}

//==========================================================================
void sortArr(stuType *student[],int cnt){
   int i;
   int gap=cnt/2;
   bool passOK;
   int cmp;
   while(gap>0){
      passOK=true;
      for(i=0;i<cnt-gap;i++){
         cmp=strcmp(student[i]->getlname(), student[i+gap]->getlname());
          
         if(cmp > 0 || (cmp == 0 &&
                 strcmp(student[i]->getfname(), student[i+gap]->getfname()) > 0)){
            
            exchange(student[i], student[i+gap]);
            passOK=false;
         }
      }
      if(passOK){
         gap=gap/2;
      }
   }
}

//==========================================================================
void exchange(stuType *a,stuType *b){
   stuType temp;
   temp=*a;
   *a=*b;
   *b=temp;
}

//==========================================================================
void printArr(ostream &out,stuType *student[],int count){
   int i;
   for(i=0;i<count;i++){
      out<<student[i]->getssNum()<<" ";
      out<<student[i]->getfname()<<" ";
      out<<student[i]->getlname()<<" ";
      out<<fixed<<setprecision(1)<<setw(2)<<student[i]->getgpa()<<endl;
   }
}

//==========================================================================
istream& operator>> (istream &in, stuType stu)
{
   in>>stu.ssNum;
   in>>stu.fname;
   in>>stu.lname;
   in>>stu.gpa;
   return in;
}

//==========================================================================
ostream& operator<< (ostream &out, stuType stu)
{
   out<<stu.ssNum;
   out<<stu.fname;
   out<<stu.lname;
   out<<stu.gpa;
   return out;
}
