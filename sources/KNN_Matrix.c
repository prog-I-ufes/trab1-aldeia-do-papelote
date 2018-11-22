#include "../headers/KNN_Matrix.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Procura quantos rotulos distintos estão presentes numa matriz
int distinctRotules(double **m, int lines, int rows){
	int i = 0;
	int j = 0;

	int distinct = 0;
	int control = 1;

	int *vet = create_I_Vector(lines);

	for( i = 0 ; i < lines ; i++ ){
		for( j = 0 ; j < distinct ; j++ ){
			if(vet[j] == m[i][rows - 1]){
				control = 0;
				break;
			}
		}
		if(control){			
			vet[distinct] = m[i][rows - 1];
			distinct++;
		} else control = 1;
	}

	return distinct;
}

// Aloca uma matriz de inteiros dinamicamente
int **createMatrix(TDimension dim){
	int i = 0;
	int **mat = (int**) malloc(sizeof(int*) * dim.x);

	for( i = 0 ; i < dim.x ; i++ ){
		mat[i] = (int*) malloc(sizeof(int) * dim.y);
	}

	return mat;
}

// Aloca uma matriz de caracteres dinamicamente
char **createCharacterMatrix(TDimension dim){
	int i = 0;
	char **mat = (char**) malloc(sizeof(char*) * dim.x);

	if(dim.y != -1)
		for( i = 0 ; i < dim.x ; i++ )
			mat[i] = (char*) malloc(sizeof(char) * dim.y);
		
	return mat;
}

// Aloca uma matriz de caracteres dinamicamente
// com linhas de tamanho variado
char **create_R_CharacterMatrix(Tcsv_map map){
	int i = 0;
	char **mat = (char**) calloc(sizeof(char*), map.lines);

	for( i = 0 ; i < map.lines; i++ ){
		mat[i] = (char*) calloc(sizeof(char), (map.length_line[i]));
	}

	return mat;
}

// Aloca uma matriz de doubles dinamicamente
double **createdoubleMatrix(TDimension dim){
	int i = 0;
	double **mat = (double**) malloc(sizeof(double*) * dim.x);
	
	for( i = 0 ; i < dim.x ; i++ )
		mat[i] = (double*) malloc(sizeof(double) * dim.y);
	
	return mat;
}

// Libera uma matriz de inteiros da memoria
void freeMatrix(int **mat, int lines){
	int i = 0;
	for( i = 0 ; i < lines ; i++ )
		free(mat[i]);
	free(mat);
}

// Libera uma matriz de caracteres da memoria
void freeCharacterMatrix(char** mat, int lines){
	int i = 0;
	for( i = 0 ; i < lines ; i++ )
		free(mat[i]);
	free(mat);
}

// Libera uma matriz de doubles da memoria
void freedoubleMatrix(double** mat, int lines){
	int i = 0;
	for( i = 0 ; i < lines ; i++ )
		free(mat[i]);
	free(mat);
}

// Imprime uma matriz de inteiros na tela
void printMatrix(int **mat, TDimension dim){
	int i = 0;
	int j = 0;

	for( i = 0 ; i < dim.x ; i++ ){
		for( j = 0 ; j < dim.y ; j++ )
			printf("[%d]", mat[i][j]);
		printf("\n");
	}
}

// Transforma a matriz de caracteres presente na estrutura
// Tcsv_data em uma matriz de doubles
double **splitNumbers(Tcsv_data *csv, int *counter){
	int i = 0;
	int j = 0;
	*counter = 1;
	char character;
	char* cpy;
	char** pch = (char**) malloc(sizeof(char*) * csv->map.lines);

	double** numbers = (double**) malloc(sizeof(double*) * csv->map.lines);

	for( i = 0 ; i < csv->map.length_line[0] ; i++)
		if((character = csv->data[0][i]) == ',') (*counter)++;

	for( i = 0 ; i < csv->map.lines ; i++ ){
		cpy = malloc(sizeof(char) * csv->map.length_line[i]);
		strcpy(cpy, csv->data[i]);

		j = 0;
		numbers[i] = (double*) malloc(sizeof(double) * (*counter));
		pch[i] = strtok (cpy,",");
		numbers[i][j] = atof(pch[i]);
		j++;
	  	while (1){
  			pch[i] = strtok (NULL, ",");
			if(pch[i] != NULL)
				numbers[i][j] = atof(pch[i]);
			else break;
			j++;
		}

		free(cpy);
	}
	
	freeCharacterMatrix(pch, csv->map.lines);
	
	return numbers;
}

// Transforma uma instrução lida em caracteres do arquivo
// config.txt pra uma estrutura do tipo Tcommand
Tcommand splitCommands(char* word){
	Tcommand command;
	command.r = 0;
	char* pch;
	
	pch = strtok (word,", ");
	command.k = atoi(pch);
	pch = strtok (NULL, ", ");
	command.distance = pch[0];
	if(pch != NULL) pch = strtok (NULL, ", ");
	if(pch != NULL)	command.r = atof(pch);
	
	return command;
}