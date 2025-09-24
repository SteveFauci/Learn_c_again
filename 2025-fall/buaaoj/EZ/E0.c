#include <stdio.h>
int main() {
    unsigned long long a, b;
    while (~scanf("%llu%llu", &a, &b)) {
        printf("%llu\n", a * b - a - b);
    }
}

// #include <stdio.h>
// int main() {
//     int n;
//     scanf("%d", &n);
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= i; j++) {
//             printf("%d*%d=%d ", i, j, i * j);
//         }
//         putchar('\n');
//     }
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     int n;
//     scanf("%d",&n);
//     int curr;
//     int max = -2147483648;
//     int min = 2147483647;
//     for(int i = 0;i < n; i++){
//         scanf("%d",&curr);
//         if(max < curr)max = curr;
//         if(min > curr)min = curr;
//     }
//     printf("%d\n",max-min);
//     return 0;
// }

// #include <stdio.h>
// int main() {
//     int a, b, c;
//     scanf("%d%d%d", &a, &b, &c);
//     int ans = (a + 1) * (b + 1) * (c + 1);
//     if(ans <= 100000000)printf("%d\nAccepted",ans);
//     else printf("%d\nTime Limit Exceeded",ans);
// }

// #include <stdio.h>
// int main() {
//     int T;
//     int a, b, op;
//     scanf("%d",&T);
//     while (T--) {
//         scanf("%d%d%d", &a, &b, &op);
//         switch (op) {
//         case (1): {
//             printf("%d + %d = %d\n", a, b, a + b);
//             break;
//         }
//         case (2): {
//             printf("%d - %d = %d\n", a, b, a - b);
//             break;
//         }
//         case (3): {
//             printf("%d * %d = %d\n", a, b, a * b);
//             break;
//         }
//         case (4): {
//             if (b != 0)
//                 printf("%d / %d = %d\n", a, b, a / b);
//             else
//                 printf("ERROR\n");
//             break;
//         }
//         case (5): {
//             if (b != 0)
//                 printf("%d %% %d = %d\n", a, b, a % b);
//             else
//                 printf("ERROR\n");
//             break;
//         }
//         }
//     }
// }