#include <stdio.h>
#include <stdlib.h>
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
	path = (char*) malloc(strlen(static_path) + 1);
	strcpy(path, static_path);
	
	return path;
}
// LE UM ARQUIVO INTEIRO E ARMAZENA NUM VETOR DE STRINGS
int lineNumberFile(FILE* f){
	int number = 0;
	int character;
	while((character=fgetc(f))!= EOF){
		if(character == '\n') number++;
	}
	return number;
}