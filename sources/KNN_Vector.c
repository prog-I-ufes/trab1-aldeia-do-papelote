#include "../headers/KNN_Vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// ALOCA UM VETOR DE FLOATS DINAMICAMENTE
float* create_F_Vector(int length){
	float *v = (float*) malloc(sizeof(float) * length);
	return v;
}
// LIBERA UM VETOR DE FLOATS DA MEMORIA
void free_F_Vector(float* v){ free(v); }
// ALOCA UM VETOR DE FLOATS DINAMICAMENTE
float* create_F_Vector(float length){

}
// LIBERA UM VETOR DE FLOATS DA MEMORIA
void free_F_Vector(float* v){

}
// SOMA O VETOR V COM O VETOR W
float* sum_F_Vector(float *v, float *w, float len){

}
// SUBTRAI O VETOR W DO VETOR V
float* subtract_F_Vector(float *v, float *w, float len){

}
// PRODUTO floatERNO ENTRE O VETOR V E O VETOR W
float product_F_Vector(float *v, float *w, float len){

}
// CRIA UM VETOR QUE É O QUADRADO DE V
float* square_F_Vector(float *v, float len){

}
// CRIA UM VETOR QUE É OS ELEMENTOS DE V ELEVADOS A N
float* pow_F_Vector(float *v, float len, float n){

}
// CRIA UM VETOR QUE É O VALOR ABSOLUTO DOS ELEMENTOS
float* abs_F_Vector(float *v, float len){

}
// SOMATÓRIO DOS ELEMENTOS DO VETOR DE floatEIROS
float sum_Elements_F_Vector(float *v, float len){

}

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
int product_I_Vector(int *v, int *w, int len){
	int i = 0;
	int product = 0;
	for( i = 0 ; i < len ; i++ )
		product += v[i] * w[i];
	return product;
}
// CRIA UM VETOR QUE E O QUADRADO DE V
int* square_I_Vector(int *v, int len){
	int i = 0;
	int *w = create_I_Vector(len);
	for( i = 0 ; i < len ; i++ )
		w[i] = v[i] * v[i];
	return w;
}
// CRIA UM VETOR QUE É OS ELEMENTOS DE V ELEVADOS A N
int* pow_I_Vector(int *v, int len, int n){
	int i = 0;
	int *w = create_I_Vector(len);
	for( i = 0 ; i < len ; i++ )
		w[i] = pow(v[i], n);

	return w;
}
// CRIA UM VETOR QUE É O VALOR ABSOLUTO DOS ELEMENTOS
int* abs_I_Vector(int *v, int len){
	int i = 0;
	int *w = create_I_Vector(len);
	for( i = 0 ; i < len ; i++ )
		w[i] = fabs(v[i]);

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
	for( i = 0 ; i < len ; i++ )
		sum += v[i];

	return sum;
}
