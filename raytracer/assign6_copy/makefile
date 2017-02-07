RAYOBJS = raytracer.o model_t.o  camera_t.o vector_t.o rayfunctions.o material_t.o light_t.o list_t.o object_t.o plane_t.o sphere_t.o fplane_t.o
RAYHDRS = model_t.h camera_t.h material_t.h irgb_t.h drgb_t.h vector_t.h rayhdrs.h ray.h light_t.h list_t.h object_t.h plane_t.h sphere_t.h fplane_t.h
rayTrace: $(RAYOBJS)
	g++ -Wall -g *.o -lm -o rayTrace
$(RAYOBJS): $(RAYHDRS) makefile
raytracer.o: raytracer.cpp 
	g++ -Wall -c -g raytracer.cpp
vector_t.o: vector_t.cpp vector_t.h
	g++ -Wall -c -g vector_t.cpp
model_t.o: model_t.cpp model_t.h ray.h
	g++ -Wall -c -g model_t.cpp
camera_t.o: camera_t.cpp camera_t.h ray.h
	g++ -Wall -c -g camera_t.cpp
material_t.o: material_t.cpp material_t.h
	g++ -Wall -c -g material_t.cpp
light_t.o: light_t.cpp light_t.h
	g++ -Wall -c -g light_t.cpp
list_t.o: list_t.cpp list_t.h
	g++ -Wall -c -g list_t.cpp
object_t.o: object_t.cpp object_t.h
	g++ -Wall -c -g object_t.cpp
plane_t.o: plane_t.cpp plane_t.h
	g++ -Wall -c -g plane_t.cpp
sphere_t.o: sphere_t.cpp sphere_t.h
	g++ -Wall -c -g sphere_t.cpp
fplane_t.o: fplane_t.cpp fplane_t.h
	g++ -Wall -c -g fplane_t.cpp
rayfunctions.o: rayfunctions.cpp rayhdrs.h
	g++ -Wall -c -g rayfunctions.cpp
clean:
	rm *.o rayTrace IMG.ppm
