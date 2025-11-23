#include<vector>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int n: nums){
            sum += n;
        }
        if(sum % 2)return false;
        int target = sum / 2;
        // dp[i][j]: 前 i 个数能否凑出和 j
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){
                dp[i][j] = dp[i-1][j]; // 先不选
                if(j >= nums[i - 1]){  // 如果放得下
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][target];
    }
};