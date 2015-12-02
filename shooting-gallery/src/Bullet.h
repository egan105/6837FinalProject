#ifndef BULLET_H_
#define BULLET_H_

#include <GL/glut.h>

class Bullet {
public:
	Bullet();
	void draw();
void step(int time);
private:
	GLuint listid;
	float loc[3];
};

#endif /*BULLET_H_*/
