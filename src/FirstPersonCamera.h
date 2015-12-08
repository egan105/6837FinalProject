#ifndef FIRSTPERSONCAMERA_H_
#define FIRSTPERSONCAMERA_H_

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Controls.h"
#include <vecmath.h>

struct Position {
  // translation
  Vector3f* cam_pos;

  // rotation
  GLfloat cam_x_rot;
  GLfloat cam_y_rot;
  GLfloat cam_z_rot;
};

class FirstPersonCamera {
private:
    int center_x;
    int center_y;

    GLfloat movement_speed;

    GLfloat x_speed;
    GLfloat y_speed;
    GLfloat z_speed;

    Position* cam;

public:
    FirstPersonCamera(int width, int height, GLfloat movement_speed);
    virtual ~FirstPersonCamera();

    Position* getPosition();

    GLfloat cap_movement_speed(GLfloat movement_speed);

    int get_center_x();

    int get_center_y();

    void update_camera_speed(Controls* controls);

    void update_camera_position();

    void update_camera_target(int x_pos, int y_pos);

    void screen_resize(int new_width, int new_height);
};

#endif // FIRSTPERSONCAMERA_H_
