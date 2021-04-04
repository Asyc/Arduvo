#ifndef ARDUVO_SRC_PROCESS_PROCESS_FINDER_HPP_
#define ARDUVO_SRC_PROCESS_PROCESS_FINDER_HPP_

#include <Windows.h>

#include <string_view>

class ProcessFinder {
public:
    ProcessFinder();
    ProcessFinder(const ProcessFinder& rhs) = delete;
    ProcessFinder(ProcessFinder&& rhs) noexcept;

    ProcessFinder& operator=(const ProcessFinder& rhs) = delete;
    ProcessFinder& operator=(ProcessFinder&& rhs) noexcept;

    ~ProcessFinder();

    DWORD findProcess(const std::string_view& name) const;
private:
    HANDLE m_TlhSnapshot;
};

#endif //ARDUVO_SRC_PROCESS_PROCESS_FINDER_HPP_
