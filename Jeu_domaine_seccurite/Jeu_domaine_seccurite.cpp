// Jeu_domaine_seccurite.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

//  Si terminal Linux : Exécuter le jeu sur un terminal Linux avec les commandes Bash
//  Pour compiler : g++ Jeu_domaine_seccurite.cpp -o Jeu_domaine_seccurite
//  Pour executer : ./Jeu_domaine_seccurite

//Concevoir un jeu dans le domaine de sécurité

#include <iostream>
#include <vector>
#include <sstream>
#include "File.h"
#include "Folder.h"
#include "ContentFile.h"

using namespace std;

//Fonction ls
// Fonction pour lister les fichiers et les répertoires dans le répertoire actuel
void listerFichiers(const Folder a_folder) {
    for (const auto& file : a_folder.my_files){
        /*
        if (files est de type dossier)
        {
            alors afficher arborescence 
                listerFichiers(files)
        }
        */
        std::cout << file->my_name << '\n';

    }
}

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

    std::cout << "create_drive::Disque dur créé" << "! \n";
    return myFolder;
}

vector<string> splitInput(const string& input) {
    istringstream iss(input);
    vector<string> arguments;
    string argument;
    while (iss >> argument) {
        if (!argument.empty()) {
            arguments.push_back(argument);
        }
    }
    return arguments;
}

// Programme principal
int main()
{
    Folder* Drive = create_drive();
    Folder* current_state = Drive; //Etat courant, pour le parcourt des dossiers

    string name_user = "";      // Nom de l'utilisateur
    std::cout << BLUE << "Bienvenue dans le jeu de la securite!\n Insere ton nom: "<< RESET<<"\n";
    cin >> name_user;
    std::cout << BLUE << "Bonjour "<< name_user << "! \n";
    std::cout << "On a trouve ce disque dur. \n"<<
        "On sait qu'il contient " << RED << "une clef de porte monnaie de crypto!\n"<< RESET <<
        BLUE << "Il faut explorer le filesystem et trouver des indices pour trouver la clef.\n "<<
        "Tu vas entrer dans un simulateur de terminal d'une machine.\n" <<
        "Tu vas decouvrir comment marche la securite."<< RESET <<"\n";
    std::cout << GREEN << "______________________Entree________________________\n";

    
     //vector<string> files = { "fichier1.txt", "fichier2.txt", "dossier1", "dossier2" };  // Fichiers contenus dans le disque
    
    Folder Drive = create_drive();
    string user_input = "";  // Commandes entrées par l'utilisateur
    
    vector<string> command;



    while (user_input != "Exit")
    {
        std::cout << GREEN<< "C:/Users/"<<name_user<<":~$ "<< RESET;
        cin >> user_input;

        //---parser la commande saisie
        //1. la mettre en minuscule
        for (int c = 0; c < user_input.size(); c++) {
            user_input[c] = tolower(user_input[c]);
        }

        //2. split les arguments
        command = splitInput(user_input);

        //---Exécution de la commande saisie
        if (command[0] == "ls") {
            listerFichiers(Drive); // Affiche les fichiers et les répertoires
        }
        else if (command[0] == "cd") {
            //vérifier si command[1] est dans la liste des folders dispo, si oui y bouger
            std::cout << GREEN << "Commande 'cd' pas encore implémenté."<< RESET <<"\n";
        }
        else if (command[0] == "mkdir") {
            //pas sûr que ça soit nécessaire ?
            std::cout << GREEN << "Commande 'mkdir' pas encore implémenté." << RESET << "\n";
        }
        else if (command[0] == "unpack") {
            //check que command[1] est un nom d'archive verrouillée
            std::cout << GREEN << "Commande 'unpack' pas encore implémenté." << RESET << "\n";
        }
        else
        {
            std::cout << GREEN << "Nous ne connaissons pas cette commande." << RESET << "\n";
        }
    }
    std::cout << GREEN << "______________________Sortie________________________\n";
    std::cout << "Jeu fini ! "<< RESET << "\n";
    return 0;
    
}
