//Modified by: Mostafa Abadi
//Date: 09/25/2023
//Purpose: My Coding contribution towards 3350 Project

//This will make the car move left or right or make it go straight and also     go down the road.
  /*  g.cameraPosition[2] -= 0.1;
//The function below will decide how much the camera moves left to right.
    g.cameraPosition[0] = 2.0 + sin(g.cameraPosition[2]*0.2);


    //Below is my code for just outputting an oval race-car track.
    
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void drawOvalTrack() {
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -10.0f);  // Translate the track down the Z-axis

    // Draw the outer oval shape
    glColor3f(0.0f, 0.8f, 0.0f);  // Green color
    glBegin(GL_LINE_LOOP);
    for (float angle = 0.0f; angle < 2.0f * 3.14159f; angle += 0.1f) {
        float x = 10.0f * cos(angle);
        float y = 5.0f * sin(angle);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();

    // Draw the inner oval shape (for the inner part of the track)
    glColor3f(0.0f, 0.0f, 0.0f);  // Black color
    glBegin(GL_LINE_LOOP);
    for (float angle = 0.0f; angle < 2.0f * 3.14159f; angle += 0.1f) {
        float x = 8.0f * cos(angle);
        float y = 3.0f * sin(angle);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();

    // Draw the start/finish line
    glColor3f(1.0f, 1.0f, 1.0f);  // White color
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex3f(-8.0f, 0.0f, 0.0f);
    glVertex3f(8.0f, 0.0f, 0.0f);
    glEnd();

    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Set up your camera and view here if needed

    drawOvalTrack();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Simple Race Track");

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
*/
