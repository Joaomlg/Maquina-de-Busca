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
    string arquivo, newDir, dirSum;
    vector <string> arquivos, aux;

    diretorio = opendir(pasta.c_str());
     
    if (diretorio == 0) {
        std::cerr << "Nao foi possivel abrir diretorio." << std::endl;
        exit (1);
    }

    while ( ( lsdir = readdir(diretorio) ) != NULL )
    {
        if( lsdir->d_type == DT_DIR ){
            arquivo = lsdir->d_name;
            if(arquivo.size()>2){
                newDir = pasta+"/"+arquivo;
                aux = requestArchievs(newDir);
                for(int i=0; i<aux.size(); i++){
                    arquivos.push_back(aux[i]);
                }
            }
        } else{
            arquivos.push_back(lsdir->d_name);
        }

    }
    
    closedir(diretorio);
    
    return arquivos;
}