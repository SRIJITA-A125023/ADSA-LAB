# 🔢 Matrix Inversion Using LU Decomposition

This project implements **matrix inversion using LU Decomposition** in the **C programming language**.  
The algorithm decomposes a given square matrix \( A \) into:

\[
A = L \times U
\]

where:
- **L** is a lower triangular matrix with diagonal elements equal to 1  
- **U** is an upper triangular matrix  

Once the decomposition is complete, the inverse of \( A \) is computed by solving:

\[
A X = I
\]

column by column using **forward and backward substitution**.

---

## 📌 Key Concepts Used

- LU Decomposition (Doolittle’s Method)  
- Forward Substitution (solving \( L \cdot Y = B \))  
- Backward Substitution (solving \( U \cdot X = Y \))  
- Matrix inversion via solving multiple linear systems  

---

## ⚙️ How the Program Works

### 1️⃣ LU Decomposition

The input matrix \( A \) is decomposed into:

\[
A = L \times U
\]

- **L** → Lower triangular matrix with diagonal elements equal to 1  
- **U** → Upper triangular matrix  

If any pivot element becomes zero during decomposition, the matrix is declared **singular**, and the inversion process terminates.

---

### 2️⃣ Solving \( A X = I \)

To compute the inverse matrix:

- Each column of the identity matrix \( I \) is treated as a right-hand-side vector \( e_i \)
- Solve the system using:
  - \( L \cdot Y = e_i \) (Forward Substitution)  
  - \( U \cdot X = Y \) (Backward Substitution)

The solution vector \( X \) forms one column of \( A^{-1} \).  
This process is repeated for all columns of the identity matrix.

---

## ⏱️ Time Complexity

Let \( n \) be the order of the matrix.

### 1️⃣ LU Decomposition
- Nested loops over the matrix  
- **Time Complexity:** \( O(n^3) \)

### 2️⃣ Forward Substitution
- Performed for each column of the identity matrix  
- \( O(n^2) \times n = O(n^3) \)

### 3️⃣ Backward Substitution
- \( O(n^2) \times n = O(n^3) \)

### ✅ Overall Time Complexity
\[
O(n^3)
\]

---

## 💾 Space Complexity

### Storage Used
- Matrix \( A \) → \( O(n^2) \)  
- Matrices \( L \) and \( U \) → \( O(n^2) \)  
- Inverse matrix \( A^{-1} \) → \( O(n^2) \)  
- Temporary vectors → \( O(n) \)

### ✅ Overall Space Complexity
\[
O(n^2)
\]

---

## 🧪 Sample Input
Enter order of matrix: 3
Enter matrix elements:
2 1 1
1 3 2
1 0 0

---

## 📤 Sample Output
Inverse Matrix:
0.0000 0.0000 1.0000
-2.0000 1.0000 3.0000
3.0000 -1.0000 -5.0000

---

## 📖 Academic Note

This project is intended for **educational purposes** and demonstrates a numerical method for matrix inversion using LU decomposition. It is suitable for coursework in **Advanced Data Structures and Algorithms** or **Numerical Methods**.

---

