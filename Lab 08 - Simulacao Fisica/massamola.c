#include "massamola.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Start function: forca - Calcula os valores da força total (gravidade + vento + mola)  */

void forca (double t, double x, double y, double* fx, double* fy)
{
    // Componente Y: Força de Gravidade
    double forca_gravidade_y = M*G;
    
    // Componente X: Força de Vento
    double forca_vento_x = W*exp(-t/20);
    
    // Calculo da Norma: |x|
    double r_norm = sqrt(x * x + y * y);
    
    // Calculo da Componente x da Força da Mola
    double forca_mola_x = -K*(r_norm-R)*(x/r_norm);
    
    // Calculo da Componente y da Força da Mola
    double forca_mola_y = -K*(r_norm-R)*(y/r_norm);

    // Calculo do somatório do Componente x
    *fx = forca_vento_x + forca_mola_x;
    
    // Calculo do somatório do Compoennte y
    *fy = forca_gravidade_y + forca_mola_y;

}

/* End function: forca  */

/* Start function: evolui - Usa o metodo de Verlet dada uma configuracao no instante t e calcula
a nova posicao do corpo no instante t+h */

double evolui (double t, double h, double x, double y, double xp, double yp, double* xn, double* yn)
{
    double fx, fy;
    
    forca(t, x, y, &fx, &fy);
    
    // Calculo da posicao das componente x e y
    *xn = x + (1-DELTA)*(x-xp) + h*h*(fx/M);
    *yn = y + (1-DELTA)*(y-yp) + h*h*(fy/M);


    return t+h;
}

/* End function: evolui  */

/* Start function: simula - Preenche um vetor de posicoes do corpo ao longo do tempo  */

void simula (double x0, double y0, double t_final, int n, double* x, double* y)
{
    double h = t_final / n;
    
    double xp = x0;
    double yp = y0;

    x[0] = x0;
    y[0] = y0;

    for (int i = 1; i <= n; i++) {
        double xn, yn;
        double t = i * h;
        t = evolui(t, h, x[i - 1], y[i - 1], xp, yp, &xn, &yn);
        x[i] = xn;
        y[i] = yn;
        xp = x[i - 1];
        yp = y[i - 1];
    }

}

/* End function: simula  */


