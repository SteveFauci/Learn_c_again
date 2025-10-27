#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    long long catalan = 1;
    for (long long i = 0; i < n; ++i) {
        catalan = (long long)catalan * 2 * (2 * i + 1) / (i + 2);
    }
    printf("%lld\n", catalan);
    return 0;
}