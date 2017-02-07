#include<cstdlib>
#include<iostream>
#include<iomanip>
using namespace std;

#ifndef DRGB
#define DRGB
//for lights and reflective materials, 
//0.0 means black and 1.0 means maximal brightness
class drgb_t
{
   public:
      double r;
      double g;
      double b;
      drgb_t()
      {
         r=g=b=0;
      }
      void dumper(char * msg)
      {
         cout<<"drgb: "<<msg<<" "<<r<<" "<<g<<" "<<b<<endl;
      }
  
   //operator overload to help with outputting double rgb values
    
   friend ostream& operator<<(ostream& outs, drgb_t& amb){
      outs << fixed << setprecision(2) << amb.r <<" "<<amb.g<<" "<<amb.b;
      return outs;
   };
   
   friend istream& operator>>(istream& ins, drgb_t& amb){
      ins >> amb.r >> amb.g >> amb.b;
      return ins;
   };
   
   drgb_t operator*(const double factor) const{
      drgb_t result; 
      result.r = this->r * factor;
      result.g = this->g * factor;
      result.b = this->b * factor;
      return result;
   };
};

#endif
