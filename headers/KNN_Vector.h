// ALOCA UM VETOR DINAMICAMENTE
int* create_I_Vector(int length);
// LIBERA UM VETOR DA MEMORIA
void free_I_Vector(int* v);
// SOMA O VETOR V COM O VETOR W
int* sum_I_Vector(int *v, int *w, int len);
// SUBTRAI O VETOR W DO VETOR V
int* subtract_I_Vector(int *v, int *w, int len);
// PRODUTO INTERNO ENTRE O VETOR V E O VETOR W
int* product_I_Vector(int *v, int *w, int len);
// CRIA UM VETOR QUE É O QUADRADO DE V
int* square_I_Vector(int *v, int len);
// IMPRIME O VETOR NA TELA
void print_Vector(int *v, int len);