#include "../headers/pch.h"
#include "../headers/DCEL.h"
#include "../headers/Input.h"
#include "../headers/Polygon.h"

int main(void)
{
    Input I = Input();
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(700, 600, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Setting the callback function for neccesary input actions for glfw
    Input::SetGLFWCallbacks(window);

    std::vector<glm::vec2> polygon;
    polygon.push_back(glm::vec2(0, 0));
    polygon.push_back(glm::vec2(2, -1));
    polygon.push_back(glm::vec2(3, -1));
    polygon.push_back(glm::vec2(2.5, 1));
    polygon.push_back(glm::vec2(2.25, 2));

    DCEL dcel = DCEL(polygon);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "Error initializing glew";

    double positions[6] = {
        0,0,
        1,0,
        0,1
    };

    Polygon P = Polygon();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        //glDrawArrays(GL_LINE_LOOP, 0, 3);
        if (Input::DetectLeftClick(window)) {
            P.AddVertex(Input::leftClickx, Input::leftClicky);
        }

        P.RenderPolygon();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}