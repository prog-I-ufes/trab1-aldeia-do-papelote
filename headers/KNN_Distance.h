#ifndef _H_DISTANCE
#define _H_DISTANCE

// CALCULA A DISTANCIA EUCLIDIANA
float euclidianDistance(float *v, float *w, int len);
// CALCULA A DISTANCIA DE MINKOWSKY
float minkowskyDistance(float *v, float *w, int len, float r);
// CALCULA D SITANCIA PELA SIMILARIDADE DOS COSSENOS
float chebyshevDistance(float *v, float *w, int len);

#endif