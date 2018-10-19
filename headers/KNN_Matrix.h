#include "KNN_Dimension.h"

// ALOCA UMA MATRIZ DINAMICAMENTE
int **createMatrix(TDimension dim);
// LIBERA UMA MATRIZ DA MEMÓRIA
void freeMatrix(int **mat, TDimension dim);
// IMPRIME A MATRIZ NA TELA
void printMatrix(int **mat, TDimension dim);