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

// ALOCA UM VETOR DE FLOATS DINAMICAMENTE
float* create_F_Vector(int length);
// LIBERA UM VETOR DE FLOATS DA MEMORIA
void free_F_Vector(int* v);
// SOMA O VETOR V COM O VETOR W
int* sum_F_Vector(int *v, int *w, int len);
// SUBTRAI O VETOR W DO VETOR V
int* subtract_F_Vector(int *v, int *w, int len);
// PRODUTO INTERNO ENTRE O VETOR V E O VETOR W
int product_F_Vector(int *v, int *w, int len);
// CRIA UM VETOR QUE É O QUADRADO DE V
int* square_F_Vector(int *v, int len);
// CRIA UM VETOR QUE É OS ELEMENTOS DE V ELEVADOS A N
int* pow_F_Vector(int *v, int len, int n);
// CRIA UM VETOR QUE É O VALOR ABSOLUTO DOS ELEMENTOS
int* abs_F_Vector(int *v, int len);
// SOMATÓRIO DOS ELEMENTOS DO VETOR DE INTEIROS
int sum_Elements_F_Vector(int *v, int len);


#endif