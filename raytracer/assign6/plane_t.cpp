#include"rayhdrs.h"

using namespace std;


/* load: THIS IS IMPORTANT! This load method only read in 2 attributes because
 * it is either called after object_t load has been processing a plane or before
 * a fplane_t processes a finite plane.
 * pre-condition: the plane information up to the word plane has been read in
 * and the input stream is established
 * post-condition: if the object being read is a plane, it will be completely read
 * otherwise, if the object is a finite plane, the input file will be ready for the
 * load method of the fplane_t 
 */
void plane_t::load(istream& ins)
{
   string attribute;
   char check;
   int i;

   for(i=0; !ins.eof() && i<2; i++){
      ins >> attribute;
      item_load(ins, attribute);
   }

   ins >> check;
   if(check!='}'){
      ins.putback(check);
   }
}


/* item_load: looks up each attribute of the plane or finite plane in ray.h and read it in.
 * pre-condition: the name of the attribute is already read in
 * post-condition: the values for each attribute is stored
 */
void plane_t::item_load(istream& ins, string attribute)
{
   int ndx;
   
   ndx = table_lookup(attributes, NUM_ATTRIBUTES, attribute);
   switch(ndx) {

      case NORMAL_ATT:
         ins >> normal;
         break;

      case POINT_ATT:
         ins >> point;
         break;
   }
}

/* dump: calls the object_t dump and then outputs the plane-specific attributes
 * pre-condition: output stream is established
 * post-condition: no change to plane. all values are outputted
 */
void plane_t::dump(ostream &outs)
{
   object_t::dump(outs);
   outs << "   normal: " << normal << endl;
   outs << "   point: " << point << endl;
}

double plane_t::hits(vector_t& base, vector_t& dir){
   
   double th;
   vector_t test;
   ndotp = normal.dot(point);

   if(fabs(normal.dot(dir)) < EPSILON)
      //ray is prallel to the plane
      return -1;

   th = (ndotp-normal.dot(base))/normal.dot(dir);
   if(th < 0)
      //hits is behind the viewpoint
      return -2;

   test = base + dir*th;
   if(test.getZvalue()>0)
      //hit is on the wrong side because z should be negative
      return -3;

   hitloc = test;
   hitnorm = normal;
   return th;
   
}
