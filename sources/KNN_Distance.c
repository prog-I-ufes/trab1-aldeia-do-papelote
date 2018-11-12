#include "../headers/KNN_Vector.h"
#include "../headers/KNN_Distance.h"
#include <math.h>

// CALCULA A DISTANCIA EUCLIDIANA
double euclidianDistance(double *v, double *w, int len){
	double aux = 0;
	double distance = 0;
	int i = 0;

	for( i = 0 ; i < len ; i++ ){
		aux = v[i] - w[i];
		aux *= aux;
		distance += aux;
	}

	sqrt(distance);

	return distance;
}
// CALCULA A DISTANCIA DE MINKOWSKY
double minkowskyDistance(double *v, double *w, int len, double r){
	double aux = 0;
	double distance = 0;
	int i = 0;

	for( i = 0 ; i < len ; i++ ){
		aux = sqrt(pow(v[i] - w[i], 2));
		distance += pow(aux, r);
	}
	
	distance = pow(distance, 1/r);

	return distance;
}
// CALCULA D DISTANCIA DE CHEBYSHEV
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