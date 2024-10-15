#include "vetor.h"
#include "matriz.h"
#include <stdio.h>

int main (void)
{
  /* Exemplo de construção de vetor dinâmico */
  double* v = vet_cria(2);
  v[0] = 1.0;
  v[1] = 2.0;
  double* y = vet_cria(2);
  y[0] = 4.0;
  y[1] = 6.0;
  double* igual = vet_cria(2);
  igual[0] = 1.0;
  igual[1] = 2.0;
  double* n_igual = vet_cria(2);
  n_igual[0] = 1.1;
  n_igual[1] = 2.0;
  double *m = vet_cria(2);
  m[0] = 1.0;
  m[1] = 2.0;
  double *u = vet_cria(3);
  
  /* Exemplo de tolerancia*/
  double tol = 0.05;

  /* Exemplo de construção de vetor estático */
  double w[] = {1.0,2.0f};

  /* Imprime vetores (são iguais em conteúdo) */
  printf("Vetor V:\n");
  vet_imprime(2,v);
  printf("Vetor W:\n");
  vet_imprime(2,w);
  printf("Vetor Y:\n");
  vet_imprime(2,y);
  /* Exemplo de construção de matriz dinâmica */
  double** A = mat_cria(3,2);
  A[0][0] = 1.0;
  A[0][1] = 2.0;
  A[1][0] = 3.0;
  A[1][1] = 4.0;
  A[2][0] = 5.0;
  A[2][1] = 6.0;
  
  double** D = mat_cria(2,3);
  D[0][0] = 2.0;
  D[0][1] = 1.0;
  D[0][2] = 4.0;
  D[1][0] = 3.0;
  D[1][1] = 6.0;
  D[1][2] = 5.0;
  
  double** E = mat_cria(3,3);

  /* Exemplo de construção de matriz estática no formato ponteiro para ponteiro */
  double linha1[] = {1.0,2.0};
  double linha2[] = {3.0,4.0};
  double linha3[] = {5.0,6.0};
  double* B[] = {linha1,linha2,linha3};

  /* Imprime matrizes (são iguais em conteúdo) */
  printf("Matriz A:\n");
  mat_imprime(3,2,A);
  printf("Matriz B:\n");
  mat_imprime(3,2,B);
  
  /* Iniciando os testes das funcoes solicitadas */
  printf("Iniciando os testes das funcoes solicitadas.\n\n");
  
  /* Verificacao do produto escalar entre dois vetores */
  
  double z = vet_escalar(2,v,y);
  printf("Teste da funcao vet_escalar do Vetor V e Y.\n");
  printf("O Resultado foi %f.\n", z);
  printf("\n");
  
  /* Verificacao da norma 2 */
  double x = vet_norma2(3,v);
  printf("Teste da funcao norma2 do vetor V.\n");
  printf("O Resultado foi %f.\n", x);
  printf("\n");
  
  /* Verificacao de vetores iguais*/
  printf("Teste da funcao igual do vetor V com os vetores Igual e N_Igual\n");
  if (vet_iguais(2,v,igual,tol) == 0)
    printf("O vetor V e Igual nao sao iguais!\n");
  else
    printf("O vetor V e Igual sao iguais!\n");
  if (vet_iguais(2,v,n_igual,tol) == 0)
    printf("O vetor V e N_Igual nao sao iguais!\n");
  else
    printf("O vetor V e N_Igual sao iguais!\n");
  printf("\n");
  
  /* Verificacao da matriz transposta*/
  printf("Teste da funcao Matriz Transposta da matriz A!\n\n");
  double ** T = mat_cria(2,3);
  mat_transposta (3,2,A,T);
  printf("Impressao da matriz T (Transposta de A):\n");
  mat_imprime(2,3,T);
  printf("\n");
  
  /* Verificacao da multiplicacao de matriz por um vetor*/
  printf("Teste da Multiplicacao da Matriz A pelo vetor m!\n\n");
  mat_multv(3,2,A,m,u);
  printf("Impressao do vetor de resultado u(A*v):\n");
  vet_imprime(3,u);
  printf("\n");
  
   /* Verificacao da multiplicacao de matriz por outra matriz*/
  printf("Teste da Multiplicacao da Matriz A pela matriz D!\n\n");
  mat_multm(3,2,3,A,D,E);
  printf("Impressao da Matriz E:\n");
  mat_imprime(3,3,E);
  printf("\n");
    

  /* Apenas objetos dinâmicos podem ser liberados */
  vet_libera(v);
  vet_libera(y);
  vet_libera(u);
  vet_libera(m);
  mat_libera(3,A);
  mat_libera(2,T);
  mat_libera(2,D);
  mat_libera(3,E);

  return 0; 
} 
