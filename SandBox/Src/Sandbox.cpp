#include "Core/Application.h"
#include <Spark.h>


class Sandbox : public Spark::Application {

  public:
    Sandbox(const Spark::ApplicationSpec& specs = Spark::ApplicationSpec())
        : Application(specs) {}
};

// SPARK_INIT_APPLICATION(Sandbox())
Spark::Application* Spark::Create(){
    ApplicationSpec spec;
    spec.window.Title = "SandBox";
    spec.window.VSync = true;
    spec.Imgui.EnableImgui = true;
    spec.Imgui.EnableDockSpace = true;
    return new Sandbox(spec);
}
