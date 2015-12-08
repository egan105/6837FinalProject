#include <GL/glut.h>
//#include <GLUT/glut.h>
#include <iostream>

#include "Stand.h"
#include "Target.h"

#define SLIDE_SCALE 250.0f

using namespace std;

Stand::Stand() {
	/*
	 * draw basic shape of stand via primitives to a display list
	 */
	listid = glGenLists(1);
	glNewList(listid, GL_COMPILE);
		glColor3f(0.2f, 0.2f, 0.8f);
		glPushMatrix();
			glTranslatef(-5.0f, 0.25f, 0.0f);
			glScalef(0.5f, 1.0f, 1.0f);
			glutSolidCube(0.5f);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(5.0f, 0.25f, 0.0f);
			glScalef(0.5f, 1.0f, 1.0f);
			glutSolidCube(0.5f);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0f, 0.5f, 0.0f);
			glScalef(20.501f, 0.5f, 1.0f);
			glutSolidCube(0.5f);
		glPopMatrix();
	glEndList();

	/*
	 * initialize all of the targets to sane values
	 */
	targets[0].isDown = false;
	targets[1].isDown = false;
	targets[2].isDown = false;
	targets[3].isDown = false;
	targets[0].radius = 1.0f;
	targets[1].radius = 1.0f;
	targets[2].radius = 1.0f;
	targets[3].radius = 1.0f;

	targets[0].goingRight = false;
	targets[0].location[0] = -1.5f;
	targets[0].location[1] = 1.75f;
	targets[0].location[2] =  0.7f;
	targets[0].color.r = 0.6f;
	targets[0].color.g = 0.3f;
	targets[0].color.b = 0.0f;

	targets[1].goingRight = true;
	targets[1].location[0] = 1.5f;
	targets[1].location[1] = 1.75f;
	targets[1].location[2] =  0.7f;
	targets[1].color.r = 0.2f;
	targets[1].color.g = 0.6f;
	targets[1].color.b = 1.0f;

	targets[2].goingRight = true;
	targets[2].location[0] = 4.0f;
	targets[2].location[1] = 1.75f;
	targets[2].location[2] =  0.7f;
	targets[2].color.r = 0.7f;
	targets[2].color.g = 0.5f;
	targets[2].color.b = 1.0f;

	targets[3].goingRight = false;
	targets[3].location[0] = -4.0f;
	targets[3].location[1] = 1.75f;
	targets[3].location[2] =  0.7f;
	targets[3].color.r = 0.0f;
	targets[3].color.g = 0.6f;
	targets[3].color.b = 0.2f;
}

void Stand::draw() {
	/* draw stand itself */
	glCallList(listid);

	/* 
	 * go through each target, attach a name to it and 
	 * if it is down, flip it down, otherwise draw it standing up.
	 */
	for(short i = 0; i < NUM_TARGETS; i++) {
		glLoadName(i);
		glPushMatrix();
			target_t *t = &targets[i];
			glColor3f(t->color.r, t->color.g, t->color.b);
			if(t->isDown) {
				glRotatef(-90, 1, 0, 0); /* TODO This is bad */
				glTranslatef(t->location[0], t->location[1], t->location[2]);
			} else {
				glTranslatef(t->location[0], t->location[1], t->location[2]);
			}
			t->target.draw();
		glPopMatrix();
		glPopName();
	}
}

void Stand::step(int time) {
	/*
	 * move each target through the +/- 5 unit sweep
	 */
	// for(short i = 0; i < NUM_TARGETS; i++) {
	// 	target_t *t = &targets[i];
	// 	if(t->location[0] >= 5) {
	// 		t->goingRight = false;
	// 	} else if(t->location[0] <= -5) {
	// 		t->goingRight = true;
	// 	}
	// 	t->location[0] += ((float) t->goingRight ? time : -time) / SLIDE_SCALE;
	// }
}
