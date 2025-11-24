#include <stdio.h>
#define N 20  

void LU_decomposition(double A[N][N], double L[N][N], double U[N][N], int n) {
    for (int i = 0; i < n; i++) {
        //upper triangular matrix
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += L[i][j] * U[j][k];
            }
            U[i][k] = A[i][k] - sum;
        }

        //lower triangular matrix
        for (int k = i; k < n; k++) {
            if (i == k)
                L[i][i] = 1; //diagonal -> 1
            else {
                double sum = 0;
                for (int j = 0; j < i; j++) {
                    sum += L[k][j] * U[j][i];
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}

void LU_solve(double L[N][N], double U[N][N], double b[N], double x[N], int n) {
    double y[N];

    //Ly = b (forward substitution: )
    for (int i = 0; i < n; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
        // diagonal of L -> 1
    }

    //Ux = y (backward substitution) 
    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
}

void print_matrix(double M[N][N], int n, char name) {
    printf("\nMatrix %c:\n", name);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%10.4lf ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    double A[N][N], L[N][N] = {0}, U[N][N] = {0};
    double b[N], x[N];

    printf("Enter the order of matrix (n): ");
    scanf("%d", &n);

    printf("Enter the elements of matrix A (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Enter the elements of vector b (%d):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    //LU decomposition
    LU_decomposition(A, L, U, n);

    //print L and U
    print_matrix(L, n, 'L');
    print_matrix(U, n, 'U');

    //solve
    LU_solve(L, U, b, x, n);

    //solution printing
    printf("\nSolution vector x:\n");
    for (int i = 0; i < n; i++) {
        printf("%10.4lf\n", x[i]);
    }

    return 0;
}
