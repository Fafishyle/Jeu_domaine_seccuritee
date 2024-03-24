#pragma once
#include <string>
#include <vector>

class File
{
public:
    std::string my_name;
    std::string my_extension;
    int my_size;
    std::string my_content;
   
public:
    File();
    File(std::string a_name, std::string extension);
    void Open();
    std::string getFullName();
    void Renamed(std::string a_name);
};

