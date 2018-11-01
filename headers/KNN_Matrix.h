#ifndef _H_MATRIX
#define _H_MATRIX

#include "KNN_Dimension.h"

// ALOCA UMA MATRIZ DE INTEIROS DINAMICAMENTE
int **createMatrix(TDimension dim);
// ALOCA UMA MATRIZ DE CHAR DINAMICAMENTE
char **createCharacterMatrix(TDimension dim);
// LIBERA UMA MATRIZ DE INTEIROS DA MEMÓRIA
void freeMatrix(int **mat, TDimension dim);
// LIBERA UMA MATRIZ DE CARACTERES DA MEMORIA
void freeCharacterMatrix(char** mat, TDimension dim);
// IMPRIME A MATRIZ NA TELA
void printMatrix(int **mat, TDimension dim);

#endif