#ifndef BISSECAO_H
#define BISSECAO_H

// Funcao que determina a raiz de uma funcao f(x) usando o metodo da bissecao 
// com erro progressivo avaliado de precisao de 8 digitos
int bissecao (double a, double b, double (*f) (double x), double* r);

#endif
