#include<iostream>
#include"camera_t.h"

using namespace std;
#ifndef MODEL_T
#define MODEL_T

class model_t;
typedef model_t * model_tptr;

class model_t
{
   public:
      model_t(istream &ins);
      void dump(ostream &outs);
      camera_t    *cam;  //the camera structure

   private:
      void load(istream &ins);
      void item_load(istream &ins, const string &entity);
};

#endif
