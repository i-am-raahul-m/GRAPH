#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create(int d) {
    Node* new = (Node*) malloc(sizeof(Node));
    new->data = d;
    new->next = NULL;
    return new;
}

void addEdge(int n, Node* mat[], int i, int j) {
    Node* iter;
    
    Node* temp = create(j);
    if (mat[i] == NULL) mat[i] = temp;
    else {
        iter = mat[i];
        while (iter->next != NULL) {
            iter = iter->next;
        }
        iter->next = temp;
    }

    temp = create(i);
    if (mat[j] == NULL) mat[j] = temp;
    else {
        iter = mat[j];
        while (iter->next != NULL) {
            iter = iter->next;
        }
        iter->next = temp;
    }
}

void disp(int n, Node* mat[]) {
    printf("Adjacency List:\n");
    Node* temp;
    for (int i = 0; i < n; i++) {
        printf("%d : ", i);
        temp = mat[i];
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void dfs(int n, Node* mat[], int src, int* vis) {
    if (vis == NULL) {
        vis = (int*) calloc(n, sizeof(int));
    }
    printf("%d ", src);
    vis[src] = 1;

    Node* temp = mat[src];
    while(temp != NULL) {
        if (vis[temp->data] != 1) {
            dfs(n, mat, temp->data, vis);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Node* mat[n];
    for (int i = 0; i < n; i++) mat[i] = NULL;

    int v1, v2;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        addEdge(n, mat, v1, v2);
    }
    disp(n, mat);

    printf("DFS traversal:\n");
    dfs(n, mat, 0, NULL);
    return 0;
}