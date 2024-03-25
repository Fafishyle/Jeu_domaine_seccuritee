#include "File.h"
#include "windows.h"
#include <iostream>

#define A 220
#define B 247
#define C 261
#define E 330
#define G 392


File::File()
{
    my_name = "Untitled";
};

File::File(std::string a_name, std::string extension) :
    my_name(a_name), my_extension(extension)
{
};

void File::Renamed(std::string a_name)
{
    my_name = a_name;
};

void File::Open()
{
    if (my_extension == "txt") {
        std::string command = "notepad.exe ressources\\" + getFullName();
        system(command.c_str());
    }
    else if (my_extension == "png") {
        std::string command = "mspaint.exe ressources\\" + getFullName();
        system(command.c_str());
    }
    else if (my_extension == "mid") {
        Beep(C, 300);
        Beep(A, 300);
        Beep(B, 300);
        Beep(B, 300);
        Beep(A, 300);
        Beep(G, 300);
        Beep(E, 300);
    }
    else if (my_extension == "exe") {
        std::cout << "Erreur : programme illisible";
    }
}

std::string File::getFullName() {
    return my_name + "." + my_extension;
}