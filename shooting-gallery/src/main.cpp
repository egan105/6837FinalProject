#include <iostream>
using namespace std;

#include <GL/glut.h>

#include "Camera.h"
#include "World.h"
#include "Target.h"

// size of selection buffer
#define SELECT_SIZE 98

// mouse scaling, system dependant!
#define MOUSE_SCALE 6

// movement unit (strafe, walk)
#define MOVE_SPEED 0.25f

Camera *camera;
World *world;

bool clicked;
int curX, curY;
long lastTime;

void safeExit() {
	delete camera;
	delete world;
	exit(0);
}

void display(void) {
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
	glBegin(GL_LINES);
		glVertex2f(0.49, 0.5);
		glVertex2f(0.51, 0.5);
		glVertex2f(0.5, 0.49);
		glVertex2f(0.5, 0.51);
	glEnd();

	/*
	 * Switch back to perspective projection, must be done
	 * here for picking to succeed
	 */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	camera->applyProjection();

	glutSwapBuffers();
}

void fire() {
	/* create/init selection buffer */
	GLuint select[SELECT_SIZE]; 
	for(int i = 0; i < SELECT_SIZE; i++) select[i] = -1;
	glSelectBuffer(SELECT_SIZE, select);

	/* get required viewport for selection */
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	/* switch to, and store projection matrix */
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();

		glRenderMode(GL_SELECT); // we're selecting now
		glLoadIdentity();

		/* pick the middle of the screen (cross-hair area) */
		GLuint x = viewport[2] / 2;
		GLuint y = viewport[3] / 2;
		gluPickMatrix(x, y, 2, 2, viewport);

		/* draw to selection buffer */
		camera->applyProjection();
		display();

		/* switch back to render mode, if something comes back we picked */
		if(glRenderMode(GL_RENDER)) {
			world->shoot(select[7]); // 7 holds the first hit
		}

		glMatrixMode(GL_PROJECTION);
	glPopMatrix();

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
		case 'r': world->reset(); break;
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
