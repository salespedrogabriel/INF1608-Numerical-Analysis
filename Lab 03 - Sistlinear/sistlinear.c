#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/***************************************************************************/
/*  Start Function: void gauss - Recebe uma matriz A (nxn) e o vetor b.
A função usa o método da eliminação de Gauss com pivotamento para determinar
e preencher o vetor solução x.
***************************************************************************/
void gauss(int n, double** A, double* b, double* x)
{
    int i, j, k, max;
    double temp, fator;

    for (i=0; i<n-1; i++){  // Pivotamento 
        
        max = i; // define i como valor maximo

        for (j=i+1; j<n; j++){  // busca maior valor absoluto da coluna
            if (fabs(A[j][i] > fabs(A[max][i]))) {
                max = j;
            }
        }

        
        if (max != i) {   // caso valor max tenha mudado
            
            for (k=0; k<n; k++) { // Pivota a matriz e troca as linhas i e max da matriz A
                temp = A[i][k];
                A[i][k] = A[max][k];
                A[max][k] = temp;
            }
            temp = b[i];  // Agora faremos a troca do vetor b tendo como referencia as trocas da matriz A
            b[i] = b[max];
            b[max] = temp;
        }

        
        for (j=i+1; j<n; j++) { // realiza a eliminacao de gauss [J será a linha e I será a coluna]
            fator = A[j][i]/A[i][i];  // calcula fator de eliminacao
            for (k=i; k<n; k++) { // subtrai o fator e multiplica em cada posicao j,k da matriz A
                A[j][k] -= fator * A[i][k];
            }
            b[j] -= fator * b[i]; // no vetor b
        }
    }

    for (int i = n - 1; i >= 0; i--) { // retro substituicao, percorrendo a matriz triangular de baixo pra cima
        
        x[i] = b[i];  // define x como b
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j]; // calcula soma dos produtos 
        }
        x[i] /= A[i][i];  // divide pelo coeficiente
    }
}
/***************************************************************************/
/*  End Function: void gauss - Retorna o vetor solução x preenchido.
***************************************************************************/
