#include "../headers/KNN_Matrix.h"
#include <stdlib.h>
#include <stdio.h>

// ALOCA UMA MATRIZ DINAMICAMENTE
int **createMatrix(TDimension dim){
	int i = 0;
	int **mat = (int**) malloc(sizeof(int) * dim.x);

	for( i = 0 ; i < dim.y ; i++ ){
		mat[i] = (int*) malloc(sizeof(int) * dim.y);
	}

	return mat;
}
// LIBERA UMA MATRIZ DA MEMORIA
void freeMatrix(int **mat, TDimension dim){
	int i = 0;
	for( i = 0 ; i < dim.x ; i++ )
		free(mat[i]);
	free(mat);
}
// IMPRIME A MATRIZ NA TELA
void printMatrix(int **mat, TDimension dim){
	int i = 0;
	int j = 0;

	for( i = 0 ; i < dim.x ; i++ ){
		for( j = 0 ; j < dim.y ; j++ )
			printf("[%d]", mat[i][j]);
		printf("\n");
	}
}