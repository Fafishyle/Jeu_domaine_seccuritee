#pragma once
#include "File.h"
#include <string>
#include <vector>

class ContentFile : public File
{
private:
    std::string my_extension;
    int my_size;
    std::string my_content;
public:
    ContentFile(std::string a_name, std::string a_extension, int a_size, std::string a_content);
    void Open();
};

