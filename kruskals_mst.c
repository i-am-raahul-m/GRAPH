#include <stdio.h>
#include <stdlib.h>

#define MAX_V 20
#define MAX_E 100

typedef struct Edge {
    int s;
    int d;
    int w;
} E;

typedef struct EdgeList {
    E edges[MAX_E];
    int ind;
} EL;

int P[MAX_V];
EL graph, mst;

void initP(int n) {
    for (int i = 0; i < n; i++) {
        P[i] = i;
    }
}

int Find(int v) {
    if (P[v] != v) P[v] = Find(P[v]);
    return P[v];
}

void Union(int u, int v) {
    P[Find(u)] = Find(v);
}

int comp(const void* a, const void* b) {
    return (((E*)a)->w - ((E*)b)->w);
}

int kruskal(int n, int m) {
    int totw = 0;
    mst.ind = 0;

    initP(n);
    qsort(graph.edges, m, sizeof(E), comp);

    int u, v, w;
    for (int i = 0; i < m; i++) {
        u = graph.edges[i].s;
        v = graph.edges[i].d;
        w = graph.edges[i].w;

        if (Find(u) != Find(v)) {
            Union(u, v);
            mst.edges[mst.ind++] = graph.edges[i];
            totw += w;
        }
    }

    if (mst.ind == n-1) return totw;
    else return -1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int v1, v2, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &v1, &v2, &w);
        graph.edges[i].s = v1;
        graph.edges[i].d = v2;
        graph.edges[i].w = w;
    }

    int minW = kruskal(n, m);
    printf("%d\n", minW);

    return 0;
}