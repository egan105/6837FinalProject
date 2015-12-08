#include <math.h>
#include <iostream>
#include <GLUT/glut.h>

#include "ParticleSystem.h"

using namespace std;

ParticleSystem::ParticleSystem() {
	fuel = 0;
	angle = 0.0;
}

void ParticleSystem::newSpeed(float destination[3]) {
	float x, y, z;
	float len;

	x = (2.0 * ((GLfloat) rand ()) / ((GLfloat) RAND_MAX)) - 1.0;
	y = (2.0 * ((GLfloat) rand ()) / ((GLfloat) RAND_MAX)) - 1.0;
	z = (2.0 * ((GLfloat) rand ()) / ((GLfloat) RAND_MAX)) - 1.0;

	len = sqrt (x * x + y * y + z * z);

	if (len)
	{
		x = x / len;
		y = y / len;
		z = z / len;
	}

	destination[0] = x * 0.5;
	destination[1] = y * 0.5;
	destination[2] = z * 0.5;
}

void ParticleSystem::newExplosion(float pos[3]) {
	for(int i = 0; i < NUM_PARTICLES; i++) {
		particles[i].position[0] = pos[0];
		particles[i].position[1] = pos[1];
		particles[i].position[2] = pos[2];

		particles[i].color[0] = 1.0;
		particles[i].color[1] = 1.0;
		particles[i].color[2] = 0.5;

		newSpeed(particles[i].speed);
	}

	for(int j = 0; j < NUM_DEBRIS; j++) {
		debris[j].position[0] = pos[0];
		debris[j].position[1] = pos[1];
		debris[j].position[2] = pos[2];

		debris[j].orientation[0] = 0.0;
		debris[j].orientation[1] = 0.0;
		debris[j].orientation[2] = 0.0;

		debris[j].color[0] = 0.7;
		debris[j].color[1] = 0.7;
		debris[j].color[2] = 0.7;

		debris[j].scale[0] = (2.0 * (GLfloat) rand()) / (GLfloat) RAND_MAX - 1.0;
		debris[j].scale[1] = (2.0 * (GLfloat) rand()) / (GLfloat) RAND_MAX - 1.0;
		debris[j].scale[2] = (2.0 * (GLfloat) rand()) / (GLfloat) RAND_MAX - 1.0;

		newSpeed(debris[j].speed);
		newSpeed(debris[j].orientationSpeed);
	}

	fuel = 100;
}

void ParticleSystem::draw() {
	if(fuel > 0) {
		// glPushMatrix();

		// glDisable(GL_LIGHTING);
		// glDisable(GL_DEPTH_TEST);

		// glBegin(GL_POINTS);

		// for(int i = 0; i < NUM_PARTICLES; i++) {
		// 	glColor3fv(particles[i].color);
		// 	glVertex3fv(particles[i].position);
		// }

		// glEnd();

		// glPopMatrix();

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_DEPTH_TEST);

		glNormal3f(0.0, 0.0, 1.0);

		for(int j = 0; j < NUM_DEBRIS; j++) {
			glColor3fv(debris[j].color);

			glPushMatrix();

			glTranslatef(debris[j].position[0], debris[j].position[1], debris[j].position[2]);

			glRotatef(debris[j].orientation[0], 1.0, 0.0, 0.0);
			glRotatef(debris[j].orientation[1], 0.0, 1.0, 0.0);
			glRotatef(debris[j].orientation[2], 0.0, 0.0, 1.0);

			glScalef(debris[j].scale[0], debris[j].scale[1], debris[j].scale[2]);

			glBegin(GL_TRIANGLES);
			glVertex3f(0.0, 0.5, 0.0);
			glVertex3f(-0.25, 0.0, 0.0);
			glVertex3f(0.25, 0.0, 0.0);
			glEnd();

			glPopMatrix();
		}
	}
}

void ParticleSystem::step() {
	if(fuel > 0) {
		// for(int i = 0; i < NUM_PARTICLES; i++) {
		// 	particles[i].position[0] += particles[i].speed[0] * 0.2;
		// 	particles[i].position[1] += particles[i].speed[1] * 0.2;
		// 	particles[i].position[2] += particles[i].speed[2] * 0.2;

		// 	particles[i].color[0] -= 1.0 / 500.0;
		// 	if(particles[i].color[0] < 0.0) particles[i].color[0] = 0.0;

		// 	particles[i].color[1] -= 1.0 / 100.0;
		// 	if(particles[i].color[1] < 0.0) particles[i].color[1] = 0.0;

		// 	particles[i].color[2] -= 1.0 / 50.0;
		// 	if(particles[i].color[2] < 0.0) particles[i].color[2] = 0.0;
		// }

		for(int j = 0; j < NUM_DEBRIS; j++) {
			debris[j].position[0] += debris[j].speed[0] * 0.25;
			debris[j].position[1] += debris[j].speed[1] * 0.25;
			debris[j].position[2] += debris[j].speed[2] * 0.25;

			debris[j].orientation[0] += debris[j].orientationSpeed[0] * 10;
			debris[j].orientation[1] += debris[j].orientationSpeed[1] * 10;
			debris[j].orientation[2] += debris[j].orientationSpeed[2] * 10;
		}

		--fuel;
	}
}

int ParticleSystem::getFuel() {
	return fuel;
}
