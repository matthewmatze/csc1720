#include"ray.h"
#include"vector_t.h"
#include"drgb_t.h"
#include"irgb_t.h"

#ifndef CAMERA_T
#define CAMERA_T

class camera_t
{  
   private:
      string name;
      vector_t view_point;    // viewpoint in world coordinates
      int pixel_dim[2];    // projection screen size in pixels 
      double world_dim[2]; // screen size in world coords
      irgb_t *pixmap;      // the pixel map for the image
   public:
      camera_t(){};
      camera_t(istream &ins);
      void getdir(int x, int y, vector_t &dir);
      void setpix(int x, int y, drgb_t *pix);
      int getxdim(void);
      int getydim(void);
      vector_t getviewpt(void);
      void dump(ostream &outs);
      void write_image(const char *image_filename);
   private:
      void load(istream &ins);
      void item_load(istream &ins, const string &attribute);
};


#endif
