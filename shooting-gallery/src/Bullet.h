#ifndef BULLET_H_
#define BULLET_H_

//#include <GL/glut.h>
#include <GLUT/glut.h>
#include "Camera.h"

class Bullet {
public:
	Bullet(Camera *camera);
	void draw();
    void step(int time);
private:
	float loc[3];
	float dir[3];
	float fixedX;
	float fixedY;
};

#endif /*BULLET_H_*/

