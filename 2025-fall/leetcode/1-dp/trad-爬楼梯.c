#include<stdio.h>
long long dp[105] = {0,1,2,4,8};
int main(){
    for(int i = 5; i < 105; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
    }
    int T,num;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&num);
        printf("%lld\n",dp[num]);
    }
}