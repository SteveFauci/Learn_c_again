#include<vector>
using namespace std;
int MOD = 1e9+7;
class Solution {
public:
    int countHousePlacements(int n) {
        int pre0 ,pre1 ,pre2 ,pre3;
        int cur0 ,cur1 ,cur2 ,cur3;
        pre0 = pre1 = pre2 = pre3 = cur0 = cur1 = cur2 = cur3 = 1;
        for(int i = 1; i < n; i++){
            cur0 = ((pre0 + pre1) % MOD + (pre2+ pre3) % MOD) % MOD;
            cur1 = (pre0 + pre2) % MOD;
            cur2 = (pre0 + pre1) % MOD;
            cur3 = (pre0) % MOD;
            pre0 = cur0; pre1 = cur1; pre2 = cur2; pre3 = cur3;
        }
        int sum = ((cur0+ cur1) % MOD + (cur2+ cur3) % MOD) % MOD;
        return sum;
    }
};
class Solution0 {
public:
    int countHousePlacements(int n) {
        vector<vector<int>> dp(n, vector<int>(4,1));
        for(int i = 1; i < n; i++){
            dp[i][0] = ((dp[i - 1][0] % MOD + dp[i - 1][1] % MOD) % MOD + (dp[i - 1][2] % MOD + dp[i - 1][3] % MOD) % MOD) % MOD;
            dp[i][1] = (dp[i - 1][0] % MOD + dp[i - 1][2] % MOD) % MOD;
            dp[i][2] = (dp[i - 1][0] % MOD + dp[i - 1][1] % MOD) % MOD;
            dp[i][3] = (dp[i - 1][0] % MOD) % MOD;
        }
        int sum = ((dp[n - 1][0] % MOD + dp[n - 1][1] % MOD) % MOD + (dp[n - 1][2] % MOD + dp[n - 1][3] % MOD) % MOD) % MOD;
        return sum;
    }
};