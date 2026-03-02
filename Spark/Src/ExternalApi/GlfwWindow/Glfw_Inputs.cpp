#include "Core/Application.h"
#include "Core/Inputs.h"
#include "GLFW/glfw3.h"

bool Spark::Input::IsKeyState(int key, int state) {

    GLFWwindow* window = static_cast<GLFWwindow*>(
        Application::Get().GetWindow()->GetNativeWindow());
    int it = glfwGetKey(window, key);
    return (it == state);
}


bool Spark::Input::IsMouseKeyState(int key, int state) {

    GLFWwindow* window = static_cast<GLFWwindow*>(
        Application::Get().GetWindow()->GetNativeWindow());
    int it = glfwGetMouseButton(window, key);
    return (it == state);
}


void Spark::Input::GetMousePos(double* x, double* y) {

    GLFWwindow* window = static_cast<GLFWwindow*>(
        Application::Get().GetWindow()->GetNativeWindow());
    glfwGetCursorPos(window, x, y);
}
