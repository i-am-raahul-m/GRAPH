#include <stdio.h>
#include <stdlib.h>

typedef struct BST{
    int d;
    struct BST* l;
    struct BST* r;
} BST;

BST* create(int d) {
    BST* r = (BST*) malloc(sizeof(BST));
    r->d = d;
    r->l = r->r = NULL;
    return r;
}

BST* insert(BST* root, int x) {
    if (root == NULL) root = create(x);
    if (x < root->d) root->l = insert(root->l, x);
    else if (x > root->d) root->r = insert(root->r, x);
    return root;
}

BST* search(BST* root, int x) {
    if (root == NULL || root->d == x) return root;
    else if (x < root->d) return search(root->l, x);
    else return search(root->r, x);
}

BST* min(BST* root) {
    BST* iter = root;
    while (iter != NULL && iter->l != NULL) iter = iter->l;
    return iter;
}

BST* max(BST* root) {
    BST* iter = root;
    while (iter != NULL && iter->r != NULL) iter = iter->r;
    return iter;
}

BST* delete(BST* root, int x) {
    if (root == NULL) return root;
    else if (x < root->d) root->l = delete(root->l, x);
    else if (x > root->d) root->r = delete(root->r, x);
    else {
        if (root->l == NULL && root->r == NULL) {
            free(root);
            return NULL;
        }
        else if (root->l == NULL){
            BST* temp = root->r;
            free(root);
            return temp;
        }
        else if (root->r == NULL) {
            BST* temp = root->l;
            free(root);
            return temp;
        }
        BST* suc = min(root->r);
        root->d = suc->d;
        root->r = delete(root->r, suc->d);
    }
    return root;
}

void inord(BST* root) {
    if (root == NULL) return;
    inord(root->l);
    printf("%d ", root->d);
    inord(root->r);
}

void preord(BST* root) {
    if (root == NULL) return;
    printf("%d ", root->d);
    preord(root->l);
    preord(root->r);
}

void posord(BST* root) {
    if (root == NULL) return;
    posord(root->l);
    posord(root->r);
    printf("%d ", root->d);
}

void level(BST* root) {
    if (root == NULL) return;
    BST* queue[100];
    int f = 0, r = 0;

    queue[r++] = root;

    BST* temp;
    while (f < r) {
        temp = queue[f++];
        printf("%d ", temp->d);

        if (temp->l != NULL) queue[r++] = temp->l;
        if (temp->r != NULL) queue[r++] = temp->r;
    }
}

int main() {
    BST* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 100);
    inord(root); printf("\n");
    level(root);
    return 0;
}