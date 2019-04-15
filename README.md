# Maquina-de-Busca

> --- Pré-processamento ---
### 1- Leitura de arquivos
  * Listar arquivos na base de dados;
  * Ler arquivos um a um, palavra por palavra;
  * Tratas palavras (LowerCase e sem caracter especial);
  * Inserir palavras no indice invertido (vocabulário).

### 2- Gerar coordenadas de cada palavra p/ documento
  * Calcular tf e idf de cada palavra do vocabulário por cada documento da base de dados;
  * Armazenar valores em uma estrutura de coordenadas.

> --- Inicio do programa ---
### 3- Entrada do usuário
  * Lê entrada de busca do usuário (query);
  * Trata query (separa palavras e trata-as);
  * Calcula coordenadas de cada palavra do vocabulário em relação à query;
  * Armazena coordenadas.

### 4- Rankeia documentos
  * Calcula similaridades de cada palavra da query por documento;
  * Calcula peso de cada documento (soma das similaridades de cada documento);
  * Descarta documentos com peso igual a zero;
  * Ordena documentos pelo peso (decrescente).

### 5- Saida
  * Exibe para o usuário os documentos relacionados à sua busca, em ordem.
