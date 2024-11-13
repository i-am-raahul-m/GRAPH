#include <stdio.h>
#include <limits.h>
#define MAX_V 10

int K[MAX_V];
int pSet[MAX_V];

int minKey(int n) {
    int min = INT_MAX, min_ind = -1;
    for (int i = 0; i < n; i++) {
        if (pSet[i] == 0 && min > K[i]) {
            min = K[i];
            min_ind = i;
        }
    }
    return min_ind;
}

void dijkstra(int g[][MAX_V], int n, int src) {
    int totDist = 0;
    for (int i = 0; i < n; i++) {
        K[i] = INT_MAX;
        pSet[i] = 0;
    }
    K[src] = 0;

    int u;
    for (int i = 0; i < n-1; i++) {
        u = minKey(n);
        if (u == -1) break;
        pSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (pSet[v] == 0 && g[u][v] && g[u][v]+K[u] < K[v] && K[u] != INT_MAX) {
                K[v] = K[u] + g[u][v];
            }
        }
    }
}

void print(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", i, K[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int g[MAX_V][MAX_V] = {0};

    int u, v, w;
    for (int i = 0 ; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        g[u][v] = w;
    }

    dijkstra(g, n, 0);
    print(n);
    return 0;
}