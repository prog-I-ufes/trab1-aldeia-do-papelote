#ifndef _H_MATRIX
#define _H_MATRIX

#include "KNN_Dimension.h"

// ALOCA UMA MATRIZ DE INTEIROS DINAMICAMENTE
int **createMatrix(TDimension dim);
// ALOCA UMA MATRIZ DE CHAR DINAMICAMENTE
char **createCharacterMatrix(TDimension dim);
// ALOCA UMA MATRIZ DE CHAR COM LINHAS DE TAMANHO VARIADOS
char **create_R_CharacterMatrix(Tcsv_map map);
// LIBERA UMA MATRIZ DE INTEIROS DA MEMÓRIA
void freeMatrix(int **mat, int lines);
// LIBERA UMA MATRIZ DE CARACTERES DA MEMORIA
void freeCharacterMatrix(char** mat, int lines);
// IMPRIME A MATRIZ NA TELA
void printMatrix(int **mat, TDimension dim);

#endif