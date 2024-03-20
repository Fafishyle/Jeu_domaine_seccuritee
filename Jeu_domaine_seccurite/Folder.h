#pragma once
#include "File.h"
#include <string>
#include <vector>

class Folder : public File
{
private:
        std::vector <File> content;
        std::string password;
public:
     void Open();
};

