#include "process_finder.hpp"

#include <TlHelp32.h>

#include <stdexcept>

ProcessFinder::ProcessFinder() : m_TlhSnapshot(CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL)) {
    if (m_TlhSnapshot == INVALID_HANDLE_VALUE)
        throw std::runtime_error("Failed to create ToolHelp32 snapshot");
}

ProcessFinder::ProcessFinder(ProcessFinder&& rhs) noexcept : m_TlhSnapshot(INVALID_HANDLE_VALUE) {
    std::swap(m_TlhSnapshot, rhs.m_TlhSnapshot);
}

ProcessFinder& ProcessFinder::operator=(ProcessFinder&& rhs) noexcept {
    if (this != &rhs) {
        std::swap(m_TlhSnapshot, rhs.m_TlhSnapshot);
    }

    return *this;
}
ProcessFinder::~ProcessFinder() {
    if (m_TlhSnapshot != INVALID_HANDLE_VALUE)
        CloseHandle(m_TlhSnapshot);
}

DWORD ProcessFinder::findProcess(const std::string_view& name) const {
    PROCESSENTRY32 entry;

    auto result = Process32First(m_TlhSnapshot, &entry);
    while (result) {
        if (name == entry.szExeFile) {
            return entry.th32ProcessID;
        }

        result = Process32Next(m_TlhSnapshot, &entry);
    }

    return NULL;
}
