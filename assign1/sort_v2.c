/*
      Name: Matthew Matze
      Date: 10/23/2014
      Class: CSC1720
      Location:~/csc1720/assign1
*/

#include<stdio.h>
#include<stdlib.h>

void load(int intarray[], int *sizeptr, FILE *infile);

/*
 *  The load function will put all of the elements from the inputfile
 * into an array of less than 100 until it hits end of file. The
 * intarray[] will store all of the integers from the input file in
 * the infile. The *sizeptr holds the size of the array and store it at the 
 * address of size in main.
*/

void sort(int intarray[], int size);

/*
 *  The sort function sorts all of the elements of the array intarray[]
 * using a selection sort.The intarray[] holds all of the numbers which
 * are then sorted from least to greatest. The size holds the value
 * which is the size of the array. This is used to tell the sort when
 * to stop.
*/

void print(int intarray[], int size, FILE *outfile);

/*
 *  The print function prints all othe elements of the intarray[]
 * and stores them in the *outfile. The intarray[] will store all 
 * of the integers which will be displayed to the output file. 
 * The size int is used to make sure that we only output the 
 * appropriate ammount of numbers.
*/

int main(void)
{
   FILE *infile;
   FILE *outfile;
   int intarray[100];
   int size=0;
   char filename[30];
   char outfilename[30];
   fprintf(stdout, "Please enter the image filename(No Spaces): ");
   fscanf(stdin, "%s", filename);
   infile=fopen(filename, "r");
   if(infile==NULL){
      fprintf(stderr,"Error with file: ");
      fprintf(stderr,"%s\n", filename);
      exit(1);
   }
   fprintf(stdout, "Please enter the image filename(No Spaces): ");
   fscanf(stdin, "%s", outfilename);
   outfile=fopen(outfilename, "w");
   load(intarray, &size, infile);
   sort(intarray, size);
   print(intarray, size, outfile);
   fclose(infile);
   fclose(outfile);
   return 0;
}
void load(int intarray[], int *sizeptr, FILE *infile)
{
   int counter=0;
   while(fscanf(infile, "%d", &intarray[counter])!=EOF){
      counter++;
   }
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
void print(int intarray[], int size, FILE *outfile)
{
   int i;
   for(i=1;i<size+1;i++){
      fprintf(outfile, "%10d", intarray[i-1]);
      if(i%5==0)
         fprintf(outfile, "\n");
   }
   if(i%5!=0)
      fprintf(outfile, "\n");
}
