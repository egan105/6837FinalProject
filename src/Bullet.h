#ifndef BULLET_H_
#define BULLET_H_

//#include <GL/glut.h>
#include <GLUT/glut.h>
#include "Camera.h"

class Bullet {
public:
	Bullet(Camera *camera);
	void draw();
    void step(int time, float g, float w);
    float loc[3];
    bool follow;
    int rotation;
private:
	float dir[3];
	float clock;
	float wscale;
};

#endif /*BULLET_H_*/

