#include"rayhdrs.h"
#include<fstream>

/* constructor: initialize a camera
 * pre-condition: The input stream has been established and the
 *                the word camera is read by the model
 * post-condition: camera name and attributes are loaded
 */
camera_t::camera_t(istream &ins)
{
   string brace;

   ins >> name;
   ins >> brace;

   load(ins);
   
   pixmap = new irgb_t[pixel_dim[0]*pixel_dim[1]]; 
}

/* load: iterates through camera attributes and call item-load
 * pre-condition: the { has been read in and the input stream is established
 * post-condition: the } is read in and the camera is completely loaded
 */
void camera_t::load(istream &ins)
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
void camera_t::item_load(istream &ins, const string &attribute)
{
   int ndx;
  
   ndx = table_lookup(attributes, NUM_ATTRIBUTES, attribute);
   switch(ndx) {

      case PIXELDIM_ATT:
         ins >> pixel_dim[0];
         ins >> pixel_dim[1];
         break;

      case WORLDDIM_ATT:
         ins >> world_dim[0];
         ins >> world_dim[1];
         break;

      case VIEWPOINT_ATT:
         ins >> view_point;
         break;
   }
}

/* getxdim:
 * pre-condition:
 * post-condition:
 */
int camera_t::getxdim(void)
{
   return pixel_dim[0];
}

/* getydim:
 * pre-condition:
 * post-condition:
 */
int camera_t::getydim(void)
{
   return pixel_dim[1];
}

/* getviewpt:
 * pre-condition:
 * post-condition:
 */
vector_t camera_t::getviewpt(void)
{
   return view_point;
}

/* dump:
 * pre-condition:
 * post-condition:
 */
void camera_t::dump(ostream &outs)
{
   outs << "Camera: " << name << endl;
   outs << "   pixeldim: " << pixel_dim[0] << " " << pixel_dim[1] << endl;
   outs << "   worlddim: " << world_dim[0] << " " << world_dim[1] << endl;
   outs << "   viewpoint: " << view_point << endl;
}

/* getdir:
 * pre-condition:
 * post-condition:
 */
vector_t camera_t::getdir(int x, int y)
{
   double wx = world_dim[0]*x/(pixel_dim[0]-1);
   double wy = world_dim[1]*y/(pixel_dim[1]-1);
   double wz = 0.0;

   //cerr<< wx<<" "<<wy<<" "<<wz<<endl;
   vector_t pixelloc = vector_t(wx, wy, wz);

   vector_t ray = (pixelloc-view_point);
   return ray.unit();
}

/* setpix:
 * pre-condition:
 * post-condition:
 */
void camera_t::setpix(int x, int y, drgb_t& d_pix)
{
   irgb_t i_pix; 

   i_pix = scale_and_clamp(d_pix);
   
   int offset = ((pixel_dim[1]-y-1)*pixel_dim[0] + x);
   *(pixmap+offset) = i_pix;
}


irgb_t camera_t::scale_and_clamp(drgb_t& d_pix)
{
   irgb_t i_pix;
   int temp;

   temp = (d_pix.r*255);
   if(temp>0 && temp<255)
      i_pix.r = (unsigned char) temp;
   else if(temp<0)
      i_pix.r = 0;
   else if(temp>255)
      i_pix.r = 255;

   temp = (d_pix.g*255);
   if(temp>0 && temp<255)
      i_pix.g = (unsigned char) temp;
   else if(temp<0)
      i_pix.g = 0;
   else if(temp>255)
      i_pix.g = 255;
   
   temp = (d_pix.b*255);
   if(temp>0 && temp<255)
      i_pix.b = (unsigned char) temp;
   else if(temp<0)
      i_pix.b = 0;
   else if(temp>255)
      i_pix.b = 255;

   return i_pix;
}

/* write_image:
 * pre-condition:
 * post-condition:
 */
void camera_t::write_image(const char *image_filename)
{
   ofstream outs;
   outs.open(image_filename);
   if(outs.fail()) {
      cerr << "Problems creating image file: " << image_filename << endl;
      exit(1); 
   } else {
      outs << "P6" << endl;
      outs << "#Created by ReZa, MaTt, DaViD raytracing program!" << endl;
      outs << pixel_dim[0] << " " << pixel_dim[1] << endl;
      outs << "255" << endl;;
      outs.write((char*)pixmap,(sizeof(irgb_t)*pixel_dim[0]*pixel_dim[1]));
      outs.close(); 
   }
}

