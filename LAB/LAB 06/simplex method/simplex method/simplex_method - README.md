
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

## Time Complexity

Let:

m = number of constraints

n = number of variables + slack/surplus variables

### Per pivot:

Finding entering variable: O(n)

Finding leaving variable: O(m)

Row operations: O(m × n)

### Total:

If the algorithm performs k pivots:

Time Complexity = O(k × m × n)


In practice, k is usually moderate, but in worst-case theoretical scenarios Simplex can take exponential time.

## Space Complexity

The tableau size is:

(m + 1) rows × (n + 1) columns


So memory usage is:

Space Complexity = O(m × n)

## Compilation

Use any C compiler. For GCC:

```bash
gcc simplex.c -o simplex
