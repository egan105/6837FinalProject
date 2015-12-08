#ifndef WORLD_H_
#define WORLD_H_

#include <GL/glut.h>
//#include <GLUT/glut.h>
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
	bool inWorld(Bullet *b);
	void adjustWind(float t,bool zero);
	void adjustGravity(float t);
private:
	GLuint listid;
	std::vector<Bullet*> bullets;
	std::vector<int> indices;
	Stand *stand;
	float gscale =1.0f;
	float wscale =0.0f;
};

#endif /*WORLD_H_*/
