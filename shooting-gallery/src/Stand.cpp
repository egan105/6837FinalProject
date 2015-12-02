#include <GL/glut.h>

#include "Stand.h"
#include "Target.h"

#define SLIDE_SCALE 250.0f

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

	targets[0].goingRight = false;
	targets[0].xOffset = -0.5;
	targets[0].color.r = 0.6f;
	targets[0].color.g = 0.3f;
	targets[0].color.b = 0.0f;

	targets[1].goingRight = true;
	targets[1].xOffset = 0.5;
	targets[1].color.r = 0.2f;
	targets[1].color.g = 0.6f;
	targets[1].color.b = 1.0f;

	targets[2].goingRight = true;
	targets[2].xOffset = 4.0;
	targets[2].color.r = 0.7f;
	targets[2].color.g = 0.5f;
	targets[2].color.b = 1.0f;

	targets[3].goingRight = false;
	targets[3].xOffset = -4.0;
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
			float zFightFix = (float) -i / 20.0f;
			if(t->isDown) {
				glRotatef(-90, 1, 0, 0); /* TODO This is bad */
				glTranslatef(t->xOffset, 1.20f, 0.7f + zFightFix);
			} else {
				glTranslatef(t->xOffset, 1.75f, zFightFix);
			}
			t->target.draw();
		glPopMatrix();
	}
	glPopName();
}

void Stand::step(int time) {
	/*
	 * move each target through the +/- 5 unit sweep
	 */
	for(short i = 0; i < NUM_TARGETS; i++) {
		target_t *t = &targets[i];
		if(t->xOffset >= 5) {
			t->goingRight = false;
		} else if(t->xOffset <= -5) {
			t->goingRight = true;
		}
		t->xOffset += ((float) t->goingRight ? time : -time) / SLIDE_SCALE;
	}
}

void Stand::shoot(int targetId) {
	/* if we hit something in the range, knock it down */
	if(targetId >= 0 && targetId <= 3) {
		targets[targetId].isDown = true;
	}
}

void Stand::reset() {
	targets[0].isDown = false;
	targets[1].isDown = false;
	targets[2].isDown = false;
	targets[3].isDown = false;
}
