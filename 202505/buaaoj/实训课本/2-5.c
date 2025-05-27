#include <stdio.h>
//数字金字塔
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n-i; j++) {
            printf("  ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%3d ", i);
        }
        puts("");
    }
}