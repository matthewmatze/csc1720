/* Name: Reza Moghtaderi Esfahani
 * Date: March 8, 2014
 * Class: CSC-1720
 * Location: /home/students/rmoghtaderi/csc1720/assign5
 *
 * Description: This is the header file for the class "vector_t" and
 * all of its relevant methods. It contains the default constructor
 * and destructor, setter and getter methods for all private members, 
 * operator +/- overload, and iostream operator >>/<< overload. 
 *
 * The only format for an input to be considered a 3d vector is:
 *               < double , double , double >
 *
 * The output values will always be rounded to the nearest hundredth
 */
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<math.h>
#include<cstdlib>

#ifndef VECTOR_T
#define VECTOR_T
using namespace std;

class vector_t{
   
   private:
      double x;
      double y;
      double z;
   
   public:
      vector_t();
      vector_t(double xin, double yin, double zin);
      ~vector_t();
      
      void setXvalue(double xnew);
      void setYvalue(double ynew);
      void setZvalue(double znew);

      double getXvalue(void);
      double getYvalue(void);
      double getZvalue(void);

      void setValues(double xset, double yset, double zset);
      void setVector(const vector_t& another);

      vector_t operator+(const vector_t& second) const;
      vector_t operator-(const vector_t& second) const;
      vector_t operator/(const double factor) const;
      vector_t operator*(const double factor) const;
      vector_t scale(double factor) const;
      vector_t unit(void) const;
      double dot(const vector_t& second) const;
      double len(void) const;

      friend istream& operator>>(istream& in, vector_t& vector);
      friend ostream& operator<<(ostream& out, vector_t& vector);
};
#endif
