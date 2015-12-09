#ifndef WORLD_H_
#define WORLD_H_

#include <GLUT/glut.h>
#include <vector>

#include "Camera.h"
#include "Bullet.h"
#include "Camera.h"
#include "Stand.h"
#include "ParticleSystem.h"

#define WORLD_MAX 600.0f

using namespace std;

class World {
public:
	World(Camera* camera);
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
	vector<ParticleSystem *> particleSystems;
	float gscale =1.0f;
	float wscale =0.0f;
	Camera* camera;
};

#endif /*WORLD_H_*/
