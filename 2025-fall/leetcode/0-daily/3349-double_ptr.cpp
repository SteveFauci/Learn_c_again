#include<vector>
using namespace std;
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int fast = 0, slow = k;
        int sz = nums.size();
        int cnt = 0;
        while(fast < sz){
            slow++;fast++;
            if(nums[slow] > nums[slow-1] && nums[fast] > nums[fast-1]) cnt++;
            else cnt = 0;
            if(cnt == k - 1)return true;
        }
        return false;
    }
};