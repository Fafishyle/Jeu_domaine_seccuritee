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
    ContentFile(std::string nom, std::string extension, int taille, std::string content);
    void Open();
};

