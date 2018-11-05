#include "../headers/KNN_FileManager.h"
#include "../headers/KNN_Matrix.h"
#include "../headers/KNN_Vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ABRE UM ARQUIVO DE ACORDO COM O MODO
FILE* openFile(char* name, char mode){
	switch( mode ){
		case 'w':
			return fopen(name, "wt");
		break;
		case 'r':
			return fopen(name, "rt");
		break;
		case 'a':
			return fopen(name, "a");
		break;
	}
}
// FECHA UM ARQUIVO
void closeFile(FILE* f){ fclose(f); }
// LE UMA LINHA DE UM ARQUIVO
char* readLineFile(FILE* f){
	char* path;
	char static_path[100];
	
	fscanf(f, "%s", static_path);
	
	path = (char*) malloc((sizeof(char)*strlen(static_path)) + sizeof(char));
	
	strcpy(path, static_path);
	
	return path;
}
// LE UM ARQUIVO INTEIRO E ARMAZENA NUM VETOR DE STRINGS
Tcsv_data *readFileToMatrix(char* path){
	Tcsv_data *csv = (Tcsv_data*) malloc(sizeof(Tcsv_data));
	
	int number = 0;
	int length = 0;
	int i = 0;
	char character;

	Tcsv_map map;

	FILE* f = openFile(path, 'r');

	if(f != NULL)
		while((character=fgetc(f)) != EOF){
			if(character == '\n') number++;
		}

	closeFile(f);
	f = openFile(path, 'r');

	map.lines = number;

	map.length_line = create_I_Vector(map.lines);

	number = 0;

	if(f != NULL)
		while((character=fgetc(f)) != EOF){
			if(character != '\n') length++;
			else{ 
				map.length_line[number] = length + 1;
				length = 0;
				number++;
			}
		}

	closeFile(f);

	csv->map = map;

	f = openFile(path, 'r');

	csv->data = create_R_CharacterMatrix(csv->map);
	
	closeFile(f);

	f = openFile(path, 'r');

	for( i = 0 ; i < csv->map.lines ; i++ )
		fscanf(f, "%s", csv->data[i]);

    return csv;
}
// OMITE N LINHAS DA LEITURA DO ARQUIVO
void omitLines(FILE* f, int n){
	int i = 0;
	char* word;
	for( i = 0 ; i < n ; i++ ){
		word = readLineFile(f);
		free(word);
	}

}