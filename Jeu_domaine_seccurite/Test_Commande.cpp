#include "Folder.h"
#include <iostream>

int main (void)
{
    if (enter_user == "ls") { //commande ls tout court
    Ls_Command(current_state); // Affiche les fichiers et les répertoires
    }
    else if (enter_user.substr(0, 2) == "ls" && enter_user.substr(3).find_first_not_of(' ') == std::string::npos)
    //commande ls avec argument
    {
    }
        return 0;
}
