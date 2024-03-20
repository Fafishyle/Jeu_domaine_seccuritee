#include "Folder.h"
#include <iostream>
#include <string.h>
using namespace std;

int main (void)
{
    std::string entree;
    

    while (entree != "exit")
    {
    std::getline(std::cin, entree); // Lire une ligne entière depuis l'entrée
    if (entree == "ls") {
        // Faire quelque chose si la commande est "ls" tout court
        std::cout << "Commande 'ls' tout court" << std::endl;
    } else if (entree.substr(0, 2) == "ls" && (entree.size() == 2 || entree[2] == ' ')) {
        // Faire quelque chose si la commande est "ls" suivie d'un argument
        std::cout << "Commande 'ls' avec argument" << std::endl;
    }
    else{
        cout<<"autre"<<endl;
        }
    } 
        return 0;
}
