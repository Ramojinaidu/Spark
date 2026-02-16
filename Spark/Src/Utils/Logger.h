#ifndef LOGGER_H
#define LOGGER_H

#include "../defines.h"

#define FMT_HEADER_ONLY
#include "spdlog/spdlog.h"

#define LOGGER_PATTERN "[%T][%=10l]: %v"


namespace Spark{
class Logger{
	
public:
	static void Init();
	static std::shared_ptr<spdlog::logger>& GetCoreLogger(){ return s_CoreLogger;}

private:
	static std::shared_ptr<spdlog::logger> s_CoreLogger;
};

}

#define SPARK_INIT_LOGGER() spdlog::set_pattern(LOGGER_PATTERN);\
							spdlog::info("SPARK LOGGER INITIALIZED");\
							::Spark::Logger::Init();


#if SPARK_DEBUG

	#define SPARK_INFO(...) 	::Spark::Logger::GetCoreLogger()->info(__VA_ARGS__);
	#define SPARK_ERROR(...) 	::Spark::Logger::GetCoreLogger()->error(__VA_ARGS__);
	#define SPARK_DBUG(...) 	::Spark::Logger::GetCoreLogger()->debug(__VA_ARGS__);
	#define SPARK_CRITICAL(...) ::Spark::Logger::GetCoreLogger()->critical(__VA_ARGS__);
	#define SPARK_WARN(...) 	::Spark::Logger::GetCoreLogger()->warn(__VA_ARGS__);

#else

	#define SPARK_INFO(...) 
	#define SPARK_ERROR(...) 
	#define SPARK_DBUG(...) 
	#define SPARK_CRITICAL(...) 
	#define SPARK_WARN(...) 

#endif

#endif