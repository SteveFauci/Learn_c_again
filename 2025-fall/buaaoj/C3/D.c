#include <stdio.h>
long long arr[1000005];
long long max(long long a,long long b){
    return a>b?a:b;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &arr[i]);
        }
        long long f0 = 0, f1 = 0;
        for (int i = 0; i < n; i++) {
            long long x = arr[i];
            long long new_f = max(f1, f0 + x);
            f0 = f1;
            f1 = new_f;
        }
        printf("%lld\n", f1);
    }
}