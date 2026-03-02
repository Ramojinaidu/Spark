#ifndef LOGGER_H
#define LOGGER_H

#include <spdlog/spdlog.h>

#define CONSOLE_LOGGER_PATTERN "[%T][%=10l]: %v"
#define FILE_LOGGER_PATTERN "%v"

namespace Spark {
class Logger {

  public:
    static void Init();
    static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
        return s_CoreLogger;
    }

  private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
};

} // namespace Spark

#define SPARK_INIT_LOGGER() ::Spark::Logger::Init();

#if SPARK_DEBUG

#define SPARK_TRACE(...) ::Spark::Logger::GetCoreLogger()->trace(__VA_ARGS__);
#define SPARK_DBUG(...) ::Spark::Logger::GetCoreLogger()->debug(__VA_ARGS__);
#define SPARK_INFO(...) ::Spark::Logger::GetCoreLogger()->info(__VA_ARGS__);
#define SPARK_WARN(...) ::Spark::Logger::GetCoreLogger()->warn(__VA_ARGS__);
#define SPARK_ERROR(...) ::Spark::Logger::GetCoreLogger()->error(__VA_ARGS__);
#define SPARK_CRITICAL(...)                                                    \
    ::Spark::Logger::GetCoreLogger()->critical(__VA_ARGS__);

#else

#define SPARK_TRACE(...)
#define SPARK_DBUG(...)
#define SPARK_INFO(...)
#define SPARK_WARN(...)
#define SPARK_ERROR(...)
#define SPARK_CRITICAL(...)

#endif

#endif
