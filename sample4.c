#include <stdio.h>
#include <stdlib.h>
#define MAX_V 20

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create(int d) {
    Node* n = (Node*) malloc(sizeof(Node));
    n->data = d;
    n->next = NULL;
    return n;
}

void addEdgeLast(Node* g[MAX_V], int n, int i, int j) {
    Node* iter;
    if (g[i] == NULL) g[i] = create(j);
    else {
        iter = g[i];
        while (iter->next != NULL) {
            iter = iter->next;
        }
        iter->next = create(j);
    }

    if (g[j] == NULL) g[j] = create(i);
    else {
        iter = g[j];
        while (iter->next != NULL) {
            iter = iter->next;
        }
        iter->next = create(i);
    }
}

void addEdge(Node* g[MAX_V], int n, int i, int j) {
    Node* temp;
    temp = create(i);
    temp->next = g[j];
    g[j] = temp;

    temp = create(j);
    temp->next = g[i];
    g[i] = temp;
}

void disp(Node* g[MAX_V], int n) {
    Node* iter;
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        iter = g[i];
        while (iter != NULL) {
            printf("%d ", iter->data);
            iter = iter->next;
        }
        printf("\n");
    }
}

void bfs(Node* g[MAX_V], int n, int src) {
    int vis[n];
    for (int i = 0; i < n; i++) vis[i] = 0;

    int queue[n];
    int f = 0, r = 0;

    queue[r++] = src;
    vis[src] = 1;
    printf("%d ", src);

    Node* iter;
    int temp;
    while (f < r) {
        temp = queue[f++];
        iter = g[temp];
        while (iter != NULL) {
            if (vis[iter->data] == 0) {
                queue[r++] = iter->data;
                vis[iter->data] = 1;
                printf("%d ", iter->data);
            }
            iter = iter->next;
        }
    }
}

void dfs(Node* g[MAX_V], int n, int src, int* vis) {
    if (vis == NULL) {
        vis = (int*) calloc(n, sizeof(int));
    }
    vis[src] = 1;
    printf("%d ", src);

    Node* iter = g[src];
    while (iter != NULL) {
        if (vis[iter->data] == 0) dfs(g, n, iter->data, vis);
        iter = iter->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Node* g[MAX_V] = {NULL};
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdgeLast(g, n, u, v);
    }
    disp(g, n);
    bfs(g, n, 0); printf("\n");
    dfs(g, n, 0, NULL);
    return 0;
}