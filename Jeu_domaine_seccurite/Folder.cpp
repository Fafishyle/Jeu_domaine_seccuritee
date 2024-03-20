#include "Folder.h"

Folder::Folder(std::string un_password, int un_file_count) : password(un_password), file_count(un_file_count){
    for (int i = 0; i < file_count; i++) {
        File* a_file = new File("Fichier" + std::to_string(i + 1)); // Un pointeur pour ajouter l'objet à la vector
        content.push_back(a_file);
    }
}

void Folder::Open()
{
}
