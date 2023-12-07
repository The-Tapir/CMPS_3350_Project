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


struct Vertex {
    float position[3];
    float normal[3];
    float uv[2];
};
struct OBJMesh {
    //Here are the verticies below
    std::vector<Vertex> vertices;
    //here are the indicies below 
    std::vector<unsigned int> indices;
    std::vector<Vertex> obstacles;  
};
OBJMesh loadOBJ(const std::string& racetrack);
int time_since_mouse_moved(const bool get);
void drawTrack(); 
void drawTerrain();
void drawGuardRails();
void drawTree3D();
void drawLeaves();
void drawTrunk();
void drawScene();
void drawMoon(float radius, int slices, int stacks, GLfloat r, GLfloat g, GLfloat b);
void draw2DDiamondStar(float size, GLfloat r, GLfloat g, GLfloat b);
void initializeStars();

#endif
