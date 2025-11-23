#include<vector>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        int total = sum + target;
        if (total < 0 || total % 2 != 0) {
            return 0;
        }
        target = total / 2;
        // dp[i][j] 前 i 个数字和为 j 的情况数目
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){
                dp[i][j] = dp[i - 1][j];
                if(j >= nums[i - 1]){
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][target];
    }
};