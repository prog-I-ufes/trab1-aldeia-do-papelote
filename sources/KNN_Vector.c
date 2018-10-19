#include "../headers/KNN_Vector.h"
#include <stdlib.h>
#include <stdio.h>

int* create_I_Vector(int length){
	int *v = (int*) malloc(sizeof(int) * length);
	return v;
}

void free_I_Vector(int* v){	free(v); }

int* sum_I_Vector(int *v,int *w, int len){
	int i = 0;
	int *z = create_I_Vector(len);
	for( i = 0 ; i < len ; i++ )
		z[i] = v[i] + w[i];
	return z;
}

int* subtract_I_Vector(int *v, int *w, int len){
	int i = 0;
	int *z = create_I_Vector(len);
	for( i = 0 ; i < len ; i++ )
		z[i] = v[i] - w[i];
	return z;	
}

int* product_I_Vector(int *v, int *w, int len){
	int i = 0;
	int *z = create_I_Vector(len);
	for( i = 0 ; i < len ; i++ )
		z[i] = v[i] * w[i];
	return z;
}

int* square_I_Vector(int *v, int len){
	int i = 0;
	int *w = create_I_Vector(len);
	for( i = 0 ; i < len ; i++ )
		w[i] = v[i] * v[i];
	return w;
}

void print_Vector(int *v, int len){
	int i = 0;
	for( i = 0 ; i < len ; i++ )
		printf("[%d]\n", v[i]);
}