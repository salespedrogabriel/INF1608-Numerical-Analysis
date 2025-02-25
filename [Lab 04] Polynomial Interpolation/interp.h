#ifndef INTERP_H
#define INTERP_H

void regular (int n, double a, double b, double* xi);

void chebyshev (int n, double a, double b, double* xi);

double diferenca_finita(int i, int j, double* xi, double (*f)(double));

void coeficientes (int n, double* xi, double (*f) (double), double* bi);

double avalia (int n, double* xi, double* bi, double x);

#endif


