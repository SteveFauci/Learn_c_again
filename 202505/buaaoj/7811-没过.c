#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[1005];
char s[1005];
void strrev(char* a, int len) {
    char cache;
    for (int i = 0; i < len / 2; i++) {
        cache = *(a + i);
        a[i] = a[len - 1 - i];
        a[len - 1 - i] = cache;
    }
}
int main() {
    fgets(str, 1005, stdin);
    fgets(s, 1005, stdin);
    str[strlen(str) - 1] = '\0';
    s[strlen(s) - 1] = '\0';
    int   len = strlen(s);
    char* p = str;
    while ((p = strstr(p, s)) != NULL) {
        strrev(p, len);
        p += len;
    }
    puts(str);
}
