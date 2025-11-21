# Interior Point Method (Barrier Method) for Linear Optimization in C

This project implements a simple interior point method using a logarithmic barrier and gradient descent updates. The program solves linear optimization problems of the form:

Minimize: cᵀx
Subject to: A x = b
x > 0


It supports up to 20 variables and 20 equality constraints.

## Overview

The algorithm:

- Starts from an interior point (`x = 1` for all variables)
- Uses a barrier function with parameter `mu`
- Performs gradient descent on the barrier-augmented objective
- Projects the iterate back toward feasibility (`Ax = b`)
- Gradually reduces `mu` to move closer to the true optimum

This is an educational demonstration rather than a production-grade solver.

## Key Components

### `objective(x, c, mu, n)`
Computes the barrier-augmented objective:

f(x) = cᵀx − μ Σ log(xᵢ)



### `gradient(grad, x, c, mu, n)`
Computes the gradient of the objective.

### `matvec()`
Simple matrix–vector multiplication to compute `A x`.

### Algorithm Structure
For each outer iteration:

1. Compute gradient  
2. Perform gradient descent update on `x`  
3. Enforce positivity (`xᵢ > 0`)  
4. Project `x` back toward satisfying `A x = b`  
5. Reduce `μ` by a factor (`MU_REDUCTION = 0.5`)  

After all iterations, the program prints the approximate optimal solution and objective value.

## Compilation

Compile using GCC with math library:

```bash
gcc interior_point.c -o interior_point -lm


f(x) = cᵀx − μ Σ log(xᵢ)
