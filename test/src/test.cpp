#include <iostream>
#include<Spark.h>
int main(){
    std::cout<<"Spark App\n";
    Spark::Application* app = new Spark::Application();
    app->Run();
    delete app;

    return 0;
}
