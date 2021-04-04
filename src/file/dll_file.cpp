#include "dll_file.hpp"

#include <Windows.h>
#include <winnt.h>

#include <stdexcept>

#include "log/logger.hpp"

DllFile::DllFile(std::string path) : File(std::move(path)) {}

void DllFile::parseFile() {
    auto buffer = readFileData();

    _IMAGE_DOS_HEADER header{};
    memcpy(&header, buffer.data(), sizeof(header));

    if (header.e_magic != IMAGE_DOS_SIGNATURE)
        throw std::runtime_error("Malformed DLL file, missing PE header");

    ARDUVO_LOG_INFO("DLL file has valid PE header");
}
