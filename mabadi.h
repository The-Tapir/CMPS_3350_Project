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



struct Vertex {
    float position[3];
    float normal[3];
    float uv[2];
};

struct OBJMesh {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices; // Add indices for faces
};

OBJMesh loadOBJ(const std::string& racetrack);

int time_since_mouse_moved(const bool get);

void drawTrack(); 
//void faceIndex();


#endif
