#include "../headers/KNN_Vector.h"
#include "../headers/KNN_Dimension.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
-------------------------------------------------------------------
MANIPULACAO DE INTS
-------------------------------------------------------------------
*/

// Aloca um vetor de inteiros dinamicamente
int* create_I_Vector(int length){
	int *v = (int*) malloc(sizeof(int) * length);
	return v;
}

// Libera um vetor de inteiros da memoria
void free_I_Vector(int* v){	free(v); }

// Cria um vetor de inteiros que e a soma de V com W
int* sum_I_Vector(int *v, int *w, int len){
	int i = 0;
	int *z = create_I_Vector(len);
	for( i = 0 ; i < len ; i++ )
		z[i] = v[i] + w[i];
	return z;
}

// Cria um vetor de inteiros que e a subtracao de V com W
int* subtract_I_Vector(int *v, int *w, int len){
	int i = 0;
	int *z = create_I_Vector(len);
	for( i = 0 ; i < len ; i++ )
		z[i] = v[i] - w[i];
	return z;	
}

// Retorna o produto interno entre V e W
int product_I_Vector(int *v, int *w, int len){
	int i = 0;
	int product = 0;
	for( i = 0 ; i < len ; i++ )
		product += v[i] * w[i];
	return product;
}

// Cria um vetor que e o quadrado de V
int* square_I_Vector(int *v, int len){
	int i = 0;
	int *w = create_I_Vector(len);
	for( i = 0 ; i < len ; i++ )
		w[i] = v[i] * v[i];
	return w;
}

// Cria um vetor que e o V elevado a N
int* pow_I_Vector(int *v, int len, int n){
	int i = 0;
	int *w = create_I_Vector(len);
	for( i = 0 ; i < len ; i++ )
		w[i] = pow(v[i], n);

	return w;
}

// Cria um vetor que e o valor absoluto de V
int* abs_I_Vector(int *v, int len){
	int i = 0;
	int *w = create_I_Vector(len);
	for( i = 0 ; i < len ; i++ )
		w[i] = fabs(v[i]);

	return w;
}

// Retorna o somatorio dos elementos de V
int sum_Elements_I_Vector(int *v, int len){
	int i = 0;
	int sum = 0;
	for( i = 0 ; i < len ; i++ )
		sum += v[i];

	return sum;
}

// Imprime um vetor de inteiros na tela
void print_Vector(int *v, int len){
	int i = 0;
	for( i = 0 ; i < len ; i++ )
		printf("[%d]\n", v[i]);
}

// Retorna o elemento mais recorrente de um vetor de inteiros
int recorrence(int* v, int len){
	int elem = 0;
	int n_elem = 0;
	int pivot = 0;
	int n_pivot = 0;
	
	int w[len];

	int i = 0;
	int j = 0;
	
	for( i = 0 ; i < len ; i++ ){
		n_pivot = 0;
		pivot = v[i];
		for( j = 0 ; j < len ; j++ ){
			if(pivot == v[j]) n_pivot++;
		}
		if( n_pivot > n_elem ){
			elem = pivot;
			n_elem = n_pivot;
		}
	}
	
	return elem;
}

/*
-------------------------------------------------------------------
MANIPULACAO DE DOUBLES
-------------------------------------------------------------------
*/

// Imprime um vetor de doubles na tela
void print_F_Vector(double *v, int len){
	int i = 0;
	for( i = 0 ; i < len ; i++ )
		printf("[%f]\n", v[i]);
}

// Aloca um vetor de doubles dinamicamente
double* create_F_Vector(int length){
	double *v = (double*) malloc(sizeof(double) * length);
	return v;
}

// Libera um vetor de doubles da memoria
void free_F_Vector(double* v){ free(v); }

// Cria um vetor de doubles que e a soma de V com W
double* sum_F_Vector(double *v, double *w, int len){
	double* z = create_F_Vector(len);
	int i = 0;
	for( i = 0 ; i < len ; i++ ){
		z[i] = v[i] + w[i];
	}
	return z;
}

// Cria um vetor de doubles que e a subtracao de V com W
double* subtract_F_Vector(double *v, double *w, int len){
	double* z = create_F_Vector(len);
	int i = 0;
	for( i = 0 ; i < len ; i++ ){
		z[i] = v[i] - w[i];
	}
	return z;
}

// Retorna o produto interno entre V e W
double product_F_Vector(double *v, double *w, int len){
	int i = 0;
	double product = 0;
	for( i = 0 ; i < len ; i++ )
		product += v[i] * w[i];
	return product;
}

// Cria um vetor que e o quadrado de V
double* square_F_Vector(double *v, int len){
	double* z = create_F_Vector(len);
	int i = 0;
	for( i = 0 ; i < len ; i++ ){
		z[i] = pow(v[i],2);
	}
	return z;
}

// Cria um vetor que e o V elevado a N
double* pow_F_Vector(double *v, int len, double n){
	double* z = create_F_Vector(len);
	int i = 0;
	for( i = 0 ; i < len ; i++ ){
		z[i] = pow(v[i], n);
	}
	return z;
}

// Cria um vetor que e o valor absoluto de V
double* abs_F_Vector(double *v, int len){
	double* z = create_F_Vector(len);
	int i = 0;
	for( i = 0 ; i < len ; i++ ){
		if(v[i] < 0)
			v[i] *= -1;
		
		z[i] = v[i];
	}
	return z;
}

// Retorna o somatorio dos elementos de V
double sum_Elements_F_Vector(double *v, int len){
	int i = 0;
	double sum = 0;

	for( i = 0 ; i < len ; i++ )
		sum += v[i];

	return sum;
}

// Retorna o maior elemento de V
double max_F_Vector(double *v, int len){
	int i = 0;
	double max = v[0];

	for( i = 1 ; i < len ; i++ )
		if(max < v[i]) max = v[i];
	
	return max;
}

// Aloca um vetor de double com os K maiores elementos
void kMinors(double* dist, int len, int k, int* index){
	int i = 0;
	int j = 0;
	int aux;
	double aux_f;
	double* minor = create_F_Vector(k);
	int indexs[len];


	for( i = 0 ; i < len ; i++ )
		indexs[i] = i;

	for (i = 0 ; i < len - 1; i++){
  	  	for (j = 0 ; j < len - i - 1; j++){
  	  	   	if( dist[i] < dist[j] ){
				aux_f = dist[i];
				dist[i] = dist[j];
				dist[j] = aux_f;
				aux = indexs[i];
				indexs[i] = indexs[j];
				indexs[j] = aux;
			}
  	  	}
  	}

	for( i = 0 ; i < k ; i++ ){
		minor[i] = dist[i]; 
		index[i] = indexs[i];
	}

	free(minor);

}