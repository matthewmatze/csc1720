#include"rayhdrs.h"

using namespace std;

/* load: This loads in an sphere object.
 * pre-condition: the word sphere is already read in and the object_t load has
 *                also read it the material for the sphere
 * post-condition: the sphere attributes are completely loaded
 */
void sphere_t::load(istream& ins)
{
   string attribute;

   ins >> attribute;
   while(!ins.eof() && attribute!="}"){
      item_load(ins, attribute);
      ins >> attribute;
   }
}

/* item_load: looks up each attribute of the sphere in ray.h and read it in.
 * pre-condition: the name of the attribute is already read in
 * post-condition: the values for each attribute is stored
 */
void sphere_t::item_load(istream& ins, string attribute)
{
   int ndx;
   
   ndx = table_lookup(attributes, NUM_ATTRIBUTES, attribute);
   switch(ndx) {

      case CENTER_ATT:
         ins >> center;
         break;

      case RADIUS_ATT:
         ins >> radius;
         break;
   }
}

/* dump: calls the object_t dump and then outputs the sphere-specific attributes
 * pre-condition: output stream is established
 * post-condition: no change to sphere. all values are outputted
 */
void sphere_t::dump(ostream &outs)
{
   object_t::dump(outs);
   outs << "   center: " << center << endl;
   outs << "   radius: " << radius << endl;
}

double sphere_t::hits(vector_t& base, vector_t& dir)
{
   double th, a, b, c;
   a = dir.dot(dir);
   b = 2 * (base-center).dot(dir);
   c = (base-center).dot(base-center)-radius*radius;

   if((b*b-(4*a*c))>0){
      th = (-b-sqrt(b*b-(4*a*c)))/(2*a);
      
      if(th < 0)
         return -1;
      
      hitloc = base + dir*th;
      hitnorm = (hitloc-center).unit();
      return th;

   }else{
      return -2;
   }
}
