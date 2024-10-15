#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriz.h"
#include "vetor.h"
#include "sistlinear.h"

double mmq(int m, int n, double** A, double* b, double* x) {
    // Passo 1: Alocar a matriz transposta de A (T)
    double** T = mat_cria(n, m);
    
    // Passo 2: Calcular T = A^T
    mat_transposta(m, n, A, T);
    
    // Passo 3: Calcular A^T A
    double** ATA = mat_cria(n, n);
    mat_multm(n, m, n, T, A, ATA);
    
    // Passo 4: Calcular A^T b
    double* ATb = vet_cria(n);
    mat_multv(n, m, T, b, ATb);
    
    // Passo 5: Resolver o sistema ATA x = ATb
    gauss(n, ATA, ATb, x);
    
    // Passo 6: Calcular o vetor residual r = b - Ax
    double* r = vet_cria(m);
    mat_multv(m, n, A, x, r);
    
    for (int i = 0; i < m; i++) {
        r[i] = b[i] - r[i];
    }
    
    // Passo 7: Calcular a norma-2 do vetor residual
    double residual_norm = vet_norma2(m, r);
    
    // Liberar memória
    mat_libera(n, T);
    mat_libera(n, ATA);
    vet_libera(ATb);
    vet_libera(r);
    
    return residual_norm;
}

double ajuste_parabola(int n, double* px, double* py, double* a, double* b, double* c) {
    // Passo 1: Criar a matriz A e o vetor de resultados b
    double** A = mat_cria(n, 3);  // n linhas, 3 colunas (1, x, x^2)
    double* b_vec = vet_cria(n);   // vetor de resultados py
    
    for (int i = 0; i < n; i++) {
        A[i][0] = 1.0;             // Coeficiente para a
        A[i][1] = px[i];           // Coeficiente para b
        A[i][2] = px[i] * px[i];   // Coeficiente para c
        b_vec[i] = py[i];          // Valores de y
    }
    
    // Passo 2: Resolver o sistema de mínimos quadrados
    double* x = vet_cria(3); // vetor para armazenar os coeficientes a, b, c
    double residual_norm = mmq(n, 3, A, b_vec, x);
    
    // Passo 3: Preencher os coeficientes a, b, c
    *a = x[0];
    *b = x[1];
    *c = x[2];
    
    // Liberar memória
    mat_libera(n, A);
    vet_libera(b_vec);
    vet_libera(x);
    
    return residual_norm; // Retorna a norma-2 do vetor residual
}

double ajuste_cubica(int n, double* px, double* py, double* a, double* b, double* c, double* d) {
    // Passo 1: Criar a matriz de design A e o vetor de resultados b
    double** A = mat_cria(n, 4);  // n linhas, 4 colunas (1, x, x^2, x^3)
    double* b_vec = vet_cria(n);   // vetor de resultados py
    
    for (int i = 0; i < n; i++) {
        A[i][0] = 1.0;                   // Coeficiente para a
        A[i][1] = px[i];                 // Coeficiente para b
        A[i][2] = px[i] * px[i];         // Coeficiente para c
        A[i][3] = px[i] * px[i] * px[i]; // Coeficiente para d
        b_vec[i] = py[i];                // Valores de y
    }
    
    // Passo 2: Resolver o sistema de mínimos quadrados
    double* x = vet_cria(4); // vetor para armazenar os coeficientes a, b, c, d
    double residual_norm = mmq(n, 4, A, b_vec, x);
    
    // Passo 3: Preencher os coeficientes a, b, c, d
    *a = x[0];
    *b = x[1];
    *c = x[2];
    *d = x[3];
    
    
    // Liberar memória
    mat_libera(n, A);
    vet_libera(b_vec);
    vet_libera(x);
    
    return residual_norm; // Retorna a norma-2 do vetor residual
}

double ajuste_exponencial_exp(int n, double* px, double* py, double* a, double* b) {
    // Passo 1: Criar a matriz de design A e o vetor de resultados Y
    double** A = mat_cria(n, 2);  // n linhas, 2 colunas (1, x)
    double* Y = vet_cria(n);       // vetor para armazenar ln(py)

    for (int i = 0; i < n; i++) {
        // Calcular ln(py) apenas se py[i] > 0
        if (py[i] <= 0) {
            printf("Erro: y[%d] deve ser maior que 0 para o logaritmo.\n", i);
            vet_libera(Y);
            return -1; // Indica erro
        }
        Y[i] = log(py[i]); // ln(py)
        A[i][0] = 1.0;     // Coeficiente para ln(a)
        A[i][1] = px[i];   // Coeficiente para b
    }
    
    // Passo 2: Resolver o sistema de mínimos quadrados
    double* x = vet_cria(2); // vetor para armazenar os coeficientes ln(a), b
    double residual_norm = mmq(n, 2, A, Y, x);
    
    // Passo 3: Preencher os coeficientes a, b
    *a = exp(x[0]); // ln(a) => a
    *b = x[1];      // b
    
    
    // Liberar memória
    mat_libera(n, A);
    vet_libera(Y);
    vet_libera(x);
    
    return residual_norm; // Retorna a norma-2 do vetor residual
}

