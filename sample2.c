#include <stdio.h>
#include <limits.h>
#define MAX_V 10

int K[MAX_V];
int mstSet[MAX_V];

int min_key(int n) {
    int min = INT_MAX, min_ind = -1;
    for (int i = 0; i < n; i++) {
        if (mstSet[i] == 0 && min > K[i]) {
            min = K[i];
            min_ind = i;
        }
    }
    return min_ind;
}

int prims(int g[MAX_V][MAX_V], int n) {
    int mstExists = 1;
    for (int i = 0; i < n; i++) {
        K[i] = INT_MAX;
        mstSet[i] = 0;
    }
    K[0] = 0;

    int u;
    for (int i = 0; i < n; i++) {
        u = min_key(n);
        if (u == -1) {
            mstExists = 0;
            break;
        }
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (g[u][v] && mstSet[v] == 0 && K[v] > g[u][v]) {
                K[v] = g[u][v];
            }
        }
    }

    if (mstExists == 1) {
        int cost = 0;
        for (int i = 0; i < n; i++) {
            cost += K[i];
        }
        return cost;
    }
    else return -1;
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
    int mstCost = prims(g, n);
    if (mstCost != -1) printf("Cost of mst: %d\n", mstCost);
    else printf("Mst not possible.\n");
    return 0;
}