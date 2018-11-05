#include "../headers/KNN_Matrix.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// ALOCA UMA MATRIZ DE INTEIROS DINAMICAMENTE
int **createMatrix(TDimension dim){
	int i = 0;
	int **mat = (int**) malloc(sizeof(int*) * dim.x);

	for( i = 0 ; i < dim.x ; i++ ){
		mat[i] = (int*) malloc(sizeof(int) * dim.y);
	}

	return mat;
}
// ALOCA UMA MATRIZ DE CARACTERES DINAMICAMENTE
char **createCharacterMatrix(TDimension dim){
	int i = 0;
	char **mat = (char**) malloc(sizeof(char*) * dim.x);

	if(dim.y != -1)
		for( i = 0 ; i < dim.x ; i++ )
			mat[i] = (char*) malloc(sizeof(char) * dim.y);
		
	return mat;
}
// ALOCA UMA MATRIZ DE CHAR COM LINHAS DE TAMANHO VARIADOS
char** create_R_CharacterMatrix(Tcsv_map map){
	int i = 0;
	char **mat = (char**) malloc(sizeof(char*) * map.lines);

	for( i = 0 ; i < map.lines; i++ ){
		mat[i] = (char*) malloc(sizeof(char) * (map.length_line[i]));
	}

	return mat;
}
// LIBERA UMA MATRIZ DE INTEIROS DA MEMORIA
void freeMatrix(int **mat, int lines){
	int i = 0;
	for( i = 0 ; i < lines ; i++ )
		free(mat[i]);
	free(mat);
}
// LIBERA UMA MATRIZ DE CARACTERES DA MEMORIA
void freeCharacterMatrix(char **mat, int lines){
	int i = 0;
	for( i = 0 ; i < lines ; i++ )
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
// OFAEKOFKEFAE
float **splitNumbers(Tcsv_data *csv){
	int i = 0;
	int j = 0;
	int counter = 0;
	char** pch = (char**) malloc(sizeof(char*) * csv->map.lines);

	float** numbers = (float**) malloc(sizeof(float*) * csv->map.lines);

	counter = 0;

	pch[i] = strtok (csv->data[i],",");
	while (pch[i] != NULL){
  		pch[i] = strtok (NULL, ",");
		counter++;
  	}

	for( i = 0 ; i < csv->map.lines ; i++ ){
		numbers[i] = (float*) malloc(sizeof(float) * counter);

		//pch[i] = strtok (csv->data[i],",");
		printf("csv = %s \n", csv->data[i]);
		//numbers[i][j] = atof(pch[i]);
		//printf("%s \n", pch[i]);
		//j++;
	  	//while (1){
  		//	pch[i] = strtok (NULL, ",");
		//	printf("%s ", pch[i]);
		//	if(pch[i] != NULL)
		//		numbers[i][j] = atof(pch[i]);
		//	else break;
		//	j++;
		//}

		j = 0;	
	}

	for( i = 0 ; i < 105 ; i++ ){
		for( j = 0 ; j < 5 ; j++ ){}
			//printf("[%.2f]", numbers[i][j]);
		//printf("\n");
	}

	return numbers;
}