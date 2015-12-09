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


	stand = new Stand();
}

World::~World() {
	delete stand;
}

void World::draw() {
	glBegin(GL_QUADS);
		glColor3f(0.4f,0.7f,1.0f);		// front
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f( -WORLD_MAX, -WORLD_MAX, WORLD_MAX);
		glVertex3f( -WORLD_MAX, WORLD_MAX, WORLD_MAX);
		glVertex3f( WORLD_MAX, WORLD_MAX, WORLD_MAX);
		glVertex3f( WORLD_MAX, -WORLD_MAX, WORLD_MAX);

		glColor3f(0.4f,0.7f,1.0f);		// back
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f( -WORLD_MAX, -WORLD_MAX, -WORLD_MAX);
		glVertex3f( -WORLD_MAX, WORLD_MAX, -WORLD_MAX);
		glVertex3f( WORLD_MAX, WORLD_MAX, -WORLD_MAX);
		glVertex3f( WORLD_MAX, -WORLD_MAX, -WORLD_MAX);

		glColor3f(0.4f,0.7f,1.0f);		// left
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-WORLD_MAX,-WORLD_MAX, WORLD_MAX);
		glVertex3f(-WORLD_MAX,-WORLD_MAX, -WORLD_MAX);
		glVertex3f(-WORLD_MAX, WORLD_MAX, -WORLD_MAX);
		glVertex3f(-WORLD_MAX, WORLD_MAX, WORLD_MAX);

		glColor3f(0.4f,0.7f,1.0f);		// left
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(WORLD_MAX,-WORLD_MAX, WORLD_MAX);
		glVertex3f(WORLD_MAX,-WORLD_MAX, -WORLD_MAX);
		glVertex3f(WORLD_MAX, WORLD_MAX, -WORLD_MAX);
		glVertex3f(WORLD_MAX, WORLD_MAX, WORLD_MAX);

		glColor3f(0.4f,0.7f,1.0f);		// top
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(-WORLD_MAX, WORLD_MAX, WORLD_MAX);
		glVertex3f( WORLD_MAX, WORLD_MAX, WORLD_MAX);
		glVertex3f( WORLD_MAX, WORLD_MAX, -WORLD_MAX);
		glVertex3f(-WORLD_MAX, WORLD_MAX, -WORLD_MAX);

		glColor3f(0.4f, 0.7f, 1.0f);		// bottom
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(-WORLD_MAX, 5.0f, WORLD_MAX);
		glVertex3f( WORLD_MAX, 5.0f, WORLD_MAX);
		glVertex3f( WORLD_MAX, 5.0f, -WORLD_MAX);
		glVertex3f(-WORLD_MAX, 5.0f, -WORLD_MAX);
	glEnd();
	stand->draw();
	for(int i = 0; i < bullets.size(); i++) {
		bullets[i]->draw();
	}

	for(int j = 0; j < particleSystems.size(); j++) {
		particleSystems[j]->draw();
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

		b->step(time, gscale, wscale);
		for(int j = 0; j < NUM_TARGETS;j ++) {
			bool zLoc = fabs(b->loc[2] - stand->targets[j].location[2]) < 0.75f;
			bool leftRange = b->loc[0] <= stand->targets[j].location[0] + stand->targets[j].radius;
			bool rightRange = b->loc[0] >= stand->targets[j].location[0] - stand->targets[j].radius;

			if (zLoc && leftRange && rightRange && !stand->targets[j].isDown) {
				if (pow(stand->targets[j].location[0] - b->loc[0],2) + pow(stand->targets[j].location[1] - b->loc[1],2) < pow(stand->targets[j].radius,2)){
					ParticleSystem *ps = new ParticleSystem();
					ps->newExplosion(stand->targets[j].location);
					particleSystems.push_back(ps);
					stand->targets[j].isDown = true;
					indices.push_back(i);
				}
			}
		}
	}

	for(int m = 0; m < indices.size(); m++) {
		bullets.erase(bullets.begin() + indices[m]);
	}

	for(int n = 0; n < particleSystems.size(); n++){
		particleSystems[n]->step();
	}
}

void World::shoot(Camera *camera) {
	Bullet * b = new Bullet(camera);
	bullets.push_back(b);
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

void World::reset(){
	for(int i = 0; i < NUM_TARGETS; i++) {
		stand->targets[i].isDown = false;
		
	}
}

void World::adjustWind(float t, bool zero){
	if (zero){
		wscale=0;
	}
	wscale+=t;
}

void World::adjustGravity(float t){
	gscale+=t;
}
