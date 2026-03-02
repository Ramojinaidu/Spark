#include "ImguiLayer.h"
#include "Core/Application.h"
#include "Core/Layers.h"
#include "GLFW/glfw3.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "glad/glad.h"
#include "imgui.h"

namespace Spark {
ImguiLayer::ImguiLayer(const ImguiLayerSpecs& specs) : Layer("ImguiLayer") {
    m_EnableDocking = specs.EnableDockSpace;
    m_EnableViewPorts = specs.EnableViewports;
}

ImguiLayer::~ImguiLayer() {}

void ImguiLayer::OnDetach() {

    ImGui_ImplGlfw_Shutdown();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui::DestroyContext();
}

void ImguiLayer::OnAttach() {

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    if (m_EnableDocking)
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    if (m_EnableViewPorts)
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    // io.ConfigViewportsNoAutoMerge = true;
    // io.ConfigViewportsNoTaskBarIcon = true;

    ImGui::StyleColorsDark();

    GLFWwindow* window =
        (GLFWwindow*)Application::Get().GetWindow()->GetNativeWindow();
    ImGuiStyle& style = ImGui::GetStyle();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 410");
}

void ImguiLayer::Begin() {

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void ImguiLayer::End() {
    ImGui::Render();
    GLFWwindow* window =
        (GLFWwindow*)Application::Get().GetWindow()->GetNativeWindow();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        GLFWwindow* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);
    }
}

void ImguiLayer::OnEvent(Event& e) {

    ImGuiIO& io = ImGui::GetIO();
    e.SetHandled(io.WantCaptureKeyboard);
    e.SetHandled(io.WantCaptureMouse);
}

void ImguiLayer::OnImGuiRender() {}

void ImguiLayer::OnUpdate() {}

} // namespace Spark
