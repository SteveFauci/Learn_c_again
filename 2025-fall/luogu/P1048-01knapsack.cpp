#include<cstdio>
#include<vector>
using namespace std;

int main(){
    int T, M;
    scanf("%d%d",&T,&M);
    vector<int> time(M), value(M);
    for(int i = 0; i < M; i++){
        scanf("%d%d",&time[i], &value[i]);
    }
    // dp[i][j] 收集i草药，j时间内最大值
    vector<vector<int>> dp(M + 1,vector<int>(T + 1,0));
    for(int i = 1; i <= M; i++){
        for(int j = 0; j <= T; j++){
            dp[i][j] = dp[i-1][j]; //先不放. j 是背包容量，第i个物品
            if(time[i - 1] <= j){
                dp[i][j] = max(dp[i][j],dp[i - 1][j - time[i - 1]] + value[i - 1]);
            }
        }
    }
    printf("%d\n",dp[M][T]);
}