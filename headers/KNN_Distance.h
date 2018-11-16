#ifndef _H_DISTANCE
#define _H_DISTANCE

// Calcula a distancia de chebyshev entre dois vetores
double chebyshevDistance(double *v, double *w, int len);

// Calcula a distancia euclidiana entre dois vetores
double euclidianDistance(double *v, double *w, int len);

// Calcula a distancia de minkowsky entre dois vetores
double minkowskyDistance(double *v, double *w, int len, double r);

#endif