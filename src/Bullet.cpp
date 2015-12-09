#include "Bullet.h"

#include <iostream>
#include <math.h>

using namespace std;

Bullet::Bullet(Camera *camera) {
	loc[0] = camera->location[0];
	loc[1] = camera->location[1];
	loc[2] = camera->location[2];

	float absolute = sqrt(pow(camera->lookAt[0] - loc[0], 2) + pow(camera->lookAt[1] - loc[1], 2) + pow(camera->lookAt[2] - loc[2], 2));
	dir[0] = (camera->lookAt[0] - loc[0]) / absolute;
	dir[1] = (camera->lookAt[1] - loc[1]) / absolute;
	dir[2] = (camera->lookAt[2] - loc[2]) / absolute;

	clock = 0;

	follow = false;
}

void Bullet::draw() {
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(loc[0] + 1.0f * dir[0], loc[1] + 1.0f * dir[1], loc[2] + 1.0f * dir[2]);
	glutSolidSphere(0.05f, 7.0f, 7.0f);
	glPopMatrix();

}

void Bullet::step(int time, float gscale, float wscale) {
    float dt = time / 10.0f;

	loc[0] += dt * dir[0];
	loc[1] += dt * dir[1];
	loc[2] += dt * dir[2];

	// Gravity and Wind
	loc[1] -= gscale * 0.001f * pow(clock / 30, 2);
	loc[0] += wscale * 0.001f * pow(clock / 30, 2);
	clock += dt;
}
