#pragma once
#include "File.h"
#include <string>
#include <vector>

class ContentFile : public File
{
private:
    std::string extension;
    int taille;
    std::string content;
public:
    ContentFile(std::string un_name, std::string un_extension, int un_taille, std::string un_content);
    void Open();
};

