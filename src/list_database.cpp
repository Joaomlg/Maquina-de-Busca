#include <iostream>
#include <string>
#include <dirent.h>
#include <vector>
#include "list_database.h"

using namespace std;

vector <string> requestArchievs(string pasta){

    DIR *diretorio;
    struct dirent *lsdir;
    string arquivo, line;
    int tamanho, contador=0;
    vector <string> arquivos;

    diretorio = opendir(pasta.c_str());

    while ( ( lsdir = readdir(diretorio) ) != NULL )
    {
        arquivo = lsdir->d_name;
        tamanho = arquivo.length();
        contador++;
        arquivos.push_back(lsdir->d_name);
        
    }

    closedir(diretorio);

    return arquivos;
}