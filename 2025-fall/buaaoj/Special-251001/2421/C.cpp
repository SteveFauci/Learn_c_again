#include <cstdio>

int arrA[30005];
int arrB[30005];
int MOD = 10007;

int main() {
    int x, n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &arrA[i]);
    }
    int y,m;
    scanf("%d", &m);
    for (int i = 0; i <= m; i++) {
        scanf("%d", &arrB[i]);
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int ansA = 0, ansB = 0;
        scanf("%d%d",&x,&y);
        x%=MOD;y%=MOD;
        for (int i = n; i >= 0; i--) {
            ansA = (ansA * x + arrA[i]) % MOD;
        }
        for (int i = m; i >= 0; i--) {
            ansB = (ansB * y + arrB[i]) % MOD;
        }
        printf("%d\n",(ansA * ansB) % MOD);
    }
}