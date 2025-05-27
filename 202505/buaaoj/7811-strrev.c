#include <stdio.h>
#include <string.h>
#define max 1050
// void strrev(char* p, int len) {
//     char cache;
//     for (int i = 0; i < len / 2; i++) {
//         cache = *(p + len - 1 - i);
//         *(p + len - i - 1) = *(p + i);
//         *(p + i) = cache;
//     }
// }
char str[max];
char s[max];
int  main() {
    fgets(str, max, stdin);
    fgets(s, max, stdin);
    str[strcspn(str, "\n")] = '\0';
    s[strcspn(s, "\n")] = '\0';
    // gets(str);
    // gets(s);
    scanf("%s",str);
    int   len = strlen(s);
    char* base = str;
    char* p = base;
    while (1) {
        p = strstr(p, s);
        if (p == NULL)
            break;
        for (int i = 0; i < len; i++) {
            *(p + i) = s[len - i - 1];
        }
        p += len;
    }
    puts(str);
}