#include "ode.h"

#include <stdio.h>
#include <math.h>


/***************************************************************************/
/*  Start Function: RungeKutta - Método Runge Kutta com passo constante
***************************************************************************/

double RungeKutta(double t0, double t1, double y0, double (*f)(double t, double y), double h) {
    // Número de passos necessários
    
    double t = t0;
    double y = y0;
    int M=0;

    while (t<t1) {
        h = MIN(h,t1-t);
        // Calculando os coeficientes de Runge-Kutta
        double k0 = h * f(t, y);
        double k1 = h * f(t + h / 2, y + k0 / 2);
        double k2 = h * f(t + h / 2, y + k1 / 2);
        double k3 = h * f(t + h, y + k2);

        // Atualizando y para o próximo passo
        y += (k0 + 2 * k1 + 2 * k2 + k3) / 6;
                   
        // Atualizando t para o próximo passo
        t += h;
        M++;
    }
    //printf("M= %d\n",M);
    //printf("n= %d\n",n);
    
    return y;
}

/***************************************************************************/
/*  End Function: RungeKutta - Retorna o valor no tempo final y(t1)
***************************************************************************/

/***************************************************************************/
/*  Start Function: RungeKuttaAdapt - Método Runge Kutta com passo adaptativo
***************************************************************************/

double RungeKuttaAdapt(double t0, double t1, double y0, double (*f)(double t, double y), double tol) {
    double h = 1e-7; // passo inicial
    double t = t0;
    double y = y0;

    while (t < t1) {
        
        h = MIN(h,t1-t);
        // Cálculo de k1, k2, k3 e k4
        double k0 = h * f(t, y);
        double k1 = h * f(t + h / 2, y + k0 / 2);
        double k2 = h * f(t + h / 2, y + k1 / 2);
        double k3 = h * f(t + h, y + k2); 
        
        // Calculo do Y1
        
         double y1 = y + (k0 + 2 * k1 + 2 * k2 + k3) / 6;
         double ym,y2; 
        {
          double h2 = h/2;
          double k0 = h2 * f(t, y);
          double k1 = h2 * f(t + h2 / 2, y + k0 / 2);
          double k2 = h2 * f(t + h2 / 2, y + k1 / 2);
          double k3 = h2 * f(t + h2, y + k2);
          ym = y + (k0 + 2 * k1 + 2 * k2 + k3) / 6; 
        }
        
        // Calculo do Y2
        
        {
          double t2 = t+h/2;
          double h2 = h/2;
          double k0 = h2 * f(t2, ym);
          double k1 = h2 * f(t2 + h2 / 2, ym + k0 / 2);
          double k2 = h2 * f(t2 + h2 / 2, ym + k1 / 2);
          double k3 = h2 * f(t2 + h2, ym + k2);
          y2 = ym + (k0 + 2 * k1 + 2 * k2 + k3) / 6;
          
        }
        
        /* Observação
        
          Também é possivel calcular o y1 e o y2 da forma:
        
          double y1 = RungeKutta(t,t+h,y,f,h);
          double y2 = RungeKutta(t,t+h,y,f,h/2);
          
          Mas para ficar com os resultados mais próximos do esperado, preferi fazer da forma acima.
        
        */
        
        // Estimativa do erro
        double error = (y2 - y1)/15;
        
        double factor = pow(tol/fabs(error),0.2);
        
        if (factor>=1){
           y = y2 + error; // Aceita a nova aproximação
           t += h; // Avança no tempo
           h=MIN(1.2,factor)*h;
        }
        else{
          h = 0.8*factor*h; 
        }
        //printf("h:%g\n",h);
    }

    

    return y;
}

/***************************************************************************/
/*  End Function: RungeKuttaAdapt - Retorna o valor no tempo final y(t1)
***************************************************************************/
