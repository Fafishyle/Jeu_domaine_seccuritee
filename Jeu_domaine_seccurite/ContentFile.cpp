#include "ContentFile.h"
#include "File.h"
#include <iostream>

ContentFile::ContentFile(std::string a_name, std::string a_extension, int a_size, std::string a_content) :
    my_extension(a_extension), my_size(a_size), my_content(a_content), File(a_name)
{
    std::cout << "ContentFile::Un contenu est cree!" << std::endl;
}

void ContentFile::Open()
{
    if (this->my_extension == "TXT") {

    }
    else if (this->my_extension == "PNG") {

    }
    else if (this->my_extension == "MID") {

    }
    else if (this->my_extension == "EXE") {

    }
}