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
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = target; j > nums[i]; j--){
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};