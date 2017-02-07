#include"rayhdrs.h"

/* construct a model - initial the model data
 * pre-condition: the input stream to the data has been established
 *                nothing has been read from the stream 
 * post-condition: all entities associated with the model has been loaded
 */
model_t::model_t(istream &ins)
{

   mats = new list_t;
   lgts = new list_t;
   objs = new list_t;

   //Read in the camera, materials, objects, lights
   load(ins);

}

/* load - load all items into the model
 * pre-condition: the input stream to the data has been established
 *                nothing has been read from the stream 
 * post-condition: All entities have been loaded
 */
void model_t::load(istream &ins)
{
   string entity;
   
   //Here entity_type should be one of "camera", "material", etc
   ins >> entity;
   while(!ins.eof()) {
      item_load(ins,entity);
      ins >> entity;
   } 
}

/* item_load - load a specific entity in the model 
 * pre-condition: the entity type has been read from the stream and
 *                the entity name and attributes are next 
 * post-condition: the entity name and attributes have been read into the model
 */
void model_t::item_load(istream &ins, const string &entity)
{
   int ndx;
   material_tptr matptr;
   light_tptr litptr;
   object_tptr objptr;

   ndx = table_lookup(entities, NUM_ENTITIES, entity);
   switch(ndx) {

      case CAMERA_ENT:
         cam = new camera_t(ins);
         break; 
      
      case MATERIAL_ENT:
         matptr = new material_t(ins);
         assert(matptr != NULL);
         mats->insert((void*)matptr);          
         break;
      
      case LIGHT_ENT:
         litptr = new light_t(ins);
         lgts->insert((void*)litptr);
         break;

      case PLANE_ENT:
         objptr = new plane_t(ins, mats);
         objs->insert((void*)objptr);
         break;

      case SPHERE_ENT:
         objptr = new sphere_t(ins, mats);
         objs->insert((void*)objptr);
         break;

      case FINITE_PLANE_ENT:
         objptr = new fplane_t(ins, mats);
         objs->insert((void*)objptr);
         break;    
   }
}

/* model_dump - output all of the entities and attributes of the model
 * pre-condition: some or all of the model has been loaded
 * post-condition: nothing in the model is altered. 
 */
void model_t::dump(ostream &outs)
{
   cam->dump(outs);
   
   material_tptr temp = (material_tptr)(mats->start());
   while(temp != NULL){
      temp->dump(outs);
      temp = (material_tptr)(mats->get_next());
   }
   
   light_tptr tmp = (light_tptr)(lgts->start());
   while(tmp != NULL){
      tmp->dump(outs);
      tmp = (light_tptr)(lgts->get_next());
   }

   object_tptr ocurptr = (object_tptr)(objs->start());
   while(ocurptr != NULL){
      ocurptr->dump(outs);
      ocurptr = (object_tptr)(objs->get_next());
   }
}

