#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//pow of 2
int nextPowerOf2(int n) {
    int power = 1;
    while (power < n) power <<= 1;
    return power;
}

//memory - matrix
int** allocateMatrix(int n, int m) {
    int** mat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        mat[i] = (int*)calloc(m, sizeof(int));
    return mat;
}

//memory free - matrix
void freeMatrix(int** mat, int n) {
    for (int i = 0; i < n; i++) free(mat[i]);
    free(mat);
}

//matrix - print
void printMatrix(int **M, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

//adding 2 matrices
void add(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

//subtracting 2 matrices
void subtract(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// strassen - recursive multiplication
void strassen(int **A, int **B, int **C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int **A11 = allocateMatrix(k, k);
    int **A12 = allocateMatrix(k, k);
    int **A21 = allocateMatrix(k, k);
    int **A22 = allocateMatrix(k, k);

    int **B11 = allocateMatrix(k, k);
    int **B12 = allocateMatrix(k, k);
    int **B21 = allocateMatrix(k, k);
    int **B22 = allocateMatrix(k, k);

    int **C11 = allocateMatrix(k, k);
    int **C12 = allocateMatrix(k, k);
    int **C21 = allocateMatrix(k, k);
    int **C22 = allocateMatrix(k, k);

    int **M1 = allocateMatrix(k, k);
    int **M2 = allocateMatrix(k, k);
    int **M3 = allocateMatrix(k, k);
    int **M4 = allocateMatrix(k, k);
    int **M5 = allocateMatrix(k, k);
    int **M6 = allocateMatrix(k, k);
    int **M7 = allocateMatrix(k, k);

    int **temp1 = allocateMatrix(k, k);
    int **temp2 = allocateMatrix(k, k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    add(A11, A22, temp1, k);
    add(B11, B22, temp2, k);
    strassen(temp1, temp2, M1, k);

    add(A21, A22, temp1, k);
    strassen(temp1, B11, M2, k);

    subtract(B12, B22, temp2, k);
    strassen(A11, temp2, M3, k);

    subtract(B21, B11, temp2, k);
    strassen(A22, temp2, M4, k);

    add(A11, A12, temp1, k);
    strassen(temp1, B22, M5, k);

    subtract(A21, A11, temp1, k);
    add(B11, B12, temp2, k);
    strassen(temp1, temp2, M6, k);

    subtract(A12, A22, temp1, k);
    add(B21, B22, temp2, k);
    strassen(temp1, temp2, M7, k);

    add(M1, M4, temp1, k);
    subtract(temp1, M5, temp2, k);
    add(temp2, M7, C11, k);

    add(M3, M5, C12, k);
    add(M2, M4, C21, k);

    subtract(M1, M2, temp1, k);
    add(temp1, M3, temp2, k);
    add(temp2, M6, C22, k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }

    freeMatrix(A11, k); freeMatrix(A12, k);
    freeMatrix(A21, k); freeMatrix(A22, k);
    freeMatrix(B11, k); freeMatrix(B12, k);
    freeMatrix(B21, k); freeMatrix(B22, k);
    freeMatrix(C11, k); freeMatrix(C12, k);
    freeMatrix(C21, k); freeMatrix(C22, k);
    freeMatrix(M1, k);  freeMatrix(M2, k);
    freeMatrix(M3, k);  freeMatrix(M4, k);
    freeMatrix(M5, k);  freeMatrix(M6, k);
    freeMatrix(M7, k);
    freeMatrix(temp1, k); freeMatrix(temp2, k);
}

int main() {
    int r1, c1, r2, c2;
    printf("Enter number of rows for Matrix A: ");
    scanf("%d", &r1);
    printf("Enter number of columns for Matrix A: ");
    scanf("%d", &c1);

    printf("Enter number of rows for Matrix B: ");
    scanf("%d", &r2);
    printf("Enter number of columns for Matrix B: ");
    scanf("%d", &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible. Columns of A must equal rows of B.\n");
        return 0;
    }

    int maxSize = fmax(fmax(r1, c1), c2);
    int size = nextPowerOf2(maxSize);

    int **A = allocateMatrix(size, size);
    int **B = allocateMatrix(size, size);
    int **C = allocateMatrix(size, size);

    printf("\nEnter elements of Matrix A (%d x %d):\n", r1, c1);
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    printf("\nEnter elements of Matrix B (%d x %d):\n", r2, c2);
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    //matrix print
    printf("\nMatrix A:\n");
    printMatrix(A, r1, c1);

    printf("\nMatrix B:\n");
    printMatrix(B, r2, c2);

    //strassen multiplication
    strassen(A, B, C, size);

    printf("\nResultant Matrix (A x B):\n");
    printMatrix(C, r1, c2);

    freeMatrix(A, size);
    freeMatrix(B, size);
    freeMatrix(C, size);

    return 0;
}
