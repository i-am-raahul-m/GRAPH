#include <stdio.h>
#include <limits.h>
#define MAX_V 10

int P[MAX_V];
int K[MAX_V];
int mstSet[MAX_V];

int minKey(int n) {
    int min = INT_MAX, min_ind;
    for (int i = 0; i < n; i++) {
        if (mstSet[i] == 0 && min > K[i]) {
            min = K[i];
            min_ind = i;
        }
    }
    return min_ind;
}

int prims_MST(int graph[][MAX_V], int n) {
    for (int i = 0; i < n; i++) {
        mstSet[i] = 0;
        K[i] = INT_MAX;
    }

    K[0] = 0;
    P[0] = -1;

    for (int i = 0; i < n-1; i++) {
        int u = minKey(n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < K[v]) {
                P[v] = u;
                K[v] = graph[u][v];
            }
        }
    }

    int totw = 0;
    for (int i = 0; i < n; i++) totw += K[i];
    return totw;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int mat[MAX_V][MAX_V] = {0};

    int v1, v2, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &v1, &v2, &w);
        mat[v1][v2] = w;
        mat[v2][v1] = w;
    }

    int minW = prims_MST(mat, n);
    printf("%d\n", minW);
    return 0;
}