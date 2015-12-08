#include "Target.h"
#include "math.h"
#define num_segments 100

Target::Target() {
	/*
	 * draw basic shape of target to a display list
	 */
	listid = glGenLists(1);
	glNewList(listid, GL_COMPILE);
		glBegin(GL_POLYGON);
		    for (int i = 0; i < num_segments; i++)   {
		        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle 
		        float x = 1.0f * cosf(theta);//calculate the x component 
		        float y = 1.0f * sinf(theta);//calculate the y component 
		        glVertex2f(x +0.0f, y +0.0f);//output vertex 
		    }
    	glEnd();
	glEndList();
}

void Target::draw() {
	glCallList(listid);
}
