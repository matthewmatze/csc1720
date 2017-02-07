#include<cstdlib>
#include<iostream>
#include"vector_t.h"
#include"material_t.h"
#include"list_t.h"

#define EPSILON 0.000001   

class object_t;                         
typedef object_t * object_tptr;

#ifndef OBJECT
#define OBJECT

class object_t
{
   private:
      string name;             //object names like - ball, leftwall, rightwall, ...
   protected:
      //surface reflectivity data
      material_tptr matptr;    //primary color of the object           
      string type;             //plane, sphere, ...     
      vector_t hitloc;         //last hit point    
      vector_t hitnorm;        //normal at last hit point  
   public:
      object_t(){};
      object_t(istream &ins, list_tptr mats);
      virtual ~object_t(){};
      
      //finds if/where a ray hits the object     
      virtual double hits(const vector_t &base, const vector_t &dir);     
      //prints object attributes
      virtual void dump(ostream &outs); 
      
      // Optional plugins for procedural reflectivity /
      virtual drgb_t getamb(void);
      virtual drgb_t getdiff(void);
      virtual drgb_t getspec(void);
      virtual string getname(void);
      
      virtual vector_t getHitNorm(void);
      virtual vector_t getHitLoc(void);
      
};

#endif
