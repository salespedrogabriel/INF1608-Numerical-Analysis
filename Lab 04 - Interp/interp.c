#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979

/***************************************************************************
*  Start Function: regular - Calcula as amostras xi, preenchendo o vetor
xi, pre-alocado, passado como parametro
***************************************************************************/

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

/***************************************************************************
*  End Function: regular - retorna n amostras espaçadas regularmente no
intervalo [a,b] onde xi[0] = a, xi[n-1] = b e os demais valores sao 
regularmente distribuidos no intervalo.
***************************************************************************/

/***************************************************************************/
/*  Start Function: chebyshev - Calcula as amostras xi, preenchendo o vetor
xi, pre-alocado, passado como parametro
***************************************************************************/

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

/***************************************************************************
*  End Function: chebyshev - retorna as n amostras de Chebyshev para a
aproximacao de uma funcao qualquer, dentro do intervalo [a,b]
***************************************************************************/

/***************************************************************************/
/*  Start Function: diferenca_finita - Calcula a diferenca finita F[xi...xj]
***************************************************************************/

double diferenca_finita(int i, int j, double* xi, double (*f)(double)) {
    if (i == j) {
        return f(xi[i]);
    } else {
        double fi_1_j = diferenca_finita(i + 1, j, xi, f);
        double fi_j_1 = diferenca_finita(i, j - 1, xi, f);
        return (fi_1_j - fi_j_1) / (xi[j] - xi[i]);
    }
}

/***************************************************************************
*  End Function: diferenca_finita 
***************************************************************************/

/***************************************************************************/
/*  Start Function: coeficientes - Calcula os n coeficientes bi de acordo
com o metodo de Diferencas Divididas de Newton utilizando a funcao auxiliar
acima
***************************************************************************/

void coeficientes(int n, double* xi, double (*f)(double), double* bi) {
    for (int i = 0; i < n; i++) {
        bi[i] = diferenca_finita(0, i, xi, f);
    }
}

/***************************************************************************
*  End Function: coeficientes - Retorna o vetor bi, pre-alocado, com os 
coeficientes calculados
***************************************************************************/

/***************************************************************************/
/*  Start Function: avalia - Funcao para avaliar o polinomio interpolante
de Newton em um ponto x dado
***************************************************************************/

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

/***************************************************************************
*  End Function: avalia
***************************************************************************/
