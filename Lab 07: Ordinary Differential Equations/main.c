#include "ode.h"

#include <stdio.h>
#include <math.h>

static int N;

// solucao y(t) = e^(t^2 / 2) - t^2 - 2
#define Sf1 10.0542731796122
#define Sf2(t) (1.0 - exp(-10.0*t) / 2.0)

// COMPLETAR: escrever f1, f2

double funcao_1(double t, double y) {
  N++;
  return t * y + pow(t, 3);
}

double funcao_2(double t, double y) {
  N++;
  return 10 * (1 - y);
}

void Avalia (double t0, double t1, double y0, double h, double tol, double (*f) (double t, double y), double sol)
{
  printf("Solucao: %.16f\n", sol);
  // Método de Runge-Kutta com passo constante
    
    double relative_error;
    double y_const = RungeKutta(t0, t1, y0, f, h);
    printf("---------------------\n");
    printf("Runge-Kutta com passo constante:\n");
    printf("y(%.1f) = %.16f \n", t1,y_const);
    printf("Numero de avaliacoes: %d \n", N);
    
    relative_error = fabs(sol - y_const);
    
    printf("Erro relativo do método: %g\n", relative_error);
    printf("---------------------\n");
    N = 0; // resetar o contador
    
    // Método de Runge-Kutta adaptativo
    
    double y_adapt = RungeKuttaAdapt(t0, t1, y0, f, tol);
    printf("Runge-Kutta com passo adaptativo:\n");
    printf("y(%.1f) = %.16f\n", t1,y_adapt);
    printf("Numero de avaliacoes: %d \n", N);
    
    relative_error = fabs(sol - y_adapt);
    
    printf("Erro relativo do método: %g\n", relative_error);
    printf("---------------------\n");
    
    N = 0;
}

int main (void)
{
  double t0 = 0.0;
  double t1 = 2.4;
  double t2 = 3.0;
  double y0 = -1.0;
  double y1 = 0.0;
  double h = 0.001;
  double tol = 1e-12;
  double sol1 = Sf1;
  double sol2 = Sf2(t2);
  
  printf("\nAvaliacao da Funcao 1: y' = ty + t³\n");
  Avalia (t0,t1,y0,h,tol,funcao_1,sol1);
  printf("\n---------------------\n");
  printf("\nAvaliacao da Funcao 2: y' = 10 (1 - y)\n");
  Avalia (t0,t2,y1,h,tol,funcao_2,sol2);
  printf("\n---------------------\n");
  
      
  
  return 0;
}
