#include<vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sz = nums.size();
        vector<int> suf(sz,0);
        int pre = 0;
        for(int i = sz -2; i >= 0; i--){
            suf[i] = suf[i+1] + nums[i+1];
        }
        for(int i = 0; i < sz; i++){
            if(pre == suf[i])return i;
            pre += nums[i];
        }
        return -1;
    }
};