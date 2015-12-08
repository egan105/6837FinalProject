#ifndef PROCEDURALWORLD_H_
#define PROCEDURALWORLD_H_

#include "ProceduralBlock.h"
#include "Camera.h"

class ProceduralWorld {
private:
    // Number of segments along a single
    //    axis of the terrain
    int num_segments;

    // A lookup for the visible sections of the map
    bool* block_is_visible;

    // Contains all of the sections of the
    //    procedurally built terrain
    ProceduralBlock** blocks;

    Camera* camera;

public:
    ProceduralWorld(int world_size);
    virtual ~ProceduralWorld();
    void initialize_new_blocks();
    void draw();
};

#endif
