#ifndef ARDUVO_SRC_FILE_FILE_HPP_
#define ARDUVO_SRC_FILE_FILE_HPP_

#include <string>
#include <vector>

class File {
public:
    File(std::string path);

    [[nodiscard]] bool exists() const;

    std::vector<char> readFileData() const;

    [[nodiscard]] const std::string& getPath() const;
private:
    std::string m_Path;
};

#endif //ARDUVO_SRC_FILE_FILE_HPP_
