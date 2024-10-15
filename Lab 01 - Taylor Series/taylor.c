#include "taylor.h"
#include <stdlib.h>
#include <stdio.h>
/***************************************************************************
* * * * * * * * * * * Necessary Functions from vetor.c * * * * * * * * * * *
***************************************************************************/

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

/***************************************************************************
* * * * * * * * * * * New Functions from taylor.c * * * * * * * * * * * * *
***************************************************************************/

/***************************************************************************/
/*  Start Function: avalia_taylor - Recebe:
n: numero de termos | c: vetor de coeficientes | x0: valor inicial de x |
x: valor onde o polinomio deve ser avaliado
***************************************************************************/
double avalia_taylor (int n, double *c, double x0, double x)
{
    double power = 1;         // realizando as operacoes (x-x0)*(x-x0)*(x-x0)*...
    double factorial = 1;         // realizando as operacoes 1!,2!,3!,4!,...
    double residue = c[0];  // calculo do residuo

    for (int i=1; i<n; i++)
    {
        power = power*(x-x0);
        factorial = factorial*i;

        residue += c[i]*power/factorial;
    } 
    return residue;
}
/***************************************************************************
*  End Function: avalia_taylor - Retorna: O valor do residuo
***************************************************************************/

/***************************************************************************/
/*  Start Function: cria_seno - Recebe o numero de termos (n) 
Essa e uma funcao auxiliar feita somente para facilitar a funcao "avalia_seno"
Ela faz em torno de x0 = 0
***************************************************************************/
double* cria_seno_x0_0(int n)
{   
    double* seno = vet_cria(n);
    double flip = 1;
    for (int i=0; i<n; i++)
    {
        if (i%2 == 0){
            seno[i] = 0;
        }
        else {
            seno[i] = flip;
            flip = (-1.0)*(flip);
        }
    }
    // vet_imprime(n,seno); checagem de valores do seno
    return seno;
}
/***************************************************************************
*  End Function: cria_seno - Retorna o vetor preenchido com os valores de seno
para cada iteracao
***************************************************************************/

/***************************************************************************/
/*  Start Function: avalia_seno - Recebe o numero de iteracoes e o valor
onde o polinomio deve ser avaliado
***************************************************************************/
double avalia_seno (int n, double x)
{   
    double* c = cria_seno_x0_0(n);
    return avalia_taylor(n, c, 0, x);
}
/***************************************************************************
*  End Function: avalia_seno - Retorna o residuo maximo para a funcao sen x
***************************************************************************/
