#ifndef PROCEDURALBLOCK_H_
#define PROCEDURALBLOCK_H_

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Generator.h"
#include <vecmath.h>

class ProceduralBlock {
private:
    Vector3f** points;
    Vector3f** normals;

    int num_points;

    bool initialized;

public:
    ProceduralBlock(int size, int start_x, int start_z, int triangle_size);
    virtual ~ProceduralBlock();
    Vector3f* calculate_normals(
      Vector3f* NW, Vector3f* N, Vector3f* NE,
      Vector3f* W,  Vector3f* C, Vector3f* E,
      Vector3f* SW, Vector3f* S, Vector3f* SE
    );
    void initialize();
    bool get_initialized();
    GLuint listid;
};

#endif
