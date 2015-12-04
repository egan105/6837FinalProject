#ifndef TARGET_H_
#define TARGET_H_

#include <GLUT/glut.h>

/*
 * Octagonal target panel
 */
class Target {
public:
	Target();
	void draw();
private:
	GLuint listid;
};

#endif /*TARGET_H_*/
