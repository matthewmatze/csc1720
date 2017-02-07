#include"object_t.h"

#ifndef SPHERE
#define SPHERE

class sphere_t;
typedef sphere_t * sphere_tptr;

class sphere_t:public object_t
{
   protected:
      vector_t center;  //coordinates of the center of the sphere
      double radius;   //sphere radius

   public:
      sphere_t(){};
      sphere_t(istream &ins,list_tptr mats):object_t(ins, mats){
         type="Sphere";
         load(ins);
      };
      virtual ~sphere_t(){};

      virtual double hits(vector_t &base, vector_t &dir);
      virtual void dump(ostream &outs);

   private:
      double ndotp;    //dot product of normal and point
      void load(istream &ins);
      void item_load(istream &ins,string attribute);
};

#endif
