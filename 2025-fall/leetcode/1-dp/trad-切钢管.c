#include<stdio.h>
int price[1005];
int dp[1005];
int max(int a, int b){
    return a>b?a:b;
}
int main(){
    int L;
    scanf("%d",&L);
    for(int i = 1; i <= L; i++){
        scanf("%d",&price[i]);
    }
    int ans = -1;
    for(int i = 1; i <= L; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = max(dp[i], price[j] + dp[i - j]);
        }
    }
    printf("%d\n",dp[L]);
}