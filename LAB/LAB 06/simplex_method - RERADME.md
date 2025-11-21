# Simplex Method in C

This program solves linear programming problems using the Simplex method. It works for both maximization and minimization and supports constraints of type `<=` and `>=`.

## Features

- Supports any number of variables and constraints (up to the defined limit).
- Handles both maximization and minimization.
- Builds and displays the Simplex tableau.
- Performs pivot operations and prints each iteration.
- Detects unbounded solutions.
- Prints the final optimal values of the decision variables and objective function.

## How It Works

1. You enter:
   - Number of variables
   - Number of constraints
   - Whether the goal is maximization or minimization
   - Coefficients of each constraint
   - Type of each constraint (`<=` or `>=`)
   - Objective function coefficients

2. The program:
   - Builds the initial tableau
   - Performs the Simplex iterations
   - Prints intermediate tableaus
   - Outputs the final solution

## Compilation

Use any C compiler. For GCC:

```bash
gcc simplex.c -o simplex
