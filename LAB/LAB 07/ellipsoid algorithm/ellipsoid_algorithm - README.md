# 📖 Overview
This C program implements the Ellipsoid Algorithm to find a feasible point within a system of linear inequalities  Ax≤b  in 2D. It iteratively updates an ellipsoid containing the feasible region based on violated constraints until a feasible solution is found or a maximum iteration count is reached.

# ⚙️ Usage
- Compile with: `gcc -o ellipsoid ellipsoid.c -lm`
- Run the executable: `./ellipsoid`
- The program checks the provided linear constraints and tries to find a point satisfying all.
- It prints either the feasible point found or notifies if no solution is found within the iteration limit.

The constraints in this example are:

+1.00x +1.00y <= 4.00

+1.00x -1.00y <= 2.00

-1.00x +0.00y <= 0.00

+0.00x -1.00y <= 0.00

representing:

𝑥
+
𝑦
≤
4
x+y≤4

𝑥
−
𝑦
≤
2
x−y≤2

𝑥
≥
0
x≥0

𝑦
≥
0
y≥0
# ⏳ Time Complexity
- Each iteration involves checking constraints (linear in number of constraints \(m\)) and matrix operations on a fixed 2x2 matrix.
- Overall complexity is approximately O(m×MAX_ITER).

# 💾 Space Complexity
- Uses fixed-size arrays for ellipsoid matrix and vectors.
- Space complexity is O( 1 ) as the dimension and \(m\) are fixed/small.

# 🧩 Examples
Sample output on execution:
Linear Constraints (A*x <= b):

+1.00x +1.00y <= 4.00

+1.00x -1.00y <= 2.00

-1.00x +0.00y <= 0.00

+0.00x -1.00y <= 0.00

Initial Ellipsoid Center: (1.0000, 1.0000)

Feasible point found after 11 iterations:
x = 1.000000, y = 1.000000

---
The ellipsoid algorithm is particularly useful for solving feasibility problems and linear programming when the constraints define a convex region.
