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
	int i = 0, j = 0;
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
	csv->data = create_R_CharacterMatrix(csv->map);
	
	f = openFile(path, 'r');
	
	for( i = 0 ; i < csv->map.lines ; i++ ){
		fscanf(f, "%s", csv->data[i]);
	}

	closeFile(f);

	return csv;
}

Tcommand_data* readInstructions(char* path){
	Tcommand_data *data = (Tcommand_data*) malloc(sizeof(Tcommand_data));

	int number = 0;
	int length = 0;
	int i = 0, j = 0;
	char character;
	char* palavra;

	Tcommand command;

	Tcsv_map map;

	FILE* f = openFile(path, 'r');
	omitLines(f, 3);
	if(f != NULL)
		while((character=fgetc(f)) != EOF){
			if(character == '\n') number++;
		}

	closeFile(f);
	f = openFile(path, 'r');
	omitLines(f, 3);

	printf("\n%d\n", number);
	
	map.lines = number;
	data->data = (Tcommand*) malloc(sizeof(Tcommand) * number);

	number = 0;
	
	if(f != NULL)
		while((character=fgetc(f)) != EOF){
			if(character != '\n') length++;
			else{ 
				map.length_line[number] = length + 1;
				length = 0;
				number++;
			}
			printf("%d ", length + 1);
		}

	closeFile(f);
	printf("\n");
	data->map = map;
	
	f = openFile(path, 'r');
	omitLines(f, 3);

	for( i = 0 ; i < data->map.lines ; i++ ){
		palavra = (char*) malloc(sizeof(char) * data->map.length_line[i]);
		fscanf(f, "%s", palavra);

		//data->data[i] = splitCommands(palavra);

		//printf("%d %c %.2f \n", data->data[i].k, data->data[i].distance, data->data[i].r);

		free(palavra);
		
	}

	closeFile(f);
	
	return data;
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