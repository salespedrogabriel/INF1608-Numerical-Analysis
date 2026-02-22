<div align="center">
    <h1>Lab 2: Roots of Functions</h1> 
    <h2>INF1608 – Numerical Analysis</h2>
    <h3><p>Leonardo Quatrin Campagnolo | lquatrin@tecgraf.puc-rio.br</p>
        <p>Department of Informatics, PUC-Rio, August 29, 2024</p>
    </h3>
    <p> Original file in Portuguese at: <a href="https://github.com/salespedrogabriel/INF1608-Numerical-Analysis/blob/main/%5BLab%2001%5D%20Taylor%20Series/raiz.pdf">raiz.pdf</a></p>
    <p><b>Submission deadline:</b> 2 hours for 100% | 3 hours for 90%</p>
</div>

<div align="center">
    <p><b>The assignments will be automatically graded by test programs.</b> Follow the specifications carefully.</p>
</div>

1.  The bisection method for determining roots of the function $f(x)$ receives as input the search interval $[a, b]$, supposedly with a sign change of the function: $f(a) \cdot f(b) < 0$. The progressive error is given by half the length of the search interval, $e = \frac{b-a}{2}$. The next estimate is given by the midpoint of the interval, $c = \frac{a+b}{2}$, reducing the search interval to $[a, c]$ or $[c, b]$, according to the change in the function's sign. The method returns the midpoint of the final interval as the root estimate.

    Implement a function to determine the root of a function $f(x)$ using the bisection method, where the evaluated progressive error has a precision of 8 digits, i.e., $e_{max} < 0.5 \times 10^{-8}$. Your function must receive as parameters the search interval $[a, b]$ and the function $f(x)$ whose root is to be calculated. Additionally, the function receives the address of the variable that will store the calculated root. Your function must return the number of iterations used in determining the root, following the prototype below. If, in the initial interval, there is no sign change of $f(x)$, the coded function must return zero. The iteration should also be stopped if $|f(c)| < 10^{-12}$, returning $c$ as the root estimate. Your solution must minimize the number of evaluations of $f(x)$.

    ```
    int bissecao (double a, double b, double (*f) (double x), double* r);
    ```

2.  Test the method to find the root of the function $f(x) = x^3 + 2x^2 - 2$, and the number of iterations needed for different initial estimates.

3.  To verify the non-convergence criterion, test your implementation to find the root of the function $f(x) = x^4 + x + 1$.

4.  As an additional test, use the method to solve the following problem: the velocity of a skydiver in free fall can be given by:

    <div align="center">
      <h3>  $$v = \frac{gm}{c} \left(1 - e^{-\frac{c}{m}t}\right)$$</h3>
    </div>
    

    where $g = 9.8 \, m/s^2$. For a skydiver with a drag coefficient $c = 15 \, Kg/s$, calculate the mass $m$ so that the velocity is $v = 35 \, m/s$ at $t = 9 \, s$.

Organize your code as follows. The file "raiz.c" must contain the implementation of the `bissecao` function, with its respective prototype in the file "raiz.h". The file "main.c" must contain the tests performed.

**Submission:** The source code for this lab assignment (i.e., the files "raiz.h", "raiz.c", and "main.c", not zipped) must be submitted via the course page on EAD within 1 hour after the end of the class. The system will accept late submissions (with a loss of 1 point in the evaluation) after the deadline.
