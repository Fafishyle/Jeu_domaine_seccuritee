#pragma once
#include "File.h"
#include <string>
#include <vector>

class Folder : public File
{
public:
    int my_file_count;
    std::vector <File*> my_content;   //Pointeur vers des fichiers, pour éviter les problèmes de mémoires
    std::string my_password;
public:
    Folder(std::string a_password, int a_file_count);
    void Open();
};

