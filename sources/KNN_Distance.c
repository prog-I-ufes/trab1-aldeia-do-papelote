#include "../headers/KNN_Vector.h"
#include "../headers/KNN_Distance.h"
#include <math.h>

// CALCULA A DISTANCIA EUCLIDIANA
float euclidianDistance(int *v, int *w, int len){
	int i = 0;
	int *z;
	int *z_square;
	float distance = 0;

	z = subtract_I_Vector(v, w, len);

	z_square = square_I_Vector(z, len);

	free_I_Vector(z);

	distance = sqrt(sum_Elements_I_Vector(z_square, len));

	free_I_Vector(z_square);

	return distance;
}
// CALCULA A DISTANCIA DE MINKOWSKY
float minkowskyDistance(int *v, int *w, int len, int r){
	int i = 0;
	int *z;
	int *z_aux;
	float distance = 0;

	z = subtract_I_Vector(v, w, len);

	z_aux = abs_I_Vector(z, len);

	free_I_Vector(z);

	z = pow_I_Vector(z_aux, len, r);

	free_I_Vector(z_aux);

	distance = pow(sum_Elements_I_Vector(z, len), 1.0/r);

	free_I_Vector(z);

	return distance;
}
// CALCULA A DISTANCIA PELA SIMILARIDADE DOS COSSENOS
float cosinesDistance(int *v, int *w, int len){
	float distance = 0;
	float de = euclidianDistance(v, w, len);

	distance = product_I_Vector(v, w, len);
	distance /= de;

	return distance;
}