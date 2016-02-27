#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GL/freeglut.h"
#include "GL/gl.h"

typedef struct vertex_points
{
    float x;
    float y;
    float z;
}vertex;

int main(int argc, char** argv);
void drawTriangle();
void init_rendering();
int recurse_triangles(vertex* point, const vertex &a, const vertex &b, const vertex &c, int iteration);
int half_way(vertex* point, const vertex &a, vertex &new_point);


