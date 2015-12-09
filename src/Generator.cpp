#include "Generator.h"
#include <iostream>

using namespace std;

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef M_PI
#define M_PI  3.14159265358979323846
#endif

float get_rand(float x, float y) {
    if (x == 0) {
      x = 1995;
    }
    if (y == 0) {
      y = 1995;
    }
    srand(RAND_SEED * x * y);
    return (float)rand()/ RAND_MAX;
}

static float get_smooth_value(int x, int y) {
    float corner_pnts = (get_rand(x-1, y-1) + get_rand(x+1, y-1) +
                     get_rand(x-1, y+1) + get_rand(x+1, y+1))/16;

    float adjacent_pnts = (get_rand(x, y-1) + get_rand(x, y+1) +
                     get_rand(x-1, y) + get_rand(x+1, y))/8;

    float current_pnt = get_rand(x, y)/4;

    return current_pnt + adjacent_pnts + corner_pnts;
}

static double cosine_interpolate(double x, double y, double mu) {
    double mu2;

    mu2 = (1-cos(mu*M_PI))/2;
    return (x*(1-mu2)+y*mu2);
}

static float interpolation(float x, float y) {
    int x_int = (int) floor(x);
    float x_mod = x - x_int;

    int y_int = (int) floor(y);
    float y_mod = y - y_int;

    float point_1 = get_smooth_value(x_int, y_int);
    float point_2 = get_smooth_value(x_int + 1, y_int);
    float point_3 = get_smooth_value(x_int, y_int + 1);
    float point_4 = get_smooth_value(x_int + 1, y_int + 1);

    float i1 = (float) cosine_interpolate(point_1, point_2, x_mod);
    float i2 = (float) cosine_interpolate(point_3, point_4, x_mod);

    return (float) cosine_interpolate(i1,i2, y_mod);
}

float brownian(float x, float y, int octaves, float frequency) {
    float gain = .99f;
    float lacularity = 2.0f;

    float height = 0;
    float amps = gain;

    for (int i=0; i < octaves; i++) {
        height += interpolation(x*frequency, y*frequency) * amps;
        frequency *= lacularity;
        amps *= gain;
    }

    return height;
}

float generate_y(float x, float z) {
    return ((brownian(x, z, 5, 1.0f/200.0f) * 100) - 200);
}
