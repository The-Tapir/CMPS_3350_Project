//Name: Mostafa Abadi
//Created: September 26th, 2023
#include "mabadi.h"
// Required for the time functions
//#include <chrono>
using namespace std::chrono;  // This allows easier access to the chrono functions
// Function to load an OBJ file
int faceIndex = 0; // Variable to keep track of face index
OBJMesh loadOBJ(const std::string& racetrack) {
    OBJMesh mesh;
    //faceIndex();    
    std::vector<Vertex> vertices;
    std::ifstream file(racetrack);
    if (!file.is_open()) {
        return mesh;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        iss >> token;

        if (token == "v") {
            // Vertex position
            Vertex vertex;
            iss >> vertex.position[0] >> vertex.position[1] >> vertex.position[2];
            vertices.push_back(vertex);
        }
        else if (token == "f") {
            // Face 
            for (int i = 0; i < 3; i++) {
                std::vector<Vertex>::size_type vIndex;
                std::string vertexStr;
                iss >> vertexStr;

                // Split the vertex string into parts using '/'
                std::istringstream vertexStream(vertexStr);
                std::getline(vertexStream, token, '/');
                vIndex = std::stoi(token);

                std::cout << "Vertex Index: " << vIndex << std::endl;

                if (vIndex <= vertices.size()) {
                    // Valid vertex index
                    mesh.vertices.push_back(vertices[vIndex - 1]);
                    //mesh.indices.push_back(vIndex - 1);
                    mesh.indices.push_back(faceIndex++);
                }
            }
        }

    }
    return mesh;
}
//Mouse Timer functions.
int time_since_mouse_moved(const bool get)
{
static std::chrono::steady_clock::time_point lastMouseMoveTime = std::chrono::steady_clock::now();
if (!get) {
// Update the time
        lastMouseMoveTime = std::chrono::steady_clock::now();
        return 0;
    }
    // Calculate the time difference
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(now - lastMouseMoveTime);
    int elapsedTime = static_cast<int>(time_span.count());
    return elapsedTime;
}







