# LUP Decomposition and Linear System Solver in C

This program performs LUP decomposition on a square matrix and can optionally solve a linear system of the form **Ax = b** using the decomposed matrices.

It includes:
- LUP decomposition with partial pivoting  
- Extraction of L and U matrices  
- Forward and backward substitution  
- Optional solving of linear equations  
- Matrix printing utilities  

The implementation uses a flat 1D array to store matrices in row-major order.

---

## Features

- Computes L, U, and permutation vector P.
- Detects singular or near-singular matrices.
- Solves linear systems when requested.
- Prints matrices in a readable format.
- Works for any matrix size `N × N`.

---

## How LUP Decomposition Works

A matrix **A** is factored into:

PA = LU


Where:
- **P** is a permutation matrix (stored as an index vector)
- **L** is a unit lower triangular matrix
- **U** is an upper triangular matrix

This method is more stable than simple LU decomposition.

---

## How to Compile

Use GCC or any standard C compiler:

```bash
gcc lup.c -o lup -lm


PA = LU
