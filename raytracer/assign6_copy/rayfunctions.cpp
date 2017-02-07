#include<string>
#include<iostream>
#include<limits.h>
#include"rayhdrs.h"

using namespace std;

/* table_lookup: the main purpose of this function is to reduce the
 *               size and complexity of the parsing the model
 * pre-condition: table contains a list of key words.  len is the number
 *                of key words in the table.  sv is the item of interest
 * post-condition: return the location of sv in the table.  if not
 *                 present, then return -1.
 */
int table_lookup(const string table[], int len, const string &sv)
{
   int i=0;
   bool found=false;
   while(i<len && !found){
      if(table[i] == sv)
         found = true;
      else
         i++;
   }
   if(found) 
      cerr << sv << " found at " << i << endl;
   else
      cerr << sv << " not found." << endl;
   return found?i:-1;
}

material_tptr material_search(list_tptr mats, const string& sname)
{
   material_tptr temp = (material_tptr)(mats->start());
   while(temp != NULL){
      if(temp->getname() == sname){
         return temp;
      }else{
         temp = (material_tptr)(mats->get_next());
      }
   }
   return NULL;
}

void image_create(model_tptr model){
   int y;
   //char filename[40];

   camera_tptr cam = model->cam;
   /* Fire ray(s) through each pixel in the window */
   for (y = cam->getydim()-1; y>=0; y--) {
      make_row(model, y);
   }
   /* Create ppm image */
   // call the write_image to output the image to a file named ____.ppm
   //cout<<"Please Enter the Desired File Name: ";
   //cin.getline(filename, 40, '\n');
   cam->write_image("IMG.ppm"); 
}

void make_row(model_tptr model, int y){
   int x;
   camera_tptr cam = model->cam;
   for (x = 0; x <=cam->getxdim()-1; x++) {
      make_pixel(model, x, y);
   }
}

void make_pixel(model_tptr model, int x, int y){
   vector_t raydir, viewpoint;
   drgb_t dpix; //note the default constructor gets call to set x=y=z=0 in dpix.
   camera_tptr cam = model->cam;
   raydir = cam->getdir(x, y);
   viewpoint = cam->getviewpt();
   
    /* The ray_trace function determines the pixel color in for the pixel located at (x,y)
     * on the screen. Upon return from the ray_trace call, dpix will be set to the color in
     * d_rgb units of the pixel at location (x,y). The last two parameters are used ONLY
     * in the case of specular (bouncing) rays which we are not doing yet. */
   ray_trace(model, viewpoint, raydir, dpix, 0.0, NULL);
   
    /* This function must convert the pixel value, dpix, from drgb_t [0.0, 1.0] to
     * irgb_t (0, 255) and store it in the “upside down” location in the pixmap */
   cam->setpix(x, y, dpix);
}

object_tptr find_closest_object(list_tptr objs, vector_t& base, vector_t& dir, double& mindist){
   
   double curdist;
   object_tptr curobj = NULL;

   object_tptr temp = (object_tptr)(objs->start());
   while(temp != NULL){
      curdist = temp->hits(base, dir);
      if(curdist > 0 && curdist < mindist)
      {
         mindist = curdist;
         curobj = temp;
      }
      temp = (object_tptr)(objs->get_next());   
   }
   return curobj;
}

void ray_trace(model_tptr model, vector_t& base, vector_t& dir, drgb_t& dpix, double total_dist, object_tptr last_hit){
 /* This function traces a single ray and returns the composite intensity of the light it encounters 
  * base - location of viewer or previous hit
  * dir - unit vector in direction of object
  * dpix - pixel return location
  * total_dist - distance ray has traveled so far
  * last_hit - most recently hit object
*/

   object_tptr closest;
   double mindist = INT_MAX;
   drgb_t thisray;

   closest = find_closest_object(model->objs, base, dir, mindist);
   if(closest != NULL)
   {
      thisray = closest->getamb();
   //scale the values of “thisray” by 1 / distance to the closest object
      thisray = thisray*(1/mindist);
   }
   //add the value of “thisray” to dpix
   dpix = thisray;
}

