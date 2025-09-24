#include <vector>
using namespace std;
class Solution0 {
  public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int pre2 = nums[0];
        int pre1 = max(nums[0], nums[1]);
        int curr = -1;
        for (int i = 2; i < nums.size(); i++) {
            curr = max(pre1, pre2 + nums[i]);
            pre2 = pre1;
            pre1 = curr;
        }
        return pre1;
    }
};

class Solution {
  public:
    int rob(vector<int>& nums) {
        int f0 = 0, f1 = 0;
        for (int x : nums) {
            int new_f = max(f1, f0 + x);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
};