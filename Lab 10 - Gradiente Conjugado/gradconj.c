#include "gradconj.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vetor.h"
#include "matriz.h"

// Função que implementa o método Gradientes Conjugados sem pré-condicionador
int gradconj(int n, double** A, double* b, double* x, double tol) {
    double* r = vet_cria(n);  // Resíduo
    double* d = vet_cria(n);  // Direção
    double* Ad = vet_cria(n); // A*d
    
    // Inicialização
    for (int i = 0; i < n; i++) {
        r[i] = b[i];
        d[i] = r[i];
        x[i] = 0.0;
    }

    double rr_old = vet_escalar(n, r, r);
    double rr_new;
    double alpha, beta;
    int k;

    // Iterações do método de Gradientes Conjugados
    for (k = 0; k < n; k++) {
        // Ad = A * d
        for (int i = 0; i < n; i++) {
            Ad[i] = 0.0;
            for (int j = 0; j < n; j++) {
                Ad[i] += A[i][j] * d[j];
            }
        }

        // Cálculo de alpha
        alpha = rr_old / vet_escalar(n, d, Ad);

        // Atualiza a solução
        for (int i = 0; i < n; i++) {
            x[i] += alpha * d[i];
        }

        // Atualiza o resíduo
        for (int i = 0; i < n; i++) {
            r[i] -= alpha * Ad[i];
        }

        rr_new = vet_escalar(n, r, r);

        // Checa se a norma do resíduo é menor que a tolerância
        if (sqrt(rr_new) < tol) {
            free(r);
            free(d);
            free(Ad);
            return k +1;  // Retorna o número de iterações
        }

        // Cálculo de beta
        beta = rr_new / rr_old;

        // Atualiza a direção
        for (int i = 0; i < n; i++) {
            d[i] = r[i] + beta * d[i];
        }

        rr_old = rr_new;
    }

    free(r);
    free(d);
    free(Ad);
    return k;  // Retorna o número de iterações
}

int gradconj_jacobi (int n, double** A, double* b, double* x, double tol)
{
    double* r = vet_cria(n);
    double* r_old = vet_cria(n);
    double* d = vet_cria(n);
    double* z = vet_cria(n);
    double* z_old = vet_cria(n);
    double* Ad = vet_cria(n);
    int k;

    for (int i = 0; i < n; i++) {
        r[i] = b[i] - vet_escalar(n, A[i], x);
        z[i] = r[i] / A[i][i]; 
        d[i] = z[i];
        r_old[i]=r[i];
        z_old[i]=z[i];
    }

    for (k=0; k<n; k++) 
    {
        if (vet_norma2(n,r) < tol) {
            free(r);
            free(r_old);
            free(z_old);
            free(d);
            free(z);
            return k;
        }
        
        mat_multv(n,n,A,d,Ad);
        double alpha = vet_escalar(n,r,z) / vet_escalar(n,d,Ad);
       
        
        for (int i=0;i<n;i++){
          r_old[i] = r[i];
          z_old[i] = z[i];
          x[i] += alpha * d[i];
          r[i] -= alpha * Ad[i];
          z[i] = r[i] / A[i][i];
        }
        
        
        
        double beta = vet_escalar(n, r, z) / vet_escalar(n, r_old, z_old);

        for (int i=0;i<n;i++){
          d[i] = z[i] + beta * d[i];
        }
    }   

    free(r);
    free(r_old);
    free(z_old);
    free(d);
    free(z);

    return k;
}
