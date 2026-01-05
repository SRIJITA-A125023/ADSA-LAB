#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 999999

int graph[MAX][MAX], n;
int parent[MAX];

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
        int u = src[0] - 'A';
        int v = dest[0] - 'A';
        graph[u][v] = graph[v][u] = weight;
    }
}

// ---------- Find and Union for Kruskal ----------
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// ---------- Kruskal’s Algorithm ----------
void kruskal() {
    int edges = 0, totalCost = 0;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in MST using Kruskal’s Algorithm:\n");
    while (edges < n - 1) {
        int min = INF, u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (find(i) != find(j) && graph[i][j] < min) {
                    min = graph[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        union1(u, v);
        printf("%c - %c : %d\n", u + 'A', v + 'A', min);
        totalCost += min;
        edges++;
    }
    printf("Total cost of MST (Kruskal’s): %d\n", totalCost);
}

// ---------- Main Function ----------
int main() {
    readSIF();
    kruskal();
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
