#include "File.h"
#include "File.h"
#include <iostream>

File::File(std::string un_name) :
    name(un_name)
{
    std::cout << "File::Un fichier a ete cree!" << std::endl;
}
