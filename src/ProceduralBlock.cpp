#include "ProceduralBlock.h"

#include <math.h>
#include <vecmath.h>
#include <iostream>

using namespace std;

ProceduralBlock::ProceduralBlock(int size, int start_x, int start_z, int triangle_size) {

  initialized = false;

  num_points = (size / triangle_size) + 3;

  points = new Vector3f*[num_points*num_points];
  for (int x=0; x < num_points; x++) {
    for (int z=0; z < num_points; z++) {
      float height = generate_y(start_x + (x*triangle_size), start_z + (z*triangle_size));
      points[x*num_points + z] = new Vector3f(start_x + (x*triangle_size), height, start_z + (z*triangle_size));
    }
  }

  normals = new Vector3f*[num_points*num_points];
  for (unsigned int x = 1; x < num_points - 1; x++) {
    for (unsigned int z = 1; z < num_points - 1; z++) {
      normals[x*num_points + z] = calculate_normals(
        points[(x-1)*num_points + (z-1)], points[(x-1)*num_points + (z)], points[(x-1)*num_points + (z+1)],
        points[x*num_points + (z-1)],     points[x*num_points + z],       points[x*num_points + (z+1)],
        points[(x+1)*num_points + (z-1)], points[(x+1)*num_points + (z)], points[(x+1)*num_points + (z+1)]
      );
    }
  }
}

Vector3f get_cross(Vector3f* a, Vector3f* b, Vector3f* c) {
  Vector3f s_1 = Vector3f(a->x(), a->y(), a->z()) - Vector3f(c->x(), c->y(), c->z());
  Vector3f s_2 = Vector3f(b->x(), b->y(), b->z()) - Vector3f(c->x(), c->y(), c->z());

  return Vector3f::cross(s_1, s_2).normalized();
}

Vector3f* ProceduralBlock::calculate_normals(Vector3f* NW, Vector3f* N, Vector3f* NE,
                                   Vector3f* W,  Vector3f* C, Vector3f* E,
                                   Vector3f* SW, Vector3f* S, Vector3f* SE) {

  Vector3f normal = Vector3f::ZERO;
  normal += get_cross(NW, W, C);
  normal += get_cross(W, SW, C);
  normal += get_cross(SW, S, C);
  normal += get_cross(S, SE, C);
  normal += get_cross(SE, E, C);
  normal += get_cross(E, NE, C);
  normal += get_cross(NE, N, C);
  normal += get_cross(N, NW, C);

  normal = normal.normalized();
  return new Vector3f(-normal.x(), -normal.y(), -normal.z());
}

ProceduralBlock::~ProceduralBlock() {
  for (unsigned int x=0; x < num_points; x++) {
    for (unsigned int z=0; z < num_points; z++) {
      delete(points[x*num_points + z]);
    }
  }

  for (unsigned int x=0; x < num_points; x++) {
    for (unsigned int z=0; z < num_points; z++) {
      delete(normals[x*num_points + z]);
    }
  }
}

void ProceduralBlock::initialize() {
  glShadeModel(GL_SMOOTH);
  glColor3f(0.0f, 1.0f, 0.0f);
  glBegin(GL_TRIANGLES);

  for (unsigned int x = 1; x < num_points - 2; x++) {
    for (unsigned int z = 1; z < num_points - 2; z++) {
      // Top Triangle
      glNormal3f(normals[x*num_points + z]->x(), normals[x*num_points + z]->y(), normals[x*num_points + z]->z());
      glTexCoord2f(0.0f,0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(points[x*num_points + z]->x(), points[x*num_points + z]->y(), points[x*num_points + z]->z());

      glNormal3f(normals[(x+1)*num_points + z]->x(), normals[(x+1)*num_points + z]->y(), normals[(x+1)*num_points + z]->z());
      glTexCoord2f(0.0f,1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(points[(x+1)*num_points + z]->x(), points[(x+1)*num_points + z]->y(), points[(x+1)*num_points + z]->z());

      glNormal3f(normals[x*num_points + z + 1]->x(), normals[x*num_points + z + 1]->y(), normals[x*num_points + z + 1]->z());
      glTexCoord2f(1.0f,0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(points[x*num_points + z + 1]->x(), points[x*num_points + z + 1]->y(), points[x*num_points + z + 1]->z());

      // Bottom Triangle
      glNormal3f(normals[(x+1)*num_points + z]->x(), normals[(x+1)*num_points + z]->y(), normals[(x+1)*num_points + z]->z());
      glTexCoord2f(0.0f,1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(points[(x+1)*num_points + z]->x(), points[(x+1)*num_points + z]->y(), points[(x+1)*num_points + z]->z());

      glNormal3f(normals[(x+1)*num_points + z + 1]->x(), normals[(x+1)*num_points + z + 1]->y(), normals[(x+1)*num_points + z + 1]->z());
      glTexCoord2f(1.0f,1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(points[(x+1)*num_points + z + 1]->x(), points[(x+1)*num_points + z + 1]->y(), points[(x+1)*num_points + z + 1]->z());

      glNormal3f(normals[x*num_points + z + 1]->x(), normals[x*num_points + z + 1]->y(), normals[x*num_points + z + 1]->z());
      glTexCoord2f(1.0f,0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(points[x*num_points + z + 1]->x(), points[x*num_points + z + 1]->y(), points[x*num_points + z + 1]->z());
    }
  }

  glEnd();

  initialized = true;

}

bool ProceduralBlock::get_initialized() {
  return initialized;
}
