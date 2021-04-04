#include "file.hpp"

#include <filesystem>
#include <fstream>
#include <stdexcept>

File::File(std::string path) : m_Path(std::move(path)) {}

bool File::exists() const {
    return std::filesystem::is_regular_file(m_Path);
}

std::vector<char> File::readFileData() const {
    std::ifstream in(m_Path, std::ios_base::binary | std::ios_base::ate);
    if (!in.is_open())
        throw std::runtime_error("Could not access file: " + m_Path);

    auto pos = in.tellg();
    in.seekg(0);

    std::vector<char> buffer(pos);
    in.read(buffer.data(), buffer.size());

    return std::move(buffer);
}

const std::string& File::getPath() const {
    return m_Path;
}
