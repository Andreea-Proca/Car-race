#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"

#include "lab_m1/Tema2/Tema2.h"
namespace object2D
{
    // Create square with given bottom left corner, length and color
    Mesh* CreateSquare(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    // Create triangle
    Mesh* CreateTriangle(const std::string& name, glm::mat3 coords, glm::vec3 color, bool fill = false);
    //Create circle
    Mesh* CreateCircle(const std::string& name, glm::vec3 coords, float radius, glm::vec3 color, bool fill = false);
    //Create halo
    Mesh* CreateHalo(const std::string& name, glm::vec3 coords, float radius, glm::vec3 color, bool fill = false);
    //Create empty circle
    Mesh* CreateEmptyCircle(const std::string& name, glm::vec3 coords, float radius, glm::vec3 color, bool fill = false);
    //Create pista
    Mesh* CreatePista(const std::string& name, float length, glm::vec3 color, std::vector<glm::vec3> *pctPista, bool fill = false);
    //Create cube
    Mesh* CreateCube(const std::string& name, glm::vec3 color, bool fill = false);

}
