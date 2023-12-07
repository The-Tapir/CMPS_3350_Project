//Author: Mostafa Abadi
//Created: Setemmber 26th, 2023

#ifndef _mabadi_H_
#define _mabadi_H_
#include <vector>
#include <chrono>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
//

struct Vertex {
    float position[3];
    float normal[3];
    float uv[2];
};
struct OBJMesh {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices; // Add indices for faces
    std::vector<Vertex> obstacles;  // New vector to store obstacle vertices
};
OBJMesh loadOBJ(const std::string& racetrack);
int time_since_mouse_moved(const bool get);
void drawTrack(); 
void drawterrain();
void drawGuardRails();
//void renderStoplight();
void renderTree3D();
void drawLeaves();
void drawTrunk();
void renderScene();
void drawMoon(float radius, int slices, int stacks, GLfloat r, GLfloat g, GLfloat b);
void draw2DDiamondStar(float size, GLfloat r, GLfloat g, GLfloat b);
void initializeStars();

#endif
