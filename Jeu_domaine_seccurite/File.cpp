#include "File.h"
#include "File.h"
#include <iostream>

File::File()
{
    my_name = "Untitled";
};

File::File(std::string a_name) :
    my_name(a_name)
{
    std::cout << "File::Un File a ete cree!" << std::endl;
};

void File::Renamed(std::string a_name)
{
    my_name = a_name;
};
