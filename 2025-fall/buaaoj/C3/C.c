#include<stdio.h>

long long p [3][10005];
long long t [3][3];
long long dp[3][10005];
long long min(long long a, long long b){
    return a<b?a:b;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int m;
        scanf("%d",&m);
        for(int j = 0; j < 3; j++){
            for(int i = 0; i < m; i++){
                scanf("%lld",&p[j][i]);
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                scanf("%lld",&t[i][j]);
            }
        }
        dp[0][0] = p[0][0];
        dp[1][0] = p[1][0];
        dp[2][0] = p[2][0];
        for(int j = 1; j < m; j++){
            for(int i = 0; i < 3; i++){
                long long ans = min(
                    dp[0][j-1] + t[0][i],
                    min(
                    dp[1][j-1] + t[1][i],
                    dp[2][j-1] + t[2][i])
                    );
                dp[i][j] = p[i][j] + ans;
            }
        }
        long long ans = min(dp[0][m-1], min(dp[1][m-1], dp[2][m-1]));
        printf("%lld\n",ans);
    }
}