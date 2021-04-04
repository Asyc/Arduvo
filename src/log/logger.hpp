#ifndef ARDUVO_SRC_LOG_LOGGER_HPP_
#define ARDUVO_SRC_LOG_LOGGER_HPP_

#include <memory>

#include <spdlog/logger.h>

namespace logging {
    extern std::shared_ptr<spdlog::logger> _stdout;

    void init();
    void cleanup();
}   //namespace logging

#define ARDUVO_LOG_INFO(...) ::logging::_stdout->info(__VA_ARGS__)
#define ARDUVO_LOG_DEBUG(...) ::logging::_stdout->debug(__VA_ARGS__)
#define ARDUVO_LOG_ERROR(...) ::logging::_stdout->error(__VA_ARGS__)


#endif //ARDUVO_SRC_LOG_LOGGER_HPP_
