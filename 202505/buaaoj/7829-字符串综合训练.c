#include <stdio.h>
#include <string.h>
char  str[10005];
char  str2[10005];
char  cache[10005];
int   i = 0;
int   j = 0;
char* strrstr(char* haystack, char* needle) {
    char *p1, *p2;
    p1 = haystack;
    p2 = strstr(haystack, needle);
    while ((p2 = strstr(p2, needle)) != NULL) {
        p1 = p2;
        p2++;
    }
    return p1;
}
void operation(int op) {
    switch (op) {
    case 1:
        fgets(str2, 10005, stdin);
        str2[strcspn(str2, "\n")] = '\0';
        strcat(str, str2);
        break;
    case 2:
        scanf("%d", &i);
        str[i] = '\0';
        break;
    case 3:
        scanf("%d ", &i);
        fgets(str2, 10005, stdin);
        str2[strcspn(str2, "\n")] = '\0';
        strcpy(cache, str + i + 1);
        str[i + 1] = '\0';
        strcat(str, str2);
        strcat(str, cache);
        break;
    case 4:
        scanf("%d %d", &i, &j);
        strcpy(cache, str + j + 1);
        str[i] = '\0';
        strcat(str, cache);
        break;
    case 5:
        scanf("%d %d ", &i, &j);
        fgets(str2, 10005, stdin);
        str2[strcspn(str2, "\n")] = '\0';
        strcpy(cache, str + j + 1);
        str[i] = '\0';
        strcat(str, str2);
        strcat(str, cache);
        break;
    case 6:
        fgets(str2, 10005, stdin);
        str2[strcspn(str2, "\n")] = '\0';
        char* p = strstr(str, str2);
        if (p == NULL) {
            printf("NULL\n");
        } else {
            char* p2 = strrstr(str, str2);
            printf("%d %d\n", (int)(p - str), (int)(p2 - str));
        }
        break;
    }
}
int main() {
    fgets(str, 10005, stdin);
    str[strcspn(str, "\n")] = '\0';
    int op;
    while (~scanf("%d ", &op)) {
        operation(op);
    }
    puts(str);
}