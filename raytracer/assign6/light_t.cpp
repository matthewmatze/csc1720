#include"rayhdrs.h"

/* constructor: initialize a light
 * pre-condition: The input stream has been established and the
 *                the word light is read by the model
 * post-condition: light name and attributes are loaded
 */
light_t::light_t(istream &ins)
{
   string brace;

   ins >> name;
   ins >> brace;

   load(ins);
   
   //pixmap....dynamically setup the pixmap - later....
}

/* load: iterates through light attributes and call item-load
 * pre-condition: the { has been read in and the input stream is established
 * post-condition: the } is read in and the light is completely loaded
 */
void light_t::load(istream &ins)
{   
   string attribute; 

   ins >> attribute;
   while(!ins.eof() && attribute!="}"){
      item_load(ins, attribute);
      ins >> attribute;
   }
}

/* item_load: looks up each attribute in ray.h and read it in.
 * pre-condition: the name of the attribute is already read in
 * post-condition: the values for each attribute is stored
 */
void light_t::item_load(istream &ins, const string &attribute)
{
   int ndx;
   ndx = table_lookup(attributes, NUM_ATTRIBUTES, attribute);
   switch(ndx) {

      case LOCATION_ATT:
         ins >> location;
         break;

      case EMISSIVITY_ATT:
         ins>>emissivity;
         break;

   }
}

/* getamb:
 * pre-condition:
 * post-condition:
 */
drgb_t light_t::getemiss(void){
   return emissivity;
}

string light_t::getname(void){
   return name;
}

/* dump: outputs the name and all the attributes of this light
 * pre-condition: output stream is established
 * post-condition: no change to the light. all values are outputted
 */
void light_t::dump(ostream &outs)
{
   outs << "Light: " << name << endl;
   outs << "   location: " << location << endl;
   outs << "   emissivity: " << emissivity << endl;
}

void light_t::illuminate(list_tptr objs, object_tptr hitObj, drgb_t &pixel)
{
   vector_t dir;   // unit direction to light from hitpt
   vector_t N;     // unit direction from light to hitpt
   object_tptr obj;// closest object in dir to light
   double close;   // dist to closest object in dir to light
   double cos;     // of angle between normal and dir to light
   double dist;    // to the light from hitpoint
   double scalefactor;
   drgb_t diffuse; 
   /* Compute the distance from the hit to the light and
      a unit vector in the direction of the light from hitpt */

   vector_t hitLoc = hitObj->getHitLoc();
   vector_t temp = location-hitLoc;
   dist = temp->len();
   dir = location->unit();
   N = hitLoc->unit();
   
   /* Test the object for self-occlusion and return if occluded */

   if(

   /* Ask find_closest_object() if a ray fired toward the light hits a "regular" object.
      
      Pass "hitObj" as the "lastHit" parameter so it won't be hit again at distance 0.
      This step requires modification to the find_closest_object – add another parameter
      lastHitObj – which is a pointer to the last object hit. This object should be skipped
      when processing the list of objects in the find_closest_object function.
   */
// ..........
   /* If an object is hit and the distance to the hit is closer than the light is
      then the light is blocked by the hit object, return out of the function*/
// ............
   /* Arriving at this point means the light does illuminate the object.
   Ask hitobj->getdiff() to return diffuse reflectivity */
// .............
   /* Multiply componentwise the diffuse reflectivity by the emissivity of the light. */
// .............
   /* Scale the resulting diffuse reflectivity by cos/dist */
// ..............
   /* Add scaled value to pixel parameter. */
}
