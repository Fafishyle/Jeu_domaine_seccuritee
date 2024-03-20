#include "File.h"
#include "File.h"
#include <iostream>

File::File()
{
    my_name = "Untitled";
};

File::File(std::string a_name, std::string extension) :
    my_name(a_name), my_extension(extension)
{
    std::cout << "File::Un fichier a ete cree!" << std::endl;
};

void File::Renamed(std::string a_name)
{
    my_name = a_name;
};

void File::Open()
{
    if (my_extension == "txt") {
        std::cout << my_content;
    }
    else if (my_extension == "png") {
        std::string command = "mspaint.exe ressources\\" + getFullName();
        system(command.c_str());
    }
    else if (my_extension == "mid") {
        
    }
    else if (my_extension == "exe") {
        std::cout << "Erreur : programme illisible";
    }
}

std::string File::getFullName() {
    return my_name + "." + my_extension;
}