#include <math.h>
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
	for(int i = 0; i < bullets.size(); i++) {
		bullets[i]->draw();
	}

}

void World::step(int time) {
	indices.clear();
	stand->step(time);
	for(int i = 0; i < bullets.size(); i++) {
		Bullet * b = bullets[i];

		// Remove balls that hit the walls
		if(!inWorld(b)) {
			indices.push_back(i);
		}

		b->step(time);
		for(int j = 0; j < NUM_TARGETS;j ++) {
			bool zLoc = fabs(b->loc[2] - stand->targets[j].location[2]) < 0.5f;
			bool leftRange = b->loc[0] <= stand->targets[j].location[0] + stand->targets[j].radius;
			bool rightRange = b->loc[0] >= stand->targets[j].location[0] - stand->targets[j].radius;

			if (zLoc && leftRange && rightRange && !stand->targets[j].isDown) {
				if (pow(stand->targets[j].location[0] - b->loc[0],2) + pow(stand->targets[j].location[1] - b->loc[1],2) < pow(stand->targets[j].radius,2)){
					stand->targets[j].isDown = true;
					stand->targets[j].location[1] = 1.20f;
					indices.push_back(i);
				}
			}
		}
	}

	for(int m = 0; m < indices.size(); m++) {
		bullets.erase(bullets.begin() + indices[m]);
	}
}

void World::shoot(Camera *camera) {
	Bullet * b = new Bullet(camera);
	bullets.push_back(b);
}

void World::reset() {
	stand->reset();
}

bool World::inWorld(Bullet *b) {
	if(b->loc[0] > -WORLD_MAX && b->loc[0] < WORLD_MAX) {
		if(b->loc[1] > -WORLD_MAX && b->loc[1] < WORLD_MAX) {
			if(b->loc[2] > -WORLD_MAX && b->loc[2] < WORLD_MAX) {
				return true;
			}
		}
	}

	return false;
}
