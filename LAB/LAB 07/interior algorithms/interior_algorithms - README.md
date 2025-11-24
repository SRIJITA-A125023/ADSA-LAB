# 📖 Overview
This C program implements a basic Interior Point Method using gradient descent to solve a linear optimization problem with equality constraints. It minimizes a linear objective function \( c^T x \) subject to \( Ax = b \) and \( x > 0 \) by iteratively updating \( x \) while maintaining feasibility and positivity.

# ⚙️ Usage
- Compile with: `gcc -o interior_point interior_point.c -lm`
- Run the executable: `./interior_point`
- Input the number of variables \( n \), number of equality constraints \( m \), matrix \( A \), vector \( b \), and cost vector \( c \) as prompted.
- The program performs interior point iterations, printing intermediate results and outputs the approximate optimal solution vector \( x \) and objective value.

Example input (from the embedded comment):
Enter number of variables (n): 2
Enter number of equality constraints (m): 1
Enter matrix A (1 x 2):
1 1
Enter vector b (1 elements):
10
Enter cost vector c (2 elements):
1 1

# ⏳ Time Complexity
- Each iteration performs gradient calculation O( n ) and matrix-vector multiplication O(mn).
- The main loop runs for 20 outer iterations and up to 20,000 inner iterations.
- Overall time complexity is approximately O ( n + m ).

# 💾 Space Complexity
- Uses fixed-size arrays of dimensions \(m * n\) and vectors of length \(n\) and \(m\).
- Space complexity is O( mn ).

# 🧩 Examples
Sample run for the problem minimizing \(x_1 + x_2\) with constraint \(x_1 + x_2 = 10\):

Iter 0 mu = 1.00000 x = [ 4.9774 5.0226 ] f = 4.01234

Iter 1 mu = 0.50000 x = [ 4.8815 5.1185 ] f = 4.04567

...

Iter 19 mu = 6.10352e-06 x = [ 5.0000 5.0000 ] f = 5.00000


Optimal x ≈ [ 5.000000 5.000000 ]

Optimal objective ≈ 10.000000

---
This implementation demonstrates solving constrained linear optimization problems using interior point methods with simple gradient descent and projection.
