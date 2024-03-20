#pragma once
#include "File.h"
#include <string>
#include <vector>

class Folder : public File
{
public:
    int my_file_count; //Nombre de fichier qu'il contient
    int my_subfolder_count; //Nombre de dossier qu'il contient
    std::vector <File*> my_files;   //Pointeur vers des fichiers, pour éviter les problèmes de mémoires
    std::vector <Folder*> my_subfolders; //Pointeur vers des dossiers, pour éviter les problèmes de mémoires
    std::string my_password;
public:
    Folder(std::string a_password, int a_file_count);
    void Add_Subfolder(Folder* a_subfolder);
    void Add_File(File* a_file);
    void Open();
};

