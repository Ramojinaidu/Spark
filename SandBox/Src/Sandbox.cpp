#include <Spark.h>

int main(){

	SPARK_INIT_LOGGER()
	Spark::Application();

	SPARK_INFO("INFO")
	SPARK_DBUG("DEBUG")
	SPARK_ERROR("ERROR")
	SPARK_CRITICAL("CRITICAL")
	SPARK_WARN("WARN")

	return 0;
}
