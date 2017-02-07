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
