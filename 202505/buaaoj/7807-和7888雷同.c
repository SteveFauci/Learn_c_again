#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[100005][105];
int  cmp(const void* p1, const void* p2) {
    char* pp1 = (char*)p1;
    char* pp2 = (char*)p2;
    int   len1 = strlen(pp1);
    int   len2 = strlen(pp2);
    if (len1 != len2) {
        return len2 - len1;
    } else {
        return strcmp(pp1, pp2);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        fgets(str[i], 105, stdin);
        str[i][strcspn(str[i], "\n")] = '\0';
    }
    qsort(str, n, sizeof(str[0]), cmp);
    for (int i = 0; i < n; i++) {
        puts(str[i]);
    }
}