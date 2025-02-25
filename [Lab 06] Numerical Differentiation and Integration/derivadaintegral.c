#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/***************************************************************************/
/*  Start Function: derivada - Calcula a derivada numerica de uma funcao no 
ponto x com passo h tendo como base o metodo de segunda ordem
***************************************************************************/

double derivada(double (*f)(double x), double x, double h) {
    return (f(x + h) - f(x - h)) / (2 * h);
}

/***************************************************************************/
/*  End Function: derivada
***************************************************************************/

/***************************************************************************/
/*  Start Function: simpson - Calcula a integral composta do intervalo de
'a' ate 'b' considerando n passos de integracao
***************************************************************************/

double simpson(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n; // Passo
    double integral = 0.0; // Para começar as somas
  
    for (int i = 0; i < n; i++) {
        integral += h/6.0*(f(a)+4*f(a+(h/2))+f(a+h)); // Formula para cada soma
        a=a+h; // Alterando os passos, a0, a1, a2...
    }

    return integral;
}

/***************************************************************************/
/*  End Function: simpson
***************************************************************************/

/***************************************************************************/
/*  Start Function: simpson_adaptativo_helper - Auxiliar para a integracao
adaptativa de simpson
***************************************************************************/

double simpson_adaptativo_helper(double (*f)(double), double a, double b, double tol) {
    double c = (a + b) / 2; // Ponto médio
    double S_ab = simpson(f, a, b, 1); // Integral no intervalo [a, b]
    double S_ac = simpson(f, a, c, 1); // Integral no intervalo [a, c]
    double S_cb = simpson(f, c, b, 1); // Integral no intervalo [c, b]

    double delta = S_ab - (S_ac + S_cb); // Diferença

    // Se a diferença é menor que 15 vezes a tolerância, aceitamos o resultado
    if (fabs(delta) < 15 * tol) {
        return S_ac + S_cb - (delta / 15); // Resultado final dentro da tolerância
    } else {
        // Dividir o intervalo e repetir o processo
        double left_result = simpson_adaptativo_helper(f, a, c, tol / 2);
        double right_result = simpson_adaptativo_helper(f, c, b, tol / 2);
        return left_result + right_result; // Soma dos resultados
    }
}

/***************************************************************************/
/*  End Function: simpson_adaptativo_helper
***************************************************************************/

/***************************************************************************/
/*  Start Function: simpsonadaptativo - Apenas chama o helper
***************************************************************************/

double simpsonadaptativo(double (*f)(double), double a, double b, double tol) {
    return simpson_adaptativo_helper(f, a, b, tol);
}

/***************************************************************************/
/*  End Function: simpsonadaptativo
***************************************************************************/

/***************************************************************************/
/*  Start Function: quadraturagauss2 - Calcula a integral usando a quadratura
de Gauss com 2 pontos
***************************************************************************/

// Função que calcula a integral usando a quadratura de Gauss com 2 pontos
double quadraturagauss2(double (*f)(double), double a, double b) {
    // Pontos e pesos da quadratura de Gauss 2 pontos
    double x1 = (b - a) / 2 * -0.5773502691896257 + (a + b) / 2; // -1/sqrt(3)
    double x2 = (b - a) / 2 * 0.5773502691896257 + (a + b) / 2;  // 1/sqrt(3)
    double w1 = 1.0; // Peso para x1
    double w2 = 1.0; // Peso para x2
    
    // Cálculo da integral
    double integral = (b - a) / 2 * (w1 * f(x1) + w2 * f(x2));
    return integral;
}

/***************************************************************************/
/*  End Function: quadraturagauss2
***************************************************************************/
