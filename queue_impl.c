#include <stdio.h>

struct Queue {
    int arr[100];
    int f, r;
} q = {{}, 0, 0};
int isEmpty() {return (q.f == q.r)?1:0;}
void enqueue(int x) {q.arr[q.r++] = x;}
int dequeue() {return q.arr[q.f++];}
void disp() {
    for (int i = q.f; i < q.r; i++) printf("%d ", q.arr[i]);
    printf("\n");
}
int main() {
    int n; scanf("%d", &n);
    int temp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        enqueue(temp);
    }
    dequeue();
    disp();
    return 0;
}