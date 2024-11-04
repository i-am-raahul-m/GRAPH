#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* new = (Node*) malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    return new;
}

void addEdge(int n, Node* mat[], int i, int j) {
    Node* newEdge = createNode(i);
    newEdge->next = mat[j];
    mat[j] = newEdge;

    newEdge = createNode(j);
    newEdge->next = mat[i];
    mat[i] = newEdge;
}

void disp(int n, Node* mat[]) {
    Node* temp = NULL;
    printf("Adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        temp = mat[i];
        printf("%d ", i);
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    Node* mat[n];
    for (int i = 0; i < n; i++) mat[i] = NULL;
    disp(n, mat);

    int e;
    printf("Enter the number of edges to add to empty graph: ");
    scanf("%d", &e);
    int v1, v2;
    for (int i = 0; i < e; i++) {
        printf("Enter edge %d b/w v1 and v2, (v1 v2): ");
        scanf("%d %d", &v1, &v2);
        addEdge(n, mat, v1, v2);
    }
    disp(n, mat);

    return 0;
}