#pragma once
#include "File.h"
#include <string>
#include <vector>

class Folder : public File
{
public:
    int file_count;
    std::vector <File*> content;   //Pointeur vers des fichiers, pour �viter les probl�mes de m�moires
    std::string password;
public:
    Folder(std::string un_password, int un_file_count);
    void Open();
};

