#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriz.h"
#include "vetor.h"

/***************************************************************************/
/*  Start Function: gaussseidel - Implementa o metodo iterativo de Gauss-Seidel
***************************************************************************/
int gaussseidel(int n, double** A, double* b, double* x, double tol) {
    int iterations = 0;
    double res;

    do {
        // Atualiza cada componente de x
        for (int i = 0; i < n; i++) {
            double sum = 0.0;

            // Calcula a soma para a atualização
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }

            // Atualiza x[i]
            x[i] = (b[i] - sum) / A[i][i];
        }

        // Calcula a norma-2 do vetor resíduo r = b - Ax
        res = 0.0;
        for (int i = 0; i < n; i++) {
            double r_i = b[i];
            for (int j = 0; j < n; j++) {
                r_i -= A[i][j] * x[j];
            }
            res += r_i * r_i;
        }
        res = sqrt(res);

        iterations++;
        
    } while (res > tol);

    return iterations;
}

/***************************************************************************
*  End Function: gaussseidel - Retorna o numero de iteracoes efetuado e armazena a solucao final em x
***************************************************************************/

/***************************************************************************/
/*  Start Function: sor_gaussseidel - Implementa o metodo iterativo de Gauss-Seidel
com sobre-relaxamento (w > 1.0)
***************************************************************************/

int sor_gaussseidel(int n, double** A, double* b, double* x, double tol, double w) {
    int iterations = 0;
    double res;

    do {

        // Atualiza cada componente de x
        for (int i = 0; i < n; i++) {
            double sum = 0.0;

            // Calcula a soma para a atualização
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }

            // Calcula a nova x[i] usando a fórmula de relaxamento
            double x_new = (b[i] - sum) / A[i][i];
            x[i] = (1 - w) * x[i] + w * x_new;
        }

        // Calcula a norma-2 do vetor resíduo r = b - Ax
        res = 0.0;
        for (int i = 0; i < n; i++) {
            double r_i = b[i];
            for (int j = 0; j < n; j++) {
                r_i -= A[i][j] * x[j];
            }
            res += r_i * r_i;
        }
        res = sqrt(res);

        iterations++;
        
    } while (res > tol);
    
    return iterations;
}

/***************************************************************************
*  End Function: gaussseidel - Retorna o numero de iteracoes efetuado e armazena a solucao final em x
***************************************************************************/
