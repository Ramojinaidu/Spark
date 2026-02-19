#include "Core/Application.h"
#include <Spark.h>

int main(){

	SPARK_INIT_LOGGER()
	Spark::ApplicationSpec specs = {"Spark"};
	Spark::Application *test = new Spark::Application(specs);

	test->Run();

	delete test;
	return 0;
}
