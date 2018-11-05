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
Tcsv_data* readFileToMatrix(char* f);
// MOSTRA O NUMERO DE LINHAS DE UM ARQUIVO
void lineNumberFile(char* path, Tcsv_data *csv);
// OMITE N LINHAS DA LEITURA DO ARQUIVO
void omitLines(FILE* f, int n);

#endif