#ifndef MASSA_MOLA_H
#define MASSA_MOLA_H

#define K 0.3
#define R 200.0
#define M 2.0
#define G 9.8
#define W 10.0
#define DELTA 0.002

void forca (double t, double x, double y, double* fx, double* fy);
double evolui (double t, double h, double x, double y, double xp, double yp, double* xn, double* yn);
void simula (double x0, double y0, double t, int n, double* x, double* y);

#endif
