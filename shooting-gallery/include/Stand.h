#ifndef STAND_H_
#define STAND_H_

#include <GL/glut.h>

#include "Target.h"

#define NUM_TARGETS 4

/* encapsulate info about a target */
typedef struct {
	Target target;
	bool goingRight;
	bool isDown;
	float xOffset;
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
private:
	target_t targets[NUM_TARGETS];
	GLuint listid;
};

#endif /*STAND_H_*/
