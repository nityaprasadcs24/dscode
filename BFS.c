#include <stdio.h>
#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n;

void bfs_level(int current) {
    int i;
    for (i = 0; i < n; i++) {
        if (adj[current][i] == 1 && visited[i] == 0) {
            visited[i] = 1;
            printf("%d ", i);
        }
    }
    for (i = 0; i < n; i++) {
        if (adj[current][i] == 1 && visited[i] == 1) {
            bfs_level(i);
        }
    }
}

int main() {
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    printf("BFS Traversal: ");
    visited[start] = 1;
    printf("%d ", start);
    bfs_level(start);
    return 0;
}