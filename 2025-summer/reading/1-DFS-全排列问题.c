#include <stdio.h>
int book[50], a[50], n;

void dfs(int step) {
    if (step == n) {
        for (int i = 0; i < n; i++)
            printf("%5d", 1 + a[i]);
        puts("");
        return;
    }
    for (int i = 0; i < n; i++) {
        if (book[i] == 0) {
            a[step] = i;
            book[i] = 1;
            dfs(step + 1);
            book[i] = 0;
        }
    }
    return;
}
int main() {
    scanf("%d", &n);
    dfs(0);
    return 0;
}