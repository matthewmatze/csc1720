/* Name: Matthew Matze
 * Date: 2-28-14
 * Class: CSC1720
 * Location:~/csc1720/assign5/vector_t.cpp
 */

#include<iostream>
#include<stdio.h>
#include"vector_t.h"
#include"vector_t.cpp"

using namespace std;

int main(void)
{
   vector_t v1, v2, v3, v4;
   double v;

   cin>>v1>>v2;
   
   cout<<"v1: "<<v1<<endl;
   cout<<"v2: "<<v2<<endl;

   v3 = v2 - v1;
   cout<<"v2 - v1:"<<v3<<endl;

   v = v1.dot(v2);
   printf("v1 dot v2 is %8.3lf \n", v);

   v = v1.len();
   printf("Length of v1 is %8.3lf \n", v);

   v3 = v1.scale(1/v);
   cout << "v1 scaled by its 1/length: "<< v3 << endl;
   
   v4 = v1.unit();
   cout << "unit vector in v1 direction: "<< v4 << endl;

   return 0;
}
   
