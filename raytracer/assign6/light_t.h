#include"drgb_t.h"

#ifndef LIGHT_T
#define LIGHT_T

class light_t;
typedef light_t* light_tptr;

class light_t
{
   private:
      string name;
      vector_t location;  //location of the light
      drgb_t emissivity;
   public:
      light_t(){};  //empty default constructor
      light_t(istream &ins);
      ~light_t(){};  //empty destructor
      string getname(void);
      drgb_t getemiss(void);
      int vischeck(vector_t &);
      void illuminate(model_tptr model, object_tptr hitobj, drgb_t &pixel);
      void dump(ostream &outs);
   
   private:
      void load(istream &ins);
      void item_load(istream &ins, const string &attribute);
};

#endif
