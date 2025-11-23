#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> val(m), pri(m);
    for(int i = 0; i < m; i++){
        cin >> val[i] >> pri[i];
    }
    // n 钱   m 个数
    // dp[i][j] 表示前 i 个物品，花 j 元钱可得的最优权重
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= val[i - 1]){
                dp[i][j] = max(dp[i][j], dp[i-1][j - val[i - 1]] + val[i - 1] * pri[i - 1]);
            }
        }
    }
    cout << dp[m][n];
}