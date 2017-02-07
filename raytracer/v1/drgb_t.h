#ifndef DRGB
#define DRGB
//for lights and reflective materials, 
//0.0 means black and 1.0 means maximal brightness
class drgb_t
{
   public:
      double r;
      double g;
      double b;
      drgb_t()
      {
         r=g=b=0;
      }
      void dumper(char * msg)
      {
         fprintf(stdout,"drgb: %s %lf %lf %lf\n",msg,r,g,b);
      }
};
#endif
