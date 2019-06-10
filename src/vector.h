#ifndef VETOR_H
#define VETOR_H

#include <map>
#include <string>
#include <cmath>

using namespace std;

class Vector {
    private:
        // word, weight
		map<string, float> elements;

	public:
		//Instancia a classe com um map vazio
        Vector();  

        //Insere uma nova palavra com valor da sua coordenada
		void insert_coord(string word, float value);
		
        //Produto escalar entre dois velores
		float operator*(Vector x); 

        //Modulo do vetor
		float module();

        //Retorna o cosseno entre dois vetores
        float cos(Vector x);
};

#endif