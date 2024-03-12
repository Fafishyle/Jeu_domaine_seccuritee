// Jeu_domaine_seccurite.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

//Concevoir un jeu dans le domaine de sécurité


#include <iostream>
using namespace std;

int main()
{
    string name_user = "";
    cout << "Bienvenue dans le jeu de la securite!\n Insère ton nom: \n";
    cin >> name_user;
    cout << "Bonjour "<< name_user << "! \n";
    cout << "On a trouvé ce disque dur"<<
        "On sait qu'il contient une clé de porte monnaie de crypto"<<
        "Il faut explorer le filesystem et trouver des indices pour trouver la clé!";
    cout << "Tu vas entrer dans un simulateur de terminal d'une machine." <<
        "Tu vas découvrir comment marche la sécurité dans les réseaux en général.\n";
    cout << "______________________Entrée________________________\n";

    string enter_user = "";
    while (enter_user != "Exit" || enter_user != "exit")
    {
        cout << "C:/Users/"<<name_user<<":~$ ";
        cin >> enter_user;
        cout << "Votre réponse : "<<enter_user<<"\n";
    }
    cout << "Jeu fini ! \n";
    return 0;
    
}
