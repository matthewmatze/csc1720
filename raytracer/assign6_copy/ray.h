#include<iostream>
#include<fstream>
#include<cassert>
#include<cstdlib>

using namespace std;

#ifndef ENTITIES
#define ENTITIES
enum entity_type {CAMERA_ENT, LIGHT_ENT, MATERIAL_ENT, PLANE_ENT, SPHERE_ENT, FINITE_PLANE_ENT};

const string entities[] =
{
   "camera",
   "light",
   "material",
   "plane",
   "sphere",
   "finite_plane"
};

#define NUM_ENTITIES (sizeof(entities) / sizeof(entities[0]))
#endif

#ifndef ATTRIBUTES
#define ATTRIBUTES
enum attribute_type {PIXELDIM_ATT, WORLDDIM_ATT, VIEWPOINT_ATT, AMBIENT_ATT, DIFFUSE_ATT, SPECULAR_ATT, LOCATION_ATT, EMISSIVITY_ATT, NORMAL_ATT, POINT_ATT, CENTER_ATT, RADIUS_ATT, XDIR_ATT, DIMENSION_ATT};

const string attributes[] =
{
   "pixeldim",
   "worlddim",
   "viewpoint",
   "ambient",
   "diffuse",
   "specular",
   "location",
   "emissivity",
   "normal",
   "point",
   "center",
   "radius",
   "xdir",
   "dimension"
};

#define NUM_ATTRIBUTES (sizeof(attributes) / sizeof(attributes[0]))
#endif
