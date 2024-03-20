#include "File.h"
#include "File.h"
#include <iostream>

File::File()
{
    name = "Untitled";
};

File::File(std::string un_name) :
    name(un_name)
{
    std::cout << "File::Un File a ete cree!" << std::endl;
};

void File::Renamed(std::string un_name)
{
    name = un_name;
};
