#include"object_t.h"

#ifndef PLANE
#define PLANE

class plane_t;
typedef plane_t * plane_tptr;

class plane_t:public object_t
{
   protected:
      vector_t normal;  //vector perpendicular to the plane
      vector_t point;   //point on the plane

   public:
      plane_t(){};
      plane_t(istream &ins,list_tptr mats):object_t(ins, mats){
         type="Plane";
         load(ins);
      };
      virtual ~plane_t(){};

      virtual double hits(vector_t &base, vector_t &dir);
      virtual void dump(ostream &outs);

   private:
      double ndotp;    //dot product of normal and point
      void load(istream &ins);
      void item_load(istream &ins,string attribute);
};

#endif
