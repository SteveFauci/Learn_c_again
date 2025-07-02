#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* p[10005];
char  buffer[1005];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    getchar(); // 经典吃'\n'
    for (int i = 0; i < n; i++) {
        fgets(buffer, 1005, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        p[i] = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(p[i], buffer);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        char* temp = p[u - 1];
        p[u - 1] = p[v - 1];
        p[v - 1] = temp;
    }
    for (int i = 0; i < n; i++) {
        puts(p[i]);
    }
    for (int i = 0; i < n; i++) {
        free(p[i]);
    }
}