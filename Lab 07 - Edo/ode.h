#ifndef _RUNGE_KUTTA_H_
#define _RUNGE_KUTTA_H_

#ifndef MIN
#define MIN(a, b) (a < b ? a : b)
#endif

double funcao_1(double t, double y); 
double funcao_2(double t, double y);
double RungeKutta (double t0, double t1, double y0, double (*f) (double t, double y), double h);
double RungeKuttaAdapt (double t0, double t1, double y0, double (*f) (double t, double y), double tol);

#endif
