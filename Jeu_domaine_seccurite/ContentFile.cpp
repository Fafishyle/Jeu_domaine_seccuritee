#include "ContentFile.h"
#include "File.h"
#include <iostream>

ContentFile::ContentFile(std::string un_name, std::string un_extension, int un_taille, std::string un_content) : 
    extension(un_extension), taille(un_taille), content(un_content), File(un_name)
{
    std::cout << "ContentFile::Un dossier est cree!" << std::endl;
}

void ContentFile::Open()
{
    if (this->extension == "TXT") {

    }
    else if (this->extension == "PNG") {

    }
    else if (this->extension == "MID") {

    }
    else if (this->extension == "EXE") {

    }
}