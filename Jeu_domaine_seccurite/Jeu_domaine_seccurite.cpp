// Jeu_domaine_seccurite.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

//  Si terminal Linux : Exécuter le jeu sur un terminal Linux avec les commandes Bash
//  Pour compiler : g++ Jeu_domaine_seccurite.cpp -o Jeu_domaine_seccurite
//  Pour executer : ./Jeu_domaine_seccurite

//Concevoir un jeu dans le domaine de sécurité

#include <iostream>
#include <vector>
using namespace std;

//Fonction ls
// Fonction pour lister les fichiers et les répertoires dans le répertoire actuel
void listerFichiers(const vector<string>& files) {
    for (const auto& file : files) {
        cout << file << '\n';
    }
}

// Programme principal
int main()
{
    string name_user = "";      // Nom de l'utilisateur
    cout << "Bienvenue dans le jeu de la securite!\n Insere ton nom: \n";
    cin >> name_user;
    cout << "Bonjour "<< name_user << "! \n";
    cout << "On a trouve ce disque dur. \n"<<
        "On sait qu'il contient une cle de porte monnaie de crypto.\n"<<
        "Il faut explorer le filesystem et trouver des indices pour trouver la clef! \n"<<
        "Tu vas entrer dans un simulateur de terminal d'une machine.\n" <<
        "Tu vas decouvrir comment marche la securite.\n";
    cout << "______________________Entree________________________\n";

    
    vector<string> files = { "fichier1.txt", "fichier2.txt", "dossier1", "dossier2" };  // Fichiers contenus dans le disque
    
    string enter_user = "";  // Commandes entrées par l'utilisateur
    while (enter_user != "Exit" && enter_user != "exit")
    {
        cout << "C:/Users/"<<name_user<<":~$ ";
        cin >> enter_user;
        // Exécution de la commande saisie
        if (enter_user == "ls") {
            listerFichiers(files); // Affiche les fichiers et les répertoires
        }
        else if (enter_user.substr(0, 2) == "cd") {
            cout << "Commande 'cd' non supportée dans cette version.\n";
        }
        else if (enter_user.substr(0, 5) == "mkdir") {
            cout << "Commande 'mkdir' non supportée dans cette version.\n";
        }
        else
        {
            cout << "Nous ne connaissons pas cette commande.\n";
        }
    }
    cout << "______________________Sortie________________________\n";
    cout << "Jeu fini ! \n";
    return 0;
    
}
