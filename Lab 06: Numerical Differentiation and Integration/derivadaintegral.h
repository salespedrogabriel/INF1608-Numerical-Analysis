#ifndef DERIVADAINTEGRAL_H
#define DERIVADAINTEGRAL_h

double derivada(double (*f)(double x), double x, double h);
double simpson(double (*f)(double), double a, double b, int n);
double simpson_adaptativo_helper(double (*f)(double), double a, double b, double tol);
double simpsonadaptativo(double (*f)(double), double a, double b, double tol);
double quadraturagauss2(double (*f)(double), double a, double b);

#endif
