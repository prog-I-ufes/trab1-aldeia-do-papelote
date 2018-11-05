#include "../headers/KNN_Matrix.h"
#include <stdlib.h>
#include <stdio.h>

// ALOCA UMA MATRIZ DE INTEIROS DINAMICAMENTE
int **createMatrix(TDimension dim){
	int i = 0;
	int **mat = (int**) malloc(sizeof(int) * dim.x);

	for( i = 0 ; i < dim.x ; i++ ){
		mat[i] = (int*) malloc(sizeof(int) * dim.y);
	}

	return mat;
}
// ALOCA UMA MATRIZ DE CARACTERES DINAMICAMENTE
char **createCharacterMatrix(TDimension dim){
	int i = 0;
	char **mat = (char**) malloc(sizeof(char) * dim.x);

	if(dim.y != -1)
		for( i = 0 ; i < dim.x ; i++ )
			mat[i] = (char*) malloc(sizeof(char) * dim.y);
		
	return mat;
}
// ALOCA UMA MATRIZ DE CHAR COM LINHAS DE TAMANHO VARIADOS
void create_R_CharacterMatrix(Tcsv_data *map){
	int i = 0;
	map->data = (char**) malloc(sizeof(char) * map->map.lines);

	for( i = 0 ; i < map->map.lines; i++ ){
		map->data[i] = (char*) malloc(sizeof(char) * map->map.length_line[i]);
	}
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