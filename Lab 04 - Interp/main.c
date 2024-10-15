#include "interp.h"

#include <math.h>
#include <stdio.h>

#define PI 3.141592653589793

static double f (double x)
{
  return 1.0 / (1.0 + 12.0 * x * x);
}

static double g (double x) {
    double sigma = 0.5;
    double mu = 0.0;
    return (1 / (sigma * sqrt(2 * PI))) * exp(-0.5 * pow((x - mu) / sigma, 2));
}

#define N 10
#define M 20
int main (void)
{
  double xi[M];
  double bi[M];
  
  printf("Coeficientes espacados regularmente:\n");
  for (int i = 2; i <= N; i++) {
    regular(i, -2, 2, xi);
	printf("%d: ", i);
	for (int j = 0; j < i; j++)
	  printf("%.4f ", xi[j]);
	printf("\n");
  } 

  printf("Coeficientes de chebyshev:\n");
  for (int i = 2; i <= N; i++) {
    chebyshev(i, -2, 2, xi);
	printf("%d: ", i);
	for (int j = 0; j < i; j++)
	  printf("%.4f ", xi[j]);
	printf("\n");
  } 
  
  printf("Diff. Divididas de Newton:\n");
  printf("Regulares: ");
  regular(N, -2, 2, xi);
  coeficientes(N,xi,f,bi);
  for (int i=0; i < N; ++i)
    printf("%g ",bi[i]);
  printf("\n");
  
  printf("Chebyshev: ");
  chebyshev(N, -2, 2, xi);
  coeficientes(N,xi,f,bi);
  for (int i=0; i < N; ++i)
    printf("%g ",bi[i]);
  printf("\n");

  printf("Avalia funcao 1/(1+12x^2): \n");
  printf("Com coeficientes regulares: \n");
  regular(N, -2, 2, xi);
  coeficientes(N,xi,f,bi);
  for (float x=-2.0; x < 2.0001; x+=0.1) {
    double y = avalia(N,xi,bi,x);
    double yf = f(x);
    printf("%.1f %f %f %g\n",x,y,yf,fabs(y-yf));
  }
  printf("Com coeficientes chebyshev: \n");
  chebyshev(N, -2, 2, xi);
  coeficientes(N,xi,f,bi);
  for (float x=-2.0; x < 2.0001; x+=0.1) {
    double y = avalia(N,xi,bi,x);
    double yf = f(x);
    printf("%.1f %f %f %g\n",x,y,yf,fabs(y-yf));
  }
  
  printf("Avalia funcao (1 / (sigma * sqrt(2 * PI))) * exp(-0.5 * ((x - mu) / sigma)^2)): \n");
  printf("Com coeficientes regulares e 10 amostras: \n");
  regular(N, -2, 2, xi);
  coeficientes(N,xi,g,bi);
  for (float x=-2.0; x < 2.0001; x+=0.1) {
    double y = avalia(N,xi,bi,x);
    double yg = g(x);
    printf("%.1f %f %f %g\n",x,y,yg,fabs(y-yg));
  }
  printf("Com coeficientes chebyshev e 10 amostras: \n");
  chebyshev(N, -2, 2, xi);
  coeficientes(N,xi,g,bi);
  for (float x=-2.0; x < 2.0001; x+=0.1) {
    double y = avalia(N,xi,bi,x);
    double yg = g(x);
    printf("%.1f %f %f %g\n",x,y,yg,fabs(y-yg));
  }
  
  printf("Avalia funcao (1 / (sigma * sqrt(2 * PI))) * exp(-0.5 * ((x - mu) / sigma)^2)): \n");
  printf("Com coeficientes regulares e 20 amostras: \n");
  regular(M, -2, 2, xi);
  coeficientes(M,xi,g,bi);
  for (float x=-2.0; x < 2.0001; x+=0.1) {
    double y = avalia(M,xi,bi,x);
    double yg = g(x);
    printf("%.1f %f %f %g\n",x,y,yg,fabs(y-yg));
  }
  printf("Com coeficientes chebyshev e 20 amostras: \n");
  chebyshev(M, -2, 2, xi);
  coeficientes(M,xi,g,bi);
  for (float x=-2.0; x < 2.0001; x+=0.1) {
    double y = avalia(M,xi,bi,x);
    double yg = g(x);
    printf("%.1f %f %f %g\n",x,y,yg,fabs(y-yg));
  }
  
  return 0;
}

// Com mais amostras, o erro de chebi fica mais estavel do que com as amostras equidistantes, e o chebichev tenta ter melhores aproximações quanto mais distante do centro e piores aproximações quanto mais próximo do centro em relação a amostras regularmente espaçadas.
