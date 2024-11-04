#include <stdio.h>

void addEdge(int n, int mat[][n], int i, int j) {
    mat[i][j] = 1;
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
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int mat[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = 0;
        }
    }
    disp(n, mat);

    int e;
    printf("Enter number fo edges to be added to empty graph: ");
    scanf("%d", &e);
    int v1, v2;
    for (int i = 0; i < e; i++) {
        printf("Enter edge %d from v1 to v2, (v1 v2): ");
        scanf("%d %d", &v1, &v2);
        addEdge(n, mat, v1, v2);
    }
    disp(n, mat);
    return 0;
}