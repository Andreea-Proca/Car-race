#pragma once

#include "components/simple_scene.h"
#include "lab_m1/Tema2/lab_camera.h"
#include "lab_m1/Tema2/object2D.h"

namespace m1
{
    class Tema2 : public gfxc::SimpleScene
    {
    public:

       // std::vector<glm::vec3> pctPista;
        struct ViewportArea
        {
            ViewportArea() : x(0), y(0), width(1), height(1) {}
            ViewportArea(int x, int y, int width, int height)
                : x(x), y(y), width(width), height(height) {}
            int x;
            int y;
            int width;
            int height;
        };

        Tema2();
        ~Tema2();

        void Init() override;
        //new create mesh method from lab 6
        Mesh* CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices);

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, implemented::Cam* camera);

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;
        void RenderTree(float posx, float posz, implemented::Cam* camera);
        void RenderBamboo(float posx, float posz, implemented::Cam* camera);
        void RenderOildrum(float posx, float posz, implemented::Cam* camera);
        bool InsideTriangle(glm::vec3 P, glm::vec3 A, glm::vec3 B, glm::vec3 C);
        float TriangleArea(glm::vec3 A, glm::vec3 B, glm::vec3 C);
        bool EstePePista(glm::vec3 P);

        void RenderScene(implemented::Cam* camera);
    protected:
        glm::mat4 modelMatrix;
        float translateX, translateY, translateZ;
        float scaleX, scaleY, scaleZ;
        float angularStepOX, angularStepOY, angularStepOZ;
        float angularStepOXnew;
        GLenum polygonMode;
        ViewportArea miniViewportArea;
        int ok1, ok2;
        float trX1, trX2, trZ1, trZ2;


        implemented::Cam* camera;
        implemented::Cam* cameraMinimap;
        glm::mat4 projectionMatrix;
        bool renderCameraTarget;

        float left, right;
        float bottom, top;
        float zNear, zFar;
        float fov;
        float aspect;

        float angularStep;
        std::vector<glm::vec3> pctPista;
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

        std::vector<glm::vec3> triangles = {
            glm::vec3(2, 3, 1),
            glm::vec3(2, 0, 1),
            glm::vec3(4, 5, 3),
            glm::vec3(4, 2, 3),
            glm::vec3(6, 7, 5),
            glm::vec3(6, 4, 5),
            glm::vec3(8, 9, 7),
            glm::vec3(8, 6, 7),
            glm::vec3(10, 11, 9),
            glm::vec3(10, 8, 9),

            glm::vec3(11, 10, 12),
            glm::vec3(11, 13, 12),
            glm::vec3(13, 12, 14),
            glm::vec3(13, 15, 14),
            glm::vec3(15, 14, 16),
            glm::vec3(15, 17, 16),
            glm::vec3(17, 16, 18),
            glm::vec3(17, 19, 18),
            glm::vec3(19, 18, 20),
            glm::vec3(19, 21, 20),

            glm::vec3(21, 20, 22),
            glm::vec3(21, 23, 22),
            glm::vec3(23, 22, 24),
            glm::vec3(23, 25, 24),
            glm::vec3(25, 24, 26),
            glm::vec3(25, 27, 26),
            glm::vec3(27, 26, 28),
            glm::vec3(27, 29, 28),
            glm::vec3(29, 28, 30),
            glm::vec3(29, 31, 30),

            glm::vec3(31, 30, 32),
            glm::vec3(31, 33, 32),
            glm::vec3(0, 1, 33),
            glm::vec3(0, 33, 32)
        };
        /*
        std::vector<glm::vec3> puns = {
            glm::vec3(5.415, 0.2, 0.615), // A -> 0, 1
            glm::vec3(6.525, 0.2, 1.265), // B -> 2, 3
            glm::vec3(4.58, 0.2, 2.11), // C -> 4, 5
            glm::vec3(5.32 0.2 3.53), // D -> 6, 7
            glm::vec3(2.695 0.2 2.785), // E -> 8, 9
            glm::vec3(2.505 0.2 4.075), // F -> 10, 11
            glm::vec3(1.15 0.2 2.405), // G -> 12, 13
            glm::vec3(0.45 0.2 3.315), // H -> 14, 15
            glm::vec3(0.265 0.2 1.785), // I -> 16, 17
            glm::vec3(-0.385 0.2 2.855), // J -> 18, 19
            glm::vec3(-0.205 0.2 1.24), // K -> 20, 21
            glm::vec3(0.345 0.2 2.52), // L -> 22, 23
            glm::vec3(-1.62 0.2 1.685), // M -> 24, 25
            glm::vec3(-1.34 0.2 2.755), // N -> 26, 27
            glm::vec3(-3.14 0.2 1.91), // O -> 28, 29
            glm::vec3(-3.76 0.2 2.87), // P -> 30, 31
            glm::vec3(-4.29 0.2 0.88), // Q -> 32, 33
            glm::vec3(-5.29 0.2 1.02) // R -> 32, 33
            glm::vec3(-4.36 0.2 - 0.43) // R -> 32, 
            glm::vec3(-5.22 0.2 - 0.91) // R -> 32, 33
            glm::vec3(-3.7 0.2 - 1.72) // R -> 32, 33
            glm::vec3(-4.2 0.2 - 3.06) // R -> 32, 33

            glm::vec3(-2.145 0.2 - 2.265) // R -> 32, 33
            glm::vec3(-2.215 0.2 - 3.695) // R -> 32, 33
            glm::vec3(-0.36 0.2 - 2.18) // R -> 32, 33
            glm::vec3(-4.2 0.2 - 3.06) // R -> 32, 33
            glm::vec3(-4.2 0.2 - 3.06) // R -> 32, 33
            glm::vec3(-4.2 0.2 - 3.06) // R -> 32, 33
        };*/
    };
}   // namespace m1

