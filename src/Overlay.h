#ifndef OVERLAY_H_
#define OVERLAY_H_

#include "TextureLoader.h"

void drawOverlay(void)
{
  GLuint texture;
	texture = LoadTexture( "tie_fighter.bmp" );
	glBindTexture (GL_TEXTURE_2D, texture);
  glDisable(GL_LIGHTING);
  // Save transform attributes (Matrix Mode and Enabled Modes)
  glPushAttrib(GL_TRANSFORM_BIT|GL_ENABLE_BIT);
  // Save projection matrix and set unit transform
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(-1, 1, -1, 1);
  // Save model view matrix and set to identity
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  //Draw bottom with texture
  glColor3f(1,1,1);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,texture);
  glBegin(GL_QUADS);
  glTexCoord2d(0,0);glVertex2f(-1,-1);
  glTexCoord2d(1,0);glVertex2f(1,-1);
  glTexCoord2d(1,1);glVertex2f(1, 1);
  glTexCoord2d(0,1);glVertex2f(-1, 1);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  //  Reset model view matrix
  glPopMatrix();
  //  Reset projection matrix
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  //  Pop transform attributes (Matrix Mode and Enabled Modes)
  glPopAttrib();
  glEnable(GL_LIGHTING);
}

#endif
