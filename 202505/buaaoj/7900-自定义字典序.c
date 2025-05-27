#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char new_dic[27];
int  cmp(const void* p1, const void* p2) {
    char* pp1 = (char*)p1;
    char* pp2 = (char*)p2;
    return strcmp(pp1, pp2);
}
char words[20005][105];
int  main() {
    int n;
    scanf("%d", &n);
    getchar();
    fgets(new_dic, 27, stdin);
    new_dic[strcspn(new_dic, "\n")] = '\0';
    getchar();
    for (int i = 0; i < n; i++) {
        fgets(words[i], 105, stdin);
        words[i][strcspn(words[i], "\n")] = '\0';
        int len = strlen(words[i]);
        for (int j = 0; j < len; j++) {
            words[i][j] = strchr(new_dic, words[i][j]) - new_dic + 1;
        }
    }
    qsort(words, n, sizeof(words[0]), cmp);
    for (int i = 0; i < n; i++) {
        int len = strlen(words[i]);
        for (int j = 0; j < len; j++) {
            words[i][j] = new_dic[words[i][j] - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        puts(words[i]);
    }
}