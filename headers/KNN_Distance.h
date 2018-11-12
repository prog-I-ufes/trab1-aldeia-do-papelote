#ifndef _H_DISTANCE
#define _H_DISTANCE

// CALCULA A DISTANCIA EUCLIDIANA
double euclidianDistance(double *v, double *w, int len);
// CALCULA A DISTANCIA DE MINKOWSKY
double minkowskyDistance(double *v, double *w, int len, double r);
// CALCULA D SITANCIA PELA SIMILARIDADE DOS COSSENOS
double chebyshevDistance(double *v, double *w, int len);

#endif