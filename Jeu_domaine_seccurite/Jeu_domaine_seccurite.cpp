// Jeu_domaine_seccurite.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

//  Si terminal Linux : Exécuter le jeu sur un terminal Linux avec les commandes Bash
//  Pour compiler : g++ Jeu_domaine_seccurite.cpp -o Jeu_domaine_seccurite
//  Pour executer : ./Jeu_domaine_seccurite

//Concevoir un jeu dans le domaine de sécurité

#include <iostream>
#include <vector>
#include "File.h"
#include "Folder.h"
#include "ContentFile.h"

using namespace std;

// Pour colorier le texte du terminal
// Définition des codes ANSI pour les couleurs du texte
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

//Fonction ls
// Fonction pour lister les fichiers et les répertoires dans le répertoire actuel
void Ls_Command(const Folder* a_folder) {
    for (const auto& file : a_folder->my_files){ //Afficher fichier
        cout << file->my_name << '\n';
    }
    for (const auto& folder : a_folder->my_subfolders) { //Afficher fichier
        cout << folder->my_name << '\n';
    }
}


//Création du disque dur
Folder* create_drive()
{
    cout << "create_drive::Creation du disque dur..." << "! \n";
    //créer 10 dossiers ?
    Folder* myFolder = new Folder("Drive", "password123", 2);
    Folder* subFolder1 = new Folder("Dossier1","sub_password1", 2);   //Créé un sous-dossier
    myFolder->Add_Subfolder(subFolder1);

    cout << "create_drive::Disque dur cree" << "! \n";
    return myFolder;
}

// Programme principal
int main()
{
    Folder* Drive = create_drive();
    Folder* current_state = Drive; //Etat courant, pour le parcourt des dossiers

    string name_user = "";      // Nom de l'utilisateur
    cout << BLUE << "Bienvenue dans le jeu de la securite!\n Insere ton nom: "<< RESET<<"\n";
    cin >> name_user;
    cout << BLUE << "Bonjour "<< name_user << "! \n";
    cout << "On a trouve ce disque dur. \n"<<
        "On sait qu'il contient " << RED << "une clef de porte monnaie de crypto!\n"<< RESET <<
        BLUE << "Il faut explorer le filesystem et trouver des indices pour trouver la clef.\n "<<
        "Tu vas entrer dans un simulateur de terminal d'une machine.\n" <<
        "Tu vas decouvrir comment marche la securite."<< RESET <<"\n";
    cout << GREEN << "______________________Entree________________________\n";
    string enter_user = "";  // Commandes entrées par l'utilisateur
    while (enter_user != "Exit" && enter_user != "exit")
    {
        cout << GREEN<< "C:/Users/"<<name_user<<":~$ "<< RESET;
        cin >> enter_user;
        // Exécution de la commande saisie
        if (enter_user == "ls") { //commande ls tout court
            Ls_Command(current_state); // Affiche les fichiers et les répertoires
        }
        else if (enter_user.substr(0, 2) == "ls" && enter_user.substr(3).find_first_not_of(' ') == std::string::npos)
        //commande ls avec argument
        {
            std::cout << "ls avec argument" <<std::endl;
            std::string argument = enter_user.substr(3);
            for (const auto& subfolder : current_state->my_subfolders)
            {
                if (subfolder->my_name == argument)
                {
                    Ls_Command(subfolder);
                }
            } 
        }
        else if (enter_user.substr(0, 2) == "cd") {
            cout << GREEN << "Commande 'cd' pas encore implémenté."<< RESET <<"\n";
        }
        else if (enter_user.substr(0, 5) == "mkdir") {
            cout << GREEN << "Commande 'mkdir' pas encore implémenté." << RESET << "\n";
        }
        else
        {
            cout << GREEN << "Nous ne connaissons pas cette commande." << RESET << "\n";
        }
    }
    cout << GREEN << "______________________Sortie________________________\n";
    cout << "Jeu fini ! "<< RESET << "\n";
    return 0;
    
}
