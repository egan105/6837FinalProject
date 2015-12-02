#include "Target.h"

Target::Target() {
	/*
	 * draw basic shape of target to a display list
	 */
	listid = glGenLists(1);
	glNewList(listid, GL_COMPILE);
		glBegin(GL_POLYGON);
			glVertex3f( 0.5,  1.0, 0.0);
			glVertex3f(-0.5,  1.0, 0.0);
			glVertex3f(-1.0,  0.5, 0.0);
			glVertex3f(-1.0, -0.5, 0.0);
			glVertex3f(-0.5, -1.0, 0.0);
			glVertex3f( 0.5, -1.0, 0.0);
			glVertex3f( 1.0, -0.5, 0.0);
			glVertex3f( 1.0,  0.5, 0.0);
		glEnd();
	glEndList();
}

void Target::draw() {
	glCallList(listid);
}
