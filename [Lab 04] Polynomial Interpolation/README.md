<div align="center">
    <h1>Lab 4: Polynomial Interpolation</h1> 
    <h2>INF1608 – Numerical Analysis</h2>
    <h3><p>Leonardo Quatrin Campagnolo | lquatrin@tecgraf.puc-rio.br</p>
        <p>Department of Informatics, PUC-Rio, September 12, 2024</p>
    </h3>
    <p> Original file in Portuguese at: <a href="https://github.com/salespedrogabriel/INF1608-Numerical-Analysis/blob/main/%5BLab%2001%5D%20Taylor%20Series/polyinter.pdf">polyinter.pdf</a></p>
    <p><b>Submission deadline:</b> 3 hours for 100% | 13 hours for 90%</p>
</div>

<div align="center">
    <p><b>The assignments will be automatically graded by test programs.</b> Follow the specifications carefully.</p>
</div>

---

1. Implement the following polynomial interpolation functions:

  (a) Regular Sampling
Implement a function that returns $$n$$ regularly spaced samples in the interval $$[a, b]$$, where $$x_i [0] = a$$, $$x_i [n-1] = b$$, and the remaining values are uniformly distributed within the interval. 
The function should compute the samples $$x_i$$, filling the pre-allocated vector passed as a parameter, following the prototype:

```
void regular(int n, double a, double b, double* xi);
```

  (b) Chebyshev Sampling
Implement a function that returns $$n$$ Chebyshev samples for approximating any function within the interval $$[a, b]$$:

<div align="center">
    <<h3>$$x_i =  \frac{b-a}{2} cos\frac{βπ}{2n} + \frac{a+b}{2}, β = 1, 3, 5, ..., 2n - 1$$</h3>
</div>

The function should compute the samples $$x_i$$, filling the pre-allocated vector passed as a parameter, following the prototype:

```
void chebyshev(int n, double a, double b, double* xi);
```
