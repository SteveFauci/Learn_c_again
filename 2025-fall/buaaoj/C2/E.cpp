#include <stdio.h>
// #include<stdlib.h>
#include<string.h>
#define N 5000005

// int cmp(const void* pp1, const void* pp2) {
//     int a = *(const int*)pp1;
//     int b = *(const int*)pp2;
//     if (a < b) return -1;
//     if (a > b) return 1;
//     return 0;
// }

int nextRand() {
    static unsigned int rnd_num = 0x80000001;
    static int mod = 1e5 + 3;

    rnd_num ^= rnd_num >> 10;
    rnd_num ^= rnd_num << 9;
    rnd_num ^= rnd_num >> 25;
    return rnd_num % mod;
}

int a[N];

int bucket[100003];
int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        memset(bucket,0,sizeof(bucket));
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            a[i] = nextRand();
            bucket[a[i]]++;
        }
        // qsort(a+1,n,sizeof(int),cmp);
        // int ord = 1,ptr = 1;
        long long sum = 0;
        long long total = 0;
        for (int v = 0; v <= 100002; v++) {
            if (bucket[v] > 0) {
                long long ord = total + 1;
                sum += (long long)v * ord * bucket[v];
                total += bucket[v];
            }
        }
        printf("%lld\n",sum);
    }
    
    return 0;
}

