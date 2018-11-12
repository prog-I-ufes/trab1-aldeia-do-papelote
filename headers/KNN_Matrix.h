#ifndef _H_MATRIX
#define _H_MATRIX

#include "KNN_Dimension.h"

// ALOCA UMA MATRIZ DE INTEIROS DINAMICAMENTE
int **createMatrix(TDimension dim);
// ALOCA UMA MATRIZ DE CHAR DINAMICAMENTE
char **createCharacterMatrix(TDimension dim);
// ALOCA UMA MATRIZ DE CHAR COM LINHAS DE TAMANHO VARIADOS
char **create_R_CharacterMatrix(Tcsv_map map);
// ALOCA UMA MATRIZ DE doubleS DINAMICAMENTE
double **createdoubleMatrix(TDimension dim);
// LIBERA UMA MATRIZ DE INTEIROS DA MEMÓRIA
void freeMatrix(int **mat, int lines);
// LIBERA UMA MATRIZ DE CARACTERES DA MEMORIA
void freeCharacterMatrix(char** mat, int lines);
// LIBERA UMA MATRIZ DE doubleS DA MEMORIA
void freedoubleMatrix(double** mat, int lines);
// IMPRIME A MATRIZ NA TELA
void printMatrix(int **mat, TDimension dim);
// FAKEOFKAEOF
double **splitNumbers(Tcsv_data *csv, int *counter);
// ROAEKOREAK
Tcommand splitCommands(char* word);
#endif