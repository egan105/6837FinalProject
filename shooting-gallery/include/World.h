#ifndef WORLD_H_
#define WORLD_H_

#include <GL/glut.h>

#include "Stand.h"

#define WORLD_MAX 50.0f

class World {
public:
	World();
	virtual ~World();
	void draw();
	void step(int time);
	void shoot(int targetId);
	void reset();
private:
	GLuint listid;
	Stand *stand;
};

#endif /*WORLD_H_*/
