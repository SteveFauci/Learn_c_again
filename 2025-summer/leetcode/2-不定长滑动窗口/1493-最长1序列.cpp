#include<vector>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int my_map[2] = {0};
        int left = 0;
        int sz = nums.size();
        int ans = 0;
        for(int right = 0; right < sz; right++){
            my_map[nums[right]]++;
            while(my_map[0]>1){
                my_map[nums[left]]--;
                left++;
            }
            ans = max(ans , right - left + 1);
        }
        return ans - 1;
    }
};