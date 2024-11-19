#include <stdio.h>
#include <math.h>

// Função que implementa o Método da Seção Áurea (MSA)
int msa(double a, double b, double (*f)(double x), double tol, double* xmin) {
    const double g = (sqrt(5) - 1) / 2; 
    double x1, x2, f1, f2;
    int iter = 0;
    
    x1 = a + (1 - g) * (b - a);
    x2 = a + g * (b - a);
    
    f1 = f(x1);
    f2 = f(x2);

    // Repetir enquanto o intervalo for maior que a tolerância
    while ((b - a) / 2 > tol && iter < 50) {      
       
        // Atualiza o intervalo com base nos valores de f(x1) e f(x2)
        if (f1 <= f2) {
            b = x2; // O mínimo está em [a, x2]
            x2 = x1;
            f2 = f1;
            x1 = a + (1 - g) * (b - a); // Calcula o ponto x1
            f1 = f(x1); // Calcula o novo f1
        } else {
            a = x1; // O mínimo está em [x1, b]
            x1 = x2;
            f1 = f2;
            x2 = a + g * (b - a); // Calcula o ponto x2
            f2 = f(x2); // Calcula o novo f2
        }

        // Incrementa o número de iterações
        iter++;
    }

    // O valor mínimo está no ponto médio do intervalo final
    *xmin = (a + b) / 2;

    // Retorna o número de iterações realizadas
    return iter;
}

// Função que implementa o Método da Interpolação Parabólica Sucessiva (MIPS)
int mips(double r, double delta, double (*f)(double x), double tol, double* xmin) {
    // Definir as três estimativas iniciais
    double s = r - delta;
    double t = r + delta;
    double fs = f(s);
    double ft = f(t);
    double fr = f(r);
    
    // Definir variáveis para a nova estimativa (x)
    double x;
    double denominador;
    
    int iter = 0;

    // Loop até atingir a tolerância ou o número máximo de iterações
    while (iter < 50) {
        
        // Calcular o denominador da fórmula de interpolação
        denominador = 2.0*((s - r) * (ft - fs) - (fs - fr) * (t - s));
        
        // Se o denominador for suficientemente pequeno, usamos a média simples
        if (fabs(denominador) < 1e-10) {
            x = (r + s + t) / 3;
        } 
        else {
            // Calcular a nova estimativa x usando a fórmula da interpolação parabólica
            x = ((r + s) / 2) - ((fs - fr) * (t - r) * (t - s)) / (denominador);
        }

        // Verificar o critério de convergência
        if (iter >2 && fabs(fs - ft) <= tol) {
            *xmin = (s + t) / 2;
            return iter;
        }

        // Atualizar as estimativas
        r = s;
        s = t;
        t = x;
        fr = fs;
        fs = ft;
        
        // Avaliar a função na nova estimativa x
        double fx = f(x);
        
        // Atualizar por fim ft (f(t)) pois depende de fx
        ft = fx;    
        
        // Incrementa o número de iterações
        iter++;
        
    }

    // Caso não tenha convergido em 50 iterações, retorna zero
    return 0;
}
