#ifndef _H_DISTANCE
#define _H_DISTANCE

// CALCULA A DISTANCIA EUCLIDIANA
float euclidianDistance(int *v, int *w, int len);
// CALCULA A DISTANCIA DE MINKOWSKY
float minkowskyDistance(int *v, int *w, int len, int r);
// CALCULA D SITANCIA PELA SIMILARIDADE DOS COSSENOS
float cosinesDistance(int *v, int *w, int len);

#endif