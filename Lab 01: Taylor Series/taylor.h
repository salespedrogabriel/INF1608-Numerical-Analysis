#ifndef TAYLOR_H
#define TAYLOR_H

// cria (aloca) um vetor de dimensão n, retornando seu ponteiro
double* vet_cria (int n);

// libera (a memória) de um vetor previamente criado
void vet_libera (double* v);

// imprime elementos do vetor
void vet_imprime (int n, double* v);

// funcao que avalia um polinomio de Taylor, recebendo:
// n: numero de termos, c: vetor de coeficientes, x0: valor inicial de x, x: valor onde polinomio deve ser avaliado
double avalia_taylor (int n, double *c, double x0, double x);

// Funcao auxiliar somente para facilitar a funcao "avalia_seno"
double* cria_seno_x0_0(int n);

// Calcula a aproximacao da funcao sen x atraves do metodo de taylor
double avalia_seno (int n, double x);
#endif
