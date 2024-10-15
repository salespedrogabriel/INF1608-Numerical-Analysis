#include "raiz.h"
#include <stdio.h>
#include <math.h>

/***************************************************************************
* * * * * * * * * * * How to Run * * * * * * * * * * *
***************************************************************************/
// gcc -Wall raiz.c main.c -o main
// ./main
/***************************************************************************/

static int N=0;

double func1(double x)
{
    N++;
    return x*x*x + 2*x*x - 2;
}
double func2(double x)
{
    N++;
    return x*x*x*x + x + 1;
}

double func3(double m)
{
    double c = 15;
    double g = 9.8;
    double t = 9;
  
    double v = (g*m / c)*(1 - exp((-c*t)/m))-35;
    N++;
    return v;
}

int main (void)
{
	double a1 = -3, b1 = 3; 
	double a2 = -5, b2 = 5;
	double a3 = 0, b3 = 150;
	double a4 = 0, b4 = 250;
	double a5 = 0, b5 = 50;
	int n1, n2, n3;
	double r = 0;
	
	printf("\n \n");
        
	printf("Funcao 1: x³ +2x² -2 \n");
	printf("Avaliando a Funcao 1 no intervalo [-3,+3] \n");
	n1 = bissecao(a1, b1, func1, &r);
	printf("Iteracoes: %d \n",n1);
	printf("Avaliacoes: %d \n",N);
	printf("Q1: %.9f \n", r);
	r=0;
	N=0;
	
	printf("\n");

	printf("Funcao 2: x^4 + x + 1\n");
	printf("Avaliando a Funcao 2 no intervalo [-3,+3] \n");
	n2 = bissecao(a1, b1, func2, &r);
	printf("Iteracoes: %d \n",n2);
	printf("Avaliacoes: %d \n",N);
	printf("Q2: %.9f \n", r);
	r=0;
	N=0;
	
	printf("\n");
	
	printf("Funcao 1: x³ +2x² -2 \n");
	printf("Avaliando a Funcao 1 no intervalo [-5,+5] \n");
	n1 = bissecao(a2, b2, func1, &r);
	printf("Iteracoes: %d \n",n1);
	printf("Avaliacoes: %d \n",N);
	printf("Q1: %.9f \n", r);
	r=0;
	N=0;
	
	printf("\n");
	
	printf("Funcao 3: v = gm/c * (1 - exp(-ct/m))\n");
	printf("Avaliando a Funcao 3 no intervalo [0,150] \n");
	n3 = bissecao(a3, b3, func3, &r);
	printf("Iteracoes: %d \n",n3);
	printf("Avaliacoes: %d \n",N);
	printf("Q3: %.9f \n", r);
	r=0;
	N=0;
	
	printf("\n");
	
	printf("Funcao 3: v = gm/c * (1 - exp(-ct/m))\n");
	printf("Avaliando a Funcao 3 no intervalo [0,250] \n");
	n3 = bissecao(a4, b4, func3, &r);
	printf("Iteracoes: %d \n",n3);
	printf("Avaliacoes: %d \n",N);
	printf("Q3: %.9f \n", r);
	r=0;
	N=0;
	
	printf("\n");
	
	printf("Funcao 3: v = gm/c * (1 - exp(-ct/m))\n");
	printf("Avaliando a Funcao 3 no intervalo [0,50] \n");
	n3 = bissecao(a5, b5, func3, &r);
	printf("Iteracoes: %d \n",n3);
	printf("Avaliacoes: %d \n",N);
	printf("Q3: %.9f \n", r);
	r=0;
	N=0;
	
	printf("\n");

}
