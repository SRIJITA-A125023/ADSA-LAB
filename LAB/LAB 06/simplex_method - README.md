# 📖 Overview
This C program implements the Simplex Algorithm to solve linear programming problems with inequalities (both `<=` and `>=`) and non-negativity constraints. It accepts user input for variables, constraints, and objective function, constructs the simplex tableau, iteratively performs pivot operations, and outputs the optimal solution and objective value.

# ⚙️ Usage
- Compile using: `gcc -o simplex simplex.c`
- Run the executable: `./simplex`
- Input the number of variables and constraints.
- Specify the problem as maximization (1) or minimization (2).
- Enter each constraint’s coefficients, type (`1` for `<=` or `2` for `>=`), and RHS value.
- Input the objective function coefficients.
- The program will display each tableau step and final optimal values for variables and objective.

      Example for maximization problem:

         Enter number of variables: 2
         Enter number of constraints: 2
         Enter 1 to Maximize or 2 to Minimize the objective function: 1

         Constraint 1:
           Enter coefficient of x1: 1
           Enter coefficient of x2: 2
           Enter constraint type (1 for <= , 2 for >=): 1
           Enter RHS value: 8

         Constraint 2:
            Enter coefficient of x1: 3
            Enter coefficient of x2: 2
            Enter constraint type (1 for <= , 2 for >=): 1
            Enter RHS value: 12

         Enter coefficients of Objective Function (Z = c1x1 + c2x2 ...):
         Coefficient of x1: 3
         Coefficient of x2: 5

# ⏳ Time Complexity
- Each pivot operation involves checks across all constraints and variables O(m n).
- The number of pivot steps varies by problem and size but is generally exponential in the worst case.
- Practical performance is often efficient for moderate problem sizes.

# 💾 Space Complexity
- Uses a fixed-size 2D array tableau of size \((m+1) * (n+1)\).
- Space complexity is \(O(m n)).

# 🧩 Examples
Sample output after solving a maximization problem (from the example above):

Optimal Solution Found:
x1 = 4.00,
x2 = 2.00

Optimal Value of Z = 23.00

For an unbounded problem, it prints:
Unbounded solution!

---
This code provides a clear, interactive way to apply the Simplex Method to linear programming problems with mixed inequality types and objective goals.

