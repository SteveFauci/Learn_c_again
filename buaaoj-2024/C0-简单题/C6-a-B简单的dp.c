#include <stdio.h>
#define max(a, b) ((a > b) ? (a) : (b))
int main() {
    int L;
    int dp[1005];
    int price[1005];
    scanf("%d", &L);
    for (int i = 1; i <= L; i++) {
        scanf("%d", &price[i]);
    }
    for (int i = 1; i <= L; i++) {
        dp[i] = price[i];
        for (int j = 1; j <= i - 1; j++)
            dp[i] = max(dp[i], dp[i - j] + price[j]);
    }
    printf("%d", dp[L]);
}