# 📖 Overview
This C program implements Strassen's algorithm for fast matrix multiplication of two integer matrices. It handles matrices of arbitrary size by padding them to the next power of two, recursively divides the matrices into submatrices, and applies Strassen's formula to multiply them more efficiently than the standard cubic approach.

# ⚙️ Usage
- Compile with: `gcc -o strassen_matrix_multiplication strassen_matrix_multiplication.c -lm`
- Run the executable: `./strassen_matrix_multiplication`
- Input dimensions of matrices A and B.
- Enter elements of matrix A and matrix B.
- The program outputs the input matrices and their product.
- Matrix multiplication is only performed if the column count of A equals the row count of B, otherwise it errors out.

Example interaction:
      Enter number of rows for Matrix A: 2
      
      Enter number of columns for Matrix A: 3

      Enter number of rows for Matrix B: 3
      
      Enter number of columns for Matrix B: 2
      
      Enter elements of Matrix A (2 x 3):
          1 2 3
          4 5 6
      
      Enter elements of Matrix B (3 x 2):
          7 8
          9 10
          11 12
          
      Resultant Matrix (A x B):
          58 64
          139 154

# ⏳ Time Complexity
- Strassen's algorithm has a time complexity of approximately O( n^{2.81} ), improving over the classical O( n^3 ) for large matrices.
- The recursive division and combination steps dominate the computation.

# 💾 Space Complexity
- Requires O( n^2 ) space for storing input, output, and intermediate submatrices during recursion.
- Additional dynamic memory allocation is used during recursion for submatrices.

# 🧩 Examples
    Input:
        Matrix A (2x2):
            1 3
            7 5
            
        Matrix B (2x2):
            6 8
            4 2
        
    
    Output:
        Resultant Matrix (A x B):
            18 14
            62 66
            

---
This implementation provides an efficient way to multiply large matrices using Strassen's divide-and-conquer method, adapting to non-power-of-two dimensions by padding.

