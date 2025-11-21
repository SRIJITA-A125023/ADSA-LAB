#include <stdio.h>
#include <math.h>

#define MAX_ITER 5000
#define N 2       // Dimension

// Matrix-vector multiplication
void mat_vec_mul(double M[2][2], double v[2], double out[2]) {
    out[0] = M[0][0]*v[0] + M[0][1]*v[1];
    out[1] = M[1][0]*v[0] + M[1][1]*v[1];
}

// Dot product
double dot(double a[2], double b[2]) {
    return a[0]*b[0] + a[1]*b[1];
}

int main() {

    // Example constraints:
    // x + y <= 4
    // x - y <= 2
    // x >= 0
    // y >= 0

    double A[][2] = {
        {1, 1},
        {1, -1},
        {-1, 0},
        {0, -1}
    };

    double b[] = {4, 2, 0, 0};
    int m = 4;

    // Print the constraints
    printf("Linear Constraints (A*x <= b):\n");
    for (int i = 0; i < m; i++) {
        printf("%+.2fx %+.2fy <= %.2f\n", A[i][0], A[i][1], b[i]);
    }
    printf("\n");

    // Initial ellipsoid parameters
    double center[2] = {1.0, 1.0};
    double E[2][2] = { {10, 0},
                       {0, 10} };

    printf("Initial Ellipsoid Center: (%.4f, %.4f)\n\n",
           center[0], center[1]);

    // Ellipsoid algorithm loop
    for (int iter = 1; iter <= MAX_ITER; iter++) {
        int violated = -1;

        // Check all constraints
        for (int i = 0; i < m; i++) {
            if (A[i][0]*center[0] + A[i][1]*center[1] > b[i]) {
                violated = i;
                break;
            }
        }

        // If none violated, feasible point found
        if (violated == -1) {
            printf("Feasible point found after %d iterations:\n", iter);
            printf("x = %.6f, y = %.6f\n", center[0], center[1]);
            return 0;
        }

        // Violated constraint's normal vector
        double g[2] = {A[violated][0], A[violated][1]};

        // Compute E*g
        double Eg[2];
        mat_vec_mul(E, g, Eg);

        // Compute sqrt(g^T E g)
        double denom = sqrt(dot(g, Eg));

        // Normalize the direction
        double d[2] = { g[0] / denom, g[1] / denom };

        // Update center
        center[0] -= (1.0 / (N + 1)) * d[0];
        center[1] -= (1.0 / (N + 1)) * d[1];

        // Update ellipsoid shape matrix
        double alpha = 2.0 / (N + 1);
        double beta = (N*N) / (N*N - 1);

        double temp[2][2];
        double gEg = dot(g, Eg);

        temp[0][0] = beta * (E[0][0] - alpha * Eg[0] * Eg[0] / gEg);
        temp[0][1] = beta * (E[0][1] - alpha * Eg[0] * Eg[1] / gEg);
        temp[1][0] = beta * (E[1][0] - alpha * Eg[1] * Eg[0] / gEg);
        temp[1][1] = beta * (E[1][1] - alpha * Eg[1] * Eg[1] / gEg);

        // Copy updated ellipsoid back
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                E[i][j] = temp[i][j];
    }

    printf("No feasible point found within iteration limit.\n");
    return 0;
}

/*
1 + 1 = 2 ≤ 4     
1 − 1 = 0 ≤ 2     
x = 1 ≥ 0          
y = 1 ≥ 0 */