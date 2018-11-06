#include "../headers/KNN_Vector.h"
#include "../headers/KNN_Distance.h"
#include <math.h>

// CALCULA A DISTANCIA EUCLIDIANA
float euclidianDistance(float *v, float *w, int len){
	float *z;
	float *z_square;
	float distance = 0;

	z = subtract_F_Vector(v, w, len);
	z_square = square_F_Vector(z, len);
	free_F_Vector(z);
	distance = sqrt(sum_Elements_F_Vector(z_square, len));
	free_F_Vector(z_square);

	return distance;
}
// CALCULA A DISTANCIA DE MINKOWSKY
float minkowskyDistance(float *v, float *w, int len, float r){
	float *z;
	float *z_aux;
	float distance = 0;

	z = subtract_F_Vector(v, w, len);
	z_aux = abs_F_Vector(z, len);
	free_F_Vector(z);
	z = pow_F_Vector(z_aux, len, r);
	free_F_Vector(z_aux);
	distance = pow(sum_Elements_F_Vector(z, len), 1.0/r);
	free_F_Vector(z);

	return distance;
}
// CALCULA D DISTANCIA DE CHEBYSHEV
float chebyshevDistance(float *v, float *w, int len){
	float *z;
	float *z_aux;
	float distance;

	z = subtract_F_Vector(v, w, len);
	z_aux = abs_F_Vector(z, len);
	free_F_Vector(z);
	distance = max_F_Vector(z_aux, len);
	free_F_Vector(z_aux);

	return distance;
}