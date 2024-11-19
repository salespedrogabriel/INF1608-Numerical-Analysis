#include "vetor.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/***************************************************************************
*  Start Function: vet_cria - Aloca um vetor de dimensao n
***************************************************************************/
double* vet_cria (int n)
{
  double* v = (double*)malloc(n*sizeof(double));
  return v;
}
/***************************************************************************
*  End Function: vet_cria - Retorna o seu ponteiro
***************************************************************************/

/***************************************************************************/
/*  Start Function: vet_libera - Libera a memoria de um vetor previamente criado
***************************************************************************/
void vet_libera (double* v)
{
  free(v);
}
/***************************************************************************
*  End Function: vet_libera 
***************************************************************************/

/***************************************************************************/
/*  Start Function: vet_mults - Multiplica o vetor por um escalar
***************************************************************************/
void vet_mults (int n, double* v, double s, double* w)
{
  for (int i=0; i<n; ++i)
    w[i] = v[i]*s;
}

/***************************************************************************
*  End Function: vet_mults - Retorna o vetor preenchido pelo resultado
***************************************************************************/

/***************************************************************************/
/*  Start Function: vet_imprime - Imprime o valor de cada posicao do vetor
***************************************************************************/
void vet_imprime (int n, double* v)
{
  for (int i=0; i<n; ++i)
    printf("Vetor | i:%d | Valor: %.16g\n",i,v[i]);
  printf("\n");
}

/***************************************************************************
*  End Function: vet_imprime 
***************************************************************************/

/***************************************************************************/
/*  Start Function: vet_escalar - Calcula o produto escalar entre dois vetores de dimensao n
***************************************************************************/
double vet_escalar (int n, double* v, double* w){
  double sum = 0;
  for (int i=0; i<n; i++){
    sum += v[i]*w[i];
  }
  return sum;
}

/***************************************************************************
*  End Function: vet_escalar - Retorna o vetor com o resultado do produto escalar
***************************************************************************/

/***************************************************************************/
/*  Start Function: vet_norma2 - Calcula a norma de um vetor de dimensao n
***************************************************************************/
double vet_norma2 (int n, double* v){
  double sum = sqrt(vet_escalar(n,v,v));
  return sum;
}
/***************************************************************************/
/*  End Function: vet_norma2 - Retorna o vetor com o resultado da norma
***************************************************************************/

/***************************************************************************/
/*  Start Function: vet_iguais- Verifica se dois vetores sao iguais
***************************************************************************/
int vet_iguais (int n, double* g, double* x, double tol){
  for (int i=0;i<n;i++){
    if (fabs(g[i]-x[i]) > tol)
      return 0;
  }
  return 1;
}
/***************************************************************************/
/*  End Function: vet_norma2 - Retorna 0 se nao sao iguais e 1 se sao iguais
***************************************************************************/
