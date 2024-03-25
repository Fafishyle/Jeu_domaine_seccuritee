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

//permet de créer un dossier composé de exactement 1 sous-dossier + 1 puzzle
Folder* Create_Classic_Level(Folder* parent_folder, int level, std::string extension, std::string word_pass)
{
        std::string folder_name = "dossier" + std::to_string(level);
        Folder* subfolder = new Folder(folder_name, word_pass, 1);
        std::string file_name = "puzzle" + std::to_string(level);
        File* file = new File(file_name, extension);
        parent_folder->Add_File(file);
        parent_folder->Add_Subfolder(subfolder);
        subfolder->parent_folder = parent_folder;
        return subfolder;
}

//Création du disque dur
Folder* create_drive()
{
    Folder* myFolder = new Folder("Drive", "", 0);
    myFolder->parent_folder = nullptr;

    Folder* puzzle1 = new Folder("etape1","azerty", 0);   //Créé un sous-dossier
    File* indice1 = new File("bienvenue", "txt");
    myFolder->Add_Subfolder(puzzle1);
    myFolder->Add_File(indice1);

    Folder* puzzle2 = new Folder("etape2", "krakatoa18", 0);
    File* indice2 = new File("puzzle2", "txt");
    puzzle1->Add_Subfolder(puzzle2);
    puzzle1->Add_File(indice2);

    Folder* puzzle3 = new Folder("etape3", "jakadi", 0);
    File* indice3 = new File("puzzle3", "png");
    puzzle2->Add_Subfolder(puzzle3);
    puzzle2->Add_File(indice3);

    Folder* puzzle4 = new Folder("etape4", "spaghetti", 0);
    File* indice4 = new File("puzzle4", "txt");
    puzzle3->Add_Subfolder(puzzle4);
    puzzle3->Add_File(indice4);

    Folder* puzzle5 = new Folder("etape5", "pandore", 0);
    File* indice5 = new File("51324", "txt");
    puzzle4->Add_Subfolder(puzzle5);
    puzzle4->Add_File(indice5);

    Folder* puzzle6 = new Folder("etape6", "cabbage", 0);
    File* indice6 = new File("melody", "mid");
    puzzle5->Add_Subfolder(puzzle6);
    puzzle5->Add_File(indice6);

    Folder* puzzle7 = new Folder("wallet_key", "123456", 0);
    File* indice7 = new File("worst_password", "txt");
    puzzle6->Add_Subfolder(puzzle7);
    puzzle6->Add_File(indice7);

    File* key = new File("key", "txt");
    puzzle7->Add_File(key);

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
    string user_input = "";  // Commandes entrées par l'utilisateur
    vector<string> command;

    bool exit_flag = false;

    std::cout << GREEN << "Utilisez la commande OPEN bienvenue.txt pour ouvrir votre premier indice.\n" << RESET;

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
                    cout << "commande parent";
                    if (cwd->parent_folder == nullptr) {
                        std::cout << RED << "Erreur : Pas de dossier parent (racine)" << RESET << "\n";
                    }
                    else {
                        cwd->isLocked = false;
                        cwd = cwd->parent_folder;
                    }
                    goto await_input;
                }
                string foldername = command[1];
                for (Folder* f : cwd->my_subfolders) {
                    if ((f->my_name) == foldername) {
                        cwd = f; //déplacer ? ou non? pour la commande cd ..
                        if (f->isLocked) {
                            if (promptPassword(f->my_password)) {
                                //password ok
                                std::cout << GREEN << "Mot de passe valide!" << RESET << "\n";
                                f->isLocked = false;
                                //cwd = f;
                            }
                            else {
                                //wrong password
                                std::cout << RED << "Erreur : Mot de passe incorrect" << RESET << "\n";
                            }
                        }
                        else {
                            cwd = f;
                        }
                        goto await_input;
                    }
                }
                std::cout << RED << "Erreur : dossier introuvable" << RESET << "\n";
            }



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

