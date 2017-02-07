/* Team: Reza Moghtaderi, Matt Matze, David Friedman
 * Date: March 29, 2014
 * Class: CSC1720
 * Location: /home/students/rmoghtaderi/csc1720/assign6
 *
 * Description: This is a ray-tracing project in the making!
 * It reads materials, lights, planes, spheres and finite planes
 * from the scene file and store them in three (materials, lights,
 * objects) lists using void pointers. Then, the program will output
 * the information read, to the outstream.
 */


//#include"ray.h"
#include"rayhdrs.h"
//#include"model_t.h"

int main(int argc, char *argv[])
{
   model_tptr model = new model_t(cin);

   //load and dump model
   model->dump(cerr);

   //raytrace the image
   image_create(model);

   return 0;
}

