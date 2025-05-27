#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[5005][505];
int  cmp(const void* p1, const void* p2) {
    char* pp1 = (char*)p1;
    char* pp2 = (char*)p2;
    if (strlen(pp1) < strlen(pp2)) {
        return -1;
    } else if (strlen(pp1) > strlen(pp2)) {
        return 1;
    } else {
        return strcmp(pp1, pp2);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        fgets(str[i], 505, stdin);
        str[i][strcspn(str[i], "\n")] = '\0';
    }
    qsort(str, n, sizeof(str[0]), cmp);
    for (int i = 0; i < n; i++) {
        puts(str[i]);
    }
}