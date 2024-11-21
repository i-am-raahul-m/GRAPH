#include <stdio.h>
#include <string.h>
#include <math.h>

int isNum(char c) {
    return ('a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' || '0' <= c && c <= '9')?1:0;
}

int pri(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    return -1;
}

struct Stack {
    char arr[100];
    int r;
} s = {{}, 0};
int isEmpty() {return (s.r == 0)?1:0;}
void push(char c) {s.arr[s.r++] = c;}
char pop() {return s.arr[--s.r];}
char top() {return s.arr[s.r-1];}

void eval(char res[]) {
    int n = strlen(res);

    int s[100];
    int r = 0;

    char temp;
    for (int i = 0; i < n; i++) {
        temp = res[i];
        if (isNum(temp)) s[r++] = temp-48;
        else {
            int t1 = s[--r];
            int t2 = s[--r];
            switch(temp) {
                case '^': {s[r++] = pow(t2, t1); break;}
                case '*': {s[r++] = t2*t1; break;}
                case '/': {s[r++] = t2/t2; break;}
                case '+': {s[r++] = t2+t1; break;}
                case '-': {s[r++] = t2-t1; break;}
            }
        }
    }
    printf("%d\n", s[--r]);
}

int main() {
    char str[100];
    scanf("%s", str);
    int n = strlen(str);

    char cur;
    char res[n+1]; res[n] = '\0'; int ind = 0;
    for (int i = 0; i < n; i++) {
        cur = str[i];
        if (isNum(cur)) {
            res[ind++] = cur;
        }
        else if (cur == '(' || cur == '^') push(cur);
        else if (cur == ')') {
            char temp = pop();
            if (!isEmpty() && temp != '(') {
                res[ind++] = temp;
                temp = pop();
            }
        }
        else {
            char temp = top();
            while (!isEmpty() && pri(temp) >= pri(cur)) {
                res[ind++] = pop();
                temp = top();
            }
            push(cur);
        }
    }
    while(!isEmpty()) res[ind++] = pop();
    printf("%s\n", res);
    eval("123*+");
    return 0;
}