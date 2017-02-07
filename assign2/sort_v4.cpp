/*
      Name: Matthew Matze
      Date: 1/30/2014
      Class: CSC1720
      Location:~/csc1720/assign2
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<cstring>
#include<ctime>

using namespace std;

struct info
{
   char ssn[12];
   char fname[21];
   char lname[21];
   float GPA;
};
void load(istream &in, struct info *student[], int *sizeptr);

/*
 * The load function will load  all of the elements from the inputfile 
 * dynamicly into an array  until it hits end of file. The 
 * istream redirects the input file to the load function. The
 * info[] will store all of the integers from the input file. 
 * The *sizeptr holds the size of the array and store it at the 
 * address of size in main.
*/

void exchange(struct info *student[], int i, int gap);

/*
 * The exchange function takes in a info struct and two ints and swaps the structs
*/

void sort(struct info *student[], int size);

/*
 * The sort function sorts all the elements of the array info[] 
 * using a selection sort.The student[] holds all of the numbers 
 * which are then sorted from least to greatest.The size holds
 * the value which is the size of the array. This is used to tell 
 * the sort when to stop.
*/
 
void print(ostream &in, struct info *student[], int size);

/*
 * The print function prints all of the elements of the student[]
 * to the output file. The ostream directs the output file to the 
 * load function. The student[] will store all of the integers
 * which will be displayed to the output file. The size int is used
 * to make sure that we only output the approriate ammount of numbers. 
*/
int main(void)
{
   struct info *student[100000];
   char filename[30];
   char outputfile[30];
   ifstream in;
   ofstream out;
   
   cout<<"Type in your input filename: ";
   cin>>filename;
   in.open(filename);
   if(in.fail()) {
      cerr<<"problem input file"<<endl;
      exit(1);
   }
   cout<<"Type in your output filename: ";
   cin>>outputfile;
   out.open(outputfile);
   if(in.fail()) {
      cerr<<"problem output file"<<endl;
      exit(1);
   }

   int size=0;
   clock_t  start, stop;
   start = clock();
   load(in, student, &size);
   stop = clock();
   cout << "Load time: " << (double)(stop - start)/CLOCKS_PER_SEC << endl;
   start = clock();
   sort(student, size);
   stop = clock();
   cout << "Sort time: " << (double)(stop - start)/CLOCKS_PER_SEC << endl;
   start = clock();
   print(out, student, size);
   cout << "Print time: " << (double)(stop - start)/CLOCKS_PER_SEC << endl;

   in.close();
   out.close();

   cout<<endl;

   return 0;
}
void load(istream &in, struct info *student[], int *sizeptr)
{
   *sizeptr=0;
   student[0]= new info[0];
   while(in>>student[*sizeptr]->ssn){
   in>>student[*sizeptr]->fname;
   in>>student[*sizeptr]->lname;
   in>>student[*sizeptr]->GPA;
   *sizeptr+=1;
   student[*sizeptr]= new info[*sizeptr];
   }
}
void sort(struct info *student[], int size)
{
   int gap=size/2;
   bool passOk;
   while(gap>0){
      passOk=true; //assume a pass does not call exchange
      for(int i=0; i<size-gap;i++){
         if(strcmp(student[i+gap]->lname, student[i]->lname)<0||(strcmp(student[i+gap]->lname, student[i]->lname)==0&&strcmp(student[i+gap]->fname, student[i]->fname)<0)){
            exchange(student, i, gap);
            passOk=false;
         }
      }
      if(passOk)
         gap/=2;
   }
}
void exchange(struct info *student[], int i, int gap)
{
   struct info temp;
         temp=*student[i+gap];
         *student[i+gap]=*student[i];
         *student[i]=temp;
}
void print(ostream &out, struct info *student[], int size)
{
   for(int i=0;i<size;i++){
      out << student[i]->ssn<<" ";
      out << student[i]->fname<<" ";
      out << student[i]->lname<<" ";
      out << student[i]->GPA<<" ";
      out<<"\n";
   }
}
