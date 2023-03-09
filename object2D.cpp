#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"

#include "lab_m1/Tema2/Tema2.h"


Mesh* object2D::CreatePista(
    const std::string& name,
    float length,
    glm::vec3 color,
    std::vector<glm::vec3> *pctPista,
    bool fill)
{
    std::vector<glm::vec3> puncte = {
        glm::vec3(4.86, 0.2, 0.29), // A -> 0, 1
        glm::vec3(4.21, 0.2, 1.4), // B -> 2, 3
        glm::vec3(2.79, 0.2, 2.14), // C -> 4, 5
        glm::vec3(1.5, 0.2, 1.95), // D -> 6, 7
        glm::vec3(0.59, 0.2, 1.25), // E -> 8, 9
        glm::vec3(-0.48, 0.2, 0.6), // F -> 10, 11
        glm::vec3(-1.76,  0.2, 1.15), // G -> 12, 13
        glm::vec3(-2.83,  0.2, 1.43), // H -> 14, 15
        glm::vec3(-3.79,  0.2, 0.81), // I -> 16, 17
        glm::vec3(-3.93,  0.2, -0.19), // J -> 18, 19
        glm::vec3(-3.45,  0.2, -1.05), // K -> 20, 21
        glm::vec3(-2.11,  0.2, -1.55), // L -> 22, 23
        glm::vec3(-0.68,  0.2, -1.62), // M -> 24, 25
        glm::vec3(0.44,  0.2, -0.98), // N -> 26, 27
        glm::vec3(1.4,  0.2, -0.25), // O -> 28, 29
        glm::vec3(2.55,  0.2, -0.8), // P -> 30, 31
        glm::vec3(3.5,  0.2, -1.4), // Q -> 32, 33
        glm::vec3(4.6,  0.2, -1.2) // R -> 32, 33
    };

    glm::vec3 UP = glm::vec3(0, 1, 0);
    std::vector<VertexFormat> vertices;
    for (int i = 0; i < 17; i++) {
        glm::vec3 D = puncte[i+1] - puncte[i];
        glm::vec3 P = cross(D, UP);
        glm::vec3 R = puncte[i] + (P * -0.5f);
        glm::vec3 A = puncte[i] - (P * 1.5f);
        vertices.push_back(VertexFormat(R, color));
        vertices.push_back(VertexFormat(A, color));
        pctPista->push_back(R);
        pctPista->push_back(A);
    }

    Mesh* pista = new Mesh(name);
    std::vector<unsigned int> indices = { 
        2, 3, 1,
        2, 0, 1,

        4, 5, 3,
        4, 2, 3,

        6, 7, 5,
        6, 4, 5,

        8, 9, 7,
        8, 6, 7,

        10, 11, 9,
        10, 8, 9,
       
       11, 10, 12,
       11, 13, 12,

       13, 12, 14, 
       13, 15, 14,

       15, 14, 16,
       15, 17, 16,

       17, 16, 18,
       17, 19, 18,

       19, 18, 20,
       19, 21, 20,

       21, 20, 22,
       21, 23, 22,

       23, 22, 24,
       23, 25, 24,

       25, 24, 26,
       25, 27, 26,

       27, 26, 28,
       27, 29, 28,

       29, 28, 30,
       29, 31, 30,

       31, 30, 32,
       31, 33, 32,

       0, 1, 33,
       0, 33, 32
    };
    pista->InitFromData(vertices, indices);
    return pista;
}

// CUBE
Mesh* object2D::CreateCube(
    const std::string& name,
    glm::vec3 color,
    bool fill)
{
    std::vector<VertexFormat> vertices
    {
        VertexFormat(glm::vec3(-1, -1,  1), glm::vec3(0, 1, 1),  glm::vec3(color.x-0.7, color.y - 0.7, color.z - 0.7)),
        // TODO(student): Complete the vertices data for the cube mesh
        VertexFormat(glm::vec3(1, -1,  1), glm::vec3(0, 0, 1),  glm::vec3(color.x - 0.8, color.y - 0.8, color.z - 0.8)),
        VertexFormat(glm::vec3(-1, 1,  1), glm::vec3(1, 0, 1),  glm::vec3(color.x - 0.2, color.y - 0.2, color.z - 0.2)),
        VertexFormat(glm::vec3(1, 1,  1), glm::vec3(0, 1, 1),  glm::vec3(color.x - 0.3, color.y - 0.3, color.z - 0.3)),
        VertexFormat(glm::vec3(-1, -1,  -1), glm::vec3(0, 0, 1),  glm::vec3(color.x - 0.4, color.y - 0.4, color.z - 0.4)),
        VertexFormat(glm::vec3(1, -1,  -1), glm::vec3(0, 1, 1),  glm::vec3(color.x - 0.5, color.y - 0.5, color.z - 0.5)),
        VertexFormat(glm::vec3(-1, 1,  -1), glm::vec3(0, 1, 0),  glm::vec3(color.x - 0.6, color.y - 0.6, color.z - 0.6)),
        VertexFormat(glm::vec3(1, 1,  -1), glm::vec3(0, 0, 1), color)
    };

    std::vector<unsigned int> indices =
    {
        0, 1, 2,    // indices for first triangle
        1, 3, 2,    // indices for second triangle
        // TODO(student): Complete indices data for the cube mesh
        2, 3, 7,
        2, 7, 6,
        1, 7, 3,
        1, 5, 7,
        6, 7, 4,
        7, 5, 4,
        0, 4, 1,
        1, 4, 5,
        2, 6, 4,
        0, 2, 4
    };

    Mesh* cube = new Mesh(name);

    cube->InitFromData(vertices, indices);
    return cube;
}



// _______________________________________________________________________________________
// SQUARE
Mesh* object2D::CreateSquare(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), glm::vec3(color.x - 0.5,color.y - 0.3, color.z - 0.1)),
        VertexFormat(corner + glm::vec3(0, length, 0), glm::vec3(color.x - 0.5,color.y - 0.3, color.z - 0.1))
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

// TRIANGLE
Mesh* object2D::CreateTriangle(
    const std::string& name,
    glm::mat3 coords,
    glm::vec3 color,
    bool fill)
{
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(glm::vec3(coords[0]), color),
        VertexFormat(glm::vec3(coords[1]), color),
        VertexFormat(glm::vec3(coords[2]),glm::vec3(color.x - 0.5,color.y - 0.3, color.z - 0.3))
    };
    std::vector<unsigned int> indices =
    {
        0, 1, 2
    };

    Mesh* triangle = new Mesh(name);

    triangle->InitFromData(vertices, indices);
    return triangle;
}

Mesh* object2D::CreateCircle(
    const std::string& name,
    glm::vec3 coords,
    float radius,
    glm::vec3 color,
    bool fill)
{
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * 3.141592653589793238f;

    Mesh* circle = new Mesh(name);

    std::vector<VertexFormat> vertices = {
        VertexFormat(glm::vec3(coords.x, coords.y, 0), glm::vec3(color.x - 0.5,color.y - 0.3, color.z - 0.3)),
        VertexFormat(glm::vec3(coords.x + (radius * cos(0 * twicePi / triangleAmount)), coords.y + (radius * sin(0 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(1 * twicePi / triangleAmount)), coords.y + (radius * sin(1 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(2 * twicePi / triangleAmount)), coords.y + (radius * sin(2 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(3 * twicePi / triangleAmount)), coords.y + (radius * sin(3 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(4 * twicePi / triangleAmount)), coords.y + (radius * sin(4 * twicePi / triangleAmount)), 0), color),

        VertexFormat(glm::vec3(coords.x + (radius * cos(5 * twicePi / triangleAmount)), coords.y + (radius * sin(5 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(6 * twicePi / triangleAmount)), coords.y + (radius * sin(6 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(7 * twicePi / triangleAmount)), coords.y + (radius * sin(7 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(8 * twicePi / triangleAmount)), coords.y + (radius * sin(8 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(9 * twicePi / triangleAmount)), coords.y + (radius * sin(9 * twicePi / triangleAmount)), 0), color),

        VertexFormat(glm::vec3(coords.x + (radius * cos(10 * twicePi / triangleAmount)), coords.y + (radius * sin(10 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(11 * twicePi / triangleAmount)), coords.y + (radius * sin(11 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(12 * twicePi / triangleAmount)), coords.y + (radius * sin(12 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(13 * twicePi / triangleAmount)), coords.y + (radius * sin(13 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(14 * twicePi / triangleAmount)), coords.y + (radius * sin(14 * twicePi / triangleAmount)), 0), color),

        VertexFormat(glm::vec3(coords.x + (radius * cos(15 * twicePi / triangleAmount)), coords.y + (radius * sin(15 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(16 * twicePi / triangleAmount)), coords.y + (radius * sin(16 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(17 * twicePi / triangleAmount)), coords.y + (radius * sin(17 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(18 * twicePi / triangleAmount)), coords.y + (radius * sin(18 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(19 * twicePi / triangleAmount)), coords.y + (radius * sin(19 * twicePi / triangleAmount)), 0), color),
    
        VertexFormat(glm::vec3(coords.x + (radius * cos(20 * twicePi / triangleAmount)), coords.y + (radius * sin(20 * twicePi / triangleAmount)), 0), color)
   
   };

    std::vector<unsigned int> indices =  
   {
        0, 1, 2,
        1, 2, 3,
        2, 3, 4,
        3, 4, 5,
        4, 5, 6,
        5, 6, 7,
        6, 7, 8,
        7, 8, 9,
        8, 9, 10,
        9, 10, 11,
        10, 11, 12,
        11, 12, 13,
        12, 13, 14,
        13, 14, 15,
        14, 15, 16,
        15, 16, 17,
        16, 17, 18,
        17, 18, 19,
        18, 19, 20,
        20, 0, 1,

        //fill
        0, 2, 3,
        0, 3, 4,
        0,4,5,
        0,5,6,
        0, 6,7, 
        0, 7,8,
        0,8,9,
        0,9,10,
        0,10,11,
        0,11,12,
        0,12,13,
        0,13,14,
        0,14,15,
        0,15,16,
        0,16,17,
        0,17,18,
        0,18,19,
        0,19,20
    };

    circle->InitFromData(vertices, indices);
    return circle;
}


// HALO
Mesh * object2D::CreateHalo(
    const std::string & name,
    glm::vec3 coords,
    float radius,
    glm::vec3 color,
    bool fill)
{
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * 3.141592653589793238f;

    Mesh* halo = new Mesh(name);

    std::vector<VertexFormat> vertices = {
        VertexFormat(glm::vec3(coords.x + (radius * cos(0 * twicePi / triangleAmount)), coords.y + (radius * sin(0 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(1 * twicePi / triangleAmount)), coords.y + (radius * sin(1 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(2 * twicePi / triangleAmount)), coords.y + (radius * sin(2 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(3 * twicePi / triangleAmount)), coords.y + (radius * sin(3 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(4 * twicePi / triangleAmount)), coords.y + (radius * sin(4 * twicePi / triangleAmount)), 0), color),

        VertexFormat(glm::vec3(coords.x + (radius * cos(5 * twicePi / triangleAmount)), coords.y + (radius * sin(5 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(6 * twicePi / triangleAmount)), coords.y + (radius * sin(6 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(7 * twicePi / triangleAmount)), coords.y + (radius * sin(7 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(8 * twicePi / triangleAmount)), coords.y + (radius * sin(8 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(9 * twicePi / triangleAmount)), coords.y + (radius * sin(9 * twicePi / triangleAmount)), 0), color),

        VertexFormat(glm::vec3(coords.x + (radius * cos(10 * twicePi / triangleAmount)), coords.y + (radius * sin(10 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(11 * twicePi / triangleAmount)), coords.y + (radius * sin(11 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(12 * twicePi / triangleAmount)), coords.y + (radius * sin(12 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(13 * twicePi / triangleAmount)), coords.y + (radius * sin(13 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(14 * twicePi / triangleAmount)), coords.y + (radius * sin(14 * twicePi / triangleAmount)), 0), color),

        VertexFormat(glm::vec3(coords.x + (radius * cos(15 * twicePi / triangleAmount)), coords.y + (radius * sin(15 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(16 * twicePi / triangleAmount)), coords.y + (radius * sin(16 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(17 * twicePi / triangleAmount)), coords.y + (radius * sin(17 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(18 * twicePi / triangleAmount)), coords.y + (radius * sin(18 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(19 * twicePi / triangleAmount)), coords.y + (radius * sin(19 * twicePi / triangleAmount)), 0), color),

        VertexFormat(glm::vec3(coords.x + (radius * cos(20 * twicePi / triangleAmount)), coords.y + (radius * sin(20 * twicePi / triangleAmount)), 0), color)
    };

    std::vector<unsigned int> indices = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

    halo->InitFromData(vertices, indices);
    return halo;
}
//EMPTY CIRCLE
Mesh* object2D::CreateEmptyCircle(
    const std::string& name,
    glm::vec3 coords,
    float radius,
    glm::vec3 color,
    bool fill)
{
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * 3.141592653589793238f;

    Mesh* circle = new Mesh(name);

    std::vector<VertexFormat> vertices = {
        VertexFormat(glm::vec3(coords.x, coords.y, 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(0 * twicePi / triangleAmount)), coords.y + (radius * sin(0 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(1 * twicePi / triangleAmount)), coords.y + (radius * sin(1 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(2 * twicePi / triangleAmount)), coords.y + (radius * sin(2 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(3 * twicePi / triangleAmount)), coords.y + (radius * sin(3 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(4 * twicePi / triangleAmount)), coords.y + (radius * sin(4 * twicePi / triangleAmount)), 0), color),

        VertexFormat(glm::vec3(coords.x + (radius * cos(5 * twicePi / triangleAmount)), coords.y + (radius * sin(5 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(6 * twicePi / triangleAmount)), coords.y + (radius * sin(6 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(7 * twicePi / triangleAmount)), coords.y + (radius * sin(7 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(8 * twicePi / triangleAmount)), coords.y + (radius * sin(8 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(9 * twicePi / triangleAmount)), coords.y + (radius * sin(9 * twicePi / triangleAmount)), 0), color),

        VertexFormat(glm::vec3(coords.x + (radius * cos(10 * twicePi / triangleAmount)), coords.y + (radius * sin(10 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(11 * twicePi / triangleAmount)), coords.y + (radius * sin(11 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(12 * twicePi / triangleAmount)), coords.y + (radius * sin(12 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(13 * twicePi / triangleAmount)), coords.y + (radius * sin(13 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(14 * twicePi / triangleAmount)), coords.y + (radius * sin(14 * twicePi / triangleAmount)), 0), color),

        VertexFormat(glm::vec3(coords.x + (radius * cos(15 * twicePi / triangleAmount)), coords.y + (radius * sin(15 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(16 * twicePi / triangleAmount)), coords.y + (radius * sin(16 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(17 * twicePi / triangleAmount)), coords.y + (radius * sin(17 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(18 * twicePi / triangleAmount)), coords.y + (radius * sin(18 * twicePi / triangleAmount)), 0), color),
        VertexFormat(glm::vec3(coords.x + (radius * cos(19 * twicePi / triangleAmount)), coords.y + (radius * sin(19 * twicePi / triangleAmount)), 0), color),

        VertexFormat(glm::vec3(coords.x + (radius * cos(20 * twicePi / triangleAmount)), coords.y + (radius * sin(20 * twicePi / triangleAmount)), 0), color)

    };

    std::vector<unsigned int> indices =
    {
         0, 1, 2,
         1, 2, 3,
         2, 3, 4,
          3, 4, 5,
          4, 5, 6,
          5, 6, 7,
          6, 7, 8,
          7, 8, 9,
          8, 9, 10,
          9, 10, 11,
          10, 11, 12,
          11, 12, 13,
          12, 13, 14,
          13, 14, 15,
          14, 15, 16,
          15, 16, 17,
          16, 17, 18,
          17, 18, 19,
          18, 19, 20,
          20, 0, 1,

          5, 6, 0,
          12, 13, 0,
          17, 18, 0
    };

    circle->InitFromData(vertices, indices);
    return circle;
}
