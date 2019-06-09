#ifndef LIST_DATABASE_H
#define LIST_DATABASE_H

#include <string>
#include <dirent.h>
#include <vector>

using namespace std;

//Organiza em uma lista, todos os arquivos do diretorio database
vector <string> requestArchievs(string path);

#endif