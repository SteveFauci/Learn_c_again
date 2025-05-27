#include <stdio.h>
#include <string.h>
char str[10005];
int  num[26];
int  main() {
    int N;
    scanf("%d", &N);
    getchar();
    while (N--) {
        fgets(str, 10005, stdin);
        str[strcspn(str, "\n")] = '\0';
        int len = strlen(str);
        int flag = 0;
        int odds = 0;
        for (int i = 0; i < 26; i++) {
            num[i] = 0;
        }
        for (int i = 0; i < len; i++) {
            num[str[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (num[i] % 2)
                odds++;
        }
        if (len % 2 && odds)
            puts("Yes");
        else if (len % 2 == 0 && odds == 0)
            puts("Yes");
        else
            puts("No");
    }
}