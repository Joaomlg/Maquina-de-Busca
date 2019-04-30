#include <iostream>
#include <string>
#include <dirent.h>
#include "list_database.h"

using namespace std;

string requestArchievs(){

    DIR *diretorio;
    struct dirent *lsdir;
    string arquivo, arquivoSelecionado, line;
    int tamanho, contador=0;

    diretorio = opendir("../database/");

    /* Mostra todos arquivos txt no diretorio */
    while ( ( lsdir = readdir(diretorio) ) != NULL )
    {
        arquivo = lsdir->d_name;
        tamanho = arquivo.length();
        if( arquivo[tamanho-3]=='t' && arquivo[tamanho-2]=='x' && arquivo[tamanho-1]=='t'){
            contador++;
            cout << contador << " - " << lsdir->d_name <<endl;
        }
        
    }

    closedir(diretorio);

    //Retorna uma lista
    return arquivoSelecionado;
}