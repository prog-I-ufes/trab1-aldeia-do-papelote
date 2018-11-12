#ifndef _H_VECTOR
#define _H_VECTOR

// ALOCA UM VETOR DINAMICAMENTE
int* create_I_Vector(int length);
// LIBERA UM VETOR DA MEMORIA
void free_I_Vector(int* v);
// SOMA O VETOR V COM O VETOR W
int* sum_I_Vector(int *v, int *w, int len);
// SUBTRAI O VETOR W DO VETOR V
int* subtract_I_Vector(int *v, int *w, int len);
// PRODUTO INTERNO ENTRE O VETOR V E O VETOR W
int product_I_Vector(int *v, int *w, int len);
// CRIA UM VETOR QUE É O QUADRADO DE V
int* square_I_Vector(int *v, int len);
// CRIA UM VETOR QUE É OS ELEMENTOS DE V ELEVADOS A N
int* pow_I_Vector(int *v, int len, int n);
// CRIA UM VETOR QUE É O VALOR ABSOLUTO DOS ELEMENTOS
int* abs_I_Vector(int *v, int len);
// SOMATÓRIO DOS ELEMENTOS DO VETOR DE INTEIROS
int sum_Elements_I_Vector(int *v, int len);
// IMPRIME O VETOR NA TELA
void print_Vector(int *v, int len);

// ALOCA UM VETOR COM OS K MAIORES ELEMENTOS
double* kMinors(double* dist, int len, int k, int* index);
// BUSCA O ELEMENTO MAIS RECORRENTE DE UM VETOR
int recorrence(int* v, int len);

// ALOCA UM VETOR DE doubleS DINAMICAMENTE
double* create_F_Vector(int length);
// LIBERA UM VETOR DE doubleS DA MEMORIA
void free_F_Vector(double* v);
// SOMA O VETOR V COM O VETOR W
double* sum_F_Vector(double *v, double *w, int len);
// SUBTRAI O VETOR W DO VETOR V
double* subtract_F_Vector(double *v, double *w, int len);
// PRODUTO doubleERNO ENTRE O VETOR V E O VETOR W
double product_F_Vector(double *v, double *w, int len);
// CRIA UM VETOR QUE É O QUADRADO DE V
double* square_F_Vector(double *v, int len);
// CRIA UM VETOR QUE É OS ELEMENTOS DE V ELEVADOS A N
double* pow_F_Vector(double *v, int len, double n);
// CRIA UM VETOR QUE É O VALOR ABSOLUTO DOS ELEMENTOS
double* abs_F_Vector(double *v, int len);
// SOMATÓRIO DOS ELEMENTOS DO VETOR DE doubleEIROS
double sum_Elements_F_Vector(double *v, int len);
// RETORNA O MAXIMO ELEMENTO EM UM VETOR DE doubleS
double max_F_Vector(double *v, int len);

#endif