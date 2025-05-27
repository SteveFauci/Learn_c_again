#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct my_stru {
    char b[1005];
    int  top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}
int isEmpty(Stack* s) {
    return s->top == -1;
}
void push(Stack* s, char br) {
    s->b[++(s->top)] = br;
}
char pull(Stack* s) {
    if (isEmpty(s))
        return '\0';
    return s->b[(s->top)--];
}

char str[1005];
int  main() {
    Stack* a = (Stack*)malloc(sizeof(Stack));
    initStack(a);
    fgets(str, 1005, stdin);
    str[strcspn(str, "\n")] = '\0';
    int flag = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[') {
            push(a, str[i]);
        }
        if (str[i] == '}' || str[i] == ')' || str[i] == ']') {
            char ch = pull(a);
            if ((str[i] == '}' && ch != '{') || (str[i] == ']' && ch != '[') ||
                (str[i] == ')' && ch != '('))
                flag = 1;
        }
    }
    if (!isEmpty(a)) {
        flag = 1;
    }
    flag ? printf("NO\n") : printf("YES\n");
    free(a);
}