#include "Bullet.h"

Bullet::Bullet() {
	/*
	 * draw basic shape of target to a display list
	 */
	loc[0] = 0.0f;
	loc[1] = 1.0f;
	loc[2] = 10.0f;
}

void Bullet::draw() {
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.1);
	glTranslatef(0.0f, 1.0f ,loc[2]);
	glutSolidSphere(0.075f, 10.0f, 10.0f);
	glPopMatrix();
	
}

void Bullet::step(int time) {
	loc[2] -= time / 250.0f;
}

