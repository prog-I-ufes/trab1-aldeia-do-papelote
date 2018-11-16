#ifndef _H_FILEMANAGER
#define _H_FILEMANAGER

#include <stdio.h>
#include "KNN_Dimension.h"

// Abre um arquivo de acordo com o modo(char mode)
FILE* openFile(char* name, char mode);

// Fecha um arquivo
void closeFile(FILE* f);

// Le uma linha de um arquivo
char* readLineFile(FILE* f);

// Le um arquivo inteiro e armazena seus dados
// na estrutura Tcsv_data
Tcsv_data* readFileToMatrix(char* path);

// Le um arquivo de instrucoes e armazena seus dados
// na estrutura Tcommand_data
Tcommand_data* readInstructions(char* path);

// Omite n linhas da leitura de um arquivo
void omitLines(FILE* f, int n);

#endif