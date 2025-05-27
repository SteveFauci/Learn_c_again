#include <ctype.h>
#include <stdio.h>
int cnt[26];
int max(int* p, int size) {
    int m = *p;
    for (int i = 0; i < size; i++) {
        *(p + i) > m ? m = *(p + i) : m;
    }
    return m;
}
int main() {
    char ch;
    while ((ch = getchar()) != EOF) {
        if (isupper(ch))
            cnt[ch - 'A']++;
    }
    int max_cnt = max(cnt, 26);
    for (int i = 0; i < max_cnt; i++) {
        for (int j = 0; j < 26; j++) {
            if (cnt[j] >= max_cnt - i)
                putchar('*');
            else
                putchar(' ');
        }
        puts("");
    }
    for (int i = 0; i < 26; i++) {
        putchar('A' + i);
    }
}
