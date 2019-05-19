#ifndef VOCABULARY_H
#define VOCABULARY_H

#include <map>
#include <string>

using namespace std;

class Vetor
{
    private:
        // word, weight
		map<string, float> element;
	public:
		//Instancia a classe
        Vetor();  

        //Insere uma nova palavra com valor da sua coordenada
		void insert_coord(string word, float value);
		
        //Produto escalar entre dois velores
		float operator*(); 

        //Modulo do vetor
		float module();  
};

#endif