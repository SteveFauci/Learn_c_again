#include <stdio.h>
#include <string.h>
char str[55];
int  main() {
    int key;
    scanf("%d", &key);
    getchar();
    fgets(str, 55, stdin);
    str[strcspn(str, "\n")] = '\0';
    for(int i = 0;i<strlen(str);i++){
        putchar('a'+(str[i]-'a'+key)%26);
    }
    puts("");
}