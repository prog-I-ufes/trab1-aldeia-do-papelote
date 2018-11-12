#include "../headers/KNN_Vector.h"
#include "../headers/KNN_Distance.h"
#include <math.h>

// CALCULA A DISTANCIA EUCLIDIANA
double euclidianDistance(double *v, double *w, int len){
	double *z;
	double *z_square;
	double distance = 0;

	z = subtract_F_Vector(v, w, len);
	z_square = square_F_Vector(z, len);
	free_F_Vector(z);

	distance = sqrt(sum_Elements_F_Vector(z_square, len));
	free_F_Vector(z_square);

	return distance;
}
// CALCULA A DISTANCIA DE MINKOWSKY
double minkowskyDistance(double *v, double *w, int len, double r){
	double *z = create_F_Vector(len);
	double distance = 0;
	int i = 0;

	for( i = 0 ; i < len ; i++ ){
		z[i] = v[i] - w[i];
		if( z[i] < 0 ) z[i] *= -1;
		z[i] = pow(z[i], r);
		distance += z[i];
	}
	
	distance = pow(distance, 1/r);

	free_F_Vector(z);

	return distance;
}
// CALCULA D DISTANCIA DE CHEBYSHEV
double chebyshevDistance(double *v, double *w, int len){
	double aux = 0;
	double distance = 0;
	int i = 0;

	for( i = 0 ; i < len ; i++ ){
		aux = v[i] - w[i];
		if( aux < 0 ) aux *= -1;
		if( aux > distance ) distance = aux;
	}
	
	return distance;
}