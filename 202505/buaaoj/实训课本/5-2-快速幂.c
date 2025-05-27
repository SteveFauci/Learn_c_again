#include <stdio.h>
#define Mytype unsigned long long
Mytype quickPow(Mytype a, Mytype b, Mytype p) {
    Mytype res = 1;
    a %= p;
    while (b) {
        if (b % 2)
            res = (res * a) % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
int main() {
    Mytype a, b, p;
    scanf("%lld%lld%lld", &a, &b, &p);
    printf("%lld^%lld mod %lld=%lld\n", a, b, p, quickPow(a, b, p));
    return 0;
}