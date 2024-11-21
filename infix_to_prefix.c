#include <stdio.h>
#include <string.h>
#include <math.h>

struct Stack {
    char arr[100];
    int r;
} s = {{}, 0}, s1 = {{}, 0};
int isEmpty(struct Stack* st) {return (st->r == 0)?1:0;}
void push(struct Stack* st, char c) {st->arr[st->r++] = c;}
char pop(struct Stack* st) {return st->arr[--st->r];}
char top(struct Stack* st) {return st->arr[st->r-1];}

int isNum(char c) {
    return ('a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' || '0' <= c && c <= '9')?1:0;
}

int pri(char c){
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    return -1;
}

void eval(char res[]) {
    int s[100];
    int r = 0;
    int n = strlen(res);

    char temp;
    for (int i = n-1; i >= 0; i--) {
        temp = res[i];
        if (isNum(temp)) s[r++] = temp-48;
        else {
            int t1 = s[--r];
            int t2 = s[--r];
            switch(temp) {
                case '^': {s[r++] = pow(t1, t2); break;}
                case '+': {s[r++] = t1+t2; break;}
                case '-': {s[r++] = t1-t2; break;}
                case '*': {s[r++] = t1*t2; break;}
                case '/': {s[r++] = t1/t2; break;}
            }
        }
    }
    printf("%d", s[--r]);
}

int main() {
    char str[100];
    scanf("%s", str);
    int n = strlen(str);

    strrev(str);
    for (int i = 0; i < n; i++) {
        if (str[i] == ')') str[i] = '(';
        else if (str[i] == '(') str[i] = ')';
    }
    //printf("%s\n", str);

    char res[n+1]; res[n] = '\0';
    int ind = 0;
    char cur;
    for (int i = 0; i < n; i++) {
        cur = str[i];
        if (isNum(cur)) res[ind++] = cur;
        else if (cur == '(') push(&s, cur);
        else if (cur == ')') {
            char temp = pop(&s);
            while (!isEmpty(&s) && temp != '(') {
                res[ind++] = temp;
                temp = pop(&s);
            }
        }
        else if (cur == '^') {
            char temp = top(&s);
            while (!isEmpty(&s) && pri(temp) == pri(cur)) {
                res[ind++] = pop(&s);
                temp = top(&s);
            }
            push(&s, cur);
        }
        else {
            char temp = top(&s);
            while (!isEmpty(&s) && pri(temp) > pri(cur)) {
                res[ind++] = pop(&s);
                temp = top(&s);
            }
            push(&s, cur);
        }
    }
    while (!isEmpty(&s)) res[ind++] = pop(&s);
    res[ind] = '\0';
    strrev(res);
    printf("%s\n", res);
    eval("+12");
    return 0;
}