#include "lab_m1/Tema2/Tema2.h"

#include <vector>
#include <string>
#include <iostream>

#include "lab_m1/Tema2/transform3D.h"
#include "lab_m1/Tema2/object2D.h"
#include <components/text_renderer.h>


using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */

Tema2::Tema2()
{
}


Tema2::~Tema2()
{
}


void Tema2::Init()
{
    camera = new implemented::Cam();
    camera->Set(glm::vec3(3.5, 0.6, 3.0), glm::vec3(3.0, 0.3, 3.0), glm::vec3(0, 1, 0));

    cameraMinimap = new implemented::Cam();
    cameraMinimap->Set(glm::vec3(3.1, 2.0, 3.0), glm::vec3(3.0, 0.3, 3.0), glm::vec3(0, 1, 0));

    Mesh* mesh = new Mesh("box");
    mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "box.obj");
    meshes[mesh->GetMeshID()] = mesh;

    // Initialize tx, ty and tz (the translation steps)
    translateX = 3.0f;
    translateY = 0;
    translateZ = 3.0f;
    trX1 = trX2 = trZ1 = trZ2 = 0;

    // Sets the resolution of the small viewport
    glm::ivec2 resolution = window->GetResolution();
    miniViewportArea = ViewportArea(50, 50, resolution.x / 5.f, resolution.y / 5.f);

    Mesh* pista= object2D::CreatePista("pista", 50.0, glm::vec3(0.2, 0.2, 0.2), &pctPista, true);
    AddMeshToList(pista);

    Mesh* trunk = object2D::CreateCube("trunk", glm::vec3(0.8, 0.5, 0.8), true);
    AddMeshToList(trunk);

    Mesh* leaves = object2D::CreateCube("leaves", glm::vec3(0, 0.7, 0.3), true);
    AddMeshToList(leaves);

    Mesh* grass = object2D::CreateCube("grass", glm::vec3(0.3, 0.5, 0.3), true);
    AddMeshToList(grass);

    Mesh* car = object2D::CreateCube("car", glm::vec3(0, 0.6, 0.8), true);
    AddMeshToList(car);

    Mesh* car1 = object2D::CreateCube("car1", glm::vec3(0.8, 0.2, 0.2), true);
    AddMeshToList(car1);

    Mesh* car2 = object2D::CreateCube("car2", glm::vec3(0.8, 0.2, 0.6), true);
    AddMeshToList(car2);

    Mesh* sphere = new Mesh("sphere");
    sphere->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "sphere.obj");
    meshes[sphere->GetMeshID()] = sphere;

    Mesh* bamboo = new Mesh("bamboo");
    bamboo->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "vegetation/bamboo"), "bamboo.obj");
    meshes[bamboo->GetMeshID()] = bamboo;

    Mesh* oildrum = new Mesh("oildrum");
    oildrum->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "props"), "oildrum.obj");
    meshes[oildrum->GetMeshID()] = oildrum;

    Mesh* plane = new Mesh("plane");
    plane->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "plane50.obj");
    meshes[plane->GetMeshID()] = plane;

    left = -3.0f;
    right = 3.0f;
    top = 2.0f;
    bottom = -2.0f;
    fov = RADIANS(60);
    aspect = window->props.aspectRatio;
    zNear = 0.01f;
    zFar = 200.0f;
    projectionMatrix = glm::perspective(fov, aspect, zNear, zFar);
    angularStep = 0;
}

void Tema2::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.64, 0.89, 0.97, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    // Sets the screen area where to draw
    glm::ivec2 resolution = window->GetResolution();
    glViewport(0, 0, resolution.x, resolution.y);
}

void Tema2::RenderScene(implemented::Cam* camera) {

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(5.415, 0.2, 0.615);
    modelMatrix *= transform3D::Scale(0.5f, 0.5f, 0.5f);
    RenderMesh(meshes["sphere"], shaders["VertexNormal"], modelMatrix, camera);

    RenderBamboo(2.0f, 2.0f, camera);
    RenderBamboo(4.0f, 4.0f, camera);
    RenderBamboo(-4.0f, -4.0f, camera);
    RenderBamboo(-2.0f, -2.0f, camera);
    RenderOildrum(1.5f, 1.5f, camera);
    RenderTree(1.0f, 1.0f, camera);
    RenderTree(4.86, 0.29, camera);
    RenderTree(-0.48, 0.6, camera);
    RenderTree(-1.76, 1.15, camera);
    RenderTree(-2.83, 1.43, camera);
    RenderTree(-3.79, 0.81, camera);
    RenderTree(-3.93, -0.19, camera);
    RenderTree(-3.45, -1.05, camera);
    RenderTree(-2.11, -1.55, camera);
    RenderTree(-0.68, -1.62, camera);
    RenderTree(0.44, -0.98, camera);
    RenderTree(1.4, -0.25, camera);
    RenderTree(2.55, -0.8, camera);
    RenderTree(3.5, -1.4, camera);

    RenderTree(5.0f, 4.0f, camera);
    RenderTree(6.86, 2.29, camera);
    RenderTree(6.21, 3.4, camera);
    RenderTree(3.5, 3.95, camera);
    RenderTree(3.59, 5.25, camera);
    RenderTree(-4.83, 3.43, camera);
    RenderTree(-5.93, -2.19, camera);
    RenderTree(-5.45, -3.05, camera);
    RenderTree(-4.11, -3.55, camera);
    RenderTree(2.44, -2.98, camera);
    RenderTree(4.7, -2.0, camera);
    RenderTree(4.6, -2.8, camera);
    RenderTree(5.5, -3.4, camera);
    RenderTree(6.6, -3.2, camera);


    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(translateX, 0.3f, translateZ);
    modelMatrix *= transform3D::RotateOY(RADIANS(angularStep - 90));
    modelMatrix *= transform3D::Scale(0.05f, 0.05f, 0.1f);
    RenderMesh(meshes["car"], shaders["VertexNormal"], modelMatrix, camera);

    RenderMesh(meshes["pista"], shaders["VertexColor"], glm::mat3(1), camera);
    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(0.0f, 0.1f, 0.0f);
    modelMatrix *= transform3D::Scale(100.0f, 0.01f, 100.0f);
    RenderMesh(meshes["grass"], shaders["VertexNormal"], modelMatrix, camera);

}

void Tema2::Update(float deltaTimeSeconds)
{
    glm::ivec2 resolution = window->GetResolution();
    trX1 += deltaTimeSeconds;
    if (trX1 > 1) {
        trX2 += 1;
        if (trX2 == pctPista.size())
            trX2 = 0;
        trX1 = 0;
    }

    projectionMatrix = glm::perspective(fov, aspect, zNear, zFar);
    RenderScene(camera);
    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(pctPista[trX2].x, 0.3f, pctPista[trX2].z);
    modelMatrix *= transform3D::RotateOY(RADIANS(90 + atan((pctPista[trX2].z) / (pctPista[trX2].x))));
    modelMatrix *= transform3D::Scale(0.05f, 0.05f, 0.1f);
    RenderMesh(meshes["car1"], shaders["VertexNormal"], modelMatrix, camera);


   // glViewport(miniViewportArea.x, miniViewportArea.y, miniViewportArea.width, miniViewportArea.height);
    glViewport(0, 0, resolution.x / 4, resolution.y / 4);
    glEnable(GL_SCISSOR_TEST);
    glClearColor(0, 0, 1, 1);
    glScissor(0, 0, (resolution.x / 4), (resolution.y / 4));
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
    projectionMatrix = glm::ortho(left, right, bottom, top, zNear, zFar);
    RenderScene(cameraMinimap);
}

void Tema2::FrameEnd()
{

}

void Tema2::RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, implemented::Cam *camera)
{
    if (!mesh || !shader || !shader->program)
        return;

    // Render an object using the specified shader and the specified position
    shader->Use();
    glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
    glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    mesh->Render();
}

/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema2::OnInputUpdate(float deltaTime, int mods)
{
        float cameraSpeed = 2.0f;

        if (window->KeyHold(GLFW_KEY_W)) {
            glm::vec3 new_pos = glm::vec3(translateX - cameraSpeed * deltaTime * cos(RADIANS(-angularStep)),
                                        0, translateZ - cameraSpeed * deltaTime * sin(RADIANS(-angularStep)));
            if (EstePePista(new_pos) == true) {
                camera->MoveForward(cameraSpeed * deltaTime);
                cameraMinimap->MoveForward(cameraSpeed * deltaTime * cos(RADIANS(-angularStep)));
                cameraMinimap->TranslateRight(cameraSpeed * deltaTime * sin(RADIANS(-angularStep)));
                translateX -= cameraSpeed * deltaTime * cos(RADIANS(-angularStep));
                translateZ -= cameraSpeed * deltaTime * sin(RADIANS(-angularStep));
            }
        }

        if (window->KeyHold(GLFW_KEY_A)) {
            angularStep += 60 * deltaTime;
            camera->RotateThirdPerson_OY(RADIANS(60 * deltaTime));
        }

        if (window->KeyHold(GLFW_KEY_S)) {
            glm::vec3 new_pos = glm::vec3(translateX + cameraSpeed * deltaTime * cos(RADIANS(-angularStep)),
                0, translateZ + cameraSpeed * deltaTime * sin(RADIANS(-angularStep)));
            if (EstePePista(new_pos) == true) {
                camera->MoveForward(-cameraSpeed * deltaTime);
                cameraMinimap->MoveForward(-cameraSpeed * deltaTime * cos(RADIANS(-angularStep)));
                cameraMinimap->TranslateRight(-cameraSpeed * deltaTime * sin(RADIANS(-angularStep)));
                translateX += cameraSpeed * deltaTime * cos(RADIANS(-angularStep));
                translateZ += cameraSpeed * deltaTime * sin(RADIANS(-angularStep));
            }
        }

        if (window->KeyHold(GLFW_KEY_D)) {
            angularStep -= 60  * deltaTime;
            camera->RotateThirdPerson_OY(RADIANS(-60 * deltaTime));
        }
}


void Tema2::OnKeyPress(int key, int mods)
{
    // Add key press event
    if (key == GLFW_KEY_SPACE)
    {
        switch (polygonMode)
        {
        case GL_POINT:
            polygonMode = GL_FILL;
            break;
        case GL_LINE:
            polygonMode = GL_POINT;
            break;
        default:
            polygonMode = GL_LINE;
            break;
        }
    }
}


void Tema2::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{

}


void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema2::OnWindowResize(int width, int height)
{
}

void Tema2::RenderTree(float posx, float posz, implemented::Cam* camera) {
    glm::mat4 modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(posx, 0.3f, posz);
    modelMatrix *= transform3D::Scale(0.07f, 0.2f, 0.07f);
    RenderMesh(meshes["trunk"], shaders["VertexNormal"], modelMatrix, camera);

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(posx, 0.6f, posz);
    modelMatrix *= transform3D::Scale(0.25f, 0.25f, 0.25f);
    RenderMesh(meshes["leaves"], shaders["VertexNormal"], modelMatrix, camera);

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(posx, 1.0f, posz);
    modelMatrix *= transform3D::Scale(0.2f, 0.2f, 0.2f);
    RenderMesh(meshes["sphere"], shaders["VertexNormal"], modelMatrix, camera);
}

void Tema2::RenderBamboo(float posx, float posz, implemented::Cam* camera) {
    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(posx, 0.0f, posz);
    modelMatrix *= transform3D::Scale(0.2f, 0.05f, 0.2f);
    RenderMesh(meshes["bamboo"], shaders["Simple"], modelMatrix, camera);
}

void Tema2::RenderOildrum(float posx, float posz, implemented::Cam *camera) {
    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(posx, 0.0f, posz);
    modelMatrix *= transform3D::Scale(0.2f, 0.2f, 0.2f);
    RenderMesh(meshes["oildrum"], shaders["Simple"], modelMatrix, camera);
}

float Tema2::TriangleArea(glm::vec3 A, glm::vec3 B, glm::vec3 C) {
    glm::vec2 AB = glm::vec2(B.x - A.x, B.z - A.z);
    glm::vec2 AC = glm::vec2(C.x - A.x, C.z - A.z);
    float cross_product = AB.x * AC.y - AB.y * AC.x;
    return abs(cross_product) / 2;
}

bool Tema2::InsideTriangle(glm::vec3 P, glm::vec3 A, glm::vec3 B, glm::vec3 C) {
    float triangle_area = TriangleArea(A, B, C);
    float area_sum = 0;
    area_sum += TriangleArea(A, B, P);
    area_sum += TriangleArea(A, C, P);
    area_sum += TriangleArea(B, C, P);
    
    if (triangle_area == area_sum)
        return true;
    else
        return false;
}

bool Tema2::EstePePista(glm::vec3 P) {
    for (int i = 0; i < 34; i++) {
        if (InsideTriangle(P, pctPista[triangles[i].x], 
                            pctPista[triangles[i].y],
                              pctPista[triangles[i].z]) == true)
            return true;
    }
    return false;
}

