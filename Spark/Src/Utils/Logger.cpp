#include "Logger.h"

#include "spdlog/common.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

namespace Spark {

std::shared_ptr<spdlog::logger> Logger::s_CoreLogger = nullptr;

void Logger::Init() {

    std::vector<spdlog::sink_ptr> s_Sinks;
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("Logs/MemoryAllocs.log",true);

    console_sink->set_pattern(CONSOLE_LOGGER_PATTERN);
    console_sink->set_level(spdlog::level::trace);

    file_sink->set_pattern(FILE_LOGGER_PATTERN);
    file_sink->set_level(spdlog::level::trace);

    s_Sinks.emplace_back(console_sink);
    s_Sinks.emplace_back(file_sink);

    s_CoreLogger = std::make_shared<spdlog::logger>("SPARK",s_Sinks.begin(),s_Sinks.end());
    s_CoreLogger->set_level(spdlog::level::trace);
    s_CoreLogger->flush_on(spdlog::level::trace);
    spdlog::register_logger(s_CoreLogger);

}

} // namespace Spark
