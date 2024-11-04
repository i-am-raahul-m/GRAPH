#include <stdio.h>
#include <stdlib.h>

void addEdge(int n, int mat[][n], int i, int j) {
    mat[i][j] = mat[j][i] = 1;
}

void disp(int n, int mat[][n]) {
    printf("Adjacency matrix:\n");
    printf("  ");
    for (int i = 0; i < n; i++) printf("%d ", i);
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter no. of vertices: ");
    scanf("%d", &n);
    int mat[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = 0;
        }
    }
    disp(n, mat);

    int e;
    printf("No. of edges to be added to empty graph: ");
    scanf("%d", &e);
    int v1, v2;
    for (int i = 0; i < e; i++) {
        printf("Edge %d b/w v1 and v2, (v1 v2): ", i);
        scanf("%d %d", &v1, &v2);
        addEdge(n, mat, v1, v2);
    }
    disp(n, mat);
    
    return 0;
}