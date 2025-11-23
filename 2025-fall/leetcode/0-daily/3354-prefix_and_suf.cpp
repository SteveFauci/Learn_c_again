#include<vector>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n),suf(n);
        int ans = 0;
        pre[0] = nums[0];
        suf[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i - 1] + nums[i];
            suf[n - 1 - i] = suf[n - i] + nums[n - 1 - i];
        }
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                if(pre[i] == suf[i])ans += 2;
                else if(pre[i] + 1 == suf[i])ans += 1;
                else if(pre[i] - 1 == suf[i])ans += 1;
            }
        }
        return ans;
    }
};