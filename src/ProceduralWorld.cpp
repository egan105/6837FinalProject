#include "ProceduralWorld.h"
#include <iostream>

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define DRAW_SEGMENTS 16
#define SEGMENT_SIZE 120
#define TRIANGLE_SIZE 3

using namespace std;

ProceduralWorld::ProceduralWorld(int world_size, Camera* camera) {
    this->camera = camera;
    num_segments = world_size;
    shift = (SEGMENT_SIZE * world_size)/2;

    block_is_visible = new bool[num_segments*num_segments];
    for (unsigned int x=0; x < num_segments; x++) {
      for (unsigned int z=0; z < num_segments; z++) {
        block_is_visible[x * num_segments + z] = false;
      }
    }

    blocks = new ProceduralBlock*[num_segments*num_segments];
    for (unsigned int x=0; x < num_segments; x++) {
      for (unsigned int z=0; z < num_segments; z++) {
        blocks[x * num_segments + z] = NULL;
      }
    }
}

ProceduralWorld::~ProceduralWorld() {
    for (unsigned int i = 0; i < num_segments; i++) {
      for (unsigned int j = 0; j < num_segments; j++) {
        delete (blocks[i * num_segments + j]);
      }
    }
    delete (blocks);
}

void ProceduralWorld::reset_table() {
  for (unsigned int x=0; x < num_segments; x++) {
    for (unsigned int z=0; z < num_segments; z++) {
      block_is_visible[x * num_segments + z] = false;
    }
  }
}

int ProceduralWorld::get_block_coordinate(int point) {
  return ((int) fmax(0, point + shift)) / SEGMENT_SIZE;
}

void ProceduralWorld::initialize_new_blocks() {
  reset_table();

  int closest_x_block = get_block_coordinate((int) camera->x());
  int closest_z_block = get_block_coordinate((int) camera->z());

  int x_start = (int) fmax(0, closest_x_block - (DRAW_SEGMENTS/2));
  int z_start = (int) fmax(0, closest_z_block - (DRAW_SEGMENTS/2));

  int x_end = (int) fmin(num_segments-1, closest_x_block + (DRAW_SEGMENTS/2));
  int z_end = (int) fmin(num_segments-1, closest_z_block + (DRAW_SEGMENTS/2));

  for (unsigned int x=x_start; x < x_end; x++) {
    for (unsigned int z=z_start; z < z_end; z++) {
      block_is_visible[x * num_segments + z] = true;
      ProceduralBlock* current_block = blocks[x*num_segments + z];
      if (current_block == NULL) {
        blocks[x*num_segments + z] = new ProceduralBlock(SEGMENT_SIZE, x*(SEGMENT_SIZE)-shift, z*(SEGMENT_SIZE)-shift, TRIANGLE_SIZE);
        current_block = blocks[x*num_segments + z];
      }
      if (!current_block->get_initialized()) {
        current_block->listid = glGenLists(1);
        glNewList(current_block->listid, GL_COMPILE);
        current_block->initialize();
        glEndList();
      }
    }
  }
}

void ProceduralWorld::delete_distant_blocks() {
  for (unsigned int x=0; x < num_segments; x++) {
    for (unsigned int z=0; z < num_segments; z++) {
      if (!block_is_visible[x * num_segments + z]) {
        ProceduralBlock* current_block = blocks[x*num_segments + z];
        blocks[x*num_segments + z] = NULL;
      }
    }
  }
}

void ProceduralWorld::draw() {
    for (unsigned int x=0; x < num_segments; x++) {
      for (unsigned int z=0; z < num_segments; z++) {
        //cout << block_is_visible[x*num_segments + z] << endl;
        if (block_is_visible[x*num_segments + z]) {
          ProceduralBlock* current_block = blocks[x*num_segments + z];
          if (current_block->get_initialized()) {
            glCallList(current_block->listid);
          }
        }
      }
    }
}
