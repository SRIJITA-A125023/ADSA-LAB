#include<stdio.h>
#include<math.h>
#define N 102573
#include <stdlib.h>


typedef struct {
    char name[20];
    double value;
} Function;


int f1(double n) { return n * log2(n); }
double f2(double n) { return 12 * sqrt(n); }
double f3(double n) { return 1.0 / n; }
double f4(double n) { return pow(n, log2(n)); }
double f5(double n) { return 100 * n * n + 6 * n; }
double f6(double n) { return pow(n, 0.51); }
double f7(double n) { return n * n - 324; }
double f8(double n) { return 50 * sqrt(n); }
double f9(double n) { return 2 * pow(n, 3); }
double f10(double n) { return pow(3, n); }
double f11(double n) { return pow(2, 32) * n; }
double f12(double n) { return log2(n); }


int compare(const void *a, const void *b) {
    double diff = ((Function*)a)->value - ((Function*)b)->value;
    if (diff < 0) return -1;
    else if (diff > 0) return 1;
    return -1;
}

int main() {
    Function funcs[12] = {
        {"n log2 n", f1(N)},
        {"12 sqrt(n)", f2(N)},
        {"1/n", f3(N)},
        {"n^(log2 n)", f4(N)},
        {"100n^2 + 6n", f5(N)},
        {"n^0.51", f6(N)},
        {"n^2 - 324", f7(N)},
        {"50 sqrt(n)", f8(N)},
        {"2n^3", f9(N)},
        {"3^n", f10(N)},
        {"2^32 * n", f11(N)},
        {"log2 n", f12(N)}
    };

    
    qsort(funcs, 12, sizeof(Function), compare);

    printf("Functions in increasing order of growth (approximate for n=%d):\n", N);
    for (int i = 0; i < 12; i++) {
        printf("%s => %e\n", funcs[i].name, funcs[i].value);
    }

    return 0;
}

