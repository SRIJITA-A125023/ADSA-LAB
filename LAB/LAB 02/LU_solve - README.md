# LU Decomposition and Linear System Solver in C

This program performs LU decomposition on a square matrix **A** and then solves the linear system **Ax = b** using forward and backward substitution. The implementation uses Doolittle's method where **L** has ones on its diagonal.

---

## Features

- Computes **L** (lower triangular) and **U** (upper triangular) matrices.
- Solves a linear system **Ax = b** using LU factors.
- Prints matrices in an easy-to-read layout.
- Accepts any size up to `20 × 20`.

---

## How the Algorithm Works

### LU Decomposition

The matrix **A** is decomposed into:

A = L × U


Where:
- **L** is lower triangular with all diagonal entries equal to 1.
- **U** is upper triangular.

### Solving Ax = b

Once **L** and **U** are computed:

1. Solve **Ly = b**    (forward substitution)  
2. Solve **Ux = y**    (backward substitution)

---

## How to Compile

Use any C compiler such as GCC:

```bash
gcc lu.c -o lu -lm


