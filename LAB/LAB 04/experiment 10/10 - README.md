# 📖 Overview
This C program implements the Strassen algorithm for multiplying two square matrices whose sizes are powers of two. Strassen’s algorithm reduces the number of recursive multiplications compared to the standard method, improving the multiplication time complexity. The program recursively divides matrices into submatrices and combines partial results to form the final product.

# ⚙️ Usage
- Compile with: `gcc -o strassen strassen.c`
- Run: `./strassen`
- Enter the size of the square matrices (must be a power of two, e.g., 2, 4, 8).
- Input the elements of matrix A and matrix B.
- The program outputs the resultant matrix product after Strassen multiplication.

Example:


    Enter the size of the square matrices (power of 2, e.g., 2, 4, 8): 2
    
    Enter elements of Matrix A:
        1 2
        3 4
    
    Enter elements of Matrix B:
        5 6
        7 8
    
    Resultant Matrix after Strassen Multiplication:
        19 22
        43 50

# ⏳ Time Complexity
- Strassen's algorithm runs in approximately O( n^{2.81} ), which is faster than the classical O( n^3 ) algorithm for large matrices.

# 💾 Space Complexity
- Uses O( n^2 ) space for storing matrices, submatrices, and intermediate computations.
- Recursive allocations for submatrices contribute to additional memory overhead.

# 🧩 Examples
      Input:
          Matrix A (2x2):
              1 3
              7 5
              
          Matrix B (2x2):
              6 8
              4 2
          
      Output:
          Resultant Matrix after Strassen Multiplication:
              18 14
              62 66

---
This program demonstrates an efficient divide-and-conquer approach to matrix multiplication via Strassen's method.



