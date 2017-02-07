/* Model is the main foundation of this program.
 * It holds the three lists that contain all the scene elements
 */

#include<iostream>
#include"camera_t.h"
#include"material_t.h"
#include"light_t.h"
#include"list_t.h"
#include"object_t.h"
#include"plane_t.h"
#include"sphere_t.h"
#include"fplane_t.h"
//#include"rayhdrs.h"


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
      camera_t  *cam;  //the camera structure
      list_tptr mats;  //the list containing all the materials as void*
      list_tptr lgts;  //the list containing all the lights as void*
      list_tptr objs;  //the list containing all the objects as void*

   private:
      void load(istream &ins);
      void item_load(istream &ins, const string &entity);
};

#endif
