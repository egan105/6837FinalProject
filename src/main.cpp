#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

#include <GLUT/glut.h>

#include "Overlay.h"
#include "Seed.h"
#include "TextureLoader.h"
#include "Controls.h"
#include "Camera.h"
#include "World.h"
#include "Target.h"
#include "ProceduralWorld.h"
#include "ObjectLoader.h"

// size of selection buffer
#define SELECT_SIZE 98

// mouse scaling, system dependant!
#define MOUSE_SCALE 50

// movement unit (strafe, walk)
#define MOVE_SPEED 6.0f

const int MAX_BUFFER_SIZE = 0x10000;

Camera *camera;
// FirstPersonCamera *fpCamera;
// Controls *controls;
World *world;
ProceduralWorld* terrain;

Object *ak47;

float WATER_LEVEL = 5.0f;
int RAND_SEED = rand() % 8898783 + 1;
bool clicked;
bool largeReticle;
int zoom = 0;
int curX, curY;
long lastTime;
int countVar = 0;
int rate = 10;
bool firing = false;
bool follow = false;
int counter = 150;

void safeExit() {
	delete camera;
	delete world;
	exit(0);
}

void display(void) {
	glutReshapeWindow(750,750);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	camera->apply();

	terrain->initialize_new_blocks();
	terrain->delete_distant_blocks();
	terrain->draw();


	/* Start picking stack */
	glInitNames();
	glPushName(-1);

	world->draw();
	if(!camera->follow && follow && camera->hit && counter == 0) {
		follow = false;
		camera->reset();
		counter = 150;
	} else if (camera->hit && follow && counter > 0) {
		counter -= 1;
	} else if (!camera->follow && follow && !camera->hit) {
		follow = false;
	}
	if(!follow) {
		// if(zoom == 0) {
		// 	glTranslatef(camera->location[0] + 4.0, camera->location[1] - 3.0, camera->location[2] + 7.5);
		// 	glRotatef(-90, 1, 0, 0);
		// 	glRotatef(180, 0, 1, 0);
		// 	glRotatef(-135, 0, 0, 1);
		// 	glColor3f(255.0/255, 215.0/255, 0.0/255);
		// 	//glScalef(0.01f,0.01f,0.01f);
		// 	// glRotatef(-camera->lookAt[0], 0, 1, 0);
		// 	//glRotatef(7*(camera->lookAt[1] - 200.0), 0, 1, 0);
		// 	for(unsigned int j=0; j < ak47->vecf.size(); j++) {
		// 	    vector<unsigned> indices = ak47->vecf[j];
		// 	    int a = indices[0];
		// 	    int c = indices[2];
		// 	    int d = indices[3];
		// 	    int f = indices[5];
		// 	    int g = indices[6];
		// 	    int i = indices[8];

		//       glBegin(GL_TRIANGLES);
		// 	    glNormal3d(ak47->vecn[c-1][0], ak47->vecn[c-1][1], ak47->vecn[c-1][2]);
		// 	    glVertex3d(ak47->vecv[a-1][0], ak47->vecv[a-1][1], ak47->vecv[a-1][2]);
		// 	    glNormal3d(ak47->vecn[f-1][0], ak47->vecn[f-1][1], ak47->vecn[f-1][2]);
		// 	    glVertex3d(ak47->vecv[d-1][0], ak47->vecv[d-1][1], ak47->vecv[d-1][2]);
		// 	    glNormal3d(ak47->vecn[i-1][0], ak47->vecn[i-1][1], ak47->vecn[i-1][2]);
		// 	    glVertex3d(ak47->vecv[g-1][0], ak47->vecv[g-1][1], ak47->vecv[g-1][2]);
		// 	    glEnd();
		//     }
		//     glPopMatrix();
		// }

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

		if(largeReticle && zoom == 0) {
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
		} else if(!largeReticle && zoom == 0) {
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

		if(zoom != 0){
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
	}

	/*
	 * Switch back to perspective projection, must be done
	 * here for picking to succeed
	 */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float scale = zoom != 0 ? 0.5 / zoom : 1.0;

	camera->applyProjection(scale);

	// drawOverlay();

	glutSwapBuffers();
}

void fire() {
	largeReticle = true;
	if(camera->follow) {
		follow = true;
		largeReticle = false;
		zoom = 0;
		camera->locCache[0] = camera->location[0];
		camera->locCache[1] = camera->location[1];
		camera->locCache[2] = camera->location[2];
		camera->lookCache[0] = camera->lookAt[0];
		camera->lookCache[1] = camera->lookAt[1];
		camera->lookCache[2] = camera->lookAt[2];
	}
	world->shoot(camera);

    glutPostRedisplay();
}

void special_key(int key, int x, int y) {
	switch(key) {
		case GLUT_KEY_UP:
			camera->fly(MOVE_SPEED);
			break;
		case GLUT_KEY_DOWN:
			camera->fly(-MOVE_SPEED);
			break;
		case GLUT_KEY_LEFT:
			camera->spin(MOVE_SPEED);
			break;
		case GLUT_KEY_RIGHT:
			camera->spin(-MOVE_SPEED);
			break;
		default:
			break;
	}
	glutPostRedisplay();
}

void rebuild_terrain() {
	RAND_SEED = rand() % 8898783 + 1;
	camera->location[0] = 0.0f;		// x
	camera->location[1] = 200.0f;		// y
	camera->location[2] = 0.0f;	// z
	camera->lookAt[0] = 10.0f;	// x
	camera->lookAt[1] = 200.0f;	// y
	camera->lookAt[2] = 10.0f;	// z
	ProceduralWorld* newTerrain = new ProceduralWorld(256, camera);
	terrain = newTerrain;
}

void key_down(unsigned char key, int x, int y) {
	switch(key) {
		case 'o': cout << camera->x() << " " << camera->y() << " " << camera->z() << endl; break;
		case 'W':
		case 'w': camera->walk(MOVE_SPEED); break;
		case 'S':
		case 's': camera->walk(-MOVE_SPEED); break;
		case 'A':
		case 'a': camera->strafe(-MOVE_SPEED); break;
		case 'C':
		case 'c': camera->follow = !camera->follow; break;
		case 'D':
		case 'd': camera->strafe(MOVE_SPEED); break;
		case 'R':
		case 'r': world->reset(); break;
		case 'T':
		case 't': world->trace = !world->trace; break;
		case 'Z':
		case 'z': zoom = (zoom + 1) % 3; break;
		case 'G':
		case 'g': world->adjustGravity(1);break;
		case 'F':
		case 'M': rebuild_terrain(); break;
		case 'f': world->adjustGravity(-1);break;
		case '-': world->adjustWind(-1,false);break;
		case '=': world->adjustWind(1,false);break;
		case '0': world->adjustWind(0,true);break;
		case '5': WATER_LEVEL -= 1.0f; break;
		case '6': WATER_LEVEL += 1.0f; break;
		case 27: safeExit(); break;
		default:
			cout << "[main] Unknown keypress [" << key << "]\n";
	}
    glutPostRedisplay();
}

void motion(int x, int y) {
	if(clicked) {
		float dX = (float) (curX- x) / MOUSE_SCALE;
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
			if(GLUT_DOWN == state){
				firing = true;
				countVar = rate-1;
			}
			if(GLUT_UP == state){
				firing = false;
				countVar = 0;
			}
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
	countVar++;
	if (firing && countVar%rate==0){
		countVar =0;
		fire();
	}
	if (countVar>rate) countVar =0;

	long newTime = glutGet(GLUT_ELAPSED_TIME);
	world->step(newTime - lastTime);
	lastTime = newTime;
	glutPostRedisplay();
}

int main(int argc, char **argv) {
	ak47 = loadInput("AWPv2.obj");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(750, 750);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("Shooting Gallery");

	/* install callbacks */
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMotionFunc(motion);
	glutMouseFunc(mouse);
	glutKeyboardFunc(key_down);
	glutSpecialFunc(special_key);
	//glutKeyboardUpFunc(key_up);
	glutIdleFunc(idle);

	/* Open GL Setup begins here */

	// Lighting
	GLfloat pos[4] = { 0.0, 90.0, 0.0, 0.0 };
	GLfloat ambient[]  = {0.1f, 0.1f, 0.1f, 1.0f};
	GLfloat diffuse[]  = {0.7f, 0.7f, 0.7f, 1.0f};
	GLfloat specular[]  = {1.0f, 1.0f, 1.0f, 1.0f};

	// Lighting setup
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	// Enable culling of rear faces
	// glEnable(GL_CULL_FACE);
	// Enable Textures
	GLuint texture;
	texture = LoadTexture( "terrain.bmp" );
	glBindTexture (GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);

	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	// Enable lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	// Enable occlusion of objects
	glEnable(GL_DEPTH_TEST);

	// Fog settings
	GLfloat fogColor[4]= {0.0f,0.55f,.55f, 1.0f};      // Fog / Sky Color

	// Set class fog variables
	float fog_distance_start = 400.0f;
	float fog_distance_end = 900.0f;

	glClearColor(fogColor[0],fogColor[1],fogColor[2],fogColor[3]);
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_DENSITY, 0.003f);
	glHint(GL_FOG_HINT, GL_DONT_CARE);
	glFogf(GL_FOG_START, fog_distance_start);
	glFogf(GL_FOG_END, fog_distance_end);
	glEnable(GL_FOG);

	/* global initializations */
	clicked = false;
	lastTime = 0;

	camera = new Camera();
	world = new World(camera);
	terrain = new ProceduralWorld(256, camera);

  glutMainLoop();
  return 0;
}
