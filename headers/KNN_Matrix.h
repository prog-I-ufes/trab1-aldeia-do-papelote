#ifndef _H_MATRIX
#define _H_MATRIX

#include "KNN_Dimension.h"
#include "KNN_Vector.h"

// Procura quantos rotulos distintos estão presentes numa matriz
int distinctRotules(double **m, int lines, int rows);

// Aloca uma matriz de inteiros dinamicamente
int **createMatrix(TDimension dim);

// Aloca uma matriz de caracteres dinamicamente
char **createCharacterMatrix(TDimension dim);

// Aloca uma matriz de caracteres dinamicamente
// com linhas de tamanho variado
char **create_R_CharacterMatrix(Tcsv_map map);

// Aloca uma matriz de doubles dinamicamente
double **createdoubleMatrix(TDimension dim);

// Libera uma matriz de inteiros da memoria
void freeMatrix(int **mat, int lines);

// Libera uma matriz de caracteres da memoria
void freeCharacterMatrix(char** mat, int lines);

// Libera uma matriz de doubles da memoria
void freedoubleMatrix(double** mat, int lines);

// Imprime uma matriz de inteiros na tela
void printMatrix(int **mat, TDimension dim);

// Transforma a matriz de caracteres presente na estrutura
// Tcsv_data em uma matriz de doubles
double **splitNumbers(Tcsv_data *csv, int *counter);

// Transforma uma instrução lida em caracteres do arquivo
// config.txt pra uma estrutura do tipo Tcommand
Tcommand splitCommands(char* word);

#endif