#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> pre(sz,1);
        vector<int> suf(sz,1);
        for(int i = 1; i < sz; i++){
            pre[i] = pre[i-1] * nums[i-1];
        }
        for(int i = sz-2; i >= 0; i--){
            suf[i] = suf[i+1] * nums[i+1];
        }
        vector<int> ans(sz,1);
        for(int i = 0; i < sz; i++){
            ans[i] = pre[i] * suf[i];
        }
        return ans;
    }
};