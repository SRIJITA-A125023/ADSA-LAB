# Strassen Matrix Multiplication in C

This project implements matrix multiplication using the Strassen algorithm.  
It works for square matrices whose size is a power of two, such as 2, 4, 8, and so on.

## Overview

The program reads two square matrices, applies the Strassen algorithm recursively, and prints the resulting product matrix.  
It uses fixed-size arrays (10×10) but only processes the first `n x n` elements based on user input.

## Features

- Recursive Strassen implementation  
- Matrix addition and subtraction helpers  
- Simple input and output format  
- No dynamic allocation  
- Works for any power-of-2 matrix size up to 8×8 (within the 10×10 limit)

## How the Algorithm Works

Strassen reduces the usual 8 multiplications in a 2×2 block matrix multiplication down to 7.  
It divides each matrix into four submatrices and computes seven intermediate matrices (M1 to M7).  
The final result is built from these smaller matrices.

## Usage

### Compile

```bash
gcc strassen.c -o strassen
