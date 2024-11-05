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
        while (temp->next != NULL) {
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

void bfs(int n, Node* mat[], int src) {
    int vis[n];
    for (int i = 0; i < n; i++) vis[i] = 0;

    int queue[n];
    int f = 0, r = 0;

    queue[r++] = src;
    int temp;
    Node* iter;

    while (f < r) {
        temp = queue[f++];
        printf("%d ", temp);
        vis[temp] = 1;

        iter = mat[temp];
        while(iter != NULL) {
            if (vis[iter->data] != 1) {
                queue[r++] = iter->data;
            }
            iter = iter->next;
        }
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

    printf("BFS traversal:\n");
    bfs(n, mat, 0);
    return 0;
}