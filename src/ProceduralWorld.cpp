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

ProceduralWorld::ProceduralWorld(int world_size) {

    num_segments = world_size;

    block_is_visible = new bool[num_segments*num_segments];
    for (unsigned int x=0; x < num_segments; x++) {
      for (unsigned int z=0; z < num_segments; z++) {
        block_is_visible[x * num_segments + z] = true;
      }
    }

    int shift = (SEGMENT_SIZE*world_size)/2;
    blocks = new ProceduralBlock*[num_segments*num_segments];
    for (unsigned int x=0; x < num_segments; x++) {
      for (unsigned int z=0; z < num_segments; z++) {
        blocks[x * num_segments + z] = new ProceduralBlock(SEGMENT_SIZE, x*(SEGMENT_SIZE)-shift, z*(SEGMENT_SIZE)-shift, TRIANGLE_SIZE);
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

void ProceduralWorld::initialize_new_blocks() {
  for (unsigned int x=0; x < num_segments; x++) {
    for (unsigned int z=0; z < num_segments; z++) {
      ProceduralBlock* current_block = blocks[x*num_segments + z];
      if (current_block != NULL && !current_block->get_initialized()) {
        current_block->listid = glGenLists(1);
        glNewList(current_block->listid, GL_COMPILE);
        current_block->initialize();
        glEndList();
      }
    }
  }
}


void ProceduralWorld::draw() {
    for (unsigned int x=0; x < num_segments; x++) {
      for (unsigned int z=0; z < num_segments; z++) {
        if (block_is_visible[x*num_segments + z]) {
          ProceduralBlock* current_block = blocks[x*num_segments + z];
          glCallList(current_block->listid);
        }
      }
    }
}
