#include <stdio.h>
#include <limits.h>
#define MAX_V 10

int K[MAX_V];
int pSet[MAX_V];

int min_key(int n) {
    int min = INT_MAX, min_ind = -1;
    for (int i = 0; i < n; i++) {
        if (pSet[i] == 0 && min > K[i]) {
            min_ind = i;
            min = K[i];
        }
    }
    return min_ind;
}

void dijkstra(int g[MAX_V][MAX_V], int n, int src) {
    for (int i = 0; i < n; i++) {
        K[i] = INT_MAX;
        pSet[i] = 0;
    }
    K[src] = 0;
    
    int u;
    for (int i = 0; i < n-1; i++) {
        u = min_key(n);
        if (u == -1) break;
        pSet[i] = 1;

        for (int v = 0; v < n; v++) {
            if (g[u][v] && pSet[v] == 0 && K[v] > K[u] + g[u][v]) {
                K[v] = K[u] + g[u][v];
            }
        }
    }
}

int main() {
    int n, m; 
    scanf("%d %d", &n, &m);
    int g[MAX_V][MAX_V] = {0};

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        g[u][v] = g[v][u] = w;
    }
    int src;
    scanf("%d", &src);

    dijkstra(g, n, src);

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", i, K[i]);
    }
    return 0;
}