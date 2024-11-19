#include "otimizacao.h"
#include <stdio.h>
#include <math.h>

static int N = 0;
static double f1 (double x)
{
  N++;
  return x*x + sin(x);
}

static double f2 (double x)
{
  N++;
  return x*x*x*x*x*x - 11*x*x*x + 17*x*x - 7*x + 1;
}


void testmsa (double a, double b, double (*f) (double x))
{
  N = 0;
  double xmin;
  int n = msa(a, b, f, 1e-5, &xmin);
  printf("msa  [a = %5g, b = %5g]: it = %2d, xmin = %10g, fevals: %2d\n", a, b, n, xmin, N);
}

void testmips (double r, double delta, double (*f) (double x))
{
  N = 0;
  double xmin;
  int n = mips(r, delta, f, 1e-6, &xmin);
  printf("mips [r = %5g, d = %5g]: it = %2d, xmin = %10g, fevals: %2d\n", r, delta, n, xmin, N);
}

int main (void)
{
  printf("MSA:\n");
  printf("x*x + sin(x)\n");
  testmsa(-0.5, +0.5, f1);
  testmsa(-1.5, +1.5, f1);
  
  
  printf("x^6 - 11 x^3 + 17 x^2 - 7 x + 1\n");
  testmsa(-0.5, +0.5, f2);
  testmsa(-0.7, +0.7, f2);  
  testmsa(1, 2, f2);
  testmsa(1, 8, f2);  

  printf("MIPS:\n");
  printf("x*x + sin(x)\n");
  testmips(0.0, 0.5, f1);
  testmips(1.5, 1.0, f1);
  testmips(1.2, 0.2, f1);
  
  printf("x^6 - 11 x^3 + 17 x^2 - 7 x + 1\n");
  testmips(0.0, 0.5, f2);
  testmips(0.6, 0.01, f2);
  testmips(1, 0.5, f2);
  testmips(1.4, 0.1, f2);
  testmips(1, 1e-07, f2);
   
  return 0;
}
