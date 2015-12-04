#include "Bullet.h"

#include <iostream>;

using namespace std;

Bullet::Bullet(Camera *camera) {
	loc[0] = camera->location[0];
	loc[1] = camera->location[1];
	loc[2] = camera->location[2];
	dir[0] = camera->lookAt[0];
	dir[1] = camera->lookAt[1];
	dir[2] = camera->lookAt[2];
	fixedX = loc[0];
	fixedY = loc[1];
}

void Bullet::draw() {
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.3);
	glTranslatef(loc[0], loc[1] ,loc[2] - 0.25f);
	glutSolidSphere(0.075f, 10.0f, 10.0f);
	glPopMatrix();
	
}

void Bullet::step(int time) {
	float total = abs(dir[0]) + abs(dir[1]);
	//loc[0] = fixedX;
	//loc[1] = fixedY;

	if(dir[0] > 0) {
		loc[0] += 0.5 * (time / 250.0f) * (dir[0] / total);
	}

	if(dir[1] > 0) {
		loc[1] += 0.5 * (time / 250.0f) * (dir[1] / total);
	}

	loc[2] -= (time / 250.0f);
}

