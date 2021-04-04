#include <Windows.h>

#include <iostream>
#include <string>
#include <cxxopts.hpp>

#include "log/logger.hpp"

#include "file/dll_file.hpp"
#include "process/process_finder.hpp"

static void inject(DWORD pid, std::string file) {
    ARDUVO_LOG_INFO("Loading DLL file: {}", file);

    DllFile library(std::move(file));
    library.parseFile();
}

int main(int argc, const char** argv) {
    logging::init();

    cxxopts::Options options("arduvo", "Help: ");

    options.add_option("", "p", "process", "The target process name to inject into", cxxopts::value<std::string>(), "[id]");
    options.add_option("", "f", "file", "The target dll file to inject", cxxopts::value<std::string>(), "[path]");

    int error = 0;

    try {
        auto parsed = options.parse(argc, argv);

        auto processName = parsed["process"].as<std::string>();
        auto file = parsed["file"].as<std::string>();

        DWORD pid = NULL;

        ARDUVO_LOG_INFO("Iterating process list...");
        { pid = ProcessFinder().findProcess(processName); } // Scoped to ensure immediate destruction of TlHelp32 snapshot

        if (pid == NULL)
            throw std::runtime_error("Could not find running process with name: " + processName);

        ARDUVO_LOG_INFO("Found target process: {}({})", processName, pid);
        inject(pid, std::move(file));
    } catch (const cxxopts::OptionException& ex) {
        ARDUVO_LOG_ERROR(ex.what());
        ARDUVO_LOG_ERROR(options.help());

        error = -1;
    } catch (const std::runtime_error& ex) {
        ARDUVO_LOG_ERROR(ex.what());

        error = -1;
    }

    logging::cleanup();
    return error;
}
