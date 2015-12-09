#include <math.h>
#include <assert.h>
#include <stdio.h>
#include <vecmath.h>

#include <GLUT/glut.h>
#include "Camera.h"
#include "Generator.h"

Camera::Camera(void) {
	width = height = 1;

	location[0] = 0.0f;		// x
	location[1] = 195.0f;		// y
	location[2] = 0.0f;	// z

	lookAt[0] = 0.0f;	// x
	lookAt[1] = 200.0f;	// y
	lookAt[2] = 10.0f;	// z
}

float Camera::x() {
	return location[0];
}

float Camera::z() {
	return location[2];
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

void Camera::fly(float amount) {
	Vector3f direction = Vector3f(lookAt[0] - location[0], lookAt[1] - location[1], lookAt[2] - location[2]).normalized();
	location[0] += direction.x() * amount;
	location[1] += direction.y() * amount;
	location[2] += direction.z() * amount;
	lookAt[0] += direction.x() * amount;
	lookAt[1] += direction.y() * amount;
	lookAt[2] += direction.z() * amount;
}

void Camera::strafe(float amount) {
	Vector3f forward = Vector3f(lookAt[0] - location[0], 0, lookAt[2] - location[2]).normalized();
	Vector3f direction = Vector3f::cross(forward, Vector3f(0.0f,1.0f,0.0f));
	location[0] += direction.x() * amount;
	location[2] += direction.z() * amount;
	lookAt[0] += direction.x() * amount;
	lookAt[2] += direction.z() * amount;
}

void Camera::walk(float amount) {
	Vector3f direction = Vector3f(lookAt[0] - location[0], 0, lookAt[2] - location[2]).normalized();
	location[0] += direction.x() * amount;
	location[2] += direction.z() * amount;
	lookAt[0] += direction.x() * amount;
	lookAt[2] += direction.z() * amount;
}

void Camera::yaw(float amount) {
	lookAt[0] += amount;
}

void Camera::pitch(float amount) {
	lookAt[1] += amount;
}
