#include <stdio.h>
#include <stdlib.h>
#define MAX_V 10
#define MAX_E 30

typedef struct Edges{
    int s, d, w;
} E;

typedef struct EdgeList {
    E ed[MAX_E];
    int ind;
} EL;

EL graph, mst;
int P[MAX_V];

void initP(int n) {
    for (int i = 0; i < n; i++) {
        P[i] = i;
    }
}

int Find(int u) {
    if (P[u] != u) P[u] = Find(P[u]);
    return P[u];
}

void Union(int u, int v) {
    P[u] = Find(P[v]);
}

int comp(const void* a, const void* b) {
    return (((E*)a)->w - ((E*)b)->w);
}

int kruskal(int n, int m) {
    int totw = 0;
    mst.ind = 0;

    initP(n);
    qsort(graph.ed, m, sizeof(E), comp);

    int u, v, w;
    for (int i = 0; i < m; i++) {
        u = graph.ed[i].s;
        v = graph.ed[i].d;
        w = graph.ed[i].w;
        if (Find(u) != Find(v)) {
            Union(u, v);
            totw += w;
            mst.ed[mst.ind++] = graph.ed[i];
        }
    }

    if (mst.ind == n-1) return totw;
    else return -1;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph.ed[i].s = u;
        graph.ed[i].d = v;
        graph.ed[i].w = w;
    }

    int mstCost = kruskal(n, m);
    if (mstCost != -1) printf("Cost of mst = %d\n.", mstCost);
    else printf("Mst not possible.");
    return 0;
}