#ifndef _H_FILEMANAGER
#define _H_FILEMANAGER

#include <stdio.h>
#include "KNN_Dimension.h"

// ABRE UM ARQUIVO DE ACORDO COM O MODO
FILE* openFile(char* name, char mode);
// FECHA UM ARQUIVO
void closeFile(FILE* f);
// LE UMA LINHA DE UM ARQUIVO
char* readLineFile(FILE* f);
// LE UM ARQUIVO INTEIRO E ARMAZENA NUMA MATRIZ
Tcsv_data* readFileToMatrix(char* path);
// LE UM ARQUIVO DE INSTRUÇÕES E ARMAZENA NUM VETOR
Tcommand_data* readInstructions(char* path);
// OMITE N LINHAS DA LEITURA DO ARQUIVO
void omitLines(FILE* f, int n);

#endif