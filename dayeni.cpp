//Name: David Ayeni
//

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include "fonts.h"
#include "dayeni.h"

void drawMenu(int xres, int yres, int selectedOption) {
    unsigned int blue = 0x0000FF;
//    unsigned int lightblue = 0x669FF;
    unsigned int white = 0xFFFFFF;
    // Set up the orthographic projection for 2D rendering
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, xres, 0, yres);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Define menu option positions and dimensions
    float OptionWidth = xres * 0.001;
    float OptionHeight = yres * 0.2;
    float spacing = yres * 0.05;

    float centerY = yres * 0.5;
    float centerX = yres * 0.5;

    float startY = centerY + ((OptionHeight * 3) + (spacing * 2)) * 0.5;

    Rect r;
    r.bot = startY;
    r.left = centerX - (OptionWidth * 0.5);
    r.center = 1;

    if (selectedOption == 0) {
        // If "Play" is selected, change the color to white
        ggprint8b(&r, 16, blue, "Play");
    } else {
        ggprint8b(&r, 16, white, "Play");
    }

    r.bot -= OptionHeight + spacing;
	if (selectedOption == 1) {
        // If "Highscore" is selected, change the color to white
        ggprint8b(&r, 16, blue, "Highscore");
    } else {
        ggprint8b(&r, 16, white, "Highscore");
    }

    r.bot -= OptionHeight + spacing;
    if (selectedOption == 2) {
        // If "Exit" is selected, change the color to white
        ggprint8b(&r, 16, blue, "Exit");
    } else {
        ggprint8b(&r, 16, white, "Exit");
    }

}

void drawHighscore() {

}
/*
void exitGame() {
    cleanup_fonts(); // Cleanup any resources
    XCloseDisplay(x11.dpy); // Close the X display
    exit(0); // Exit the program
}
*/
