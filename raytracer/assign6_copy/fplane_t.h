#include"plane_t.h"

#ifndef FINITE_PLANE
#define FINITE_PLANE

class fplane_t;
typedef fplane_t * fplane_tptr;

class fplane_t:public plane_t
{
   private:
      //matrix_t rot;        //rotation matrix - implement later
      //vector_t projxdir;   //projected unitized xdir
      vector_t xdir;         //input xdir
      
      void load(istream &ins);
      void item_load(istream &ins,string attribute);
     
   protected:
      //vector_t  newloc;    //translated then rotate hitloc
      double    dims[2];     //input dims in world coords
      
   public:
      fplane_t(){};
      fplane_t(istream &ins,list_tptr mats):plane_t(ins, mats){
         type="Finite_plane";
         load(ins);
      };
      virtual ~fplane_t(){};
                          
      //virtual double hits(vector_t &base, vector_t &dir);
      virtual void dump(ostream &outs);
};

#endif
