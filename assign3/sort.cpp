/*
      Name: Matthew Matze
      Date: 1/30/2014
      Class: CSC1720
      Location:~/csc1720/assign3
*/

#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<cstring>
#include<ctime>

using namespace std;

void load(char *type, char str[]);
/*
 * Precondition:The load function uses the output type pointer and the original character array. 
 * The load function then loads the type with a single character which defines the type and the
 * original character array with the characters from the data file.
 * Postcondition: The Type character has been retrieved from the data file and the character array
 * has been loaded.
*/
void sort(char *type, char str[],char outstr[], int *length, int *outlength, bool *same, bool *pal);
/*
 * Precondition:The sort function uses the type, original character array, output character array,
 * the original length, the outputlength, the duplicate detecting bool and the palindrome detecting
 * bool.
 * Postcondition: The sort function decides what kind of method we are going to use based on what
 * character we read in from the type. Depending on which type it will either call the reverse, paltest,
 * or elimDup.
*/
void reverse(char outstr[], int *length);
/*
 * Precondition:The reverse function takes in the output array and reverses the characters.
 * Postcondition: The characters of the output array are reversed in order.
*/
void exchange(char outstr[], int i, int j);
/*
 * Precondition:The exchange function takes in the output array, integer i, and integer j.
 * Postcondition:Theexchange function exchanges elements i and j or the output array.
*/
bool paltest(char outstr[], char str[]);
/*
 * Precondition:The paltest requires two character arrays.
 * Postcondition: The paltest function will test if the output array is a palindrom of the input array
*/
void elimDup(char str[], char outstr[],int *length, int *outlength);
/*
 * Precondition:The duplicate elimination function uses the original array, the output array, the
 * original length, and the output length.
 * Postcondition: The function takes the original array and puts it in the output array without
 * any duplicates and increments the output length appropriately
*/
void print(char *type, char str[], char outstr[],int *outlength, bool pal, bool same);
/*
 * Precondition:The print function takes the output type, the original array, the output array, the
 * palindrom bool, and the duplicate bool
 * Postcondition:The print function will decide which method of output is appropriate with the type
 * character and then depending on which one is chosen it will output the correct response.
*/
int main(void)
{

int size;
int length;
int outlength=0;
char type;
char str[61];
char outstr[61];
bool pal;
bool same;
cin>>size;
for(int i=0;i<size;i++){
   load(&type, str);
   for(length=0; str[length]; length++);
      outlength=length;//Find the length and make outlength equal by default
   sort(&type, str, outstr, &length, &outlength, &same, &pal);
   print(&type, str, outstr,&outlength, pal, same);
   }
}
void load(char *type, char str[])
{
cin>>*type;
cin>>str;
}

void sort(char *type, char str[],char outstr[], int *length, int *outlength, bool *same, bool *pal)
{

switch(*type){
   case 'r':
   strcpy(outstr,str); //Set the output array to equal the input by default
   reverse(outstr, length);
   break;
   case 'p':
   strcpy(outstr,str); //Set the output array to equal the input by default
   reverse(outstr, length);
   *pal=paltest(outstr, str);
   break;
   case 'd':
   elimDup(str, outstr,length,  outlength);
   if(*outlength==*length)
   *same=true;
   else
   *same=false;
   break;
}
}

void reverse(char outstr[], int *length)
{
int j=*length-1;
for(int i=0;i<j;i++){
exchange(outstr, i, j);
j--;
}
}

void exchange(char outstr[], int i, int j)
{

char temp;
temp=outstr[i];
outstr[i]=outstr[j];
outstr[j]=temp;

}

bool paltest(char outstr[],char str[])
{
int test;
bool pal;
test=strcmp(str,outstr);
if (test==0)
   pal=true;
else
   pal=false;
   return pal;
}

void elimDup(char str[], char outstr[], int *length, int *outlength){
   int j;
   char k[60];
   bool dup;
   *outlength=0;
   k[0]=str[0];
   for(int i=1;i<*length;i++){
      dup=true;
      for(j=i-1;j>=0;j--){
         if(str[i]==str[j])
             dup=false;
      }
   if(dup==true){
      *outlength+=1;
      k[*outlength]=str[i];
      }
   }
   *outlength+=1;
   strcpy(outstr, k);
}
void print(char *type, char str[], char outstr[],int *outlength, bool pal, bool same)
{

switch(*type){
   case 'r':
      cout << "The string '"<<str<<"' in reverse is '"<<outstr<<"'."<<endl;
   break;
   case 'p':
      if(pal==true)
         cout << "The string '"<<str<<"' is a palindrome."<<endl;
      else
         cout << "The string '"<<str<<"' is not a palindrome."<<endl;
   break;
   case 'd':
         if(same==false){
            cout << "The string '"<<str<<"' with duplicate characters removed is '"; 
            for (int i=0;i<*outlength;i++){
            cout<<outstr[i];
            }
            cout<<"'."<<endl;
            }
         else
            cout << "The string '"<<str<<"' doesn't have any duplicates."<<endl;
   break;
   }
}

