#ifndef _H_DIMENSION
#define _H_DIMENSION

// Estrutura de dimensao X e Y
typedef struct Dimension{
	int x;
	int y;
} TDimension;

// Estrutura que guarda o numero de linhas
// e o tamanho de cada linha
typedef struct csv_map{
    int lines;
    int *length_line;
} Tcsv_map;

// Estrutura que guarda uma matriz de caracteres
// e csv_map que contem suas respectivas dimensoes
typedef struct csv_data{
    Tcsv_map map;
    char** data;
} Tcsv_data;

// Estrutura que guarda um comando do arquivo
// config.txt
// k = numero de k 
// distance = tipo de distancia
// r = variavel para calcular minkowsky
typedef struct command{
    int k;
    char distance;
    float r;
} Tcommand;

// Estrutura que guarda um vetor de comandos
// e csv_map que contem suas respectivas dimensoes
typedef struct command_data{
    Tcommand *data;
    Tcsv_map map;
} Tcommand_data;

// Libera uma estrutura do tipo Tcommand_data da memoria
void freeCommands(Tcommand_data *data);

#endif