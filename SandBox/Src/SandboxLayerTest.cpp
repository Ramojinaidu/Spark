#include "SandboxLayerTest.h"
#include "Core/Application.h"
#include "Core/Keys.h"
#include "imgui.h"

TestLayer::TestLayer():Layer("test"){

}

TestLayer::~TestLayer(){

}

void TestLayer::OnAttach(){

}

void TestLayer::OnDetach(){

}

void TestLayer::OnUpdate(){

}

void TestLayer::OnEvent(Spark::Event& e){

}

void TestLayer::OnImGuiRender(){
    ImGui::Begin("Test");
    ImGui::Separator();
    ImGui::End();
    bool show = true;
    ImGui::ShowDemoWindow(&show);
}
