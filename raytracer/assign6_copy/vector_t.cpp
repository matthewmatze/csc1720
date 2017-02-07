/* Name: Reza Moghtaderi Esfahani
 * Date: March 8, 2014
 * Class: CSC1720
 * Location: /home/students/rmoghtaderi/csc1720/assign5
 *
 * Description: This is the implementation file for the class "vector_t".
 * It contains the implementation of all the methods that were declared
 * in vector_t.h
 *
 * This file needs to be in the same directory as the header file at the
 * time of compilation.
 */
#include "vector_t.h"
using namespace std;

   // Default constructor, setting all values to zero
   vector_t::vector_t(){
      x=0.0;
      y=0.0;
      z=0.0;
   }
   // Constructor based on inputted values of x, y, and z
   vector_t::vector_t(double xin, double yin, double zin){
      x=xin;
      y=yin;
      z=zin;
   }

   vector_t::~vector_t(){
      // Nothing to do here, default destructor
      
   }
   
   // Setter methods for x, y, and z      
   void vector_t::setXvalue(double xnew){
      x=xnew;
   }
   void vector_t::setYvalue(double ynew){
      y=ynew;
   }
   void vector_t::setZvalue(double znew){
      z=znew;
   }

   // Getter methods for x, y, and z
   double vector_t::getXvalue(void){
      return x;
   }
   double vector_t::getYvalue(void){
      return y;
   }
   double vector_t::getZvalue(void){
      return z;
   }

   // Setter method for the entire vector at once
   void vector_t::setValues(double xset, double yset, double zset){
      x=xset;
      y=yset;
      z=zset;
   }
   // Setter method to change the x, y, z values based on another vector
   void vector_t::setVector(const vector_t& another){
      x=another.x;
      y=another.y;
      z=another.z;
   }

   // Oprator + and - overload (vector +/- vector will return vector)
   vector_t vector_t::operator+(const vector_t& second) const{
      vector_t result;
      result.x=this->x+second.x;
      result.y=this->y+second.y;
      result.z=this->z+second.z;
      return result;
   }
   vector_t vector_t::operator-(const vector_t& second) const{
      vector_t result;
      result.x=this->x-second.x;
      result.y=this->y-second.y;
      result.z=this->z-second.z;
      return result;
   }
   vector_t vector_t::operator/(const double factor) const{
      vector_t result;
      result.x=this->x/factor;
      result.y=this->y/factor;
      result.z=this->z/factor;
      return result;
   }
   vector_t vector_t::operator*(const double factor) const{
      vector_t result;
      result.x=this->x*factor;
      result.y=this->y*factor;
      result.z=this->z*factor;
      return result;
   }
   // Method to scale all components of a vector by a factor
   vector_t vector_t::scale(double factor) const{
      vector_t result;
      result.x=this->x*factor;
      result.y=this->y*factor;
      result.z=this->z*factor;
      return result;
   }
   // Method to return the unit vector
   vector_t vector_t::unit(void) const{
      return this->scale(1/this->len());
   }
   // Method to return the Dot product of two vectors
   // vector.dot(vector) returns product value
   double vector_t::dot(const vector_t& second) const{
      double result=0.0;
      result+=this->x*second.x;
      result+=this->y*second.y;
      result+=this->z*second.z;
      return result;
   }
   // Method to return the length of a vector
   double vector_t::len(void) const{
      return sqrt((this->x)*(this->x)+(this->y)*(this->y)+(this->z)*(this->z));
   }

   // Operator >> and << overload to display and record correct vector values
   istream& operator>>(istream &ins, vector_t &vec) 
   {
      char delim;
      ins >> delim; // <
      if(delim != '<') {
         cerr << "Not a vector" << endl;
         return ins;
      }
      ins >> vec.x; 
      ins >> delim; // ,
      if(delim != ',') {
         cerr << "Not a vector" << endl;
         return ins;
      }
      ins >> vec.y; 
      ins >> delim; // ,
      if(delim != ',') {
         cerr << "Not a vector" << endl;
         return ins;
      }
      ins >> vec.z; 
      ins >> delim; // > 
      if(delim != '>') {
         cerr << "Not a vector" << endl;
         return ins;
      }
      return ins;  //must always return the stream you manipulate
   }
   ostream& operator<<(ostream& out, vector_t& vector){
      out<<"<";
      out<<fixed<<setprecision(2)<<vector.x;
      out<<",";
      out<<fixed<<setprecision(2)<<vector.y;
      out<<",";
      out<<fixed<<setprecision(2)<<vector.z;
      out<<'>';
      return out;
   }

