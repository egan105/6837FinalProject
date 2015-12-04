#ifndef WORLD_H_
#define WORLD_H_

#include <GLUT/glut.h>
#include <vector>

#include "Bullet.h"
#include "Camera.h"
#include "Stand.h"

#define WORLD_MAX 50.0f

using namespace std;

class World {
public:
	World();
	virtual ~World();
	void draw();
	void step(int time);
	void shoot(Camera *camera);
	void reset();
private:
	GLuint listid;
	std::vector<Bullet*> bullets;
	Stand *stand;
};

#endif /*WORLD_H_*/
