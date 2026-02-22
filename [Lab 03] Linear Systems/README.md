<div align="center">
    <h1>Lab 3: Solving Linear Systems</h1> 
    <h2>INF1608 – Numerical Analysis</h2>
    <h3><p>Leonardo Quatrin Campagnolo | lquatrin@tecgraf.puc-rio.br</p>
        <p>Department of Informatics, PUC-Rio, September 5, 2024</p>
    </h3>
    <p> Original file in Portuguese at: <a href="https://github.com/salespedrogabriel/INF1608-Numerical-Analysis/blob/main/%5BLab%2001%5D%20Taylor%20Series/raiz.pdf">raiz.pdf</a></p>
    <p><b>Submission deadline:</b> 3 hours for 100% | 13 hours for 90%</p>
</div>

<div align="center">
    <p><b>The assignments will be automatically graded by test programs.</b> Follow the specifications carefully.</p>
</div>

---


For this exercise, consider the matrix representation implemented in Lab 0. The matrix is represented by a vector of pointers, where each element points to a row vector.

1.  For solving linear systems of the form $A_{n \times n} x_n = b_n$, consider the Gaussian elimination method which transforms matrix $A$ into an upper triangular matrix and then applies back substitution to find the solution. To improve the numerical stability of the method, a pivoting strategy should be employed, i.e., the rows of the matrix are swapped to ensure that the pivot element for the elimination of each column is always the element with the largest absolute value in that column.

    Implement a function that receives as parameters a matrix $A$, of dimension $n \times n$, and the vector $b$. The function must use the Gaussian elimination method, with pivoting, to determine and fill the solution vector $x$. The function may alter the values of $A$ and $b$ provided. The function prototype should be:

    ```
    void gauss (int n, double** A, double* b, double* x);
    ```

2.  Write code to test your functions. You can use the systems indicated below for initial tests. Be sure to test the same systems by swapping the order of the equations to validate the pivoting.

$$
\begin{bmatrix}
1 & -1 & 0\\
-1 & 2 & 1\\
0 & 1 & 2
\end{bmatrix}
\quad
\begin{bmatrix}
x_1 \\
x_2 \\
x_3
\end{bmatrix}
\quad = \quad
\begin{bmatrix}
0 \\
2 \\
3
\end{bmatrix}
\quad and \quad
\begin{bmatrix}
3 & -1 & 0 & 0 & 0 & 0.5\\
-1 & 3 & -1 & 0 & 0.5 & 0\\
0 & -1 & 3 & -1 & 0 & 0\\
0 & -0 & -1 & 3 & -1 & 0\\
0 & 0.5 & 0 & -1 & 3 & -1\\
0.5 & 0 & 0 & 0 & -1 & 3
\end{bmatrix}
\quad
\begin{bmatrix}
x_1\\
x_2\\
x_3\\
x_4\\
x_5\\
x_6
\end{bmatrix}
\quad = \quad
\begin{bmatrix}
2.5\\
1.5\\
1\\
1\\
1.5\\
2.5
\end{bmatrix}
$$


It is known that the solutions to these systems are $[1\; 1\; 1]$ and $[1\; 1\; 1\; 1\; 1\; 1]$, respectively.

Place the function prototype in a module "sistlinear.h" and the implementation in a module "sistlinear.c". Write another module "main.c" with the test of your implementation.

**Submission:** The source code for this assignment (i.e., the files "sistlinear.h", "sistlinear.c" and "main.c", not zipped), as well as the Lab 0 codes, if used in the solution ("vetor.h", "vetor.c", "matriz.h" and "matriz.c", not zipped), must be submitted via the course page on EAD. The assignment must be submitted by Thursday, September 5th, at 2:00 PM. After this period, submission will remain open until the end of the day with a deduction of 1.0 point from the lab grade.
