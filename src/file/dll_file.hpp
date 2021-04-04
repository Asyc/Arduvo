#ifndef ARDUVO_SRC_FILE_DLL_FILE_HPP_
#define ARDUVO_SRC_FILE_DLL_FILE_HPP_

#include "file.hpp"

class DllFile : public File {
public:
    DllFile(std::string path);

    void parseFile();
private:

};

#endif //ARDUVO_SRC_FILE_DLL_FILE_HPP_
