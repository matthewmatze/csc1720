#include"model_t.h"

int table_lookup(const string table[], int len, const string &sv);
material_tptr material_search(list_tptr mats, const string& sname);

void image_create(model_tptr model);
void make_row(model_tptr model, int y);
void make_pixel(model_tptr model, int x, int y);
object_tptr find_closest_object(list_tptr objs, vector_t& base, vector_t& dir, double& mindist);
void ray_trace(model_tptr model, vector_t& base, vector_t& dir, drgb_t& dpix, double total_dist, object_tptr last_hit);

