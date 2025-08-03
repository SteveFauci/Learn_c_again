#include <vector>
using namespace std;
class Solution {
  public:
    int countHillValley(vector<int>& nums) {
        int sz = nums.size();
        int cnt = 0;
        int curr = nums[0];
        for (int i = 0; i < sz; i++) {
            if(curr == nums[i])continue;
            else curr = nums[i];
            int left = i, right = i;
            while (nums[left] == curr && left > 0) {
                left--;
            }
            while (nums[right] == curr && right < sz - 1) {
                right++;
            }
            if(nums[right] > curr && nums[left] > curr) cnt++;
            if(nums[right] < curr && nums[left] < curr) cnt++;
        }
        return cnt;
    }
};