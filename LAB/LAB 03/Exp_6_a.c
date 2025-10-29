#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 999999

int graph[MAX][MAX], n;

// ---------- Read Graph in SIF Format ----------
void readSIF() {
    int i, j, weight;
    char src[20], dest[20];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize graph with INF
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            graph[i][j] = INF;

    printf("Enter edges in SIF format (u v w), enter -1 -1 -1 to stop:\n");
    while (1) {
        scanf("%s %s %d", src, dest, &weight);
        if (weight == -1)
            break;
        int u = src[0] - 'A';  // Convert vertex label to index
        int v = dest[0] - 'A';
        graph[u][v] = graph[v][u] = weight;
    }
}

// ---------- Prim’s Algorithm ----------
void prims() {
    int selected[MAX] = {0};
    int edgeCount = 0, totalCost = 0;

    selected[0] = 1; // Start from vertex A (index 0)

    printf("\nEdges in MST using Prim’s Algorithm:\n");
    while (edgeCount < n - 1) {
        int min = INF, x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("%c - %c : %d\n", x + 'A', y + 'A', graph[x][y]);
        totalCost += graph[x][y];
        selected[y] = 1;
        edgeCount++;
    }
    printf("Total cost of MST (Prim’s): %d\n", totalCost);
}

// ---------- Main Function ----------
int main() {
    readSIF();
    prims();
    return 0;
}


/*
Enter number of vertices: 4
Enter edges in SIF format (u v w), enter -1 -1 -1 to stop:
A B 4
A C 3
B C 2
B D 5
C D 7
-1 -1 -1
*/