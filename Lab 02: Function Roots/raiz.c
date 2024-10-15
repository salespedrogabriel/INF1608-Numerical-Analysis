#include "raiz.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define P 8
#define PMAX 12
#define TOL 0.5 * pow(10, -P)
#define TOLMAX pow(10,-PMAX)

/***************************************************************************/
/*  Start Function: bissecao - Funcao determina a raiz de uma funcao f(x)
usando o metodo da bissecao, recebe o intervalo de busca [a,b] e a funcao
f(x) que a raiz deseja calcular e o endereco da variavel que armazenara a raiz 
calculada
***************************************************************************/
int bissecao (double a, double b, double (*f) (double x), double* r)
{
    double fa = f(a);
    double fb = f(b);
    double fc;
	// verifica se existe raiz entre a e b
	if (fa * fb >= 0)
    {
    	// retorna 0
      	printf("A Funcao nao convergiu.\n");
        return 0;
    }

    double c = a;
    int n = 0;
	
    while ((b-a)/2 >= TOL)
    {
    	// adiciona iteracao
    	 n ++;
    	// encontra ponto medio
    	c = (a+b)/2;
    	fc = f(c);
    	
 
        // verifica se o modulo f(c) < 10ˆ-12
        if (fabs(fc) < TOLMAX)
        {
        	// se nao for define r e retorna n
        	*r = c;
        	
            return n;
        }
 
        // decide para que lado da funcao vai
        else if (fc*fa < 0){
            b = c;
            fb = fc;
        }
        else{
            a = c;
            fa = fc;
        }
         
    }

    *r = (a+b)/2;
   
	return n;
}
/***************************************************************************/
/*  End Function: bissecao - retorna o numero de iteracoes
***************************************************************************/
