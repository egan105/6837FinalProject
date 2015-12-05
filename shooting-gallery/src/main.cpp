#include <iostream>
#include <math.h>
using namespace std;

#include <GLUT/glut.h>

#include "Camera.h"
#include "World.h"
#include "Target.h"

// size of selection buffer
#define SELECT_SIZE 98

// mouse scaling, system dependant!
#define MOUSE_SCALE 50

// movement unit (strafe, walk)
#define MOVE_SPEED 0.1f

Camera *camera;
World *world;

bool clicked;
bool largeReticle;
bool zoom = false;
int curX, curY;
long lastTime;

void safeExit() {
	delete camera;
	delete world;
	exit(0);
}

void display(void) {
	glutReshapeWindow( 750, 750);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	camera->apply();

	/* Start picking stack */
	glInitNames();
	glPushName(-1);

	world->draw();

	/*
	 * Draw the crosshair in ortho2d mode
	 */
	glColor3f(0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1, 0, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLineWidth(2);

	int num_segments = 1000;
	float center = 0.5f;
	float scaleLarge = 1.5f / 50;
	float scaleOrig = 1.0f / 50;

	if(largeReticle && !zoom) {
		glBegin(GL_LINES);
		glVertex2f(0.46, 0.5);
		glVertex2f(0.48, 0.5);
		glVertex2f(0.52, 0.5);
		glVertex2f(0.54, 0.5);
		glVertex2f(0.5, 0.46);
		glVertex2f(0.5, 0.48);
		glVertex2f(0.5, 0.52);
		glVertex2f(0.5, 0.54);
		glEnd();

		glBegin(GL_POINTS);
	 	for(int i = 0; i < num_segments; ++i)
		{
	 		glVertex2f(center + scaleLarge * cos(2.0f*M_PI*i / num_segments), 
	 			center + scaleLarge * sin(2.0f*M_PI*i / num_segments));
		}
		glEnd();
		largeReticle = false;
	} else if(!largeReticle && !zoom) {
		glBegin(GL_LINES);
		glVertex2f(0.475, 0.5);
		glVertex2f(0.49, 0.5);
		glVertex2f(0.51, 0.5);
		glVertex2f(0.525, 0.5);
		glVertex2f(0.5, 0.475);
		glVertex2f(0.5, 0.49);
		glVertex2f(0.5, 0.51);
		glVertex2f(0.5, 0.525);
		glEnd();

		glBegin(GL_POINTS);
	 	for(int i = 0; i < num_segments; ++i)
		{
	 		glVertex2f(center + scaleOrig * cos(2.0f*M_PI*i / num_segments), center + scaleOrig * sin(2*M_PI*i / num_segments));
		}
		glEnd();
	}

	if(zoom){
		glLineWidth(0.25f);
		glBegin(GL_LINES);
		glVertex2f(0.5, 1.0);
		glVertex2f(0.5, 0.0);
		glVertex2f(0.0, 0.5);
		glVertex2f(1.0, 0.5);
		glEnd();

	    glScalef(0.5f,0.5f,1.0f);
	    int slices = 20;
	    glBegin(GL_QUADS);
	    for(unsigned int j = 0; j < slices; ++j) {
	        float curAngle = ((j + 0) / (float)slices) * M_PI;
	        float nxtAngle = ((j + 1) / (float)slices) * M_PI;
	        glVertex2f(1.0f + sin(curAngle), 1.0f + cos(curAngle));
	        glVertex2f(2.0f, 1.0f + cos(curAngle));
	        glVertex2f(2.0f, 1.0f + cos(nxtAngle));
	        glVertex2f(1.0f + sin(nxtAngle), 1.0f + cos(nxtAngle));
	    }
	    glEnd();

	    glBegin(GL_QUADS);
	    for(unsigned int j = slices; j < 2*slices; ++j) {
	        float curAngle = ((j + 0) / (float)slices) * M_PI;
	        float nxtAngle = ((j + 1) / (float)slices) * M_PI;
	        glVertex2f(1.0f + sin(curAngle), 1.0f + cos(curAngle));
	        glVertex2f(0.0f, 1.0f + cos(curAngle));
	        glVertex2f(0.0f, 1.0f + cos(nxtAngle));
	        glVertex2f(1.0f + sin(nxtAngle), 1.0f + cos(nxtAngle));
	    }
	    glEnd();
	}

	/*
	 * Switch back to perspective projection, must be done
	 * here for picking to succeed
	 */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float scale = zoom ? 0.5f : 1.0f;
	camera->applyProjection(scale);

	glutSwapBuffers();
}

void fire() {
	world->shoot(camera);
	largeReticle = true;

    glutPostRedisplay();
}

void key(unsigned char key, int x, int y) {
	switch(key) {
		case 'W':
		case 'w': camera->walk(-MOVE_SPEED); break;
		case 'S':
		case 's': camera->walk(MOVE_SPEED); break;
		case 'A':
		case 'a': camera->strafe(-MOVE_SPEED); break;
		case 'D':
		case 'd': camera->strafe(MOVE_SPEED); break;
		case 'R':
		case 'r': world = new World(); break;
		case 'Z':
		case 'z': zoom = !zoom; break;
		case 27: safeExit(); break;
		default:
			cout << "[main] Unknown keypress [" << key << "]\n";
	}
    glutPostRedisplay();
}

void motion(int x, int y) {
	if(clicked) {
		float dX = (float) (x - curX) / MOUSE_SCALE;
		float dY = (float) (curY - y) / MOUSE_SCALE;
		camera->yaw(dX);
		camera->pitch(dY);
		curX = x;
		curY = y;
	}
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
	switch(button) {
		case GLUT_LEFT_BUTTON:
			if(GLUT_DOWN == state) fire();
			break;
		case GLUT_RIGHT_BUTTON:
			clicked = state == GLUT_DOWN;
			curX = x; curY = y;

			/* hide cursor while looking around */
			glutSetCursor(clicked ? GLUT_CURSOR_NONE : GLUT_CURSOR_INHERIT);

			break;
	}
    glutPostRedisplay();
}

/*
 * delegate reshaping to the camera
 */
void reshape(int w, int h) {
	camera->reshape(w, h);
    glutPostRedisplay();
}

/*
 * on idle, step the world and redraw
 */
void idle() {
	long newTime = glutGet(GLUT_ELAPSED_TIME);
	world->step(newTime - lastTime);
	lastTime = newTime;
	glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(-1, -1);
    glutCreateWindow("Shooting Gallery");

	/* install callbacks */
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
	glutMotionFunc(motion);
	glutMouseFunc(mouse);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);

	/* basic GL initializations */
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	/* global initializations */
	clicked = false;
	lastTime = 0;

	camera = new Camera();
	world = new World();

    glutMainLoop();
    return 0;
}
