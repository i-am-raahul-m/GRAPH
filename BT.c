#include <stdio.h>
#include <stdlib.h>

typedef struct BT {
    int d;
    struct BT* l;
    struct BT* r;
} BT;

BT* create(int d) {
    BT* root = (BT*) malloc(sizeof(BT));
    root->d = d;
    root->l = root->r = NULL;
    return root;
}

void inord(BT* root) {
    if (root == NULL) return;
    inord(root->l);
    printf("%d ", root->d);
    inord(root->r);
}

BT* level_insert(BT* root, int d) {
    if (root == NULL) return create(d);
    BT* queue[100];
    int f = 0, r = 0;

    queue[r++] = root;

    BT* temp;
    while (f < r) {
        temp = queue[f++];
        if (temp->l == NULL) {
            temp->l = create(d);
            break;
        }
        else queue[r++] = temp->l;

        if (temp->r == NULL) {
            temp->r = create(d);
            break;
        }
        else queue[r++] = temp->r;
    }
    return root;
}

void level_trav(BT* root) {
    if (root == NULL) return;
    BT* queue[100];
    int f = 0, r = 0;

    queue[r++] = root;

    BT* temp;
    while (f < r) {
        temp = queue[f++];
        printf("%d ", temp->d);

        if (temp->l != NULL) queue[r++] = temp->l;
        if (temp->r != NULL) queue[r++] = temp->r;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    BT* root = NULL;
    int temp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        root = level_insert(root, temp);
    }
    level_trav(root); printf("\n");
    return 0;
}