#include <stdio.h>
#include <string.h>

#define MAXN 100
#define MAXM 100
#define MAXE 1000

typedef struct {
    int u, v;
} Edge;

int main() {
    int nLeft, nRight, e;
    Edge edges[MAXE];
    int matchedLeft[MAXN + 1] = {0};
    int matchedRight[MAXM + 1] = {0};
    int matchCount = 0;

    printf("Enter number of left nodes, right nodes, and edges: ");
    scanf("%d %d %d", &nLeft, &nRight, &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &edges[i].u, &edges[i].v);
    }

    printf("\n--- Greedy Matching Process ---\n");

    for (int i = 0; i < e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        printf("\nConsidering edge (%d, %d): ", u, v);

        if (matchedLeft[u] == 0 && matchedRight[v] == 0) {
            // Add this edge to the matching
            matchedLeft[u] = v;
            matchedRight[v] = u;
            matchCount++;
            printf("Added to matching.\n");
        } else {
            printf("Skipped (conflict with existing match).\n");
        }

        // Show current matching state
        printf("Current matching: ");
        int first = 1;
        for (int x = 1; x <= nLeft; x++) {
            if (matchedLeft[x] != 0) {
                if (!first) printf(", ");
                printf("%d-%d", x, matchedLeft[x]);
                first = 0;
            }
        }
        if (first) printf("None");
        printf("\n");
    }

    printf("\n--- Final Matching ---\n");
    printf("Total matched pairs: %d\n", matchCount);
    for (int u = 1; u <= nLeft; u++) {
        if (matchedLeft[u] != 0)
            printf("%d -> %d\n", u, matchedLeft[u]);
    }

    return 0;
}


/*input
5 4 8
1 6
1 7
2 6
3 7
3 9
4 7
5 8
5 9

*/