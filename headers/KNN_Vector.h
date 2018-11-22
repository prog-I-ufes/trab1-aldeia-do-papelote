#ifndef _H_VECTOR
#define _H_VECTOR


/*
-------------------------------------------------------------------
MANIPULACAO DE INTS
-------------------------------------------------------------------
*/

// Aloca um vetor de inteiros dinamicamente
int* create_I_Vector(int length);

// Libera um vetor de inteiros da memoria
void free_I_Vector(int* v);

// Cria um vetor de inteiros que e a soma de V com W
int* sum_I_Vector(int *v, int *w, int len);

// Cria um vetor de inteiros que e a subtracao de V com W
int* subtract_I_Vector(int *v, int *w, int len);

// Retorna o produto interno entre V e W
int product_I_Vector(int *v, int *w, int len);

// Cria um vetor que e o quadrado de V
int* square_I_Vector(int *v, int len);

// Cria um vetor que e o V elevado a N
int* pow_I_Vector(int *v, int len, int n);

// Cria um vetor que e o valor absoluto de V
int* abs_I_Vector(int *v, int len);

// Retorna o somatorio dos elementos de V
int sum_Elements_I_Vector(int *v, int len);

// Imprime um vetor de inteiros na tela
void print_Vector(int *v, int len);

// Retorna o elemento mais recorrente de um vetor de inteiros
int recorrence(int* v, int len);

/*
-------------------------------------------------------------------
MANIPULACAO DE DOUBLES
-------------------------------------------------------------------
*/

// Imprime um vetor de doubles na tela
void print_F_Vector(double *v, int len);

// Aloca um vetor de doubles dinamicamente
double* create_F_Vector(int length);

// Libera um vetor de doubles da memoria
void free_F_Vector(double* v);

// Cria um vetor de doubles que e a soma de V com W
double* sum_F_Vector(double *v, double *w, int len);

// Cria um vetor de doubles que e a subtracao de V com W
double* subtract_F_Vector(double *v, double *w, int len);

// Retorna o produto interno entre V e W
double product_F_Vector(double *v, double *w, int len);

// Cria um vetor que e o quadrado de V
double* square_F_Vector(double *v, int len);

// Cria um vetor que e o V elevado a N
double* pow_F_Vector(double *v, int len, double n);

// Cria um vetor que e o valor absoluto de V
double* abs_F_Vector(double *v, int len);

// Retorna o somatorio dos elementos de V
double sum_Elements_F_Vector(double *v, int len);

// Retorna o maior elemento de V
double max_F_Vector(double *v, int len);

// Aloca um vetor de double com os K maiores elementos
void kMinors(double* dist, int len, int k, int* index);

#endif