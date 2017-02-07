#include"ray.h"
#include"model_t.h"

int main(int argc, char *argv[])
{
   model_tptr model = new model_t(cin);

   //load and dump model
   model->dump(cout);

   //raytrace the image

   return 0;
}

