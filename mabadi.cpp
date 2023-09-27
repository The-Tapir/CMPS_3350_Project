#include <GL/glut.h>
#include <cmath>

const int numSegments = 800;
const float outerRadius = 10.0f;
const float innerRadius = 15.0f;
const float trackHeight = 1.0f; // Height of the track

void drawOvalTrack() {
    // Draw the white line for the track
    glColor3f(1.0f, 1.0f, 1.0f); // White color
    glLineWidth(12.0f); // Increase line width for the start and finish line

    glBegin(GL_LINES);
    glVertex3f(-outerRadius - 12.0f, 0.0f, -trackHeight / 2.0f);
    glVertex3f(-outerRadius - 12.0f, 0.0f, trackHeight / 2.0f);
    glVertex3f(outerRadius + 12.0f, 0.0f, -trackHeight / 2.0f);
    glVertex3f(outerRadius + 12.0f, 0.0f, trackHeight / 2.0f);
    glEnd();

    // Draw the outer oval shape
    glColor3f(0.0f, 0.8f, 0.0f); // Green color

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= numSegments; ++i) {
        float theta = (2.0f * 3.1415926f * i) / numSegments;
        float x1 = outerRadius * cos(theta);
        float y1 = outerRadius * sin(theta);
        float x2 = innerRadius * cos(theta);
        float y2 = innerRadius * sin(theta);

        glVertex3f(x1, y1, -trackHeight / 2.0f);
        glVertex3f(x1, y1, trackHeight / 2.0f);
        glVertex3f(x2, y2, -trackHeight / 2.0f);
        glVertex3f(x2, y2, trackHeight / 2.0f);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Set up a perspective projection for a 3D view
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 800.0f / 600.0f, 1.0f, 50.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(15.0f, 0.0f, 15.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    drawOvalTrack();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Race Track");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

