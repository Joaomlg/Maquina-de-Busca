#include "list_database.h"

using namespace std;

vector <string> requestArchievs(string path){
    vector <string> files, aux;

    DIR *dir;
    dir = opendir(path.c_str());

    struct dirent *lsdir;
    while((lsdir = readdir(dir)) != NULL) {
        string curr_file = lsdir->d_name;
        if(curr_file != "." && curr_file != "..") {
            if(lsdir->d_type == DT_REG){
                files.push_back(curr_file);
            } else {
                aux = requestArchievs(path + "/" + curr_file);
                for(int i=0; i<aux.size(); i++){
                    files.push_back(aux[i]);
                }
            }
        }
    }

    closedir(dir);

    return files;
}