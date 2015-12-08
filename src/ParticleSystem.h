#ifndef PARTICLESYSTEM_H_
#define PARTICLESYSTEM_H_

#include <GLUT/glut.h>
#include <vector>

using namespace std;

#define NUM_PARTICLES 1000
#define NUM_DEBRIS 70

/* encapsulate info about a particle */
typedef struct {
	float position[3];
	float speed[3];
	float color[3];
} particle;

/* debris*/
typedef struct {
	float position[3];
	float speed[3];
	float orientation[3];
	float orientationSpeed[3];
	float color[3];
	float scale[3];
} debrisData;

class ParticleSystem {
public:
	ParticleSystem();
	void newSpeed(float destination[3]);
	void newExplosion(float pos[3]);
	void draw();
	void step();
	int getFuel();
private:
	particle particles[NUM_PARTICLES];
	debrisData debris[NUM_DEBRIS];
	int fuel;
	float angle;
};

#endif /*PARTICLESYSTEM_H_*/
