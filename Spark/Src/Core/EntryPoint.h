#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H
#include "Core/Application.h"

extern Spark::Application* Spark::Create();

int main(){

    SPARK_INIT_LOGGER()
    auto* app = Spark::Create();

    app->Run();

    delete app;

    return 0;
}

#endif
