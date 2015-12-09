#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

#include <GLUT/glut.h>

#include "TextureLoader.h"
#include "Controls.h"
#include "Camera.h"
#include "World.h"
#include "Target.h"
#include "ProceduralWorld.h"

// size of selection buffer
#define SELECT_SIZE 98

// mouse scaling, system dependant!
#define MOUSE_SCALE 50

// movement unit (strafe, walk)
#define MOVE_SPEED 3.0f

const int MAX_BUFFER_SIZE = 0x10000;

Camera *camera;
// FirstPersonCamera *fpCamera;
// Controls *controls;
World *world;
ProceduralWorld* terrain;


// This is the list of points (3D vectors)
vector<vector<float> > vecv;

// This is the list of normals (also 3D vectors)
vector<vector<float> > vecn;

// This is the list of faces (indices into vecv and vecn)
vector<vector<unsigned> > vecf;

bool clicked;
bool largeReticle;
bool zoom = false;
int curX, curY;
long lastTime;
int countVar = 0;
int rate = 0;
bool firing = false;

void safeExit() {
	delete camera;
	delete world;
	exit(0);
}

void display(void) {
	glutReshapeWindow(800,600);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	camera->apply();

	terrain->initialize_new_blocks();
	terrain->draw();


	/* Start picking stack */
	glInitNames();
	glPushName(-1);

	world->draw();

	if(!zoom) {
		glTranslatef(camera->location[0], camera->location[1], camera->location[2]);
		glRotatef(90,0, 1, 0);
		glRotatef(-camera->lookAt[0], 0, 1, 0);
		glRotatef(camera->lookAt[1], 0, 0, 1);
		for(unsigned int j=0; j < vecf.size(); j++) {
		    vector<unsigned> indices = vecf[j];
		    int a = indices[0];
		    int c = indices[2];
		    int d = indices[3];
		    int f = indices[5];
		    int g = indices[6];
		    int i = indices[8];

	      glBegin(GL_TRIANGLES);
		    glNormal3d(vecn[c-1][0], vecn[c-1][1], vecn[c-1][2]);
		    glVertex3d(vecv[a-1][0], vecv[a-1][1], vecv[a-1][2]);
		    glNormal3d(vecn[f-1][0], vecn[f-1][1], vecn[f-1][2]);
		    glVertex3d(vecv[d-1][0], vecv[d-1][1], vecv[d-1][2]);
		    glNormal3d(vecn[i-1][0], vecn[i-1][1], vecn[i-1][2]);
		    glVertex3d(vecv[g-1][0], vecv[g-1][1], vecv[g-1][2]);
		    glEnd();
	    }
	    glPopMatrix();
	}

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

void special_key(int key, int x, int y) {
	switch(key) {
		case GLUT_KEY_UP:
			camera->fly(MOVE_SPEED);
			break;
		case GLUT_KEY_DOWN:
			camera->fly(-MOVE_SPEED);
			break;
		default:
			break;
	}
	glutPostRedisplay();
}

void key_down(unsigned char key, int x, int y) {
	switch(key) {
		case 'W':
		case 'w': camera->walk(MOVE_SPEED); break;
		case 'S':
		case 's': camera->walk(-MOVE_SPEED); break;
		case 'A':
		case 'a': camera->strafe(-MOVE_SPEED); break;
		case 'D':
		case 'd': camera->strafe(MOVE_SPEED); break;
		case 'R':
		case 'r': delete world; world = new World(camera); break;
		case 'Z':
		case 'z': zoom = !zoom; break;
		case 'G':
		case 'g': world->adjustGravity(1);break;
		case 'F':
		case 'f': world->adjustGravity(-1);break;
		case '-': world->adjustWind(-1,false);break;
		case '=': world->adjustWind(1,false);break;
		case '0': world->adjustWind(0,true);break;
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

void loadInput(){
  string line;
  ifstream myfile("vader.obj");
  if (myfile.is_open()){
    while ( getline (myfile,line) ){

        stringstream ss(line);
        float v[3];
	    vector<float> vec;
	    string s;
	    ss >> s;
	    //if (s=="g") cout << line <<endl;

	    if (s == "v") {
	      ss >> v[0] >> v[1] >> v[2];
	      vec.push_back(v[0]);
	      vec.push_back(v[1]);
	      vec.push_back(v[2]);
	      vecv.push_back(vec);
	    } else if (s == "vn") {
	      ss >> v[0] >> v[1] >> v[2];
	      vec.push_back(v[0]);
	      vec.push_back(v[1]);
	      vec.push_back(v[2]);
	      vecn.push_back(vec);
	    } else if (s == "f") {
	      vector<unsigned> faces;

	      string abc;
	      string def;
	      string ghi;

	      ss >> abc >> def >> ghi;
	      string faceIndices = abc + " " + def + " " + ghi;

	      replace(faceIndices.begin(), faceIndices.end(), '/', ' ');
	      stringstream ssFaces(faceIndices);
	      unsigned n;

	      while (ssFaces >> n) {
	        faces.push_back(n);
	      }
	      vecf.push_back(faces);
	  	}
	}
  }
  myfile.close();
}

int main(int argc, char **argv) {
	loadInput();

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
	//glEnable(GL_CULL_FACE);
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
	GLfloat fogColor[4]= {0.4f,0.7f,1.0f, 1.0f};      // Fog / Sky Color

	// Set class fog variables
	float fog_distance_start = 200.0f;
	float fog_distance_end = 600.0f;

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
	terrain = new ProceduralWorld(10);

  glutMainLoop();
  return 0;
}
