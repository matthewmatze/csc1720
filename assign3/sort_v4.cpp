/*
      Name: Matthew Matze
      Date: 1/30/2014
      Class: CSC1720
      Location:~/csc1720/assign3
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<cstring>
#include<ctime>

using namespace std;

char origstr[60][60];
void load(/*istream &in,*/ char origstr[][60], int i, char type[], int strsize[]);

/*
 * The exchange function takes in a info struct and two ints and swaps the structs
*/

void reverse(char outstr[][60],int size, int strsize[]);

/*
 * The sort function sorts all the elements of the array info[] 
 * using a selection sort.The student[] holds all of the numbers 
 * which are then sorted from least to greatest.The size holds
 * the value which is the size of the array. This is used to tell 
 * the sort when to stop.
*/
 
void sortd(char outstr[][60],int size, char type[], int outstrsize[], int strsize[]);







char outstr[60][60];
void print(/*ostream &output,*/ char origstr[][60], char outstr[][60], int strsize[], int outstrsize[], int size, char type[]);

/*
 * The print function prints all of the elements of the student[]
 * to the output file. The ostream directs the output file to the 
 * load function. The student[] will store all of the integers
 * which will be displayed to the output file. The size int is used
 * to make sure that we only output the approriate ammount of numbers. 

*/
void exchange(char outstr[][60], int i, int j, int k);

/*
 * Precondition:
 * We are loading in the two dimesional chara
*/

int main(void)
{
/*
   ifstream data; 
   ofstream output;
   
   data.open("data");
   if(data.fail()) {
      cerr<<"problem input file"<<endl;
      exit(1);
   }
   printf("test1");
   output.open("output");
   if(data.fail()) {
      cerr<<"problem output file"<<endl;
      exit(1);
   }
*/ int size;
   cin>>size;
   int outstrsize[size];
   char type[size];
   printf("test2\n");
   int strsize[size];
   for(int i=0;i<size;i++){
      load(/*data,*/ origstr, i, type, strsize);
      for(int j=0;j<size;j++){
         for(int k=0;k<strsize[j];k++){
            outstr[j][k]=origstr[j][k];
         }
      }
      if(type[i]=='r')
         reverse(outstr, size, strsize);
      else if(type[i]=='p'){
         reverse(outstr, size, strsize);
         if(strcmp(outstr[i], origstr[i])!=0)
            type[i]='g';
      }
      else
         sortd(outstr, size, type, outstrsize, strsize);
      print(/*output,*/ origstr, outstr, strsize, outstrsize, size, type);
   }
   /*data.close();
   output.close();
   */
   cout<<endl;

   return 0;
}
void load(/*istream &data,*/ char origstr[][60], int i, char type[], int strsize[])
{
   cin>>type[i];
   while(type[i]!='r'&&type[i]!='p'&&type[i]!='d')
      cin>>type[i];
   strsize[i]=0;
   while(cin>>origstr[i][strsize[i]])
      strsize[i]+=1;
}
void sortd(char outstr[][60],int size, char type[], int outstrsize[], int strsize[])
{
   int l, k, j, i;
   for(i=0;i<size;i++){
      for( j=0;j<outstrsize[i];j++){
         for(k=outstrsize[i]-1;k>0;k--){
            if(outstrsize[k]==outstrsize[j]){
               for(l=k;l<outstrsize[i];l++)
                  exchange(outstr, i, l, l+1);
               outstrsize[i]--;
            }
         }
      }
      if(outstrsize[i]==strsize[i])
         type[i]='n';
   }
}
void reverse(char outstr[][60],int size, int strsize[])
{
for(int i=0;i<size;i++){
   int k=strsize[i]-1;
   for(int j=0;j<=k;j++){
      exchange(outstr, i, j, k);
      k--;
      }
   }
}
void exchange(char outstr[][60], int i, int j, int k)
{
   char temp;
         temp=outstr[i][j];
         outstr[i][j]=outstr[i][k];
         outstr[i][k]=temp;
}

void print(/*ostream &output,*/ char origstr[][60], char outstr[][60], int strsize[], int outstrsize[], int size, char type[])
{
   for(int i=0;i<size;i++){
      if(type[i]=='r'){
         cout << "The string '"; 
         for(int j=0; j<strsize[i];j++)
         cout << origstr[j];
         cout <<"' in reverse is '";
         for(int k=0; k<strsize[i];k++)
         cout << outstr[k];
         cout <<"'.";
      }
      else if(type[i]=='d'){
         cout << "The string '"; 
         for(int j=0; j<strsize[i];j++)
         cout << origstr[j];
         cout <<"' with duplicate characters removed is '";
         for(int k=0; k<outstrsize[i];k++)
         if(outstr[i][k]!='0')
         cout << outstr[k];
         cout <<"'.";
         }
      else if(type[i]=='n'){
         cout << "The string '"; 
         for(int j=0; j<strsize[i];j++)
         cout << origstr[j];
         cout <<"' doesn't have any duplicates.";
         }
      else if(type[i]=='p'){
         cout << "The string '"; 
         for(int j=0; j<strsize[i];j++)
         cout << origstr[j];
         cout <<"' is a palindrome.'";
         }
      else(type[i]=='g');{
         cout << "The string '"; 
         for(int j=0; j<strsize[i];j++)
         cout << origstr[j];
         cout <<"' is not a palindrome.'";
         }
      cout<<"\n";
   }
}
