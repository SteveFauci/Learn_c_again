#include <stdio.h>
#include <string.h>
int calc(int num1, int num2, char op) {
    switch (op) {
    case ('+'): return num1 + num2;
    case ('-'): return num1 - num2;
    case ('*'): return num1 * num2;
    case ('/'): return num1 / num2;
    default: return -1;
    }
}
int main() {
    char str[55];
    int  Stack[50];
    int  top = -1;

    fgets(str, 55, stdin);
    str[strcspn(str, "\n")] = '\0';

    int sz = strlen(str);
    int temp = 0;
    for (int i = 0; i < sz - 1; i++) {
        char ch = str[i];
        if ('0' <= ch && ch <= '9') {
            temp *= 10;
            temp += ch - '0';
        } else {
            if (temp) {
                top++;
                Stack[top] = temp;
                temp = 0;
            }
            if (ch == '.') {
                continue;
            }
            int num2 = Stack[top];
            top--;
            int num1 = Stack[top];
            Stack[top] = calc(num1, num2, ch);
        }
    }
    printf("%d\n", Stack[0]);
    return 0;
}