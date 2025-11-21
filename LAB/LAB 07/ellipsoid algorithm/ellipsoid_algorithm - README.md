# Ellipsoid Method for Linear Feasibility (C Implementation)

This project implements the Ellipsoid Algorithm to find a feasible point that satisfies a set of linear constraints of the form:

A * x ≤ b


The example uses a 2-dimensional system (`N = 2`) and demonstrates how the ellipsoid is updated until it finds a feasible point or reaches an iteration limit.

## Overview

The program:

- Defines four linear constraints  
- Initializes an ellipsoid with a center and shape matrix  
- Iteratively checks constraint violations  
- Updates the ellipsoid center and matrix when a constraint is violated  
- Stops when it finds a feasible point or exceeds `MAX_ITER`

This implementation gives a practical demonstration of how the ellipsoid method narrows down a feasible region in optimization and feasibility problems.

## Constraints Used

The system solved in the code:

x + y ≤ 4
x − y ≤ 2
x ≥ 0
y ≥ 0


These form a convex polygon in 2D.

## Key Components

### `mat_vec_mul()`
Multiplies a 2×2 matrix by a 2D vector.

### `dot()`
Computes the dot product of two vectors.

### Ellipsoid Update Steps
When a constraint is violated:

1. Compute normal vector `g`
2. Compute `E * g`
3. Normalize `g` using `sqrt(gᵀEg)`
4. Shift ellipsoid center
5. Update the ellipsoid shape matrix `E`

### Termination
- If all constraints are satisfied at the current center, a feasible point is found.
- If not found in `MAX_ITER` iterations, the algorithm stops.

## Time Complexity

Let:

n = number of variables (= 2)

m = number of constraints (= 4)

T = number of iterations (MAX_ITER = 5000)

### Per iteration

Check all constraints: O(m)

Matrix-vector multiplication for update: O(n²)

Several vector operations: O(n)

Since n = 2, these are constant-time operations.

### Overall
Time Complexity = O(T × (m + n²))


With fixed small n, the runtime is dominated by:

O(T × m)


## Space Complexity

The program stores:

Matrix A: O(m × n)

Matrix E: O(n²)

Vectors center, b, g, Eg: O(n + m)

### Total:

Space Complexity = O(mn + n² + m + n)


With n = 2, this is effectively O(m).

Memory usage is small and fixed.


## Compilation

Use GCC (links math library):

```bash
gcc ellipsoid.c -o ellipsoid -lm
