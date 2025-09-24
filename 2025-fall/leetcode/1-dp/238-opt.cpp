#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> suf(sz,1);
        for(int i = sz-2; i >= 0; i--){
            suf[i] = suf[i+1] * nums[i+1];
        }
        int pre = 1;
        for(int i = 0; i < sz; i++){
            suf[i] *= pre;
            pre *= nums[i];
        }
        return suf;
    }
};