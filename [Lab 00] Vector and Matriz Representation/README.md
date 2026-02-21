<div align="center">
    <h1>Lab 0: Representation of Vectors and Matrices</h1> 
    <h2>INF1608 – Numerical Analysis</h2>
    <h3><p>Leonardo Quatrin Campagnolo | lquatrin@tecgraf.puc-rio.br</p>
        <p>Department of Informatics, PUC-Rio, August 15, 2024</p>
    </h3>
    <p> Original file in Portuguese at: <a href="https://github.com/salespedrogabriel/INF1608-Numerical-Analysis/blob/main/%5BLab%2000%5D%20Vector%20and%20Matriz%20Representation/matriz.pdf">matriz.pdf</a></p>
    <p><b>Submission deadline:</b> 2 hours for 100% | 3 hours for 90%</p>
</div>

<div align="center">
    <p><b>The assignments will be automatically graded by test programs.</b> Follow the specifications carefully.</p>
</div>

---

The objective of this lab is to create functions for the representation and manipulation of dynamic vectors and matrices. The matrix will be represented as a vector of pointers, where each element points to a row vector.

1. Study the provided vector code and complete it by implementing the following functions:  
   (a) Implement a function that computes and returns the value of the dot product between two vectors of dimension `n`.
<div align="center">
  <h3>  $${\Large \mathbf{v} \cdot \mathbf{w} = \sum_{0}^{n-1} v_i w_i}$$</h3>
</div>

```
double vet_escalar (int n, double* v, double* w);
```

  (b) Implement a function that computes the norm-2 of a vector of dimension *n*. The norm-2 of a vector is given by:

<div align="center">
  <h3>  $${\Large \|\mathbf{v}\|_2 = \sqrt{\sum_{0}^{n-1} v_i^2}}$$</h3>
</div>

```
double vet_norma2 (int n, double* v);
```
  (c) Implement a function that tests whether two vectors v and w are equal, element by element, within a given tolerance, i.e., the absolute value of the differences between elements must be less than or equal to a tolerance tol.

```
int vet_iguais (int n, double* v, double* w, double tol);
```

2. Study the provided matrix code and complete it by implementing the following functions:  
  (a) Implement a function that receives the dimension m × n of matrix A, and fills another matrix T with dimension n × m, already allocated, with the result of the transposed matrix of A:

<div align="center">
  <h3>  $${\Large A = [a_{ij}]_{i,j=1}^{m,n} \Rightarrow T = A^T = [a_{ji}]_{j,i=1}^{n,m}}$$</h3>
</div>

```
void mat_transposta (int m, int n, double **A, double** T);
```

(b) Implement a function that receives a matrix and a vector, and fills another vector, already allocated, with the result of the matrix-vector multiplication. 
The function receives the dimension m × n of the matrix and assumes that the first vector v has dimension n and the result vector w has dimension m:

<div align="center">
  <h3>  $${\Large w_i = \sum_{j=0}^{n-1} A_{ij} v_j}$$</h3>
</div>

```
void mat_multv (int m, int n, double** A, double* v, double* w);
```

(c) Implement a function that calculates the multiplication between two matrices: C = AB. 
The function receives the dimensions m, n and q, and the matrices $$A_{m×n}$$, $$B_{n×q}$$ and $$C_{m×q}$$, filling C, already allocated:

<div align="center">
  <h3>  $${\Large C_{ik} = \sum_{j=0}^{n-1} A_{ij} B_{jk}}$$</h3>
</div>

```
void mat_multm (int m, int n, int q, double** A, double** B, double** C);
```

Complement the "main.c" module to test your implementation.

**Submission:** The source code of this assignment (i.e., the files "vetor.h", "vetor.c", "matriz.h", "matriz.c" and "main.c", **not** zipped) must be submitted via the course page on EAD by the end of class. 
This lab does not count towards the course evaluation. To be corrected late, the final submission deadline is up to 1 hour after the end of class.
