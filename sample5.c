#include <stdio.h>
#include <stdlib.h>
#define MAX_V 20

void bfs(int g[MAX_V][MAX_V], int n, int src) {
    int vis[n];
    for (int i = 0; i < n; i++) vis[i] = 0;

    int queue[n];
    int f = 0, r = 0;

    queue[r++] = src;
    vis[src] = 1;
    printf("%d ", src);

    int temp;
    while (f < r) {
        temp = queue[f++];

        for (int i = 0; i < n; i++) {
            if (g[temp][i] == 1 && vis[i] == 0) {
                queue[r++] = i;
                vis[i] = 1;
                printf("%d ", i);
            }
        }
    }
}

void dfs(int g[MAX_V][MAX_V], int n, int src, int* vis) {
    if (vis == NULL) {
        vis = (int*) calloc(n, sizeof(int));
    }
    vis[src] = 1;
    printf("%d ", src);

    for (int i = 0; i < n; i++) {
        if (g[src][i] == 1 && vis[i] == 0) {
            dfs(g, n, i, vis);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int g[MAX_V][MAX_V] = {0};

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        g[u][v] = g[v][u] = 1;
    }
    bfs(g, n, 0); printf("\n");
    dfs(g, n, 0, NULL);
    return 0;
}