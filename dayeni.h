#ifndef _DAYENI_H_
#define _DAYENI_H_

#include <iostream>
#include <chrono>
#include <typeinfo>
#include <string>
#include <X11/Xlib.h>
#include <cmath>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include "fonts.h"


void drawMenu(int xres, int yres, int selectedoption);
void drawHighscore();
//void exitGame();
float mouseMovement(XEvent *e, const bool get);


#endif
