# 📖 Overview
This C program performs LU decomposition on a square matrix \( A \) without pivoting, decomposing it into a lower triangular matrix \( L \) and an upper triangular matrix \( U \). It then solves the linear system \( Ax = b \) by forward and backward substitution using matrices \( L \) and \( U \).

# ⚙️ Usage
- Compile with: `gcc -o lu_decomposition lu_decomposition.c`
- Run the executable: `./lu_decomposition`
- Input the order \( n \) of the matrix.
- Enter the elements of the \( n * n \) matrix \( A \) row-wise.
- Enter the elements of the vector \( b \).
- The program outputs matrices \( L \), \( U \), and the solution vector \( x \).

  Example input:
      
        Enter the order of matrix (n): 3
    
    
        Enter the elements of matrix A (3x3):
          4 3 2
          3 2 1
          2 1 3
      
        Enter the elements of vector b (3):
          1 2 3

# ⏳ Time Complexity
- LU decomposition requires  O( n^3 ) operations.
- Forward and backward substitution each require  O( n^2 ) .
- Overall complexity is  O( n^3 ) .

# 💾 Space Complexity
- Uses  O( n^2 )  space for matrices \( A \), \( L \), and \( U \).
- Uses  O(n)  space for vectors \( b \), \( x \), and intermediate calculations.

# 🧩 Examples
  For the example above, the program outputs:
    
    Matrix L:
      1.0000 0.0000 0.0000
      0.7500 1.0000 0.0000
      0.5000 0.3333 1.0000
    
    Matrix U:
      4.0000 3.0000 2.0000
      0.0000 -0.2500 -0.5000
      0.0000 0.0000 2.0000
    
    Solution vector x:
      -3.0000
      7.0000
      -3.0000
    

---
This program provides a fundamental LU decomposition method for solving linear systems but does not include pivoting, which may affect stability for some matrices.
