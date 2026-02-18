#include "Core/Application.h"
#include <Spark.h>

int main(){

	SPARK_INIT_LOGGER()
	Spark::ApplicationSpec specs = {"Spark"};
	Spark::Application *test = new Spark::Application(specs);

	test->Run();

	delete test;

	SPARK_INFO("INFO")
	SPARK_DBUG("DEBUG")
	SPARK_ERROR("ERROR")
	SPARK_CRITICAL("CRITICAL")
	SPARK_WARN("WARN")

	return 0;
}
