/* Name: Matthew Matze
 * Date: 2-28-14
 * Class: CSC1720
 * Location:~/csc1720/assign5/vector_t.cpp
 *
 * Vector_t Class definition.
*/

#include<iostream>
#include<string>
#include<cstring>
#include<math.h>

using namespace std;

#ifndef VECTOR_T
#define VECTOR_T

class vector_t
{
   friend istream & operator>>(istream &in, vector_t &c);
   friend ostream & operator<<(istream &out, const vector_t &c);
   private:
      double x;
      double y;
      double z;
   public:

      vector_t();
      vector_t(double newx, double newy, double newz);
      ~vector_t();

      void setx (double newx);
      void sety (double newy);
      void setz (double newz);
      
      double getx(void);
      double gety(void);
      double getz(void);
      
      vector_t operator-(const vector_t& b) const;
      double len();
      vector_t scale(double scalenum);
      vector_t unit();
      double dot(vector_t b);


};
#endif
