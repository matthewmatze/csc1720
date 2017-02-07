#include"rayhdrs.h"

using namespace std;

/* constructor:
 * pre-condition:
 * post-condition:
 */
object_t::object_t(istream& ins, list_tptr mats)
{
   string brace;
   string check;
   string sname;

   ins >> name;
   ins >> brace;
   ins >> check;
 
   if(check == "material"){
      ins >> sname;
      matptr = material_search(mats, sname);
   }else{
      cerr << "Material is REQUIRED for an object type!" << endl;
   }
}

void object_t::dump(ostream& outs)
{
   outs << type <<": " << name << endl;
   matptr->dump(outs);
   //In order to have a nice output, use the line below instead of the one above
   //outs << "   material: " <<  matptr->getname() << endl;
}


double object_t::hits(const vector_t& base,const vector_t& dir){
    return -5;
};



drgb_t object_t::getamb(void)
{
   return matptr->getamb();
}

drgb_t object_t::getdiff(void)
{
   return matptr->getdif();
}

drgb_t object_t::getspec(void)
{
   return matptr->getspec();
}

string object_t::getname(void)
{
   return name;
}

vector_t object_t::getHitNorm(void)
{
   return hitnorm;
}
vector_t object_t::getHitLoc(void)
{
   return hitloc;
}

