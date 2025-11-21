# Strassen Matrix Multiplication in C

This project implements matrix multiplication using the Strassen algorithm.  
It supports non-square matrices by padding them to the next power of two.

## Features

- Automatic padding to handle matrices of any size  
- Recursive Strassen multiplication  
- Matrix addition and subtraction helpers  
- Dynamic memory allocation  
- Clean matrix printing  
- Works for both square and non-square matrices as long as A's columns match B's rows

## How It Works

Strassen's algorithm reduces the number of multiplications compared to the standard approach.  
It divides the matrices into four submatrices and computes seven intermediate products, which leads to faster performance for large matrices.

## Input Requirements

- Matrix A size: `r1 x c1`  
- Matrix B size: `r2 x c2`  
- `c1` must equal `r2` for multiplication to work.

## Output

The program prints:

- Matrix A  
- Matrix B  
- Resultant Matrix (A × B)

## Compilation

Use any C compiler. For example with GCC:

```bash
gcc strassen.c -o strassen -lm

