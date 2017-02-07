#include<iostream>
#include<fstream>
#include<cassert>
#include<cstdlib>

using namespace std;

#ifndef ENTITIES
#define ENTITIES
enum entity_type {CAMERA_ENT, LIGHT_ENT, MATERIAL_ENT, PLANE_ENT};

const string entities[] =
{
   "camera",
   "light",
   "material",
   "plane"
};

#define NUM_ENTITIES (sizeof(entities) / sizeof(entities[0]))
#endif

#ifndef ATTRIBUTES
#define ATTRIBUTES
enum attribute_type {PIXELDIM_ATT, WORLDDIM_ATT, VIEWPOINT_ATT};

const string attributes[] =
{
   "pixeldim",
   "worlddim",
   "viewpoint"
};

#define NUM_ATTRIBUTES (sizeof(attributes) / sizeof(attributes[0]))
#endif

#include"rayhdrs.h"
