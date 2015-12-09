#include <GLUT/glut.h>
#include <iostream>

#include "Stand.h"
#include "Target.h"

#define SLIDE_SCALE 250.0f

using namespace std;

Stand::Stand() {
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
	targets[0].location[0] = 202.2f;
	targets[0].location[1] = 148.6f;
	targets[0].location[2] = 202.2f;
	targets[0].color.r = 1.0f;
	targets[0].color.g = 0.0f;
	targets[0].color.b = 0.0f;
	targets[0].rotation = 0;

	targets[1].location[0] = 202.2f;
	targets[1].location[1] = 152.6f;
	targets[1].location[2] = 202.2f;
	targets[1].color.r = 0.2f;
	targets[1].color.g = 0.6f;
	targets[1].color.b = 1.0f;
	targets[1].rotation = 0;

	// targets[2].location[0] = 4.0f;
	// targets[2].location[1] = 1.75f;
	// targets[2].location[2] =  0.7f;
	// targets[2].color.r = 0.7f;
	// targets[2].color.g = 0.5f;
	// targets[2].color.b = 1.0f;
	// targets[2].rotation = 0;

	// targets[3].location[0] = -4.0f;
	// targets[3].location[1] = 1.75f;
	// targets[3].location[2] =  0.7f;
	// targets[3].color.r = 0.0f;
	// targets[3].color.g = 0.6f;
	// targets[3].color.b = 0.2f;
	// targets[3].rotation = 0;
}

void Stand::draw() {
	/* draw stand itself */
	glCallList(listid);

	/*
	 * go through each target, attach a name to it and
	 * if it is down, flip it down, otherwise draw it standing up.
	 */
	for(int i = 0; i < NUM_TARGETS; i++) {
		glLoadName(i);
		glPushMatrix();
			target_t *t = &targets[i];
			if(!t->isDown) {
				t->rotation = (t->rotation + 5) % 360;
				glTranslatef(t->location[0], t->location[1], t->location[2]);
				glRotatef(t->rotation, 0, 1, 0);
				glColor3f(t->color.r, t->color.g, t->color.b);
				t->target.draw();
			}

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
