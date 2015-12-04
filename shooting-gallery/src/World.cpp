#include <iostream>
using namespace std;

#include <GLUT/glut.h>

#include "World.h"
#include "Stand.h"

World::World() {
	/*
	 * draw basic shape of world via primitives to a display list
	 */
	listid = glGenLists(1);
	glNewList(listid, GL_COMPILE);
		glBegin(GL_QUADS);
			glColor3f(1.0f, 1.0f, 1.0f);		// floor
			glVertex3f( WORLD_MAX, 0.0f,  WORLD_MAX);
			glVertex3f( WORLD_MAX, 0.0f, -WORLD_MAX);
			glVertex3f(-WORLD_MAX, 0.0f, -WORLD_MAX);
			glVertex3f(-WORLD_MAX, 0.0f,  WORLD_MAX);

			glColor3f(1.0f, 1.0f, 1.0f);		// front
			glVertex3f(-WORLD_MAX, 0.0f, -WORLD_MAX);
			glVertex3f( WORLD_MAX, 0.0f, -WORLD_MAX);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f( WORLD_MAX, WORLD_MAX, -WORLD_MAX);
			glVertex3f(-WORLD_MAX, WORLD_MAX, -WORLD_MAX);

			glColor3f(1.0f, 1.0f, 1.0f);		// left
			glVertex3f(-WORLD_MAX, 0.0f, -WORLD_MAX);
			glVertex3f(-WORLD_MAX, 0.0f,  WORLD_MAX);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(-WORLD_MAX, WORLD_MAX,  WORLD_MAX);
			glVertex3f(-WORLD_MAX, WORLD_MAX, -WORLD_MAX);

			glColor3f(1.0f, 1.0f, 1.0f);		// right
			glVertex3f(WORLD_MAX, 0, -WORLD_MAX);
			glVertex3f(WORLD_MAX, 0, WORLD_MAX);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f(WORLD_MAX, WORLD_MAX, WORLD_MAX);
			glVertex3f(WORLD_MAX, WORLD_MAX, -WORLD_MAX);

			glColor3f(1.0f, 1.0f, 1.0f);		// back
			glVertex3f(-WORLD_MAX, 0.0f, WORLD_MAX);
			glVertex3f( WORLD_MAX, 0.0f, WORLD_MAX);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex3f( WORLD_MAX, WORLD_MAX, WORLD_MAX);
			glVertex3f(-WORLD_MAX, WORLD_MAX, WORLD_MAX);
		glEnd();
	glEndList();

	stand = new Stand();
}

World::~World() {
	delete stand;
}

void World::draw() {
	glCallList(listid);
	stand->draw();
	for (int i =0; i<bullets.size();i++){
		bullets[i]->draw();
	}

}

void World::step(int time) {
	stand->step(time);
	for (int i =0; i<bullets.size();i++){
		bullets[i]->step(time);
	}
}

void World::shoot(Camera *camera) {
	Bullet * b = new Bullet(camera);
	bullets.push_back(b);
}

void World::reset() {
	stand->reset();
}
