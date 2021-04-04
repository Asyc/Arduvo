#include "logger.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/wincolor_sink.h>

namespace logging {

std::shared_ptr<spdlog::logger> _stdout;
//std::shared_ptr<spdlog::logger> _stderr;

void init() {
    _stdout = spdlog::stdout_color_st("stdout");
    _stdout->set_pattern("[%T] [%n/%l] %v");

    //_stderr = spdlog::stderr_color_mt("stderr");
    //_stderr->set_pattern("[%T] [%n] %v");
}

void cleanup() {
    _stdout.reset();
    //_stderr.reset();
}

}   // namespace logging

