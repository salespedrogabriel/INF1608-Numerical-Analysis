#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979

void regular (int n, double a, double b, double* xi)
{
    // error handle de n
    if (n <= 0) {
        printf("ERROR: n <= 1");
        return;
    }
    
    if (n == 1) {
        xi[0] = a;
        return;
    }

    // define intervalo 
    double intervalo = (b - a) / (n - 1);

    // aloca n amostras nos intervalos 
    for (int i = 0; i < n; i++) {
        xi[i] = a + i * intervalo;
    }

}

void chebyshev (int n, double a, double b, double* xi)
{
    // error handle de n
    if (n <= 0) {
        printf("ERROR: n <= 1");
        return;
    }

    // Calcula o meio e a amplitude do intervalo
    double mid = (a + b) / 2;
    double amplitude = (b - a) / 2;

    // Calcula os pontos de Chebyshev e preenche o vetor xi
    for (int i = 0; i < n; i++) {
        double theta = (2 * i + 1) * M_PI / (2 * n);
        xi[i] = mid + amplitude * cos(theta);
    }
}

// Função para calcular a diferença finita F[xi...xj]
double diferença_finite(int i, int j, double* xi, double (*f)(double)) {
    if (i == j) {
        return f(xi[i]);
    } else {
        double fi_1_j = diferença_finite(i + 1, j, xi, f);
        double fi_j_1 = diferença_finite(i, j - 1, xi, f);
        return (fi_1_j - fi_j_1) / (xi[j] - xi[i]);
    }
}

// Função para calcular os coeficientes b_i
void coeficientes(int n, double* xi, double (*f)(double), double* bi) {
    for (int i = 0; i < n; i++) {
        bi[i] = diferença_finite(0, i, xi, f);
    }
}

// Função para avaliar o polinômio interpolante de Newton em um ponto x
double avalia(int n, double* xi, double* bi, double x) {
    double resultado = bi[0]; // Inicia o resultado com o primeiro coeficiente b0
    double produto = 1.0;

    // Avalia o polinômio usando a fórmula de Horner para o polinômio de Newton
    for (int i = 1; i < n; i++) {
        produto *= (x - xi[i - 1]);
        resultado += bi[i] * produto;
    }

    return resultado;
}
