#include "FirstPersonCamera.h"
#include <iostream>

#ifndef M_PI
#define M_PI  3.14159265358979323846
#endif

using namespace std;

/** Constructor
 *
 *
 *
 */
FirstPersonCamera::FirstPersonCamera(int width, int height, GLfloat movement_speed) {
    // Camera center offset
    center_x = width/2;
    center_y = height/2;

    // Set initial max speed
    this->movement_speed = movement_speed;

    // Set initial camera speeds
    x_speed = 0;
    y_speed = 0;
    z_speed = 0;

    cam = new Position();
    cam->cam_pos = new Vector3f(0,10,50);
    cam->cam_x_rot = 0;
    cam->cam_y_rot = 0;
    cam->cam_z_rot = 0;
}

/** Destructor
 *
 *
 *
 */
FirstPersonCamera::~FirstPersonCamera() {
    delete (cam);
}

Position* FirstPersonCamera::getPosition() {
    return cam;
}

int FirstPersonCamera::get_center_x() {
  return center_x;
}

int FirstPersonCamera::get_center_y() {
  return center_y;
}

// Convert degrees to radians
float radians(const float degrees) {
    return degrees * M_PI / 180.0f;
}

GLfloat FirstPersonCamera::cap_movement_speed(GLfloat speed) {
    if (speed > movement_speed) {
        return movement_speed;
    }
    if (speed < -movement_speed) {
        return movement_speed;
    }
    return speed;
}

void FirstPersonCamera::update_camera_speed(Controls* controls) {
    Matrix4f rotateX = Matrix4f::rotateX(cam->cam_x_rot);
    Matrix4f rotateY = Matrix4f::rotateY(cam->cam_y_rot);
    Matrix4f rotateZ = Matrix4f::rotateZ(cam->cam_z_rot);

    Vector3f forward = (rotateZ * (rotateY * (rotateX * Vector4f(0,0,1,0)))).xyz();
    Vector3f right = (rotateZ * (rotateY * (rotateX * Vector4f(1,0,0,0)))).xyz();

    Vector3f speeds = Vector3f::ZERO;

    if (controls->FORWARD) {
      speeds += movement_speed * forward;
    }
    if (controls->BACK) {
      speeds -= movement_speed * forward;
    }
    if (controls->RIGHT) {
      speeds += movement_speed * right;
    }
    if (controls->LEFT) {
      speeds -= movement_speed * right;
    }

    x_speed = cap_movement_speed(speeds.x());
    y_speed = cap_movement_speed(speeds.y());
    z_speed = cap_movement_speed(speeds.z());
}

void FirstPersonCamera::update_camera_position() {
    cam->cam_pos = new Vector3f(cam->cam_pos->x() + x_speed,
                                cam->cam_pos->y() + y_speed,
                                cam->cam_pos->z() + z_speed);
}

void FirstPersonCamera::update_camera_target(int x_pos, int y_pos) {
    GLfloat verticalSensitivity = 10.0f;
    GLfloat horizontalSensitivity = 10.0f;

    int horizontalDisplacement = x_pos - center_x;
    int verticalDisplacement = y_pos - center_y;

    bool static init = true;
    if (init) {
        init = false;
        return;
    }

    cam->cam_x_rot -= verticalDisplacement / verticalSensitivity;
    cam->cam_y_rot += horizontalDisplacement / horizontalSensitivity;

    if (cam->cam_x_rot > 90.0f) {
        cam->cam_x_rot = 90.0f;
    }
    else if (cam->cam_x_rot < -90.0f) {
        cam->cam_x_rot = -90.0f;
    }

    if (cam->cam_y_rot < -180.0f) {
        cam->cam_y_rot += 360.0f;
    } else if (cam->cam_y_rot > 180.0f) {
        cam->cam_y_rot -= 360.0f;
    }
}

void FirstPersonCamera::screen_resize(int new_width, int new_height) {
    center_x = new_width/2;
    center_y = new_width/2;
}
