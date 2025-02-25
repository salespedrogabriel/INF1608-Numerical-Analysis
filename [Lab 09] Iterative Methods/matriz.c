#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/***************************************************************************
*  Start Function: mat_cria - Aloca uma matriz de dimensao m x n,
representada por vetor de vetores linha
***************************************************************************/
double** mat_cria (int m, int n)
{
  double** A = (double**) malloc(m*sizeof(double*));
  for (int i=0; i<m; ++i)
    A[i] = (double*) malloc(n*sizeof(double));
  return A;
}
/***************************************************************************
*  End Function: mat_cria - Retorna o seu ponteiro
***************************************************************************/

/***************************************************************************
*  Start Function: mat_libera - Libera a memoria de uma matriz previamente criada
***************************************************************************/
void mat_libera (int m, double** A)
{
  for (int i=0; i<m; ++i)
    free(A[i]);
  free(A);
}
/***************************************************************************
*  End Function: mat_libera
***************************************************************************/

/***************************************************************************
*  Start Function: mat_imprime - Imprime elementos da matriz
***************************************************************************/
void mat_imprime (int m, int n, double** A)
{
  for (int i=0; i<m; ++i) {
    for (int j=0; j<n; ++j) {
      printf("Matriz: Linha: %d | Coluna: %d | Valor: %.16g\n",i,j, A[i][j]);
    }
    printf("\n");
  }
}

/***************************************************************************
*  End Function: mat_imprime
***************************************************************************/

/***************************************************************************
*  Start Function: mat_transposta - Preenche a matriz transposta de A em T, previamente criada
A tem dimensao m x n; T tem dimensao n x m
***************************************************************************/

void mat_transposta (int m, int n, double **A, double** T){
  for (int i=0; i<m; i++){
    for (int j=0; j<n; j++){
      T[j][i] = A[i][j];
    }
  }
}

/***************************************************************************
*  End Function: mat_transposta - Retorna a matriz transposta preenchida
***************************************************************************/

/***************************************************************************
*  Start Function: mat_multv - Calcula o produto de uma matriz A (m x n) por um vetor v (m) 
resultando no vetor w (m)
***************************************************************************/

void mat_multv (int m, int n, double** A, double* v, double* w){
  for (int i=0; i<m; i++) {
    w[i] = 0.0; 
    for (int j=0; j<n; j++)
      w[i] += A[i][j] * v[j];
  }
}

/***************************************************************************
*  End Function: mat_multv
***************************************************************************/
  
/***************************************************************************
*  Start Function: mat_multm - Calcula o produto de uma matriz A (m x n) por uma
matriz B (n x q), armazenando o resultado na matriz C (m x q)
***************************************************************************/  
void mat_multm (int m, int n, int q, double** A, double** B, double** C)
{
  for (int i=0; i<m; i++) {
    for (int k=0; k<q; k++) {
      C[i][k] = 0.0;
      for (int j=0; j<n; j++) 
        C[i][k] += A[i][j] * B[j][k];
    }
  }
}

/***************************************************************************
*  End Function: mat_multm
***************************************************************************/
