#include <math.h>
#include <assert.h>
#include <stdio.h>

#include <GLUT/glut.h>
#include "Camera.h"

Camera::Camera(void) {
	width = height = 1;

	location[0] = 0.0f;		// x
	location[1] = 3.0f;		// y
	location[2] = 45.0f;	// z

	lookAt[0] = 0.0f;	// x
	lookAt[1] = 1.0f;	// y
	lookAt[2] = 0.0f;	// z
}

void Camera::apply() {
	gluLookAt(location[0], location[1], location[2],
			  lookAt[0], lookAt[1], lookAt[2], 
			  0.0f, 1.0f, 0.0f);
}

void Camera::applyProjection(float scale) {
	scale = scale;
	gluPerspective(60.0f * scale, (GLdouble) width / (GLdouble) height, 0.1f, 1000.0f);
}

void Camera::reshape(int _width, int _height) {
	width  = _width;
	height = _height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	applyProjection(scale);

	glViewport(0, 0, width, height);
}

// keep the camera in the world
#define BOUNDED(val) (val > -49 && val < 49)

void Camera::strafe(float amount) {
	if(BOUNDED(lookAt[0])) {
		lookAt[0] += amount;
	}
	if(BOUNDED(location[0])) {
		location[0] += amount;
	}
}

void Camera::walk(float amount) {
	if(BOUNDED(lookAt[2])) {
		lookAt[2] += amount;
	}
	if(BOUNDED(location[2])) {
		location[2] += amount;
	}
}

void Camera::yaw(float amount) {
	lookAt[0] += amount;
}

void Camera::pitch(float amount) {
	lookAt[1] += amount;
}
