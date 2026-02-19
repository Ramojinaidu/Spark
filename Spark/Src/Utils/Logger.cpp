#include "Logger.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Spark {

std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;

void Logger::Init() {

    s_CoreLogger = std::make_shared<spdlog::logger>("SPARK");
    s_CoreLogger->sinks().emplace_back(
        std::make_shared<spdlog::sinks::stdout_color_sink_mt>());

    s_CoreLogger->set_pattern(LOGGER_PATTERN);
    s_CoreLogger->set_level(spdlog::level::trace);
    s_CoreLogger->flush_on(spdlog::level::trace);
}

} // namespace Spark
