# 📖 Overview
This C program performs LUP (LU with Partial Pivoting) decomposition on a square matrix to factor it into Lower (L) and Upper (U) triangular matrices while tracking row permutations (P). It also optionally solves the system \( Ax = b \) using the decomposed matrices.

# ⚙️ Usage
- Compile the program with: `gcc -o lup_decompose lup_decompose.c -lm`
- Run the executable: `./lup_decompose`
- Input the order \( N \) of the matrix.
- Enter the elements of the \( N \times N \) matrix row-wise.
- The program performs LUP decomposition, prints matrices L and U and the permutation array P.
- Optionally, choose to solve \( Ax = b \) by inputting vector \( b \), and the program outputs solution vector \( x \).

Example interaction:

    Enter the order of the matrix (N): 3
    
    Enter the elements of the matrix row by row:
    
        A = 2​
        
        A = -1​
        
        A = 0​
        
        A = -1​
        
        A = 2​
        
        A = -1​
        
        A = 0​
        
        A = -1​
        
        A = 2​
        
    Permutation P: 0 1 2
    
    Do you want to solve Ax = b? (y/n): y
    
    Enter the elements of vector b:
    
        b = 1​
        
        b = 0​
        
        b = 1​
    
    Solution vector x:
        x = 1.000000​
        
        x = 1.000000​
        
        x = 1.000000


# ⏳ Time Complexity
- The LUP decomposition requires O(N^3) operations for an  (N * N ) matrix.
- Forward and backward substitutions for solving ( Ax = b ) take O(N^2) .

# 💾 Space Complexity
- Uses O(N^2) space for storing the matrix and decomposition.
- Additional O(N) arrays for permutation and solution vectors.

# 🧩 Examples
For a 3x3 matrix example as above, the program outputs:

L =

1.000000   0.000000  0.000000

-0.500000  1.000000  0.000000

0.000000   -0.666667 1.000000

U =

2.000000 -1.000000 0.000000

0.000000 1.500000 -1.000000

0.000000 0.000000 1.333333

Permutation P: 0 1 2

Solution vector x:

  x = 1.000000​
  
  x = 1.000000​
  
  x = 1.000000​

---
This LUP decomposition solver is robust for solving linear systems with pivoting to avoid instability in singular or near-singular matrices.
