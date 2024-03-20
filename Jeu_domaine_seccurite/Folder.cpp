#include "Folder.h"

Folder::Folder(std::string a_password, int a_file_count) : my_password(a_password), my_file_count(a_file_count){
    for (int i = 0; i < my_file_count; i++) {
        File* a_file = new File("Fichier" + std::to_string(i + 1)); // Un pointeur pour ajouter l'objet à la vector
        my_content.push_back(a_file);
    }
}

void Folder::Open()
{
}
