#ifndef STAND_H_
#define STAND_H_

#include <GLUT/glut.h>

#include "Target.h"

#define NUM_TARGETS 4

/* encapsulate info about a target */
typedef struct {
	Target target;
	bool goingRight;
	bool isDown;
	float xOffset;
	float radius;
	float location[3];
	struct color_t {
		GLfloat r, g, b;
	} color;
} target_t;

/*
 * A simple boxy stand for targets
 */
class Stand {
public:
	Stand();
	void draw();
	void step(int time);
	void shoot(int targetId);
	void reset();
	target_t targets[NUM_TARGETS];
private:
	
	GLuint listid;
};

#endif /*STAND_H_*/
