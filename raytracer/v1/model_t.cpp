#include"model_t.h"

/* construct a model - initial the model data
 * pre-condition: the input stream to the data has been established
 *                nothing has been read from the stream 
 * post-condition: all entities associated with the model has been loaded
 */
model_t::model_t(istream &ins)
{
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

   ndx = table_lookup(entities, NUM_ENTITIES, entity);
   switch(ndx) {
      case CAMERA_ENT: cam = new camera_t(ins);
                   break;
   }
}

/* model_dump - output all of the entities and attributes of the model
 * pre-condition: some or all of the model has been loaded
 * post-condition: nothing in the model is altered. 
 *
 */
void model_t::dump(ostream &outs)
{
   cam->dump(outs);
}

