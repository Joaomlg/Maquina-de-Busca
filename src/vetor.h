#ifndef VETOR_H
#define VETOR_H

#include <map>
#include <string>

using namespace std;

class Vetor
{
    private:
        // word, weight
		map<string, float> element;
        float modulo;
        float somatorio;
	public:
		//Instancia a classe com um map vazio
        Vetor();  

        //Insere uma nova palavra com valor da sua coordenada
		void insert_coord(string word, float value);
		
        //Produto escalar entre dois velores
		float operator*(Vetor x); 

        //Modulo do vetor
		float module();  
};

#endif