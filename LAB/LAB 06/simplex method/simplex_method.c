#include <stdio.h>
#include <stdlib.h>

#define MAX 20   // Max size for tableau

// Function to print the simplex tableau
void printTableau(float tableau[MAX][MAX], int m, int n) {
    printf("\nCurrent Simplex Tableau:\n");
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%10.2f ", tableau[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Simplex Algorithm Core
void simplex(float tableau[MAX][MAX], int m, int n) {
    int i, j, pivotCol, pivotRow;
    float min, ratio, pivotElement;
    float result[MAX];

    while (1) {
        // Step 1: Find entering variable (most negative in last row)
        min = 0;
        pivotCol = -1;
        for (j = 0; j < n; j++) {
            if (tableau[m][j] < min) {
                min = tableau[m][j];
                pivotCol = j;
            }
        }
        if (pivotCol == -1)
            break;  // Optimal solution reached

        // Step 2: Find leaving variable (minimum ratio test)
        min = 99999;
        pivotRow = -1;
        for (i = 0; i < m; i++) {
            if (tableau[i][pivotCol] > 0) {
                ratio = tableau[i][n] / tableau[i][pivotCol];
                if (ratio < min) {
                    min = ratio;
                    pivotRow = i;
                }
            }
        }

        if (pivotRow == -1) {
            printf("Unbounded solution!\n");
            return;
        }

        // Step 3: Pivot operation
        pivotElement = tableau[pivotRow][pivotCol];
        for (j = 0; j <= n; j++)
            tableau[pivotRow][j] /= pivotElement;

        for (i = 0; i <= m; i++) {
            if (i != pivotRow) {
                float factor = tableau[i][pivotCol];
                for (j = 0; j <= n; j++)
                    tableau[i][j] -= factor * tableau[pivotRow][j];
            }
        }

        printTableau(tableau, m, n);
    }

    // Step 4: Display results
    printf("\nOptimal Solution Found:\n");
    for (j = 0; j < n; j++)
        result[j] = 0;

    for (i = 0; i < m; i++) {
        int basicVar = -1;
        for (j = 0; j < n; j++) {
            if (tableau[i][j] == 1) {
                int zeroCount = 0;
                for (int k = 0; k < m; k++)
                    if (tableau[k][j] == 0 || k == i)
                        zeroCount++;
                if (zeroCount == m)
                    basicVar = j;
            }
        }
        if (basicVar != -1)
            result[basicVar] = tableau[i][n];
    }

    for (j = 0; j < n - m; j++)
        printf("x%d = %.2f\n", j + 1, result[j]);

    printf("Optimal Value of Z = %.2f\n", tableau[m][n]);
}

int main() {
    float tableau[MAX][MAX];
    int m, n;
    int constraintType, numVariables, numConstraints;
    int isMaximization;
    float coeffs[MAX], rhs[MAX];
    int constraintSigns[MAX];

    printf("Enter number of variables: ");
    scanf("%d", &numVariables);

    printf("Enter number of constraints: ");
    scanf("%d", &numConstraints);

    printf("Enter 1 to Maximize or 2 to Minimize the objective function: ");
    scanf("%d", &isMaximization);

    // Initialize tableau
    for (int i = 0; i <= numConstraints; i++)
        for (int j = 0; j <= numVariables + numConstraints; j++)
            tableau[i][j] = 0;

    // Input constraint coefficients
    for (int i = 0; i < numConstraints; i++) {
        printf("\nConstraint %d:\n", i + 1);
        for (int j = 0; j < numVariables; j++) {
            printf("Enter coefficient of x%d: ", j + 1);
            scanf("%f", &tableau[i][j]);
        }

        printf("Enter constraint type (1 for <= , 2 for >=): ");
        scanf("%d", &constraintType);
        constraintSigns[i] = constraintType;

        printf("Enter RHS value: ");
        scanf("%f", &rhs[i]);
        tableau[i][numVariables + i] = (constraintType == 1) ? 1 : -1; // slack or surplus
        tableau[i][numVariables + numConstraints] = rhs[i];
    }

    m = numConstraints;
    n = numVariables + numConstraints;

    // Input objective function coefficients
    printf("\nEnter coefficients of Objective Function (Z = c1*x1 + c2*x2 ...):\n");
    for (int j = 0; j < numVariables; j++) {
        printf("Coefficient of x%d: ", j + 1);
        scanf("%f", &coeffs[j]);
        tableau[m][j] = (isMaximization == 1) ? -coeffs[j] : coeffs[j]; // For minimization, reverse sign
    }

    // --- Display the problem setup clearly ---
    printf("\n---------------------------------------------\n");
    if (isMaximization == 1)
        printf("Objective: Maximize Z = ");
    else
        printf("Objective: Minimize Z = ");

    for (int j = 0; j < numVariables; j++) {
        printf("%.2fx%d", coeffs[j], j + 1);
        if (j < numVariables - 1)
            printf(" + ");
    }
    printf("\nSubject to:\n");

    for (int i = 0; i < numConstraints; i++) {
        for (int j = 0; j < numVariables; j++) {
            printf("%.2fx%d", tableau[i][j], j + 1);
            if (j < numVariables - 1)
                printf(" + ");
        }
        if (constraintSigns[i] == 1)
            printf(" <= ");
        else
            printf(" >= ");
        printf("%.2f\n", rhs[i]);
    }
    printf("and xj >= 0 for all j\n");
    printf("---------------------------------------------\n");

    printTableau(tableau, m, n);
    simplex(tableau, m, n);

    return 0;
}

/* input <=
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

Enter coefficients of Objective Function (Z = c1*x1 + c2*x2 ...):
Coefficient of x1: 3
Coefficient of x2: 5
*/

/* input >=
Enter number of variables: 2
Enter number of constraints: 2
Enter 1 to Maximize or 2 to Minimize the objective function: 2

Constraint 1:
Enter coefficient of x1: 6
Enter coefficient of x2: 4
Enter constraint type (1 for <= , 2 for >=): 2
Enter RHS value: 24

Constraint 2:
Enter coefficient of x1: 1
Enter coefficient of x2: 2
Enter constraint type (1 for <= , 2 for >=): 2
Enter RHS value: 6

Enter coefficients of Objective Function (Z = c1*x1 + c2*x2 ...):
Coefficient of x1: 5
Coefficient of x2: 4
*/
