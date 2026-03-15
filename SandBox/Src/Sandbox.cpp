#include <Spark.h>
#include "SandboxLayerTest.h"


class Sandbox : public Spark::Application {

  public:
    Sandbox(const Spark::ApplicationSpec& specs = Spark::ApplicationSpec())
        : Application(specs) {

            Spark::Layer* test = new TestLayer();
            PushLayer(test);
        }
};

Spark::Application* Spark::Create(){
    ApplicationSpec spec;
    spec.window.Title = "SandBox";
    // spec.window.Width = 400;
    // spec.window.Height = 300;
    spec.window.VSync = true;
    spec.window.Maximize = true;
    spec.window.Resizable= true;
    spec.Imgui.EnableImgui = true;
    spec.Imgui.EnableDockSpace = true;
    spec.Imgui.EnableViewports = false;

    return new Sandbox(spec);
}
