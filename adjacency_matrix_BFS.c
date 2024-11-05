#include <stdio.h>
#define MAX 100

void addEdge(int n, int mat[][MAX], int i, int j) {
    mat[i][j] = mat[j][i] = 1;  // For undirected graph
    // mat[i][j] = 1;  // For directed graph
}

void disp(int n, int mat[][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void bfs(int n, int mat[][MAX], int src) {
    int vis[n];
    for (int i = 0; i < n; i++) vis[i] = 0;

    int queue[MAX];
    int f = 0, r = 0;

    queue[r++] = src;

    int temp;
    while (f < r) {
        temp = queue[f++];
        vis[temp] = 1;
        printf("%d ", temp);
        for (int i = 0; i < n; i++) {
            if (mat[temp][i] == 1 && vis[i] != 1) {
                queue[r++] = i;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int mat[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = 0;
        }
    }

    int v1, v2;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        addEdge(n, mat, v1, v2);
    }
    disp(n, mat);
    bfs(n, mat, 0);

    return 0;
}