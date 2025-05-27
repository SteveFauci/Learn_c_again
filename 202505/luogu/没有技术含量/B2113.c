#include <stdio.h>
#include <string.h>
char str[105];
int  main() {
    fgets(str, 105, stdin);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i + 1] != '\n') {
            char ch = str[i] + str[i + 1];
            putchar(ch);
        } else {
            char ch = str[i] + str[0];
            putchar(ch);
        }
    }
}