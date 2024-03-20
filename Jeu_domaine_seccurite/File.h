#pragma once
#include <string>
#include <vector>

class File
{
public:
        std::string my_name;
public:
    File();
    File(std::string a_name);
    void Renamed(std::string a_name);
};

