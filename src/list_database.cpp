#include <iostream>
#include <string>
#include <dirent.h>
#include <vector>
#include <cstdlib>
#include "list_database.h"

using namespace std;

vector <string> requestArchievs(string pasta){

    DIR *diretorio;
    struct dirent *lsdir;
    string arquivo;
    vector <string> arquivos, aux;

    diretorio = opendir(pasta.c_str());

    while ( ( lsdir = readdir(diretorio) ) != NULL )
    {
        if( lsdir->d_type == DT_REG ){
            arquivos.push_back(lsdir->d_name);
        } else{
            aux = requestArchievs(lsdir->d_name);
            for(int i=0; i<aux.size(); i++){
                arquivos.push_back(aux[i].c_str);
            }
        }
        
    }

    closedir(diretorio);

    return arquivos;
}