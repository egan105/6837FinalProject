#include "Bullet.h"

#include <iostream>
#include <math.h>

using namespace std;

Bullet::Bullet(Camera *camera) {
	loc[0] = camera->location[0];
	loc[1] = camera->location[1];
	loc[2] = camera->location[2];

	dir[0] = camera->lookAt[0] - loc[0];
	dir[1] = camera->lookAt[1] - loc[1];
	dir[2] = camera->lookAt[2] - loc[2];

	clock = 0;
}

void Bullet::draw() {
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(loc[0], loc[1] ,loc[2]);
	glutSolidSphere(0.05f, 7.0f, 7.0f);
	glPopMatrix();
	
}

void Bullet::step(int time) {
	float absolute = sqrt(pow(dir[0], 2) + pow(dir[1], 2) + pow(dir[2], 2));
    float dt = time / 125.0f;

	loc[0] += dt * dir[0] / absolute;
	loc[1] += dt * dir[1] / absolute;
	loc[2] += dt * dir[2] / absolute;

	// Gravity
	loc[1] -= 0.001f * pow(clock / 7, 2);
	clock += dt;



}

