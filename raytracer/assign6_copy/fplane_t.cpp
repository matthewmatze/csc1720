//#include"fplane_t.h"
#include"rayhdrs.h"

using namespace std;

/* load: This method is called after object_t and plane_t load functions have 
 * finished reading in the information for finite plane attributes
 * pre-condition: the finite plane information up to xdir and dimension has been read in
 * and the input stream is established
 * post-condition: the finite plane attributes have been read in.
 */
void fplane_t::load(istream& ins)
{
   string attribute;

   ins >> attribute;
   while(!ins.eof() && attribute!="}"){
      item_load(ins, attribute);
      ins >> attribute;
   }
}

/* item_load: looks up each attribute of the finite plane in ray.h and read it in.
 * pre-condition: the name of the attribute is already read in
 * post-condition: the values for each attribute is stored
 */
void fplane_t::item_load(istream& ins, string attribute)
{
   int ndx;
   
   ndx = table_lookup(attributes, NUM_ATTRIBUTES, attribute);
   switch(ndx) {

      case XDIR_ATT:
         ins >> xdir;
         break;

      case DIMENSION_ATT:
         ins >> dims[0];
         ins >> dims[1];
         break;
   }
}

/* dump: THIS IS IMPORTANT! this method calls the plane_t dump which 
 * will in turn call the object_t dump and then outputs the finite plane-specific attributes
 * pre-condition: output stream is established
 * post-condition: no change to the finite plane. all values are outputted
 */
void fplane_t::dump(ostream &outs)
{
   plane_t::dump(outs);
   outs << "   xdir: " << xdir << endl;
   outs << "   dimension: " << dims[0] <<" "<< dims[1] << endl;
}


/*
double fplane_t::hits(vector_t& base, vector_t& dir)
{
   return;
}
*/
