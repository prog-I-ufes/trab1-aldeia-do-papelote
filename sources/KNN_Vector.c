#include "../headers/KNN_Vector.h"
#include "../headers/KNN_Dimension.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

float* kMinors(float* dist, int len, int k, int* index){
	int i = 0;
	int j = 0;
	int aux;
	float aux_f;
	float* minor = create_F_Vector(k);
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

	minor[0] = dist[0];
	index[0] = indexs[0];

	for( i = 1 ; i < k ; i++ ){
		minor[i] = dist[i]; 
		index[i] = indexs[i];
	}

	return minor;
}

// ALOCA UM VETOR DE FLOATS DINAMICAMENTE
float* create_F_Vector(int length){
	float *v = (float*) malloc(sizeof(float) * length);
	return v;
}
// LIBERA UM VETOR DE FLOATS DA MEMORIA
void free_F_Vector(float* v){ free(v); }
// SOMA O VETOR V COM O VETOR W
float* sum_F_Vector(float *v, float *w, int len){
	float* z = create_F_Vector(len);
	int i = 0;
	for( i = 0 ; i < len ; i++ ){
		z[i] = v[i] + w[i];
	}
	return z;
}
// SUBTRAI O VETOR W DO VETOR V
float* subtract_F_Vector(float *v, float *w, int len){
	float* z = create_F_Vector(len);
	int i = 0;
	for( i = 0 ; i < len ; i++ ){
		z[i] = v[i] - w[i];
	}
	return z;
}
// PRODUTO floatERNO ENTRE O VETOR V E O VETOR W
float product_F_Vector(float *v, float *w, int len){
	int i = 0;
	float product = 0;
	for( i = 0 ; i < len ; i++ )
		product += v[i] * w[i];
	return product;
}
// CRIA UM VETOR QUE É O QUADRADO DE V
float* square_F_Vector(float *v, int len){
	float* z = create_F_Vector(len);
	int i = 0;
	for( i = 0 ; i < len ; i++ ){
		z[i] = v[i]*v[i];
	}
	return z;
}
// CRIA UM VETOR QUE É OS ELEMENTOS DE V ELEVADOS A N
float* pow_F_Vector(float *v, int len, float n){
	float* z = create_F_Vector(len);
	int i = 0;
	for( i = 0 ; i < len ; i++ ){
		z[i] = pow(v[i], n);
	}
	return z;
}
// CRIA UM VETOR QUE É O VALOR ABSOLUTO DOS ELEMENTOS
float* abs_F_Vector(float *v, int len){
	float* z = create_F_Vector(len);
	int i = 0;
	for( i = 0 ; i < len ; i++ ){
		if(v[i] < 0)
			v[i] *= -1;
		
		z[i] = v[i];
	}
	return z;
}
// SOMATÓRIO DOS ELEMENTOS DO VETOR DE floatEIROS
float sum_Elements_F_Vector(float *v, int len){
	int i = 0;
	float sum = 0;

	for( i = 0 ; i < len ; i++ )
		sum += v[i];

	return sum;
}
// RETORNA O MAXIMO ELEMENTO EM UM VETOR DE FLOATS
float max_F_Vector(float *v, int len){
	int i = 0;
	float max = v[0];

	for( i = 1 ; i < len ; i++ )
		if(max < v[i]) max = v[i];
	
	return max;
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
