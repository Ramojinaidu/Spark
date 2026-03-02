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
    spec.window.VSync = true;
    spec.Imgui.EnableImgui = true;
    spec.Imgui.EnableDockSpace = true;
    return new Sandbox(spec);
}
