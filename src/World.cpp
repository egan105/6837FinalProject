#include <math.h>
#include <iostream>

using namespace std;

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Generator.h"
#include "World.h"
#include "Stand.h"
#include "Seed.h"

World::World(Camera* camera) {
	/*
	 * draw basic shape of world via primitives to a display list
	 */
	this->camera = camera;
	trace = false;

	stand = new Stand();
}

World::~World() {
	delete stand;
}

void World::draw() {
	int x_max = (int) camera->location[0] + WORLD_MAX;
	int z_max = (int) camera->location[2] + WORLD_MAX;
	int x_min = (int) camera->location[0] - WORLD_MAX;
	int z_min = (int) camera->location[2] - WORLD_MAX;
	glBegin(GL_QUADS);
		// front
		glNormal3f(0.0f, 0.0f, -1.0f);
		glColor3f(0.4f,0.7f,1.0f);
		glVertex3f( x_max, -10, z_max);
		glVertex3f( x_max, WORLD_MAX, z_max);
		glVertex3f( x_min, WORLD_MAX, z_max);
		glVertex3f( x_min, -10, z_max);

		// back
		glNormal3f(0.0f, 0.0f, 1.0f);
		glColor3f(0.4f,0.7f,1.0f);
		glVertex3f( x_min, -10, z_min);
		glVertex3f( x_min, WORLD_MAX, z_min);
		glVertex3f( x_max, WORLD_MAX, z_min);
		glVertex3f( x_max, -10, z_min);

		// left
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glColor3f(0.4f,0.7f,1.0f);
		glVertex3f(x_max, -10, z_min);
		glVertex3f(x_max, WORLD_MAX, z_min);
		glVertex3f(x_max, WORLD_MAX, z_max);
		glVertex3f(x_max, -10, z_max);

		// right
		glNormal3f(1.0f, 0.0f, 0.0f);
		glColor3f(0.4f,0.7f,1.0f);
		glVertex3f(x_min, -10, z_max);
		glVertex3f(x_min, WORLD_MAX, z_max);
		glVertex3f(x_min, WORLD_MAX, z_min);
		glVertex3f(x_min, -10, z_min);

		// top
		glNormal3f(0.0f, -1.0f, 0.0f);
		glColor3f(0.4f, 0.7f, 1.0f);
		glVertex3f( x_max, WORLD_MAX, z_max);
		glVertex3f( x_max, WORLD_MAX, z_min);
		glVertex3f( x_min, WORLD_MAX, z_min);
		glVertex3f( x_min, WORLD_MAX, z_max);

		// bottom
		glNormal3f(0.0f, 1.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f( x_max, WATER_LEVEL, z_max);
		glVertex3f( x_min, WATER_LEVEL, z_max);
		glVertex3f( x_min, WATER_LEVEL, z_min);
		glVertex3f( x_max, WATER_LEVEL, z_min);
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
			if(camera->follow && b->follow) {
				camera->reset();
			}
		}

		if(b->loc[1] <= generate_y(b->loc[0], b->loc[2]) + 2.0f) {
			indices.push_back(i);
			if(camera->follow && b->follow) {
				camera->reset();
			}
		}

		b->step(time, gscale, wscale);
		for(int j = 0; j < NUM_TARGETS;j ++) {
			bool zLoc = fabs(b->loc[2] - stand->targets[j].location[2]) < 1.75f;
			bool yLoc = fabs(b->loc[1] - stand->targets[j].location[1]) < 0.5f;
			bool xLoc = fabs(b->loc[0] - stand->targets[j].location[0]) < 1.75f;
			bool leftRange = b->loc[0] <= stand->targets[j].location[0] + stand->targets[j].radius;
			bool rightRange = b->loc[0] >= stand->targets[j].location[0] - stand->targets[j].radius;
			if(camera->follow && b->follow) {
				camera->location[0] = b->loc[0] - 0.2f;
				camera->location[1] = b->loc[1] - 0.2f;
				camera->location[2] = b->loc[2] - 0.2f;
				camera->lookAt[0] += 1.0f;
				camera->lookAt[2] += 1.0f;
			}

			if (xLoc && !stand->targets[j].isDown) {
				if (pow(stand->targets[j].location[2] - b->loc[2],2) + pow(stand->targets[j].location[1] - b->loc[1],2) < pow(stand->targets[j].radius,2) + 2.0f){
					ParticleSystem *ps = new ParticleSystem();
					ps->newExplosion(stand->targets[j].location);
					particleSystems.push_back(ps);
					stand->targets[j].isDown = true;
					indices.push_back(i);
					if(camera->follow) {
						camera->follow = false;
						camera->hit = true;
					}
				}
			} else if(yLoc && trace) {
				ParticleSystem *ps = new ParticleSystem();
				ps->newExplosion(b->loc);
				ps->label = true;
				ps->loc[0] = b->loc[0];
				ps->loc[1] = b->loc[1];
				ps->loc[2] = b->loc[2];
				particleSystems.push_back(ps);
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
	if(camera->follow) b->follow = true;
	bullets.push_back(b);
}

bool World::inWorld(Bullet *b) {
	if(b->loc[1] > -WORLD_MAX && b->loc[1] < WORLD_MAX) {
		return true;
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
