<div align="center">
    <h1>Lab 1: Taylor Series</h1> 
    <h2>INF1608 – Numerical Analysis</h2>
    <h3><p>Leonardo Quatrin Campagnolo | lquatrin@tecgraf.puc-rio.br</p>
        <p>Department of Informatics, PUC-Rio, August 22, 2024</p>
    </h3>
    <p> Original file in Portuguese at: <a href="https://github.com/salespedrogabriel/INF1608-Numerical-Analysis/blob/main/%5BLab%2001%5D%20Taylor%20Series/taylor.pdf">taylor.pdf</a></p>
    <p><b>Submission deadline:</b> August 23, 2024 (1 day and 12 hours)</p>
</div>

<div align="center">
    <p><b>The assignments will be automatically graded by test programs.</b> Follow the specifications carefully.</p>
</div>

---

It is known that Taylor's theorem is expressed by:

$$f(x) = f(x_0) + \frac{f'(x_0)}{1!}(x - x_0) + \frac{f''(x_0)}{2!}(x - x_0)^2 + \cdots + \frac{f^k(x_0)}{k!}(x - x_0)^k + \frac{f^{k+1}(c)}{(k+1)!}(x - x_0)^{k+1}$$

where the last term, $\frac{f^{k+1}(c)}{(k+1)!}(x - x_0)^{k+1}$, represents the remainder, with $c \in [x_0, x]$.

A Taylor polynomial therefore has the following evaluation structure:

$$p(x) = \sum_{i=0}^{n-1} \frac{c_i}{i!}(x - x_0)^i$$

where $n$ represents the number of terms in the polynomial and $c_i = f^{[i]}(x_0)$ represents each element of a coefficient vector.

1.  Write a function that evaluates a Taylor polynomial given its coefficient vector. The function receives the number of terms $n$, the coefficient vector $c$, the value $x_0$, and the value $x$ at which the polynomial should be evaluated, returning the computed value. The function prototype should be:

    ```c
    double avalia_taylor (int n, double *c, double x0, double x);
    ```

    The function cannot use the standard C mathematical library (it cannot use the `pow` function, for example). Implement it efficiently, taking advantage of the natural factorization of the terms. Note that $x^i = x \cdot x^{i-1}$ and $i! = i \cdot (i-1)!$.

2.  The illustration below shows the Taylor polynomial approximating the function $\sin x$ around the point $x_0 = 0$. Note that the polynomial coefficients follow a simple construction rule: 0, 1, 0, -1, 0, 1, 0, -1, ...

    Based on this observation, write a function that evaluates the Taylor polynomial approximating the $\sin x$ function around $x_0 = 0$. The function receives as a parameter the number of terms $n$ to be used in the approximation, returning the approximate value of the function at point $x$, using the function from the previous item.

    ```c
    double avalia_seno (int n, double x);
    ```

Using the `sin` function from the standard `math.h` library, write a test module `main.c` to evaluate the approximations in calculating $\sin(x)$ for $x = \{\pi/12, \pi/9, \pi/7, \pi/4, \pi/3\}$, using different numbers of terms. Note that the error decreases as the number of terms increases, always being smaller than the maximum remainder indicated by Taylor's Theorem.

**Observations:**
*   Calls to the `math.h` library cannot be used in the evaluation of the required functions; `math.h` functions can only be used in the test.
*   You can access the website www.desmos.com to plot functions (and polynomials).
*   You can access the website www.derivative-calculator.net to evaluate and visualize functions and their derivatives.

Group the function prototypes in a "taylor.h" module, the implementations in a "taylor.c" module, and the test in the "main.c" module.

**Submission:** The source code for this lab assignment (i.e., the files "taylor.h", "taylor.c", and "main.c", not zipped) must be submitted via the course page on EAD by 23:59 on Friday, 08/23.
