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
#include "Jeu_domaine_seccurite.h"

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
        cout << file->getFullName() << '\n';
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
    Folder* subFolder1 = new Folder("dossier1","sub_password1", 2);   //Créé un sous-dossier
    File* file = new File("puzzle3", "png");
    File* file2 = new File("puzzle1", "txt");
    myFolder->Add_Subfolder(subFolder1);
    myFolder->Add_File(file);
    myFolder->Add_File(file2);

    std::cout << "create_drive::Disque dur cre" << "! \n";
    myFolder->parent_folder = nullptr;
    return myFolder;
}

void splitInput(const string& input, vector<string>* output) {
    stringstream ss(input);
    string s;
    while (std::getline(ss, s, ' ')) {
        output->push_back(s);
    }
}

bool promptPassword(string password) {
    std::cout << GREEN << "Ce dossier est verrouille. Veuillez entrer son mot de passe." << RESET << "\n";
    string user_input = "";
    std::getline(std::cin >> std::ws, user_input);
    return user_input == password;
}

// Programme principal
int main(){

    Folder* Drive = create_drive();
    Folder* cwd = Drive; //Current Working Directory : Etat courant, pour le parcourt des dossiers, cd etc

    string name_user = "";      // Nom de l'utilisateur

    std::cout << BLUE << "Bienvenue dans le jeu de la securite!\n Insere ton nom: "<< RESET<<"\n";
    cin >> name_user;
    std::cout << BLUE << "Bonjour "<< name_user << "! \n";
    std::cout << "On a trouve ce disque dur. \n";

    

    cout << "On sait qu'il contient " << RED << "une clef de porte monnaie de crypto!\n"<< RESET <<
        BLUE << "Il faut explorer le filesystem et trouver des indices pour trouver la clef.\n "<<
        "Tu vas entrer dans un simulateur de terminal d'une machine.\n" <<
        "Tu vas decouvrir comment marche la securite."<< RESET <<"\n";
    std::cout << GREEN << "______________________Entree________________________\n";

    
     //vector<string> files = { "fichier1.txt", "fichier2.txt", "dossier1", "dossier2" };  // Fichiers contenus dans le disque
    string user_input = "";  // Commandes entrées par l'utilisateur
    
    vector<string> command;

    bool exit_flag = false;



    while (!exit_flag)
    {
        await_input:
        command.clear();

        string arborescence = cwd->my_name;

        Folder* f = cwd;
        while (f->parent_folder != nullptr) {
            f = f->parent_folder;
            arborescence = f->my_name + '/' + arborescence;
        }

        arborescence = '/' + arborescence;

        std::cout << GREEN<< "C:/Users/"<<name_user<<arborescence<<":~$ "<< RESET;
        std::getline(std::cin >> std::ws, user_input);

        //---parser la commande saisie
        //1. la mettre en minuscule
        for (int c = 0; c < user_input.size(); c++) {
            user_input[c] = tolower(user_input[c]);
        }

        //2. split les arguments
        splitInput(user_input, &command);

        //---Exécution de la commande saisie
        if (command[0] == "ls") {
            Ls_Command(cwd); // Affiche les fichiers et les répertoires
        }
        else if (command[0] == "cd") {

            if (command.size() == 1) {
                std::cout << RED << "Argument manquant : nom du dossier" << RESET << "\n";
            }
            else {
                if (command[1] == "..") {
                    if (cwd->parent_folder == nullptr) {
                        std::cout << RED << "Erreur : Pas de dossier parent (racine)" << RESET << "\n";
                    }
                    else {
                        cwd = cwd->parent_folder;
                    }
                    goto await_input;
                }
                string foldername = command[1];
                for (Folder* f : cwd->my_subfolders) {
                    if ((f->my_name) == foldername) {
                        
                        if (f->isLocked) {
                            if (promptPassword(f->my_password)) {
                                //password ok
                                std::cout << GREEN << "Mot de passe valide" << RESET << "\n";
                                f->isLocked = false;
                                cwd = f;
                            }
                            else {
                                //wrong password
                                std::cout << RED << "Erreur : Mot de passe incorrect" << RESET << "\n";
                            }
                        }
                        goto await_input;
                    }
                }
                std::cout << RED << "Erreur : dossier introuvable" << RESET << "\n";
            }



        }
        else if (command[0] == "mkdir") {
            //pas sûr que ça soit nécessaire ?
            std::cout << GREEN << "Commande 'mkdir' pas encore implémenté." << RESET << "\n";
        }
        else if (command[0] == "unpack") {
            //check que command[1] est un nom d'archive verrouillée
            std::cout << GREEN << "Commande 'unpack' pas encore implémenté." << RESET << "\n";
        }
        else if (command[0] == "exit") {
            exit_flag = true;
        }
        else if (command[0] == "open") {
            if (command.size() == 1) {
                std::cout << RED << "Argument manquant : nom du fichier" << RESET << "\n";
            }
            else {
                string filename = command[1];
                for (File* f : cwd->my_files) {
                    if ((f->my_name + "." + f->my_extension) == filename) {
                        //ouvrir le fichier
                        f->Open();
                        goto await_input;
                    }
                }
                std::cout << RED << "Erreur : fichier introuvable" << RESET << "\n";
            }
            
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
