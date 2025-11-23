#include<stdio.h>
long long price[10005];
long long dp[10005];
long long cut[10005];
long long seg[10005];
int max(int a, int b){
    return a>b?a:b;
}
int main(){
    int L;
    scanf("%d",&L);
    for(int i = 1; i <= L; i++){
        scanf("%lld",&price[i]);
    }
    int ans = -1;
    for(int i = 1; i <= L; i++){
        for(int j = 1; j <= i; j++){
            if(price[j] + dp[i - j] > dp[i]){
                dp[i] = price[j] + dp[i - j];
                cut[i] = j;
            }
        }
    }
    printf("%lld\n",dp[L]);

    int r = L;
    int cnt = 0;
    while(r > 0){
        int i = cut[r];
        seg[cnt] = i;
        cnt++;
        r-=i;
    }
    printf("%d\n",cnt);
    for(int i = 0; i < cnt; i++){
        printf("%lld ",seg[i]);
    }
    puts("");
}