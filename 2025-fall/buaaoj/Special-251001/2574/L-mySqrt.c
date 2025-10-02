// #include <stdio.h>

// int main() {
//     int x;
//     scanf("%d", &x);
//     while (x--) {
//         int T;
//         scanf("%d", &T);
//         int n = 1;
//         for (int i = 2; i * i <= T; i++) {
//             if (T % (i * i) == 0)
//                 n = i;
//         }
//         if (T / n / n == 1)
//             printf("sqrt(%d) = %d\n", T, n);
//         else if (n > 1)
//             printf("sqrt(%d) = %d * sqrt(%d)\n", T, n, (T / n) / n);
//         else
//             printf("sqrt(%d) is the simpliest answer\n", T);
//     }
// }
// #include <stdio.h>
// int main() {
//     int x;
//     scanf("%d", &x);
//     while (x--) {
//         long long T;
//         scanf("%lld", &T);
//         long long n = 1;
//         for (long long i = 1; i * i <= T; i++) {
//             if (T % (i * i) == 0) {
//                 n = i;
//             }
//         }
//         long long a = T / (n * n);
//         if (a == 1) {
//             printf("sqrt(%lld) = %lld\n", T, n);
//         } else if (n == 1) {
//             printf("sqrt(%lld) is the simpliest answer\n", T);
//         } else {
//             printf("sqrt(%lld) = %lld * sqrt(%lld)\n", T, n, a);
//         }
//     }
//     return 0;
// }

#include <stdio.h>
int main() {
    int x;
    scanf("%d", &x);
    while (x--) {
        long long T;
        scanf("%lld", &T);
        long long p = 1;
        long long temp = T;
        while (temp % 4 == 0) {
            p *= 2;
            temp /= 4;
        }
        for (long long i = 3; i * i <= temp; i += 2) {
            while (temp % (i * i) == 0) {
                p *= i;
                temp /= (i * i);
            }
        }
        if (temp == 1) {
            printf("sqrt(%lld) = %lld\n", T, p);
        } else if (p == 1) {
            printf("sqrt(%lld) is the simpliest answer\n", T);
        } else {
            printf("sqrt(%lld) = %lld * sqrt(%lld)\n", T, p, temp);
        }
    }
    return 0;
}