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
        vector<bool> dp(target + 1);
        dp[0] = true;
        for(int i = 0; i < n; i++){
            for(int j = target; j >= nums[i]; j--){
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};