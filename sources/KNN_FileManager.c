#include "../headers/KNN_FileManager.h"
#include "../headers/KNN_Matrix.h"
#include "../headers/KNN_Vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Abre um arquivo de acordo com o modo(char mode)
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

// Fecha um arquivo
void closeFile(FILE* f){ fclose(f); }

// Le uma linha de um arquivo
char* readLineFile(FILE* f){
	char* path;
	char static_path[100];
	
	fscanf(f, "%s", static_path);
	
	path = (char*) malloc((sizeof(char)*strlen(static_path)) + sizeof(char));
	
	strcpy(path, static_path);
	
	return path;
}

// Le um arquivo inteiro e armazena seus dados
// na estrutura Tcsv_data
Tcsv_data* readFileToMatrix(char* path){
	Tcsv_data *csv = (Tcsv_data*) malloc(sizeof(Tcsv_data));
	
	int number = 0;
	int length = 0;
	int i = 0, j = 0;
	char character;

	Tcsv_map map;

	// Abre o arquivo
	FILE* f = openFile(path, 'r');

	// Conta o numero de linhas
	if(f != NULL)
		while((character=fgetc(f)) != EOF){
			if(character == '\n') number++;
		}

	// Reabre o arquivo
	closeFile(f);
	f = openFile(path, 'r');

	// Guarda o numero de linhas
	map.lines = number;
	map.length_line = create_I_Vector(map.lines);

	number = 0;

	// Guarda o tamanho de cada linha + 1
	if(f != NULL)
		while((character=fgetc(f)) != EOF){
			if(character != '\n') length++;
			else{ 
				map.length_line[number] = length + 1;
				length = 0;
				number++;
			}
		}

	// Reabre o arquivo
	closeFile(f);
	f = openFile(path, 'r');

	// Guarda os dados de mapeamento
	csv->map = map;
	csv->data = create_R_CharacterMatrix(csv->map);
		
	// Leitura de cada linha
	for( i = 0 ; i < csv->map.lines ; i++ ){
		fscanf(f, "%s", csv->data[i]);
	}

	closeFile(f);

	return csv;
}

// Le um arquivo de instrucoes e armazena seus dados
// na estrutura Tcommand_data
Tcommand_data* readInstructions(char* path){
	Tcommand_data *data = (Tcommand_data*) malloc(sizeof(Tcommand_data));

	int number = 0;
	int length = 0;
	int i = 0;
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
	
	map.lines = number;
	map.length_line = create_I_Vector(map.lines);
	data->data = (Tcommand*) malloc(sizeof(Tcommand) * map.lines);

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
	data->map = map;
	
	f = openFile(path, 'r');
	omitLines(f, 3);
	fgetc(f);
	number = 0;


	for( i = 0 ; i < data->map.lines - 1 ; i++ ){
		palavra = (char*) malloc(sizeof(char) * data->map.length_line[i]);
		
		while((character = fgetc(f)) != '\n'){
			palavra[number] = character;
			number++;
		}
		number++;
		palavra[number] = '\0';
		number = 0;

		data->data[i] = splitCommands(palavra);

		free(palavra);		
	}

 	closeFile(f);
	
	return data;
}

// Omite n linhas da leitura de um arquivo
void omitLines(FILE* f, int n){
	int i = 0;
	char* word;
	for( i = 0 ; i < n ; i++ ){
		word = readLineFile(f);
		free(word);
	}
}