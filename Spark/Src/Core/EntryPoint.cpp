#include "Core/Application.h"

extern Spark::Application* Spark::Create();

int main(){

    SPARK_INIT_LOGGER()
    auto* app = Spark::Create();

    app->Run();

    delete app;
    // SPARK_MEMORY_LEAK_REPORT()
    return 0;
}
