//#include"material_t.h"
#include"rayhdrs.h"

/* constructor: initialize a material
 * pre-condition: The input stream has been established and the
 *                the word material is read by the model
 * post-condition: material name and attributes are loaded
 */
material_t::material_t(istream &ins)
{
   string brace;

   ins >> name;
   ins >> brace;

   load(ins);
   
   //pixmap....dynamically setup the pixmap - later....
}

/* load: iterates through material attributes and call item-load
 * pre-condition: the { has been read in and the input stream is established
 * post-condition: the } is read in and the camera is completely loaded
 */
void material_t::load(istream &ins)
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
void material_t::item_load(istream &ins, const string &attribute)
{
   int ndx;
   ndx = table_lookup(attributes, NUM_ATTRIBUTES, attribute);
   switch(ndx) {

      case AMBIENT_ATT:
         ins>>ambient;
         break;

      case DIFFUSE_ATT:
         ins>>diffuse;
         break;

      case SPECULAR_ATT:
         ins>>specular;
         break;
   }
}

/* getamb:
 * pre-condition:
 * post-condition:
 */
drgb_t material_t::getamb(void){
   return ambient;
}

/* getdif:
 * pre-condition:
 * post-condition:
 */
drgb_t material_t::getdif(void){
   return diffuse;
}

/* getspec:
 * pre-condition:
 * post-condition:
 */
drgb_t material_t::getspec(void){
   return specular;
}

/* getname:
 * pre-condition:
 * post-condition:
 */
string material_t::getname(void){
   return name;
}

/* dump: outputs the name and all the attributes of this material
 * pre-condition: output stream is established
 * post-condition: no change to material. all values are outputted
 */
void material_t::dump(ostream &outs)
{
   outs << "Material: " << name << endl;
   outs << "   ambient: " << ambient << endl;
   outs << "   diffuse: " << diffuse << endl;
   outs << "   specular: " << specular << endl;
}
