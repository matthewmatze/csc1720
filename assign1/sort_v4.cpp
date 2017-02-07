/*
      Name: Matthew Matze
      Date: 1/23/2014
      Class: CSC1720
      Location:~/csc1720/assign1
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

void load(istream &in, int intarray[], int *sizeptr);

/*
 * The load function will put all of the elements from the inputfile
 * into an array of less than 100 until it hits end of file. The 
 * istream redirects the input file to the load function. The
 * intarray[] will store all of the integers from the input file. 
 * The *sizeptr holds the size of the array and store it at the 
 * address of size in main.
*/

void sort(int intarray[], int size);

/*
 * The sort function sorts all the elements of the array intarray[] 
 * using a selection sort.The intarray[] holds all of the numbers 
 * which are then sorted from least to greatest.The size holds
 * the value which is the size of the array. This is used to tell 
 * the sort when to stop.
*/
 
void print(ostream &in, int intarray[], int size);

/*
 * The print function prints all of the elements of the intarray[]
 * to the output file. The ostream directs the output file to the 
 * load function. The intarray[] will store all of the integers
 * which will be displayed to the output file. The size int is used
 * to make sure that we only output the approriate ammount of numbers. 
*/

int main(void)
{
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

   int intarray[100];
   int size=0;
   load(in, intarray, &size);
   sort(intarray, size);
   print(out, intarray, size);

   in.close();
   out.close();

   cout<<endl;

   return 0;
}
void load(istream &in, int intarray[], int *sizeptr)
{
   int counter=0;
  
   while(in>>intarray[counter])
   counter++;

   *sizeptr=counter;
}
void sort(int intarray[], int size)
{
   int smallpos;
   int i,y, temp;
   for(i=0;i<size;i++){
      smallpos=i;
      for(y=i+1;y<size;y++){
         if(intarray[y]<intarray[smallpos])
            smallpos=y;
      }
      if(i!=smallpos){
      temp=intarray[i];
      intarray[i]=intarray[smallpos];
      intarray[smallpos]=temp;
      }
   }
}
void print(ostream &out, int intarray[], int size)
{
   int i;
   for(i=1;i<size+1;i++){
      out << setw(10) << intarray[i-1];
      if(i%5==0)
         out<<'\n';
   }
   if(i%5!=0)
      out<<'\n';
}
