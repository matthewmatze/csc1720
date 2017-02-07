#ifndef IRGB
#define IRGB

//for pixmap data
//0 means black and 255 means maximal brightness
class irgb_t
{
   public:
      unsigned char r;
      unsigned char g;
      unsigned char b;

      irgb_t()
      {
         r=g=b=0;
      }

      void dumper(FILE *out)
      {
         //fprintf(out,"%hhu\n%hhu\n%hhu\n",r,g,b);
         fprintf(out,"%c%c%c",r,g,b);
      }
};

#endif
