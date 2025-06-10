#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int  cmp(const void* pp1, const void* pp2) {
    char* p1 = *(char**)pp1;
    char* p2 = *(char**)pp2;
    return strcmp(p1, p2);
}
int* lexicalOrder(int n, int* returnSize) {
    int *p = (int*)malloc((n+1)*sizeof(int));
    char **s = (char**)malloc(n * sizeof(char*)); 
    for (int i = 0; i < n; i++) {
        s[i] = (char*)malloc(12);
        sprintf(s[i], "%d", i+1);
    }
    qsort(s, n, sizeof(char*), cmp);
    for (int i = 0; i < n; i++) {
        sscanf(s[i], "%d", &p[i]);
    }
    *returnSize = n;
    return p;
}
int main() {
    int a = 0;
    int* returnSize = &a;
    int  n = 50;
    int* p = lexicalOrder(n, returnSize);
    for (int i = 0; i < *returnSize; i++) {
        printf("%d\t", *(p + i));
        if(!(i%20))putchar('\n');
    }
    return 0;
}