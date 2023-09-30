#ifndef MABADI_H
#define MABADI_H

#include <X11/Xlib.h>
//#include <GL/glx.h>

class RoadRacetrack {
public:
    RoadRacetrack();
    void check_mouse(XEvent *e);
    int check_keys(XEvent *e);
    void physics();
    void render();
//private:
    //void drawRoad();
    // Add private members and methods for your racetrack logic
};

#endif

