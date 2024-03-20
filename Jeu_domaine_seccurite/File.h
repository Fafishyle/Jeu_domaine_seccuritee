#pragma once
#include <string>
#include <vector>

class File
{
public:
        std::string name;
public:
    File();
    File(std::string un_name);
    void Renamed(std::string un_name);
};

