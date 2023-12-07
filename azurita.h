//Alexis Zurita
//Only for declaration of function, Not for executables
//

#ifndef _azurita_H_
#define _azurita_H_

#include <iostream>
#include <ctime>
#include <chrono>
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>
#include <cmath>

void drawAzuritaCar(float Pos1, float Pos2, float Pos3, float theta);
int total_time_since_key_press(const bool get);
void drawCarBody(float width, float height, float depth);
void drawCarWheel(float radius, float height, int numSegments);


#endif

