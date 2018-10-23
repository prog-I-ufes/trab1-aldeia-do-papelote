#include "../headers/KNN_Vector.h"
#include <stdlib.h>
#include <stdio.h>

// ALOCA UM VETOR DINAMICAMENTE
int* create_I_Vector(int length){
	int *v = (int*) malloc(sizeof(int) * length);
	return v;
}
// LIBERA UM VETOR DA MEMORIA
void free_I_Vector(int* v){	free(v); }
// SOMA O VETOR V COM O VETOR W
int* sum_I_Vector(int *v,int *w, int len){
	int i = 0;
	int *z = create_I_Vector(len);
	for( i = 0 ; i < len ; i++ )
		z[i] = v[i] + w[i];
	return z;
}
// SUBTRAI O VETOR W DO VETOR V
int* subtract_I_Vector(int *v, int *w, int len){
	int i = 0;
	int *z = create_I_Vector(len);
	for( i = 0 ; i < len ; i++ )
		z[i] = v[i] - w[i];
	return z;	
}
// PRODUTO INTERNO ENTRE O VETOR V E O VETOR W
int* product_I_Vector(int *v, int *w, int len){
	int i = 0;
	int *z = create_I_Vector(len);
	for( i = 0 ; i < len ; i++ )
		z[i] = v[i] * w[i];
	return z;
}
// CRIA UM VETOR QUE E O QUADRADO DE V
int* square_I_Vector(int *v, int len){
	int i = 0;
	int *w = create_I_Vector(len);
	for( i = 0 ; i < len ; i++ )
		w[i] = v[i] * v[i];
	return w;
}
// IMPRIME O VETOR NA TELA
void print_Vector(int *v, int len){
	int i = 0;
	for( i = 0 ; i < len ; i++ )
		printf("[%d]\n", v[i]);
}
// SOMATÓRIO DOS ELEMENTOS DO VETOR DE INTEIROS
int sum_Elements_I_Vector(int *v, int len){
	int i = 0;
	int sum = 0;

	for( i = 0 ; i < len ; i++ ){
		sum += v[i];
	}

	return sum;
}