#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IDX(i,j,N) ((i)*(N) + (j))
#define EPS 1e-12

//LUP decomposition
int lup_decompose(double *A, int N, int *P) {
    for (int i = 0; i < N; ++i) P[i] = i;
    int parity = 1;

    for (int k = 0; k < N; ++k) {
        int pivot = k;
        double pmax = fabs(A[IDX(k,k,N)]);
        for (int i = k + 1; i < N; ++i) {
            double v = fabs(A[IDX(i,k,N)]);
            if (v > pmax) { pmax = v; pivot = i; }
        }
        if (pmax < EPS) return 0; // singular

        if (pivot != k) {
            for (int j = 0; j < N; ++j) {
                double tmp = A[IDX(k,j,N)];
                A[IDX(k,j,N)] = A[IDX(pivot,j,N)];
                A[IDX(pivot,j,N)] = tmp;
            }
            int tp = P[k]; P[k] = P[pivot]; P[pivot] = tp;
            parity = -parity;
        }

        for (int i = k + 1; i < N; ++i) {
            A[IDX(i,k,N)] /= A[IDX(k,k,N)];
            double lik = A[IDX(i,k,N)];
            for (int j = k + 1; j < N; ++j) {
                A[IDX(i,j,N)] -= lik * A[IDX(k,j,N)];
            }
        }
    }
    return parity;
}

//Ax=b using LUP (A - decomposed)
void lup_solve(const double *A, int N, const int *P, const double *b, double *x) {
    double *y = (double*)malloc(N * sizeof(double));
    if (!y) exit(1);

    for (int i = 0; i < N; ++i) y[i] = b[P[i]];

    //Ly = Pb (forward substitution)
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < i; ++j)
            y[i] -= A[IDX(i,j,N)] * y[j];

    //Ux = y (back substitution)
    for (int i = N - 1; i >= 0; --i) {
        for (int j = i + 1; j < N; ++j)
            y[i] -= A[IDX(i,j,N)] * x[j];
        x[i] = y[i] / A[IDX(i,i,N)];
    }
    free(y);
}

void extract_LU(const double *A, int N, double *L, double *U) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i > j) { L[IDX(i,j,N)] = A[IDX(i,j,N)]; U[IDX(i,j,N)] = 0.0; }
            else if (i == j) { L[IDX(i,j,N)] = 1.0; U[IDX(i,j,N)] = A[IDX(i,j,N)]; }
            else { L[IDX(i,j,N)] = 0.0; U[IDX(i,j,N)] = A[IDX(i,j,N)]; }
        }
    }
}

void print_mat(const char *name, const double *M, int N) {
    printf("%s =\n", name);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            printf("%10.6f ", M[IDX(i,j,N)]);
        printf("\n");
    }
}

int main(void) {
    int N;
    printf("Enter the order of the matrix (N): ");
    scanf("%d", &N);

    double *A = (double*)malloc(N * N * sizeof(double));
    int *P = (int*)malloc(N * sizeof(int));

    printf("Enter the elements of the matrix row by row:\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("A[%d][%d] = ", i+1, j+1);
            scanf("%lf", &A[IDX(i,j,N)]);
        }
    }

    int parity = lup_decompose(A, N, P);
    if (parity == 0) {
        printf("Matrix is singular or near-singular.\n");
        free(A); free(P);
        return 0;
    }

    //LU print
    double *L = (double*)malloc(N * N * sizeof(double));
    double *U = (double*)malloc(N * N * sizeof(double));
    extract_LU(A, N, L, U);

    print_mat("L", L, N);
    print_mat("U", U, N);

    printf("Permutation P: ");
    for (int i = 0; i < N; ++i) printf("%d ", P[i]);
    printf("\n");

    //solve Ax = b ???
    char choice;
    printf("Do you want to solve Ax = b? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        double *b = (double*)malloc(N * sizeof(double));
        double *x = (double*)calloc(N, sizeof(double));

        printf("Enter the elements of vector b:\n");
        for (int i = 0; i < N; ++i) {
            printf("b[%d] = ", i+1);
            scanf("%lf", &b[i]);
        }

        lup_solve(A, N, P, b, x);

        printf("Solution vector x:\n");
        for (int i = 0; i < N; ++i) printf("x[%d] = %.6f\n", i+1, x[i]);

        free(b); free(x);
    }

    free(A); free(P); free(L); free(U);
    return 0;
}
