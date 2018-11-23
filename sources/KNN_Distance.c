#include "../headers/KNN_Vector.h"
#include "../headers/KNN_Distance.h"
#include <math.h>

// Calcula a distancia de chebyshev entre dois vetores
double chebyshevDistance(double *v, double *w, int len){
	double aux = 0;
	double distance = 0;
	int i = 0;

	for( i = 0 ; i < len ; i++ ){
		aux = sqrt(pow(v[i] - w[i], 2));
		if( aux > distance ) distance = aux;
	}
	
	return distance;
}

// Calcula a distancia euclidiana entre dois vetores
double euclidianDistance(double *v, double *w, int len){
	double aux = 0;
	double distance = 0;
	int i = 0;

	for( i = 0 ; i < len ; i++ ){
		aux = v[i] - w[i];
		aux *= aux;
		distance += aux;
	}

	return sqrt(distance);
}

// Calcula a distancia de minkowsky entre dois vetores
double minkowskyDistance(double *v, double *w, int len, double r){
	double aux = 0;
	double distance = 0;
	int i = 0;

	for( i = 0 ; i < len ; i++ ){
		// SUBTRACAO DE VETOR
		aux = v[i] - w[i];
		// VALOR ABSOLUTO
		if( aux < 0 ) aux *= -1;
		// SOMATORIO DAS DISTANCIAS
		distance += pow(aux, r);
	}
	
	distance = pow(distance, 1/r);

	return distance;
}
