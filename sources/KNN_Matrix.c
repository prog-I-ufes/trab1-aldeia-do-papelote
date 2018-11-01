#include "../headers/KNN_Matrix.h"
#include <stdlib.h>
#include <stdio.h>

// ALOCA UMA MATRIZ DE INTEIROS DINAMICAMENTE
int **createMatrix(TDimension dim){
	int i = 0;
	int **mat = (int**) malloc(sizeof(int) * dim.x);

	for( i = 0 ; i < dim.y ; i++ ){
		mat[i] = (int*) malloc(sizeof(int) * dim.y);
	}

	return mat;
}
// ALOCA UMA MATRIZ DE CARACTERES DINAMICAMENTE
char **createCharacterMatrix(TDimension dim){
	int i = 0;
	char **mat = (char**) malloc(sizeof(char) * dim.x);

	if(dim.y != -1)
		for( i = 0 ; i < dim.y ; i++ )
			mat[i] = (char*) malloc(sizeof(char) * dim.y);
		
	return mat;
}
// LIBERA UMA MATRIZ DE INTEIROS DA MEMORIA
void freeMatrix(int **mat, TDimension dim){
	int i = 0;
	for( i = 0 ; i < dim.x ; i++ )
		free(mat[i]);
	free(mat);
}
// LIBERA UMA MATRIZ DE CARACTERES DA MEMORIA
void freeCharacterMatrix(char **mat, TDimension dim){
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